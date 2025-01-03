#pragma once
#ifndef REGISTRATION_H
#define REGISTRATION_H
#include <iostream>
#include "Student.h"
#include "Course.h"
#include "Schedule.h"

class Registration
{
public:

    Registration();
    Registration(Student student, Course course, Schedule schedule);
    ~Registration();

    Student getStudent();
    Course& getCourse();
    Schedule getSchedule();

    void setStudent(Student student);
    void setCourse(Course course);
    void setSchedule(Schedule schedule);


private:
    Student student;
    Course course;
    Schedule schedule;
};
#endif