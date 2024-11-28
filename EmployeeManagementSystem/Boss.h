#pragma once

#include "Employee.h"
#include "Programmer.h"
#include <vector>

class Boss : public Employee
{
    // название отдела котороым руководит
    string departmentName;

    // вектор указателей на подчиненных сотрудников
    vector<Employee*> staff;

public:
    // конструктор
    Boss(const string& name, const string& surname, long long salary, const string& depName)
        : Employee(name, surname, salary), departmentName(depName) {}

    // возвращает должность
    string getPosition() const override
    {
        return "Head of " + departmentName + " department";
    }

    // геттер, возвращает название отдела
    string getDepartment() const override 
    {
        return departmentName;
    }
    
    // найти начальника конкретного отдела
    Employee* findDepartmentBoss(const string& depName) override;

    // добавление нового сотрудника
    void addEmployee(Employee* employee) override;
   

    // удаление сотрудника и всех его подчиненных
    bool deleteEmployee(const string& name, const string& surname) override;
    
    // поиск по имени и фамилии
    Employee* findEmployee(const string& name, const string& surname) override;

    // считает сумму зарплат - своей и всех подчиненных
    long long salaryCount() const override;

    // вывод на экран
    void print(int depth) const override;

    // подготовка к записи в файл
    string getStringToFail() const override 
    {
        char last = getPosition()[0];
        return surname + " " + name + " " + to_string(salary) + " " + departmentName + last;
    }

    // запись в файл
    virtual ostream& saveInFail(ostream& fout) const;

    // деструктор
    ~Boss()
    {
        for (Employee* person : staff)
        {
            delete person;
        }
    }
};


