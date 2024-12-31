#include "Student.h"

Student::Student() {
    this->name = "";
    this->id = "";
    this->career = "";
    this->level = 0;
}

Student::Student(std::string name, std::string id, std::string career, int level) {
    this->name = name;
    this->id = id;
    this->career = career;
    this->level = level;
}

Student::~Student() {}

std::string Student::getName() {
    return this->name;
}

std::string Student::getId() {
    return this->id;
}

std::string Student::getCareer() {
    return this->career;
}

int Student::getLevel() const {
    return this->level;
}

void Student::setName(std::string name) {
    this->name = name;
}

void Student::setId(std::string id) {
    this->id = id;
}

void Student::setCareer(std::string career) {
    this->career = career;
}

void Student::setLevel(int level) {
    this->level = level;
}