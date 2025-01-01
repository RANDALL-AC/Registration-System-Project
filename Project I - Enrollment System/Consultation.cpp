#include "Consultation.h"

void Consultation::showRegisteredStudent(Student student, int courseCount) {
    if (courseCount > 0) {
        std::cout << "\n-------------------------------------------------------------------------------------------------------------\n";
        printf("\nDatos del estudiante matriculado:\n");
        std::cout << "Nombre: " << student.getName()
            << ", Cedula: " << student.getId()
            << ", Carrera: " << student.getCareer()
            << ", Nivel: " << student.getLevel();
        std::cout << "\n-------------------------------------------------------------------------------------------------------------\n";
    }
    else {
        std::cout << "El estudiante no tiene cursos matriculados.\n";
    }
}

void Consultation::showCourseSchedule(Course course) {
    std::cout << "Horarios del curso de " << course.getCourseName() << ": ";
    for (int i = 0; i < course.getNumSchedule(); ++i) {
        Schedule schedule = course.getSchedule(i);
        std::cout << "( Dia: " << schedule.getDay()
            << ", Aula: " << schedule.getClassroom()
            << ", Inicio: " << schedule.getStartTime()
            << ", Fin: " << schedule.getEndTime() << " )\n\n";
    }
}