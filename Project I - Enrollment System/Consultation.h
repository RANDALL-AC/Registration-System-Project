#pragma once
#ifndef CONSULTATION_H
#define CONSULTATION_H

#include <iostream>
#include "student.h"
#include "course.h"
#include "schedule.h"
#include "registration.h"

class Consultation
{
public:
    void showRegisteredStudent(Student student, int courseCount, int totalCost);
    void showAssignedCourses(Course courses[], int numCourses);
    void showStudentCourses(Student student, Registration registrations[], int numRegistrations);
    void showCourseSchedule(Course course);
};
#endif