//
// Created by asem on 15/03/19.
//

#ifndef SBE201_STACKS_QUEUES_CUSTOM_TYPES_HPP
#define SBE201_STACKS_QUEUES_CUSTOM_TYPES_HPP

#include <string>

enum class Sex
{
    Male,
    Female
}; 

struct Patient
{
    int id;
    std::string firstName;
    std::string lastName;
    int age;
    Sex sex; 
    Patient(int vId, const std::string &fname, const std::string &lname, int vAge, Sex vSex)
    {
        id = vId;
        firstName = fname;
        lastName = lname;
        age = vAge;
        sex = vSex;
    }
};

struct Point
{
    double x;
    double y;
    Point(double u = 0, double v = 0)
    {
        x = u;
        y = v;
    }
};

#endif //SBE201_STACKS_QUEUES_CUSTOM_TYPES_HPP
