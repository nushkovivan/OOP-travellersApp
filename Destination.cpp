/**
 * @file Destination.cpp
 * @details Contains the Destination's functions definitions.
 */

#include "Destination.h"
#include<iostream>
#include <cstring>
#include<string>
#include <cassert>

/**
 * @brief Constructor
 * @details Default constructor, defined in a way that it can accept user-provided values as well. It's used to initialize a newly created Date.
 *
 * @param day -the day of the date;
 * @param month - the month of the date;
 * @param year - the year of the date;
 */
Date::Date(int day, int month, int year){
    this->day = day;
    this->month = month;
    this->year = year;
}

/**
 * @brief Cheecks if a date is valid.
 * @return
 */
bool Date::isValid() const{
    //min year is 1980
    if(year > 1990){
        //if month is 1,3,5,7,8,10,12 - it has 31 days
        if((month==1  || month==3 || month==5 || month==7 ||month==8 || month==10 || month==12) && day>0 && day<=31)
            return true;
        //if month is 2,4,6,9,,11 - it has 30 days
        else if((month==4 || month==6 || month ==9 || month ==11) && day>0 && day<=30)
            return true;
        //if month is 2 - checks if the year is leap
        else if(month==2){
            if((year%400==0 || (year%100 != 0 && year%4 ==0)) && day>0 &&day<=29)
                return true;
            //if month is 2 and year is not leap - it has 28 days
            else if(day>0 && day<=28)
                return true;

            return false;
        }
        return false;
    }
    return false;
}

//Checks if two dates are equal
bool operator==( const Date& date1, const Date& date2){
    if(!date1.isValid() || !date2.isValid())
        return false;

    return (date1.day == date2.day && date1.month == date2.month && date1.year == date2.year);
}

//checks if date1 is before date2
bool operator<(const Date& date1, const Date& date2){
    if(!date1.isValid() || !date2.isValid())
        return false;
    return ((date1.day < date2.day && date1.month <= date2.month && date1.year <= date2.year)
           || (date1.month < date2.month && date1.year <= date2.year)
           || date1.year < date2.year);

}


/**
 * @brief Creates copy of an existing object.
 *
 * @param other - reference to an object of type Destination;
 */
void Destination::Copy(const Destination& other){
    //creates new array of chars with the length of other.destination+1 and stores the other.destination in it(sets the destination name)
    destination = new char[strlen(other.destination) + 1];
    assert(destination != nullptr);
    strcpy(destination, other.destination);

    //creates new array of chars with the length of other.timePeriod+1 and stores the other.timePeriod in it(sets the destination's time period)
    timePeriod = new char[strlen(other.timePeriod) + 1];
    assert(timePeriod != nullptr);
    strcpy(timePeriod, other.timePeriod);

    //sets destinations grade
    grade = other.grade;

    //creates new array of chars with the length of other.comment+1 and stores the other.comment in it(sets the destinations's comment)
    comment = new char[strlen(other.comment) + 1];
    assert(comment != nullptr);
    strcpy(comment, other.comment);

    //creates new array of chars with the length of other.photos+1 and stores the other.photos in it(sets the destinatio's photos)
    photos = new char[strlen(other.photos) + 1];
    assert(photos != nullptr);
    strcpy(photos, other.photos);
}

/**
 * @details Deallocate memory and does other cleanup for a Destination object and its class members when the object is destroyed.
 */
void Destination::Erase(){
    delete [] destination;
    delete [] timePeriod;
    delete [] comment;
    delete [] photos;
}

/**
 * @brief Constructor
 * @details Default constructor, defined in a way that it can accept user-provided values as well. It's used to initialize a newly created Destination.
 *
 * @param cDestination - array of chars storing a destination's name;
 * @param cTimePeriod - array of chars storing a time period(format ISO 8601);
 * @param cGrade - storing grade(range [1,5]);
 * @param cComment - array of chars storing a comment;
 * @param cPhotos - array of chars storing photos;
 */
Destination::Destination(const char* cDestination, const char* cTimePeriod, double cGrade, const char* cComment, const char* cPhotos){
    destination = new char[strlen(cDestination) + 1];
    assert(destination != nullptr);
    strcpy(destination, cDestination);

    timePeriod = new char[strlen(cTimePeriod) + 1];
    assert(timePeriod != nullptr);
    strcpy(timePeriod, cTimePeriod);

    grade = cGrade;

    comment = new char[strlen(cComment) + 1];
    assert(comment != nullptr);
    strcpy(comment, cComment);

    photos = new char[strlen(cPhotos) + 1];
    assert(photos != nullptr);
    strcpy(photos, cPhotos);
}

/**
 * @brief Copy constructor
 * @details Creates copy of an existing object.
 *
 * @param other - reference to an object of type Destination;
 * @see Copy(const Destination&)
 */
