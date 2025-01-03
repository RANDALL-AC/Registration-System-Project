#pragma once
#ifndef CONSULTATION_H
#define CONSULTATION_H

#include <iostream>
#include <vector>
#include "student.h"
#include "course.h"
#include "schedule.h"
#include "registration.h"

class Consultation
{
public:

    void showRegisteredStudent(Student student, int courseCount, int totalCost);
    void showAssignedCourses(std::vector<Course>& courses);
    void showStudentCourses(Student& student, std::vector<Registration>& registrations);
    void showCourseSchedule(Course& course);

};
#endif