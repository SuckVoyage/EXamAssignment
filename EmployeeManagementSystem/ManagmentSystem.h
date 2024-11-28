
#pragma once

#include "Employee.h"
#include "Boss.h"
#include "Programmer.h"
#include "Designer.h"



class ManagmentSystem
{
    Boss* director;

    // основное меню
    void mainMenu() const;

    // вспомогательное меню для добавления работника
    void addMenu(string& name, string& surname, long long* salary, string& depName) const;
    
public:
    // конструкторы
    ManagmentSystem(Boss* director) : director(director) {}
    ManagmentSystem(const string& name, const string& surname, long long salary)
        : director(new Boss(name, surname, salary, "Company")) {}
    
    // функция добавления сотрудника
    void addEmployee();

    // функция удаления сотрудника (работает рекурсивно)
    void deleteEmployee();
    

    // распечатать информацию по всем сотрудникам
    void print() const
    {
        director->print(0);
    }

    // распечатать сотрудников конкретного отдела
    void printDepartment() const;
   
    // посчитать сумму зарплат конкретного отдела
    long long departmentSalaryCount() const;

    // подсчитывает сумму зарплат
    long long salaryCount() const
    {
        return director->salaryCount();
    }


    // запись в файл
    void saveInFail(const string& path)
    {
        ofstream fout;
        fout.open(path, ios::out);
        if (fout.is_open())
        {
            director->saveInFail(fout);
            cout << "Success!";
            fout.close();
        }
        else
            cout << "Fail is not open";
    }

    // вся работа  с классом
    void start();

    // деструктор
    ~ManagmentSystem()
    {
        if (director)
            delete director;
    }
};

