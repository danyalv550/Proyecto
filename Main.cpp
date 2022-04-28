#include <iostream>
#include "Node.h"

using namespace std;

int main() {
    Node<int>a(3);
    a.print();
    a.addValue(5);
    a.addValue(8);
    a.print();
    a.deleteValue(5);
    a.print();
    a.insert(1,6);
    a.print();
}