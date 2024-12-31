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