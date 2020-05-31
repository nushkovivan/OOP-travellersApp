/**
 * @file functions.cpp
 * @details Contains the User's functions definitions.
 */

#include "User.h"
#include "Destination.h"
#include<iostream>
#include <string>
#include <vector>
#include<sstream>
#include<fstream>
#include<cstring>
#include <iomanip>
#include <bits/stdc++.h>

/**
 * @brief Checks if all the pics are with valid extensions
 *
 * @param name array of chars used to store the picture's names
 * @return true if all the pics in the array are valid and false if not
 */
bool isPicValid(char* pictures){
    //stores the picture's array in stream
    std::stringstream stream(pictures);
    std::string singlePic;

    std::vector<std::string> pics;
    //splits the individual pictures
    int counter = 0;
    while(stream>>singlePic) {
        std::string picParts;
        //stores every individual picture in new stream
        std::stringstream stream1(singlePic);
        //gets the elements separated by the point and stores it in the vector
        while(getline(stream1, picParts, '.')) {
            pics.push_back(picParts);
        }
    }

    //checks if every second element(the extension) in the vector is like jpeg/png
    for(int i = 1; i < pics.size(); i+=2){
        if(pics[i] != "jpeg" && pics[i] != "png")
            return false;
    }

    return true;
}

/**
 * @brief Checks if the date range given in the array is valid
 *
 * @param name array of chars used to store the date range
 * @return true if all the date range is valid and false if not
 */
bool isDateRangeValid(char* date){
    //stores the date range in stream
    std::stringstream stream(date);
    std::string date1, date2, err;

    std::vector<std::string> dateHelp;

    //stores the two dates in date1 and date2
    stream>>date1>>err>>date2;

    std::stringstream helpStream;
    helpStream<<date1<<" "<<date2;
    std::string dateHelper;

    //reads every element from the dates and stores it in the vector
    while(helpStream>>dateHelper) {
        std::string datePart;
        std::stringstream stream1(dateHelper);
        while(getline(stream1, datePart, '-')) {
            dateHelp.push_back(datePart);
        }
    }

    int day1, day2, month1, month2, year1, year2;
    std::stringstream dates;
    for(const auto & i : dateHelp)
        dates<<i<<" ";

    //creates two date objects to store the dates and operate with them
    dates>>year1>>month1>>day1>>year2>>month2>>day2;
    Date dateC1(day1, month1, year1), dateC2(day2, month2, year2);

    //checks if the two dates are valid and date1 is before date2
    return (dateC1.isValid() && dateC2.isValid() && (dateC1 < dateC2 || dateC1 == dateC2));
}

/**
 *
 * @param name - the name of the destination whose average grade is needed.
 * @return the average grade for the destination.
 */
double getAvgGrade(std::string name){
    Destination destination;
    //opens file "destination.txt" for reading
    std::ifstream fileDest("destinations.txt", std::ios::in);
    if(!fileDest){
        std::cout<<"File couldn't open!"<<std::endl;
        exit(1);
    }

    double grade = 0, avgGrade =0;
    int counter = 0;
    //while going through file if the destination name is the name given as argument adds it to grade and counts
    while(fileDest>>destination){
        if(destination.getDestination() == name) {
            grade += destination.getGrade();
            counter++;
        }
    }
    //average is equal to all grades / the amount of times they've been mentioned
    avgGrade = grade / counter;

    return avgGrade;
}

/**
 * @brief Checks whether the name of the user is free.
 *
 * @param user - reference to an object of type User;
 * @return true if the name is free and false if not.
 */
bool isNameFree(const User& user){
    User user1;
    bool nameFree = true;

    //opens "users.txt" for reading
    std::ifstream file("users.txt", std::ios::in);
    if (!file) {
        std::cerr << "File couldn't be open!";
        exit(1) ;
    }

    //reads users from the file and if there is an user with this name sets nameFree to false
    while(file>>user1){
        if(!strcmp(user1.getName(), user.getName()))
            nameFree = false;
    }
    return nameFree;
}

/**
 * @brief Checks whether the email of the user is free.
 *
 * @param user - reference to an object of type User;
 * @return true if the name is free and false if not.
 */
bool isEmailFree(const User& user){
    User user1;
    bool emailFree = true;

    //opens "users.txt" for reading
    std::ifstream file("users.txt", std::ios::in);
    if (!file) {
        std::cerr << "File couldn't be open!";
        exit(1) ;
    }

    //reads users from the file and if there is an user with this email sets nameFree to false
    while(file>>user1){
        if(!strcmp(user1.getEmail(), user.getEmail()))
            emailFree = false;
    }
    return emailFree;
}

