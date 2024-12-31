#pragma once
#ifndef STUDENT_H
#define STUDENT 
#include <iostream>
class Student
{
public:
    Student();
    Student(std::string name, std::string id, std::string career, int level);
    ~Student();

    std::string getName();
    std::string getId();
    std::string getCareer();
    int getLevel() const;

    void setName(std::string name);
    void setId(std::string id);
    void setCareer(std::string career);
    void setLevel(int level);
private:
    std::string name;
    std::string id;
    std::string career;
    int level;
};
#endif