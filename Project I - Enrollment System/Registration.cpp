#include "Registration.h"

Registration::Registration() {}

Registration::Registration(Student student, Course course, Schedule schedule) {
    this->student = student;
    this->course = course;
    this->schedule = schedule;
}

Registration::~Registration() {};