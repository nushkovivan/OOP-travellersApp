/**
 * @file main.cpp
 * @details Contains function definitions and controls the console work.
 */

#include "User.h"
#include "Destination.h"
#include <iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<sstream>
#include<vector>
#include <bits/stdc++.h>

bool isPicValid(char* pictures);

bool isValidDate(int day, int month, int year);
bool isDateRangeValid(int day1, int month1, int year1, int day2, int month2, int year2);
bool isDateValid(char* name);
bool isDateRangeValid(char* date);

double getAvgGrade(std::string name);

bool isNameFree(const User& user);
bool isEmailFree(const User& user);
bool isRegistered(const User& user);

void printOptions();

void yourTrips(char* name);
void findDestination();
void destinationList();
void addTrip(char* name);
void deleteTrip(char* name);
void friendsList(char* name);
void addFriend(char* name);

int main() {

    std::cout <<" ........................................."<< std::endl;
    std::cout <<".    WELCOME TO YOUR TRAVELLER'S APP    ." << std::endl;
    std::cout <<".........................................."<< std::endl;
    std::cout<<std::endl;

    std::cout<<"To use the app:"<<std::endl;
    std::cout<<"1. Connect or 2. Registration"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Your choice:";
    std::string userChoice;

    //while there's input from the user
    while(std::getline(std::cin, userChoice)){
        //if the user wants to register
        if(userChoice == "registration" || userChoice == "Registration"){
            std::cout<<std::endl;
            //inputs registration profile data
            User user1;
            user1.regInput();
            //opens "users.txt" for reading
            std::ofstream file("users.txt", std::ios::out | std::ios::app);
            if(!file){
                std::cout<<"File couldn't open!"<<std::endl;
                exit(1);
            }
            //if name and email are free - adds user in "users.txxt"
            if(isNameFree(user1) && isEmailFree(user1)) {
                file<<user1;
                std::cout<<std::endl;
                std::cout<<"Registration successful! Now you can connect!" << std::endl;
                std::cout<<std::endl;
            }
            //checks if the inputed name is free
            else if(!isNameFree(user1)){
                std::cout<<std::endl;
                std::cout<<"User name not free! Please try again!"<<std::endl;
            }
            //checks if the inputed email is free
            else if(!isEmailFree(user1)){
                std::cout<<std::endl;
                std::cout<<"Email not free! Please try again!"<<std::endl;
            }
        }
        //if the user wants to make a registration
        if(userChoice == "connect" || userChoice == "Connect"){
            User user;
            user.loginInput();
            //checks if the user name and password are in the users file
            if(isRegistered(user)){
                //shows the user the available operations
                printOptions();
                //asks the user to input his choice
                std::cin.ignore();
                std::string menuChoice;
                while(getline(std::cin,menuChoice)){
                    // calls one of the functions
                    if(menuChoice == "trips") {
                        yourTrips(user.getName());
                        break;
                    }
                    if(menuChoice == "friends") {
                        friendsList(user.getName());
                        break;
                    }
                    if(menuChoice == "destinations") {
                        destinationList();
                        break;
                    }
                    if(menuChoice == "search") {
                        findDestination();
                        break;
                    }
                    if(menuChoice == "addTrip") {
                        addTrip(user.getName());
                        break;
                    }
                    if(menuChoice == "addFriend") {
                        addFriend(user.getName());
                        break;
                    }
                    if(menuChoice == "delete") {
                        deleteTrip(user.getName());
                        break;
                    }
                    if(menuChoice == "logout") {
                        std::cout<<"Are you sure you want to exit?";
                        std::cin.clear();
                        char choice;
                        std::cin>>choice;
                        if(choice == 'y' || choice == 'C')
                            exit(0);

                        break;
                    }
                    std::cout<<"Option not supported! Please try again!";
                    std::cout<<std::endl;
                    break;
                }
            }
        }
    }

    return 0;
}
