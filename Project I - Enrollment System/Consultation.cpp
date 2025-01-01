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

void Consultation::showAssignedCourses(Course courses[], int numCourses) {
    for (int i = 0; i < numCourses; ++i) {
        std::cout << i + 1 << ". ID: " << courses[i].getCourseId()
            << ", Nombre: " << courses[i].getCourseName()
            << ", Creditos: " << courses[i].getCredits()
            << ", Profesor Asignado: " << courses[i].getAssignedProfessor() << "\n";

        showCourseSchedule(courses[i]);
    }
}

void Consultation::showStudentCourses(Student student, Registration registrations[], int numRegistrations) {
    std::cout << "\n-------------------------------------------------------------------------------------------------------------\n";
    std::cout << "Cursos asignados al estudiante: (" << student.getId() << ") " << student.getName() << "\n\n";

    for (int j = 0; j < numRegistrations; ++j) {
        if (registrations[j].getStudent().getId() == student.getId()) {
            std::cout << "Curso: " << registrations[j].getCourse().getCourseName()
                << " (ID: " << registrations[j].getCourse().getCourseId()
                << ") Creditos: " << registrations[j].getCourse().getCredits()
                << ", Profesor: " << registrations[j].getCourse().getAssignedProfessor() << "\n";

            showCourseSchedule(registrations[j].getCourse());
        }
    }
    std::cout << "\nEl estudiante no tiene cursos matriculados.\n";
    std::cout << "\n-------------------------------------------------------------------------------------------------------------\n";
}