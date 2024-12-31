#pragma once
#ifndef COURSE_H
#define COURSE_H
#include <iostream>

class Course
{
public:

    Course();
    Course(std::string courseName, std::string courseId, int credits, std::string assignedProfessor);
    ~Course();

    std::string getCourseName();
    std::string getCourseId();
    int getCredits() const;
    std::string getAssignedProfessor();

    void setCourseName(std::string courseName);
    void setCourseId(std::string courseId);
    void setCredits(int credits);
    void setAssignedProfessor(std::string assignedProfessor);

private:
    std::string courseName;
    std::string courseId;
    int credits;
    std::string assignedProfessor;
};
#endif