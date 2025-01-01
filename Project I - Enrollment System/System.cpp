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

void System::addStudent() {
  
    std::string name, id, career; int level;

    std::cout << "Ingrese el nombre del estudiante: "; std::cin >> name;
    std::cout << "Ingrese la cedula del estudiante: "; std::cin >> id;
    std::cout << "Ingrese la carrera del estudiante: "; std::cin >> career;
    std::cout << "Ingrese el nivel del estudiante: "; std::cin >> level;

    students[numStudents++] = Student(name, id, career, level);
    std::cout << "Estudiante agregado al sistema.\n";
}