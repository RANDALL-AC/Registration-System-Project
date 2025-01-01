#pragma once
#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include "student.h"
#include "course.h"
#include "schedule.h"
#include "registration.h"

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

};
#endif 