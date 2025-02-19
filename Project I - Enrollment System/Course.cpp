#include "Course.h"

Course::Course() {
    this->courseName = "";
    this->courseId = "";
    this->credits = 0;
    this->assignedProfessor = "";
}

Course::Course(std::string courseName, std::string courseId, int credits, std::string assignedProfessor) {
    this->courseName = courseName;
    this->courseId = courseId;
    this->credits = credits;
    this->assignedProfessor = assignedProfessor;
}

Course::~Course() {}

std::string Course::getCourseName() {
    return this->courseName;
}

std::string Course::getCourseId() {
    return this->courseId;
}

int Course::getCredits() const {
    return this->credits;
}

std::string Course::getAssignedProfessor() {
    return this->assignedProfessor;
}

void Course::setCourseName(std::string courseName) {
    this->courseName = courseName;
}

void Course::setCourseId(std::string courseId) {
    this->courseId = courseId;
}

void Course::setCredits(int credits) {
    this->credits = credits;
}

void Course::setAssignedProfessor(std::string assignedProfessor) {
    this->assignedProfessor = assignedProfessor;
}

void Course::addSchedule(Schedule schedule) {
    if (this->numSchedule < maxSchedulePerCourse) {
        this->schedules[this->numSchedule++] = schedule;
    }
    else {
        std::cout << "Numero maximo de horarios para este curso alcanzado.\n";
    }
}

Schedule Course::getSchedule(int index) const {
    if (index >= 0 && index < this->numSchedule) {
        return this->schedules[index];
    }
    else {
        std::cout << "Indice de horario invalido.\n";
        return Schedule();
    }
}

int Course::getNumSchedule() const {
    return this->numSchedule;
}