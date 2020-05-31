/**
 * @file User.cpp
 * @details Contains the User's functions definitions.
 */

#include "User.h"
#include<iostream>
#include <cstring>
#include <cassert>
#include<sstream>

/**
 * @brief Creates copy of an existing object.
 *
 * @param other - reference to an object of type User;
 */
void User::Copy(const User& other){
    //creates new array of chars with the length of other.name+1 and stores the other.name in it(sets user name)
    name = new char[strlen(other.name) + 1];
    assert(name != nullptr);
    strcpy(name, other.name);

    //creates array of chars with the length of other.password+1 and stores the other.password in it(sets user password)
    password = new char[strlen(other.password) + 1];
    assert(password != nullptr);
    strcpy(password, other.password);

    //creates array of chars with the length of other.email+1 and stores the other.email in it(sets user email)
    email = new char[strlen(other.email) + 1];
    assert(email != nullptr);
    strcpy(email, other.email);

    //sets current friends number and maximum friends number as those of other
    friendsCurrSize = other.friendsCurrSize;
    friendsMaxSize = other.friendsMaxSize;

    //creates array of char* with the length of friendsCurrSize+1 and stores the other.friends in it(sets user's friends list)
    friends = new char*[friendsCurrSize + 1];
    assert(friends != nullptr);
    for(int i = 0; i < friendsCurrSize; i++)
        strcpy(friends[i], other.friends[i]);
}

/**
 * @details Deallocate memory and does other cleanup for a User object and its class members when the object is destroyed.
 */
void User::Erase(){
    delete [] name;
    delete [] password;
    delete [] email;
    delete [] friends;
}

/**
 * @brief Constructor
 * @details Default constructor, defined in a way that it can accept user-provided values as well. It's used to initialize a newly created User.
 *
 * @param cName - array of chars storing a name;
 * @param cPassword - array of chars storing a password;
 * @param cEmail - array of chars storing an email;
 * @param cFriendsCurrSize  - current number of friends, 0 by default;
 * @param cFriendsMaxSize - maximum number of friends, 20 by default;
 * @param cFriends - array of char* storing the User's friends
 */
User::User(const char* cName, const char* cPassword, const char* cEmail, int cFriendsCurrSize, int cFriendsMaxSize, char** cFriends){
    name = new char[strlen(cName) + 1];
    assert(name != nullptr);
    strcpy(name, cName);

    password = new char[strlen(cPassword) + 1];
    assert(password != nullptr);
    strcpy(password, cPassword);

    email = new char[strlen(cEmail) + 1];
    assert(email != nullptr);
    strcpy(email, cEmail);

    friendsCurrSize = cFriendsCurrSize;
    friendsMaxSize = cFriendsMaxSize;

    friends = new char*[friendsCurrSize + 1];
    assert(friends != nullptr);
    for(int i = 0; i < friendsCurrSize; i++)
        strcpy(friends[i], cFriends[i]);
}

/**
 * @brief Copy constructor
 * @details Creates copy of an existing object.
 *
 * @param other - reference to an object of type User;
 * @see Copy(const User&)
 */
User::User(const User& other){
    Copy(other);
}

/**
 * @brief Assignment operator.
 * @details Used to copy values from one User to another already existing User.
 *
 * @param other - reference to an object of type User whose values we use;
 * @return the value of the User specified by the left operand after the assignment.
 * @see Copy(const User&) Erase()
 */
User& User::operator=(const User& other){
    if(this != &other){
        Erase();
        Copy(other);
    }

    return *this;
}

/**
 * @brief Destructor.
 * @details Release any resources allocated by the object of type User.
 * @see Erase()
 */
User::~User(){
    Erase();
}

/**
 * @brief Takes a parameter (newName) and assigns it to the name attribute of the User.
 *
 * @param newName - the name to be set;
 */
void User::setName(char* newName){
    delete[] name;
    name = new char[strlen(newName) + 1];
    assert(name != nullptr);
    strcpy(name, newName);
}

/**
 * @brief Takes a parameter (newPassword) and assigns it to the password attribute of the User.
 *
 * @param newPassword - the password to be set;
 */
void User::setPassword(char* newPassword){
    delete[] password;
    password = new char[strlen(newPassword) + 1];
    assert(password != nullptr);
    strcpy(password, newPassword);
}

/**
 * @brief Takes a parameter (newEmail) and assigns it to the email attribute of the User.
 *
 * @param newEmail - the email to be set;
 */
