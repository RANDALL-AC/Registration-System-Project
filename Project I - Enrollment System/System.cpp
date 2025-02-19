#include "System.h"
#include <string>

System::System()
    : students{
        Student("Evelyn Salazar A.", "601230123", "Veterinaria", 3),
        Student("Randall Arauz C.", "604940262", "Ing. Sistemas", 4),
        Student("Brayner Paez T.", "607890789", "Contabilidad", 1),
        Student("David Meza S.", "604560456", "Ing. Forestal,", 4),
        Student("Alexa Mitre B.", "601590159", "Biologia", 2)
    },
    courses{
        Course("Etica Profesional", "ETP126", 3, "Smith Ortega"),
        Course("Matematicas", "MAT 202", 3, "Eli Montes"),
        Course("Ingles", "LIX 410", 4, "Carlos Brown"),
        Course("Programacion", "EIF201", 4, "Juan Gamboa"),
        Course("Biologia", "NAT 325", 5, "Roger Dias")
    },
    schedules{
        Schedule("Lunes", "08:00", "12:00", "9", "Biologia"),
        Schedule("Lunes", "13:00", "16:00", "9", "Globalizacion y Cultura"),
        Schedule("Lunes", "08:00", "12:00", "4", "Ingles"),
        Schedule("Lunes", "08:00", "12:00", "4", "Matematicas"),
        Schedule("Martes", "13:00", "16:00", "9", "Programacion"),
    },
    numCourses(5),
    numStudents(5),
    numSchedules(5)
{
    students.reserve(maxStudents);
    schedules.reserve(maxSchedules);
    courses.reserve(maxCourses);
    registrations.reserve(maxStudents * maxCoursesPerStudents);

    for (int i = 0; i < courses.size(); ++i) {
        courses[i].addSchedule(schedules[i]);
    }
}

