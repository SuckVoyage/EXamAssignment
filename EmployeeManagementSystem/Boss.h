#pragma once

#include "Employee.h"
#include "Programmer.h"
#include <vector>

class Boss : public Employee
{
    // �������� ������ �������� ���������
    string departmentName;

    // ������ ���������� �� ����������� �����������
    vector<Employee*> staff;

public:
    // �����������
    Boss(const string& name, const string& surname, long long salary, const string& depName)
        : Employee(name, surname, salary), departmentName(depName) {}

    // ���������� ���������
    string getPosition() const override
    {
        return "Head of " + departmentName + " department";
    }

    // ������, ���������� �������� ������
    string getDepartment() const override 
    {
        return departmentName;
    }
    
    // ����� ���������� ����������� ������
    Employee* findDepartmentBoss(const string& depName) override;

    // ���������� ������ ����������
    void addEmployee(Employee* employee) override;
   

    // �������� ���������� � ���� ��� �����������
    bool deleteEmployee(const string& name, const string& surname) override;
    
    // ����� �� ����� � �������
    Employee* findEmployee(const string& name, const string& surname) override;

    // ������� ����� ������� - ����� � ���� �����������
    long long salaryCount() const override;

    // ����� �� �����
    void print(int depth) const override;

    // ���������� � ������ � ����
    string getStringToFail() const override 
    {
        char last = getPosition()[0];
        return surname + " " + name + " " + to_string(salary) + " " + departmentName + last;
    }

    // ������ � ����
    virtual ostream& saveInFail(ostream& fout) const;

    // ����������
    ~Boss()
    {
        for (Employee* person : staff)
        {
            delete person;
        }
    }
};


