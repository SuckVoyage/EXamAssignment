// EmployeeManagementSystem.cpp 
#include <iostream>

#include "ManagmentSystem.h"



int main() {
    Boss* head = new Boss("Peter", "Petrov", 1'300'000, "Company");
    head->addEmployee(new Programmer("Vasya", "Ivanov", 110'000));
    head->addEmployee(new Designer("Maxim", "Kuznetsov",130'000));
    Boss* programming = new Boss("Ivan", "Orlov", 200'000, "Programming");
    programming->addEmployee(new Programmer("Peter", "Michailov", 100'000));
    head->addEmployee(programming);
    ManagmentSystem company(head);
    company.start();
    return 0;
}
