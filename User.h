/**
 * \headerfile User.h
 * @details Contains all the Users's functions declarations.
 */

#ifndef USER_H
#define USER_H

#include<iostream>

/**
 * @class User
 * @details Class for declaring users. Every user has name, password, email and list of friends.
 */
class User{
private:
    char* name;/**< - dynamically allocated array of chars to store the user's name;*/
    char* password;/**< - dynamically allocated array of chars to store the user's password;*/
    char* email;/**< - dynamically allocated array of chars to store the user's email;*/
    char** friends;/**< - dynamically allocated array of char* to store the user's list of friends;*/
    int friendsCurrSize;/**< - the current number of friends;*/
    int friendsMaxSize;/**< - the maximum number of friends that the user can have;*/


    void Copy(const User&);
    void Erase();

public:
    User(const char* = "N/A", const char* = "N/A", const char* = "N/A", int = 0, int = 20, char** = nullptr);
    User(const User&);
    User& operator=(const User&);
    ~User();

    void setName(char*);
    void setPassword(char*);
    void setEmail(char*);

    void setCurrFriendsNum(int);
    void setMaxFriendsNum(int);
    void addFriend(char* friendA);

    char* getName()const;
    char* getPassword()const;
    char* getEmail()const;
    char** getFriends()const;

    friend std::ostream& operator<<(std::ostream &out, const User &user);
    friend std::istream& operator>>(std::istream &in, User &user);

    void print()const;
    void printFriends() const;
    void regInput();
    void loginInput();
};

#endif
