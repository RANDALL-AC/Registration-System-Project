#include "Registration.h"

Registration::Registration() {}

Registration::Registration(Student student, Course course, Schedule schedule) {
    this->student = student;
    this->course = course;
    this->schedule = schedule;
}

Registration::~Registration() {};

Student Registration::getStudent() {
    return this->student;
}

Course& Registration::getCourse() {
    return this->course;
}

Schedule Registration::getSchedule() {
    return this->schedule;
}

void Registration::setStudent(Student student) {
    this->student = student;
}

void Registration::setCourse(Course course) {
    this->course = course;
}

void Registration::setSchedule(Schedule schedule) {
    this->schedule = schedule;
}