Destination::Destination(const Destination& other){
    Copy(other);
};

/**
 * @brief Assignment operator.
 * @details Used to copy values from one Destination to another already existing Destination.
 *
 * @param other - reference to an object of type Destination whose values we use;
 * @return the value of the Destination specified by the left operand after the assignment.
 * @see Copy(const Destination&) Erase()
 */
Destination& Destination::operator=(const Destination& other){
    if(this != &other){
        Erase();
        Copy(other);
    }

    return *this;
}

/**
 * @brief Destructor.
 * @details Release any resources allocated by the object of type Destination.
 * @see Erase()
 */
Destination::~Destination(){
    Erase();
}

/**
 * @return the name of the destination.
 */
char* Destination::getDestination() const{
    return destination;
}

/**
 * @return the time period of the destination.
 */
char* Destination::getTimePeriod() const{
    return  timePeriod;
}

/**
 * @return the grade of the destination.
 */
double Destination::getGrade() const{
    return grade;
}

/**
 * @return a comment for the destination.
 */
char* Destination::getComment() const{
    return comment;
}

/**
 * @return photos of this destination
 */
char* Destination::getPhotos() const{
    return photos;
}

/**
 * @brief Takes a parameter (newDestination) and assigns it to the destination attribute of the Destination.
 *
 * @param newDestination - the destination's name to be set;
 */
void Destination::setDestination(char* newDestination){
    delete [] destination;
    destination = new char[strlen(newDestination) + 1];
    assert(destination != nullptr);
    strcpy(destination, newDestination);
}

/**
 * @brief Takes a parameter (newTimePeriod) and assigns it to the timePeriod attribute of the Destination.
 *
 * @param newTimePeriod- the destination's time period to be set;
 */
void Destination::setTimePeriod(char* newTimePeriod){
    delete [] timePeriod;
    timePeriod = new char[strlen(newTimePeriod) + 1];
    assert(timePeriod != nullptr);
    strcpy(timePeriod, newTimePeriod);
}

/**
 * @brief Takes a parameter (newGrade) and assigns it to the grade attribute of the Destination.
 *
 * @param newGrade - the destination's grade to be set;
 */
void Destination::setGrade(double newGrade){
    grade = newGrade;
}

/**
 * @brief Takes a parameter (newComment) and assigns it to the comment attribute of the Destination.
 *
 * @param newComment- the destination's comment to be set;
 */
void Destination::setComment(char* newComment){
    delete [] comment;
    comment = new char[strlen(newComment) + 1];
    assert(comment != nullptr);
    strcpy(comment, newComment);
}

/**
 * @brief Takes a parameter (newPhotos) and assigns it to the photos attribute of the Destination.
 *
 * @param newPhotos - the destination's photos to be set;
 */
void Destination::setPhotos(char* newPhotos){
    delete [] photos;
    photos = new char[strlen(newPhotos) + 1];
    assert(photos != nullptr);
    strcpy(photos, newPhotos);
}

/**
 * @details Used to ask for Destination input from the console.
 */
void Destination::input(){
    std::cout<<"Your destination:"<<std::endl;
    std::cin.getline(destination, 100);
    std::cout<<"Time period:"<<std::endl;
    std::cin.getline(timePeriod, 100);
    std::cout<<"Your grade:"<<std::endl;
    std::cin>>grade;
    std::cin.ignore();
    std::cout<<"Your comment:"<<std::endl;
    std::cin.getline(comment, 200);
    std::cout<<"Your photos:"<<std::endl;
    std::cin.getline(photos, 100);
}

/**
 * @brief Stream insertion operator << .
 * @details Used for objects of type Destination output.
 *
 * @param out - std::cout object;
 * @param user - reference to an object of our class(Destination).
 * @return a reference to the stream that was passed in(out) - to allow operators to be chained together.
 */
std::ostream& operator<< (std::ostream &out, const Destination& destination){
    out<<destination.destination<<" "<<destination.timePeriod<<" "<<destination.grade<<" "
       <<destination.comment<<" "<<destination.photos<<std::endl;

    return out;
}

/**
 * @brief Stream extraction operator >> .
 *  @details Used for objects of type Destination input.
 *
 * @param in - - std::cin object;
 * @param user - reference to an object of our class(Destination).
 * @return - a reference to the stream that was passed in(in) - to allow operators to be chained together.
 */
std::istream& operator>> (std::istream &in, Destination& destination) {
    in >> destination.destination;
    in.ignore();
    in >> destination.timePeriod;
    in.ignore();
    in >> destination.grade;
    in.ignore();
    in >> destination.comment;
    in.ignore();
    in >> destination.photos;
    in.ignore();

    return in;
}