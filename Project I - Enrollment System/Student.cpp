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