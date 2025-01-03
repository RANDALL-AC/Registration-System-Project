#include "Consultation.h"

void Consultation::showRegisteredStudent(Student student, int courseCount, int totalCost) {
    if (courseCount > 0) {
        std::cout << "\n-------------------------------------------------------------------------------------------------------------\n";
        printf("\nDatos del estudiante matriculado:\n");
        std::cout << "Nombre: " << student.getName()
            << ", Cedula: " << student.getId()
            << ", Carrera: " << student.getCareer()
            << ", Nivel: " << student.getLevel()
            << ", Costo de la matricula: " << totalCost << " colones.\n";
        std::cout << "\n-------------------------------------------------------------------------------------------------------------\n";
    }
    else {
        std::cout << "El estudiante no tiene cursos matriculados.\n";
    }
}

void Consultation::showCourseSchedule(Course& course) {
    std::cout << "Horarios del curso de " << course.getCourseName() << ": ";
    for (int i = 0; i < course.getNumSchedule(); ++i) {
        Schedule schedule = course.getSchedule(i);
        std::cout << "( Dia: " << schedule.getDay()
            << ", Aula: " << schedule.getClassroom()
            << ", Inicio: " << schedule.getStartTime()
            << ", Fin: " << schedule.getEndTime() << " )\n\n";
    }
}

void Consultation::showAssignedCourses(std::vector<Course>& courses) {
    for (int i = 0; i < courses.size(); ++i) {
        std::cout << i + 1 << ". Nombre: " << courses[i].getCourseName()
            << ", (ID: " << courses[i].getCourseId()          
            << "), Creditos: " << courses[i].getCredits()
            << ", Profesor Asignado: " << courses[i].getAssignedProfessor() << "\n";

        showCourseSchedule(courses[i]);
    }
}

void Consultation::showStudentCourses(Student& student, std::vector<Registration>& registrations) {
    std::cout << "\n-------------------------------------------------------------------------------------------------------------\n";
    std::cout << "Cursos asignados al estudiante: (" << student.getId() << ") " << student.getName() << "\n\n";

    int courseCount = 0;
    for (int j = 0; j < registrations.size(); ++j) {
        if (registrations[j].getStudent().getId() == student.getId()) {
            std::cout << courseCount + 1 << ". Curso: " << registrations[j].getCourse().getCourseName()
                << " (ID: " << registrations[j].getCourse().getCourseId()
                << ") Creditos: " << registrations[j].getCourse().getCredits()
                << ", Profesor: " << registrations[j].getCourse().getAssignedProfessor() << "\n";

            showCourseSchedule(registrations[j].getCourse());
            courseCount++;
        }
    }

    if (courseCount == 0) {
        std::cout << "\nEl estudiante no tiene cursos matriculados.\n";
    }
    else {
        std::cout << "Total de cursos matriculados: " << courseCount << "\n";
    }
    std::cout << "\n-------------------------------------------------------------------------------------------------------------\n";
}