#pragma once
#include <iostream>

using namespace std;

class ToDoList {
    private:
        string task;
        ToDoList* next;
    
    public:
        ToDoList(string inTask) {
            task = inTask;
            next = nullptr;
        }

        void addTask(string taskToAdd) {
            if(next==nullptr) {
                next = new ToDoList(taskToAdd);
            }
            else {
                next->addTask(taskToAdd);
            }
        }

        void deleteTask(string taskToDelete) {
            if(next->task==taskToDelete) {
                if(next->next!=nullptr) {
                    ToDoList* aux = next->next;
                    delete next;
                    next = aux;
                }
                else {
                    delete next;
                    next = nullptr;
                }
            }
        }

        void showList(int number=1) {
            cout << number << ": " << task << endl;
            if(next!=nullptr) {
                next->showList(number+1);
            }
        }
};