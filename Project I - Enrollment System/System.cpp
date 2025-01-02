#include "System.h"

System::System() {
    numStudents = 0;
    numCourses = 0;
    numSchedules = 0;
    numRegistrations = 0;
}

void System::showFileMenu() {
    int option;
    do {
        std::cout << "\n--- Menu de Archivo ---\n";
        std::cout << "1. Acerca de..\n";
        std::cout << "2. Volver\n";
        std::cout << "3. Salir del Sistema\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> option;

        switch (option) {
        case 1:
            about();
            break;
        case 2:
            return;
        case 3:
            exitSystem();
            break;
        default:
            std::cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (true); 
}

void System::about() {
    std::cout << "\nEste sistema de matricula fue desarrollado por [ Inge. RANDALL ARAUZ CUBILLA ] el 01/01/2025.\n";
    std::cout << "Para mas informacion o consultas al numero: 27325614 o 88125674.\n";
}

void System::exitSystem() {
    std::cout << "Saliendo del sistema...\n";
    exit(0);
}

void System::showMaintenanceMenu() {
    int option;
    do {
        std::cout << "\n--- Menu de Mantenimiento ---\n";
        std::cout << "1. Estudiantes\n";
        std::cout << "2. Cursos\n";
        std::cout << "3. Horarios\n";
        std::cout << "4. Volver\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> option;

        switch (option) {
        case 1:
            addStudent();
            break;
        case 2:
            addCourse();
            break;
        case 3:
            addSchedule();
            break;
        case 4:
            return;
        default:
            std::cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (true);
}

void System::addStudent() {
    if (numStudents >= maxStudents) {
        std::cout << "Numero maximo de estudiantes alcanzado.\n";
        return;
    }
    std::string name, id, career; int level;

    std::cout << "Ingrese el nombre del estudiante: "; std::cin >> name;
    std::cout << "Ingrese la cedula del estudiante: "; std::cin >> id;
    std::cout << "Ingrese la carrera del estudiante: "; std::cin >> career;
    std::cout << "Ingrese el nivel del estudiante: "; std::cin >> level;

    students[numStudents++] = Student(name, id, career, level);
    std::cout << "Estudiante agregado al sistema.\n";
}

void System::addCourse() {
    if (numCourses >= maxCourses) {
        std::cout << "Numero maximo de cursos alcanzado.\n";
        return;
    }
    std::string courseName, courseId, assignedProfessor, int credits;
    
    std::cout << "Ingrese el nombre del curso: "; std::cin >> courseName;
    std::cout << "Ingrese el ID del curso: "; std::cin >> courseId; 
    std::cout << "Ingrese los creditos del curso: "; std::cin >> credits;
    std::cout << "Ingrese el profesor asignado: "; std::cin >> assignedProfessor;

    courses[numCourses++] = Course(courseName, courseId, credits, assignedProfessor);
    std::cout << "Curso agregado al sistema.\n";
}

void System::addSchedule() {
    if (numSchedules >= maxSchedules) {
        std::cout << "Numero maximo de horarios alcanzado.\n";
        return;
    }

    std::string day, startTime, endTime, classroom, courseId;

    std::cout << "\nCursos disponibles para asignar Horario:\n";
    for (int i = 0; i < numCourses; ++i) {
        std::cout << i + 1 << ". " << courses[i].getCourseName() << " (ID: " << courses[i].getCourseId() << ")\n";
    }
    std::cout << "Seleccione el numero del curso: ";
    int courseSelection;
    std::cin >> courseSelection;

    if (courseSelection < 1 || courseSelection > numCourses) {
        std::cout << "Seleccion de curso invalida.\n";
        return;
    }
    courseId = courses[courseSelection - 1].getCourseId();

    if (courses[courseSelection - 1].getNumSchedule() >= maxSchedulePerCourse) {
        std::cout << "Este curso ya ha alcanzado el n�mero maximo de horarios permitidos.\n";
        return;
    }

    std::cout << "Ingrese el dia del horario: ";    std::cin >> day;
    std::cout << "Ingrese la hora de inicio (HHMM): ";    std::cin >> startTime;
    std::cout << "Ingrese la hora de fin (HHMM): ";   std::cin >> endTime;
    std::cout << "Ingrese el aula: ";   std::cin >> classroom;

    Schedule newSchedule(day, startTime, endTime, classroom, courseId);
    schedules[numSchedules++] = newSchedule;

    for (int i = 0; i < numCourses; ++i) {
        if (courses[i].getCourseId() == courseId) {
            courses[i].addSchedule(newSchedule);
            break;
        }
    }

    std::cout << "Horario agregado exitosamente al curso.\n";
}

void System::registerStudent() {
    if (numRegistrations > maxStudents * maxCoursesPerStudents) {
        std::cout << "Numero maximo de matriculas alcanzado.\n";
        return;
    }

    int studentIndex = -1;
    std::string studentId;

    std::cout << "Ingrese el ID del estudiante: ";
    std::cin >> studentId;

    for (int i = 0; i < numStudents; ++i) {
        if (students[i].getId() == studentId) {
            studentIndex = i;
            break;
        }
    }

    if (studentIndex == -1) {
        std::cout << "Estudiante no encontrado.\n";
        return;
    }

    int studentCourseCount = 0;
    for (int i = 0; i < numRegistrations; ++i) {
        if (registrations[i].getStudent().getId() == students[studentIndex].getId()) {
            studentCourseCount++;
        }
    }

    while (studentCourseCount < maxCoursesPerStudents) {

        std::cout << "\nCursos Disponibles:\n";
        consultation.showAssignedCourses(courses, numCourses);
        if (numCourses == 0) {
            std::cout << "No hay cursos disponibles\n";
        }
        std::cout << "-------------------------------------------------------------------------------------------------------------\n";

        for (int i = 0; i < numCourses; ++i) {
            if (courses[i].getNumSchedule() == 0) {
                std::cout << i + 1 << ". " << courses[i].getCourseName()
                    << " (ID: " << courses[i].getCourseId() << ") - No hay horarios disponibles\n";
            }
        }
    }
}