void User::setEmail(char* newEmail){
    delete[] email;
    email = new char[strlen(newEmail) + 1];
    assert(email != nullptr);
    strcpy(email, newEmail);
}

/**
 * @brief Takes a parameter (currSize) and assigns it to the current size of friends(friendsCurrSize) attribute of the User.
 *
 * @param currSize - the size to be set;
 */
void User::setCurrFriendsNum(int currSize){
    friendsCurrSize = currSize;
}

/**
 * @brief Takes a parameter (maxSize) and assigns it to the maximum size of friends(friendsMaxSize) attribute of the User.
 *
 * @param maxSize - the size to be set;
 */
void User::setMaxFriendsNum(int maxSize){
    friendsMaxSize = maxSize;
}

/**
 * @details Adds the name given as an argument to the friends array of the User.
 *
 * @param state - the name of the friend we want to add;
 * @note If the current number of friends(friendsCurrSize) is equal to the maximum number of friends(friendsMax Size)the
 * program should increase the maximum number of friends(friendsMaxNum) first.
 */
void User::addFriend(char* friendA){
    //checks if the maximum number of friends is reached
    if (friendsCurrSize == friendsMaxSize) {
        //increases the maximum number of friends
        ++friendsMaxSize;
        //dynamically allocates new array of char* and stores the Users friends in it, then deallocates the memory used for
        //our friends array and appropriates the buffer to friends
        char** buffer = new char*[friendsMaxSize];
        for (int i = 0; i < friendsCurrSize; i++) {
            strcpy(buffer[i], friends[i]);
        }

        delete[] friends;
        friends = buffer;
    }
    //adds the new friend at the end of the array
    friends[friendsCurrSize++] = friendA;
}


/**
 * @return the name(array of chars) of the User.
 */
char* User::getName()const{
    return name;
}

/**
 * @return the password(array of chars) of the User.
 */
char* User::getPassword()const{
    return password;
}

/**
 * @return the email(array of chars) of the User.
 */
char* User::getEmail()const{
    return email;
}

/**
 * @return the friends(array of char*) of the User;
 */
char** User::getFriends()const{
    return friends;
}

/**
 * @details Used to ask for User input from the console - for registration(name, password, email).
 */
void User::regInput(){
    std::cout<<"User name:";
    std::cin>>name;
    std::cout<<"Password:";
    std::cin>>password;
    std::cout<<"Email:";
    std::cin>>email;
}

/**
 * @details Used to ask for User input from the console - for login(name, password).
 */
void User::loginInput(){
    std::cout<<"User name:";
    std::cin>>name;
    std::cout<<"Password:";
    std::cin>>password;
}

/**
 * @details Prints Users attributes(name password, email).
 */
void User::print()const{
    std::cout<<"Name: "<<name<<" Password: "<<password<<" Email: "<<email<<"Friends: ";

}

/**
 * @details Prints users array of friends.
 */
void User::printFriends() const{
    std::cout<<"Friends:";
    for(int i = 0; i < friendsCurrSize; i++)
        std::cout<<friends[i]<<" ";

    std::cout<<std::endl;
}

/**
 * @brief Stream insertion operator << .
 * @details Used for objects of type User output.
 *
 * @param out - std::cout object;
 * @param user - reference to an object of our class(User);
 * @return a reference to the stream that was passed in(out) - to allow operators to be chained together.
 */
std::ostream& operator<<(std::ostream &out, const User &user){
    out<<user.name<<" "<<user.password<<" "<<user.email<<" ";
    for(int i = 0; i < user.friendsCurrSize; i++)
        out<<user.friends[i]<<" ";

    out<<std::endl;
    return out;
}

/**
 * @brief Stream extraction operator >> .
 *  @details Used for objects of type User input.
 *
 * @param in - - std::cin object;
 * @param user - reference to an object of our class(User).
 * @return - a reference to the stream that was passed in(in) - to allow operators to be chained together.
 */
std::istream& operator>>(std::istream &in, User &user) {
    in >> user.name;
    in >> user.password;
    in >> user.email;

    std::string friendsNames;
    in.get();
    getline(in,  friendsNames);
    std::stringstream stream1(friendsNames);
    std::string names;
    while(stream1 >> names){
        char* help = new char[20];
        strcpy(help, names.c_str());
        user.addFriend(help);
        delete [] help;
    }

    return in;
}