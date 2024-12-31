#include "Course.h"

Course::Course() {
    this->courseId = "";
    this->courseName = "";
    this->credits = 0;
    this->assignedProfessor = "";
}

Course::Course(std::string courseId, std::string courseName, int credits, std::string assignedProfessor) {
    this->courseId = courseId;
    this->courseName = courseName;
    this->credits = credits;
    this->assignedProfessor = assignedProfessor;
}

Course::~Course() {}