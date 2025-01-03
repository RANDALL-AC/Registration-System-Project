#pragma once
#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <vector>
#include "student.h"
#include "course.h"
#include "schedule.h"
#include "registration.h"
#include "consultation.h"

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

    void showConsultationMenu();
    void showRegisteredStudent();
    void showAssignedCourses();

private:

    int numStudents = 0;
    int numCourses = 0;
    int numSchedules = 0;
    int numRegistrations = 0;

    std::vector<Student> students;
    std::vector<Schedule> schedules;
    std::vector<Course> courses;
    std::vector<Registration> registrations;
    Consultation consultation;
};
#endif 