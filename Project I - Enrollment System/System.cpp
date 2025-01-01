#include "System.h"

System::System() {
    numStudents = 0;
    numCourses = 0;
    numSchedules = 0;
    numRegistrations = 0;
}

void System::about() {
    std::cout << "\nEste sistema de matricula fue desarrollado por [ Inge. RANDALL ARAUZ CUBILLA ].\n";
    std::cout << "Para mas informacion o consultas al numero: 27325614 o 88125674.\n";
}