#pragma once

#include "Employee.h"

class Designer : public Employee
{
public:
    Designer(const string& name, const string& surname, long long salary) : Employee(name, surname, salary) {}
    
    string getPosition() const override { return "designer"; }
};
