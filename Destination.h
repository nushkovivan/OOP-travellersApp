/**
 * \headerfile Destination.h
 * @details Contains all the Destination's functions declarations.
 */
#ifndef DESTINATION_H
#define DESTINATION_H

#include<iostream>

class Date {
private:
    int day;/**< - the date's day*/
    int month;/**< - the date's month*/
    int year;/**< - the date's year*/

public:
    Date(int = 0, int = 0, int = 0);
    bool isValid() const;

    friend bool operator==( const Date& date1, const Date& date2);
    friend bool operator<(const Date& date1, const Date& date2);
};

/**
 * @class Destination
 * @details Class for declaring destinations. Every Destination is in format(destination, time period, grade, comment, photos).
 */
class Destination{
private:
    char* destination;/**< - dynamically allocated array of chars to store the destination name;*/
    char* timePeriod;/**< - dynamically allocated array of chars to store the time period;*/
    double grade;/**< - used to store the rating of the destination;*/
    char* comment;/**< - dynamically allocated array of chars to store the comment for the destination;*/
    char* photos;/**< - dynamically allocated array of chars to store the photos;*/

    void Copy(const Destination&);
    void Erase();

public:
    Destination(const char* = "N/A", const char* = "N/A", double = 0.0, const char* = "N/A", const char* = "N/A");
    Destination(const Destination&);
    Destination& operator=(const Destination&);
    ~Destination();

    char* getDestination() const;
    char* getTimePeriod() const;
    double getGrade() const;
    char* getComment() const;
    char* getPhotos() const;

    void setDestination(char*);
    void setTimePeriod(char*);
    void setGrade(double);
    void setComment(char*);
    void setPhotos(char*);

    void input();

    friend std::ostream& operator<< (std::ostream &out, const Destination& destination);
    friend std::istream& operator>> (std::istream &in, Destination& destination);
};

#endif
