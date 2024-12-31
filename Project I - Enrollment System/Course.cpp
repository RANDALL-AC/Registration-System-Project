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

std::string Course::getCourseId() {
    return this->courseId;
}

std::string Course::getCourseName() {
    return this->courseName;
}

int Course::getCredits() const {
    return this->credits;
}

std::string Course::getAssignedProfessor() {
    return this->assignedProfessor;
}

void Course::setCourseId(std::string courseId) {
    this->courseId = courseId;
}

void Course::setCourseName(std::string courseName) {
    this->courseName = courseName;
}

void Course::setCredits(int credits) {
    this->credits = credits;
}

void Course::setAssignedProfessor(std::string assignedProfessor) {
    this->assignedProfessor = assignedProfessor;
}