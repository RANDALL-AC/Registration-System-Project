#pragma once
#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <iostream>

class Schedule
{
public:

    Schedule();
    Schedule(std::string day, std::string startTime, std::string endTime, std::string classroom, std::string courseName);
    ~Schedule();

    std::string getDay();
    std::string getStartTime();
    std::string getEndTime();
    std::string getClassroom();

    void setDay(std::string day);
    void setStartTime(std::string startTime);
    void setEndTime(std::string endTime);
    void setClassroom(std::string classroom);

private:
    std::string day;
    std::string startTime;
    std::string endTime;
    std::string classroom;
};
#endif