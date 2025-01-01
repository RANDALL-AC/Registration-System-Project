#pragma once
#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include "student.h"
#include "course.h"
#include "schedule.h"
#include "registration.h"

const int maxStudents = 20;
const int maxCourses = 10;
const int maxSchedules = 10;
const int maxCoursesPerStudents = 4;

class System
{
public:

    System();

    void showMenu();

    void showFileMenu();
    void about();
    void exitSystem(); 

    void showMaintenanceMenu(); 
    void addStudent();
    void addCourse();
    void addSchedule();

    void showRegistrationMenu(); 
    void registerStudent();
    bool checkScheduleConflict(Student newStudent, Schedule newSchedule); 

private:

    int numStudents = 0;
    int numCourses = 0;
    int numSchedules = 0;
    int numRegistrations = 0;

    Student students[maxStudents];
    Course courses[maxCourses];
    Schedule schedules[maxSchedules];
    Registration registrations[maxStudents * maxCoursesPerStudents];
};
#endif 