#include "Schedule.h"

Schedule::Schedule() {
    this->day = "";
    this->startTime = "";
    this->endTime = "";
    this->classroom = "";
}

Schedule::Schedule(std::string day, std::string startTime, std::string endTime, std::string classroom, std::string courseName) {
    this->day = day;
    this->startTime = startTime;
    this->endTime = endTime;
    this->classroom = classroom;
}

Schedule::~Schedule() {}

std::string Schedule::getDay() {
    return this->day;
}

std::string Schedule::getStartTime() {
    return this->startTime;
}

std::string Schedule::getEndTime() {
    return this->endTime;
}

std::string Schedule::getClassroom() {
    return this->classroom;
}

void Schedule::setDay(std::string day) {
    this->day = day;
}

void Schedule::setStartTime(std::string startTime) {
    this->startTime = startTime;
}

void Schedule::setEndTime(std::string endTime) {
    this->endTime = endTime;
}

void Schedule::setClassroom(std::string classroom) {
    this->classroom = classroom;
}