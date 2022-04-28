#pragma once
#include <iostream>

template <typename T>
class Node {
    private:
        T value;
        Node* son;
    public:
        Node(const T& newValue) {
            value = newValue;
            son = nullptr;
        }

        void addValue(const T& newValue) {
            if(son==nullptr) {
                son = new Node<T>(newValue);
            }
            else {
                son->addValue(newValue);
            }
        }

        void deleteValue(const T& valueToDelete) {
            if(son->value==valueToDelete) {
                if(son->son!=nullptr) {
                    Node* aux = son->son;
                    delete son;
                    son = aux;
                }
                else {
                    delete son;
                    son = nullptr;
                }
            }
            else {
                son->deleteValue(valueToDelete);
            }
        }

        void insert(int count, const T& valueToInsert) {
            if(count==1) {
                Node* aux = son;
                son = new Node<T>(valueToInsert);
                son->son = aux;

            }
            else {
                son->insert(count - 1, valueToInsert);
            }
        }

        void print() {
            if(son!=nullptr) {
                std::cout << value << " ";
                son->print();
            }
            else {
                std::cout << value << std::endl;
            }
        }

};