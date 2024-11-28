#pragma once
#include "Employee.h"


class Programmer : public Employee
{
public:
    Programmer(const string& name, const string& surname, long long salary) : Employee(name, surname, salary) {}
    
    // ���������������
    string getPosition() const override { return "programmer"; }

    ~Programmer() {}
};