/**
 * @brief Checks whether the user is registerd
 *
 * @param user - reference to an object of type User
 * @return true if the name is free and false if not
 */
bool isRegistered(const User& user){
    User user1;
    bool isRegistered = false;

    //opens "users.txt" for reading
    std::ifstream file("users.txt", std::ios::in);
    if (!file) {
        std::cerr << "File couldn't be open!";
        exit(1) ;
    }

    //while reading from the file if a user name and password are found on the same line isRegistered = true
    while(file>>user1){
        if(!strcmp(user1.getName(), user1.getName()) && !strcmp(user.getPassword(), user1.getPassword()))
            isRegistered = true;
    }
    return isRegistered;
};

/**
 *@brief Shows the options that the user has - to use the app
 */
void printOptions(){
    std::cout << std::endl;
    std::cout << "Login successful! Your personal menu: " << std::endl;
    std::cout << std::endl;
    std::cout << "trips        - Your trips." << std::endl;
    std::cout << "friends      - Your friends list." << std::endl;
    std::cout << "destinations - Destinations visited by other users list." << std::endl;
    std::cout << "search       - Find Destination." << std::endl;
    std::cout << "addTrip      - Add Trip." << std::endl;
    std::cout << "addFriend    - Add Friend." << std::endl;
    std::cout << "delete       - Delete Trip." << std::endl;
    std::cout << "logout       - Logout." << std::endl;
    std::cout << std::endl;
    std::cout << "Choose One:";

}

/**
 * @brief Lists all the destinations in the user(name) database
 * @param name the user name whose database we are going to use
 */
void yourTrips(char* name){
    Destination destination;

    //opens the file for reading
    std::ifstream fileTrips(name, std::ios::in);
    if(!fileTrips){
        std::cout<<"File coudn't open!"<<std::endl;
        exit(1);
    }

    //prints all destinations from file
    while(fileTrips>>destination) {
        std::cout << std::setw(20) << " " << destination.getDestination() << " | " << std::setw(25)
                  << destination.getTimePeriod() << "  | "
                  << std::setw(3) << destination.getGrade() << "| " << std::setw(50) << destination.getComment()
                  << " | "
                  << std::setw(40) << destination.getPhotos() << " |" << std::endl;
    }
}

/**
 * @brief Searches for an user inputed destination through file
 */
void findDestination(){
    //asks the user to input the name of the destination
    std::string destinationName;
    std::cout<<"Enter the destination you are searching:";
    std::cin.ignore();
    std::getline(std::cin, destinationName);

    //opens the destinations file for reading
    std::ifstream fileTrips("destinations.txt", std::ios::in);
    if(!fileTrips){
        std::cout<<"File coudn't open!"<<std::endl;
        exit(1);
    }

    //reads through "destinations.txt" and prints the destinations with the searched name
    std::string userName;
    Destination destination;
    std::cout<<destinationName<<":"<<std::endl;
    while(fileTrips>>userName>>destination){
        if(!strcmp(destination.getDestination(), destinationName.c_str())){
            std::cout<<std::setw(15)<<userName<<": "<<" "<<std::setw(4)<<destination.getGrade()<<std::endl;
        }
    }
    //prints the average grade of this destination
    std::cout<<"Avg grade: "<<getAvgGrade(destinationName);
}

/**
 * @brief Prints list of available destinations
 */
void destinationList(){
    //opens "destinations.txt" for reading
    Destination destination;
    std::ifstream fileTrips("destinations.txt", std::ios::in);
    if(!fileTrips){
        std::cout<<"File coudn't open!"<<std::endl;
        exit(1);
    }
    //reads through file and stores all the destinations name in vector
    std::string name;
    std::vector<std::string> destNames;
    while(fileTrips>>name>>destination) {
        destNames.emplace_back(destination.getDestination());
    }
    //sorts the vector
    std::sort(destNames.begin(), destNames.end());
    //gets all the destinations(each of them only once)
    for(int i = 0; i < destNames.size(); i++){
        if(destNames[i] != destNames[i+1])
            std::cout<<destNames[i]<<" ";
    }

    std::cout<<std::endl;
}

/**
 * @brief adds a new trip to the user's personal database
 * @param name the name of the user
 */
