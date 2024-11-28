#pragma once


#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

using namespace std;

// ����������� ����� �� �������� ����������� Boss, Programmer, Designer
class Employee
{
protected:
    // ���
    string name;
    // ��������
    long long salary;
    // ������� 
    string surname;
    
public:
    // �����������
    Employee(const string& name, const string& surname, long long salary)
        : name(name), salary(salary), surname(surname) {}

    // ������, ���������� ���� �������� ������ ���� ������ ������
    virtual string getDepartment() const { return string(); }

    // ������ ����������� ������� ������ ������� ���������
    virtual string getPosition() const = 0;
    

    // ��������������� ������ ��� ������ � �������� �����������
    string getFullName() const { return name + surname; }


    // ����� ���������� �� ����� � �������
    virtual Employee* findEmployee(const string& name, const string& surname)
    {
        if (name + surname == getFullName())
            return this;
        return nullptr;
    }
    
    // ����� ���������� ����������� ������
    virtual Employee* findDepartmentBoss(const string& depName)  
    {
        return nullptr;
    }


    // ���������� � ������ � ����
    virtual string getStringToFail() const
    {
        char last = getPosition()[0];
        return surname + " " + name + " " + to_string(salary) + last;
    }

    // ������ � ����
    virtual ostream& saveInFail(ostream& fout) const
    {
        return fout << getStringToFail() << endl;
    }
    
    
    // ������, ���������� ��������
    virtual long long salaryCount() const { return salary; }
    
    
    // ������� �������� �����������, ���������� false �.�. ������ ���� ����� �������
    virtual bool deleteEmployee(const string& name, const string& surname) { return false; }


    // ������� ���������� ����������, ������ ���������� ���� �������� �� �����
    virtual void addEmployee(Employee* employee)
    {
        throw runtime_error("You can't add employees to someone other than the boss");
    }

    
    // ����� �� ����� ���������� � ����������
    virtual void print(int depth) const
    {
        for (int i = 0; i < depth; i++)
            cout << "   ";
        cout << "Position - " << getPosition() << endl;
        for (int i = 0; i < depth; i++)
            cout << "   ";
        cout << surname << " " << name << " - " << salary << endl << endl;
    }

    
    // ����������
    virtual ~Employee() = 0 {}
};
