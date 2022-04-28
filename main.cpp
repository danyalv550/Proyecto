#include <iostream>
#include "ToDoList.h"

int main() {
    ToDoList a("Lavar");
    a.showList();
    a.addTask("Cocinar");
    a.addTask("Tarea");
    a.addTask("Barrer");
    a.showList();
    a.deleteTask("Cocinar");
    a.showList();
}
