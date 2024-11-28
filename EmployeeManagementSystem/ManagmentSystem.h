
#pragma once

#include "Employee.h"
#include "Boss.h"
#include "Programmer.h"
#include "Designer.h"



class ManagmentSystem
{
    Boss* director;

    // �������� ����
    void mainMenu() const;

    // ��������������� ���� ��� ���������� ���������
    void addMenu(string& name, string& surname, long long* salary, string& depName) const;
    
public:
    // ������������
    ManagmentSystem(Boss* director) : director(director) {}
    ManagmentSystem(const string& name, const string& surname, long long salary)
        : director(new Boss(name, surname, salary, "Company")) {}
    
    // ������� ���������� ����������
    void addEmployee();

    // ������� �������� ���������� (�������� ����������)
    void deleteEmployee();
    

    // ����������� ���������� �� ���� �����������
    void print() const
    {
        director->print(0);
    }

    // ����������� ����������� ����������� ������
    void printDepartment() const;
   
    // ��������� ����� ������� ����������� ������
    long long departmentSalaryCount() const;

    // ������������ ����� �������
    long long salaryCount() const
    {
        return director->salaryCount();
    }


    // ������ � ����
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

    // ��� ������  � �������
    void start();

    // ����������
    ~ManagmentSystem()
    {
        if (director)
            delete director;
    }
};