void addTrip(char* name){
    Destination destination;

    //opens the user's personal file for writing
    std::ofstream fileAdd(name, std::ios::out | std::ios::app);
    if(!fileAdd){
        std::cout<<"File coudn't open!"<<std::endl;
        exit(1);
    }

    //opens the destinations file for writing as well
    std::ofstream fileTrips("destinations.txt", std::ios::out | std::ios::app);
    if(!fileTrips){
        std::cout<<"File coudn't open!"<<std::endl;
        exit(1);
    }

    //asks the user to input destination
    destination.input();
    bool picturesVal = true, dateVal = true;
    if(!isPicValid(destination.getPhotos())){
        std::cout<<"Pictures format not supported!"<<std::endl;
        picturesVal = false;
    }
    if(!isDateRangeValid(destination.getTimePeriod())){
        std::cout<<"Date period not valid!!"<<std::endl;
        dateVal = false;
    }
    //adds the destinations in both files
    if(dateVal && picturesVal) {
        fileAdd << destination;
        fileTrips << name << " " << destination.getDestination() << " " << destination.getGrade();
        std::cout << std::endl;
        std::cout << "Destination successfully added!" << std::endl;
    }
}

/**
 * @brief Deletes destination from the users personal database
 * @param name - the user name(name of the file we're working with);
 */
void deleteTrip(char* name){
    Destination destination;
    std::string toDelete;
    //asks the user to input destination name
    std::cout<<"Please enter the destination you want to delete:";
    std::cin>>toDelete;

    //opens users personal database for reading
    std::ifstream fileDelete(name, std::ios::in);
    if(!fileDelete){
        std::cout<<"File coudn't open!"<<std::endl;
        exit(1);
    }

    //opens help file for writing
    std::ofstream fileTemp("temp.txt", std::ios::out | std::ios::app);
    if(!fileTemp){
        std::cout<<"File coudn't open!"<<std::endl;
        exit(1);
    }

    //writes all the destinations in the temporary file except the one we're deleting
    while(fileDelete>>destination){
        if(!strcmp(destination.getDestination(), toDelete.c_str()))
            continue;
        else
            fileTemp<<destination;
    }

    std::cout<<std::endl;
    std::cout<<"Destination successfully deleted!"<<std::endl;
    //closes the files
    fileDelete.close();
    fileTemp.close();
    //deletes the user personal file and renames the temporary one
    remove(name);
    rename("temp.txt", name);
}

/**
 * @brief Adds a new friend (in the user's friends array)
 * @param name - the name of the friend to be added'
 */
void addFriend(char* name){
    User user;
    std::string toAdd;
    //asks the user to enter a friend name
    std::cout<<"Please enter the user name you want to add as friend:";
    std::cin>>toAdd;

    //opens "users.txt" for reading
    std::ifstream fileFriendSearch("users.txt", std::ios::in);
    if(!fileFriendSearch){
        std::cout<<"File couldn't open!"<<std::endl;
        exit(1);
    }

    //opens "temp.txt" for writing
    std::ofstream fileFriendTemp("temp.txt", std::ios::out | std::ios::app);
    if(!fileFriendTemp){
        std::cout<<"File couldn't open!"<<std::endl;
        exit(1);
    }

    //reads users from the "users.txt" file and writes them in the temporary file, if the user name is equal to the name
    // of the friend we want to add - adds it in the user structure and then writes user in the temporary file
    while(fileFriendSearch>>user){
        if(!strcmp(user.getName(), name)){
            char* add = new char[toAdd.length() + 1];
            strcmp(add, toAdd.c_str());
            user.addFriend(add);
            delete [] add;
            fileFriendTemp<<user;
        }
        else
            fileFriendTemp<<user;
    }

    //closes the files
    fileFriendSearch.close();
    fileFriendTemp.close();

    //renoves the file "users.txt and renames "temp.tt"
    remove("users.txt");
    rename("temp.txt", "users.txt");

}

/**
 * @brief Prints all the user friends
 * @param name - the name of the user whose friends we are going to print
 */
void friendsList(char* name){
    User user;

    //opens the "users.txt" file for reading
    std::ifstream fileFriends("users.txt", std::ios::in);
    if(!fileFriends){
        std::cout<<"File couldn't open!"<<std::endl;
        exit(1);
    }

    //reads users from the file till it finds the user with the wanted name, then prints their names
    while(fileFriends>>user){
        if(!strcmp(user.getName(), name)){
            user.printFriends();
        }
    }
}