void System::showMenu() {
    int option;
    do {
        std::cout << "\n--- Menu Principal ---\n";
        std::cout << "1. Archivo\n";
        std::cout << "2. Mantenimiento\n";
        std::cout << "3. Matricula\n";
        std::cout << "4. Consulta\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> option;

        switch (option) {
        case 1:
            showFileMenu();
            break;
        case 2:
            showMaintenanceMenu();
            break;
        case 3:
            showRegistrationMenu();
            break;
        case 4:
            showConsultationMenu();
            break;
        default:
            std::cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (true);
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
    std::cin.ignore();
    std::cout << "Ingrese el nombre del estudiante: "; std::getline(std::cin, name);
    std::cout << "Ingrese la cedula del estudiante: "; std::getline(std::cin, id);
    std::cout << "Ingrese la carrera del estudiante: "; std::getline(std::cin, career); 
    std::cout << "Ingrese el nivel del estudiante: ";  std::cin >> level;

    if (numStudents >= students.size()) {
        students.resize(students.size() + 1);
    }
    students[numStudents] = Student(name, id, career, level);
    numStudents++;

    std::cout << "Estudiante agregado al sistema.\n";
}

void System::addCourse() {
    if (numCourses >= maxCourses) {
        std::cout << "Numero maximo de cursos alcanzado.\n";
        return;
    }
    std::string courseName, courseId, assignedProfessor;
    int credits;
    std::cin.ignore();
    std::cout << "Ingrese el nombre del curso: ";  std::getline(std::cin, courseName);
    std::cout << "Ingrese el ID del curso: "; std::getline(std::cin, courseId);
    std::cout << "Ingrese los creditos del curso: "; std::cin >> credits; std::cin.ignore();
    std::cout << "Ingrese el profesor asignado: ";  std::getline(std::cin, assignedProfessor); 

    if (numCourses >= courses.size()) {
        courses.resize(courses.size() + 1);
    }
    courses[numCourses] = Course(courseName, courseId, credits, assignedProfessor);
    numCourses++;

    std::cout << "Curso agregado al sistema.\n";
}

void System::addSchedule() {
    if (numSchedules >= maxSchedules) {
        std::cout << "Numero maximo de horarios alcanzado.\n";
        return;
    }

    std::string day, startTime, endTime, classroom, courseId;

    std::cout << "\nCursos disponibles para asignar Horario:\n";
    for (int i = 0; i < courses.size(); ++i) {
        std::cout << i + 1 << ". " << courses[i].getCourseName() << " (ID: " << courses[i].getCourseId() << ")\n";
    }
    std::cout << "Seleccione el numero del curso: ";
    int courseSelection;
    std::cin >> courseSelection;

    if (courseSelection < 1 || courseSelection > courses.size()) {
        std::cout << "Seleccion de curso invalida.\n";
        return;
    }
    courseId = courses[courseSelection - 1].getCourseId();

    if (courses[courseSelection - 1].getNumSchedule() >= maxSchedulePerCourse) {
        std::cout << "Este curso ya ha alcanzado el numero maximo de horarios permitidos.\n";
        return;
    }

    std::cout << "Ingrese el dia del horario: ";    std::cin >> day;
    std::cout << "Ingrese la hora de inicio (HHMM): ";  std::cin >> startTime; 
    std::cout << "Ingrese la hora de fin (HHMM): ";   std::cin >> endTime;
    std::cout << "Ingrese el aula: ";   std::cin >> classroom;

    Schedule newSchedule(day, startTime, endTime, classroom, courseId);
    if (numSchedules >= schedules.size()) {
        schedules.resize(schedules.size() + 1);
    }
    schedules[numSchedules] = newSchedule;
    numSchedules++;

    for (int i = 0; i < courses.size(); ++i) {
        if (courses[i].getCourseId() == courseId) {
            courses[i].addSchedule(newSchedule);
            break;
        }
    }

    std::cout << "Horario agregado exitosamente al curso.\n";
}

void System::showRegistrationMenu() {
    int option;
    do {
        std::cout << "\n--- Menu de Matricula ---\n";
        std::cout << "1. Registro de Matricula\n";
        std::cout << "2. Volver\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> option;

        switch (option) {
        case 1:
            registerStudent();
            break;
        case 2:
            return;
        default:
            std::cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (true);
}

void System::registerStudent() {
    if (numRegistrations > maxStudents * maxCoursesPerStudents) {
        std::cout << "Numero maximo de matriculas alcanzado.\n";
        return;
    }

    int studentIndex = -1;
    std::string studentId;
    std::cin.ignore();
    std::cout << "Ingrese el ID del estudiante: ";
    std::getline(std::cin, studentId);

    for (int i = 0; i < students.size(); ++i) {
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
    for (int i = 0; i < registrations.size(); ++i) {
        if (registrations[i].getStudent().getId() == students[studentIndex].getId()) {
            studentCourseCount++;
        }
    }

    while (studentCourseCount < maxCoursesPerStudents) {

        std::cout << "\nCursos Disponibles:\n";
        std::cout << "-------------------------------------------------------------------------------------------------------------\n";
        consultation.showAssignedCourses(courses);
        std::cout << "-------------------------------------------------------------------------------------------------------------\n";

        std::string courseId;
        std::cout << "\nIngrese el codigo del curso a matricular (o 0 para salir): ";
        std::getline(std::cin, courseId);

        if (courseId == "0") {
            std::cout << "Saliendo del proceso de matriculacion.\n";
            return;
        }

        int courseIndex = -1;
        for (int i = 0; i < courses.size(); ++i) {
            if (courses[i].getCourseId() == courseId) {
                courseIndex = i;
                break;
            }
        }

        if (courseIndex == -1 || courses[courseIndex].getNumSchedule() == 0) {
            std::cout << "Codigo de curso invalido o curso sin horarios asignados.\n";
            continue;
        }

        bool alreadyRegistered = false;
        for (int i = 0; i < registrations.size(); ++i) {
            if (registrations[i].getStudent().getId() == students[studentIndex].getId() &&
                registrations[i].getCourse().getCourseId() == courses[courseIndex].getCourseId()) {
                alreadyRegistered = true;
                break;
            }
        }

        if (alreadyRegistered) {
            std::cout << "El curso ya ha sido matriculado.\n";
            continue;
        }

        bool conflict = false;
        for (int i = 0; i < courses[courseIndex].getNumSchedule(); ++i) {
            Schedule schedule = courses[courseIndex].getSchedule(i);
            if (checkScheduleConflict(students[studentIndex], schedule)) {
                conflict = true;
                break;
            }
        }

        if (conflict) {
            std::cout << "Conflicto de horario detectado. No se puede agregar el horario.\n";
            continue;
        }

        const int costPerCredit = 2500;
        int registrationCost = courses[courseIndex].getCredits() * costPerCredit;
        students[studentIndex].addToTotalCost(registrationCost);

        if (numRegistrations >= registrations.size()) {
            registrations.resize(registrations.size() + 1);
        }
        registrations[numRegistrations] = Registration(students[studentIndex], courses[courseIndex], courses[courseIndex].getSchedule(0));
        numRegistrations++;

        std::cout << "\n-------------------------------------------------------------------------------------------------------------\n";
        std::cout << "Matricula registrada para el curso de " << courses[courseIndex].getCourseName()
            << " con el horario: ( Dia: " << courses[courseIndex].getSchedule(0).getDay()
            << ", Aula: " << courses[courseIndex].getSchedule(0).getClassroom()
            << ", Inicio: " << courses[courseIndex].getSchedule(0).getStartTime()
            << ", Fin: " << courses[courseIndex].getSchedule(0).getEndTime() << " ).\n";

        std::cout << "El costo para este curso es de: " << registrationCost << " colones.\n";
        std::cout << "El costo total acumulado de la matricula es de: " << students[studentIndex].getTotalCost()
            << " colones para el estudiante: (" << students[studentIndex].getId() << ") " << students[studentIndex].getName() << "\n";
        std::cout << "\n-------------------------------------------------------------------------------------------------------------\n";
        studentCourseCount++;
    }
    std::cout << "El estudiante ha alcanzado el numero maximo de cursos permitidos.\n";
}

bool System::checkScheduleConflict(Student student, Schedule newSchedule) {
    for (int i = 0; i < numRegistrations; ++i) {
        if (registrations[i].getStudent().getId() == student.getId()) {
            Schedule existingSchedule = registrations[i].getSchedule();

            if (existingSchedule.getDay() != newSchedule.getDay()) {
                continue;
            }

            if (existingSchedule.getClassroom() != newSchedule.getClassroom()) {
                continue;
            }

            if ((newSchedule.getStartTime() >= existingSchedule.getStartTime() && newSchedule.getStartTime() < existingSchedule.getEndTime()) ||
                (newSchedule.getEndTime() > existingSchedule.getStartTime() && newSchedule.getEndTime() <= existingSchedule.getEndTime()) ||
                (newSchedule.getStartTime() <= existingSchedule.getStartTime() && newSchedule.getEndTime() >= existingSchedule.getEndTime()) ||
                (newSchedule.getStartTime() == existingSchedule.getEndTime()) ||
                (newSchedule.getEndTime() == existingSchedule.getStartTime())) {
                return true;
            }
        }
    }
    return false;
}

void System::showConsultationMenu() {
    int option;
    do {
        std::cout << "\n--- Menu de Consulta ---\n";
        std::cout << "1. Estudiantes\n";
        std::cout << "2. Cursos\n";
        std::cout << "3. Volver\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> option;

        switch (option) {
        case 1:
            showRegisteredStudent();
            break;
        case 2:
            showAssignedCourses();
            break;
        case 3:
            return;
        default:
            std::cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (true);
}

void System::showRegisteredStudent() {
    std::string studentId;
    std::cout << "\nIngrese el ID del estudiante a buscar: ";
    std::cin >> studentId;

    bool found = false;
    for (int i = 0; i < students.size(); ++i) {
        if (students[i].getId() == studentId) {
            int courseCount = 0;
            for (int j = 0; j < registrations.size(); ++j) {
                if (registrations[j].getStudent().getId() == students[i].getId()) {
                    courseCount++;
                }
            }
            consultation.showRegisteredStudent(students[i], courseCount, students[i].getTotalCost());
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Estudiante no registrado o matriculado actualmente.\n";
    }
}

void System::showAssignedCourses() {
    std::cout << "\n-------------------------------------------------------------------------------------------------------------\n";
    std::cout << "Cursos ofertados:\n\n";
    consultation.showAssignedCourses(courses);
    std::cout << "\n-------------------------------------------------------------------------------------------------------------\n";

    std::string studentId;
    std::cout << "\nIngrese el ID del estudiante para ver los cursos matriculados: ";
    std::cin >> studentId;

    bool found = false;
    for (int i = 0; i < students.size(); ++i) {
        if (students[i].getId() == studentId) {
            consultation.showStudentCourses(students[i], registrations);
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "\nEstudiante no registrado en el sistema actualmente.\n";
    }
}