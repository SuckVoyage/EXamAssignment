#pragma once


#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

using namespace std;

// абстрактный класс от которого наследуются Boss, Programmer, Designer
class Employee
{
protected:
    // имя
    string name;
    // зарплата
    long long salary;
    // фамилия 
    string surname;
    
public:
    // конструктор
    Employee(const string& name, const string& surname, long long salary)
        : name(name), salary(salary), surname(surname) {}

    // геттер, возвращает либо название отдела либо пустую строку
    virtual string getDepartment() const { return string(); }

    // чистая виртуальная функция должна вернуть должность
    virtual string getPosition() const = 0;
    

    // вспомогательный геттер для поиска и удаления сотрудников
    string getFullName() const { return name + surname; }


    // поиск сотрудника по имени и фамилии
    virtual Employee* findEmployee(const string& name, const string& surname)
    {
        if (name + surname == getFullName())
            return this;
        return nullptr;
    }
    
    // найти начальника конкретного отдела
    virtual Employee* findDepartmentBoss(const string& depName)  
    {
        return nullptr;
    }


    // подготовка к записи в файл
    virtual string getStringToFail() const
    {
        char last = getPosition()[0];
        return surname + " " + name + " " + to_string(salary) + last;
    }

    // запись в файл
    virtual ostream& saveInFail(ostream& fout) const
    {
        return fout << getStringToFail() << endl;
    }
    
    
    // геттер, возвращает зарплату
    virtual long long salaryCount() const { return salary; }
    
    
    // функция удаления сотрудников, возвращает false т.к. только босс может уволить
    virtual bool deleteEmployee(const string& name, const string& surname) { return false; }


    // функция добавления сотрудника, выдаст исключение если добавить не боссу
    virtual void addEmployee(Employee* employee)
    {
        throw runtime_error("You can't add employees to someone other than the boss");
    }

    
    // вывод на экран информации о сотруднике
    virtual void print(int depth) const
    {
        for (int i = 0; i < depth; i++)
            cout << "   ";
        cout << "Position - " << getPosition() << endl;
        for (int i = 0; i < depth; i++)
            cout << "   ";
        cout << surname << " " << name << " - " << salary << endl << endl;
    }

    
    // деструктор
    virtual ~Employee() = 0 {}
};
