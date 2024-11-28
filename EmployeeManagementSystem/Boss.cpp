#include "Boss.h"

// найти начальника конкретного отдела
Employee* Boss::findDepartmentBoss(const string& depName) 
{
    if (depName == departmentName)
        return this;
    else
    {
        for (Employee* person : staff)
        {
            Employee* temp = person->findDepartmentBoss(depName);
            if (temp)
            {
                return temp;
            }
        }
        return nullptr;
    }
}

// добавление нового сотрудника
void Boss::addEmployee(Employee* employee) 
{
    bool flag = false;
    for (Employee* person : staff)
    {
        if (employee->getFullName() == person->getFullName())
            flag = true;
    }
    if (flag)
    {
        int choice = 0;
        cout << "Such an employee has already been added.\nWould you like to add it anyway? 1 - yes | 0 - no\n- ";
        cin >> choice;
        if (choice == 0)
        {
            delete employee;
            return;
        }
    }
    staff.push_back(employee);
}

// удаление сотрудника и всех его подчиненных
bool Boss::deleteEmployee(const string& name, const string& surname)
{
    int i = 0;
    for (Employee* person : staff)
    {
        Employee* temp = person->findEmployee(name, surname);
        if (temp)
        {
            if (person->getFullName() == name + surname) {
                auto it = staff.begin() + i;
                delete temp;
                staff.erase(it);
                return true;
            }
            else {
                if (person->deleteEmployee(name, surname))
                    return true;
            }
        }
        else
            if (person->deleteEmployee(name, surname))
                return true;
        i++;
    }
    return false;
}

// поиск по имени и фамилии
Employee* Boss::findEmployee(const string& name, const string& surname)
{
    if (name + surname == getFullName())
        return this;
    else
    {
        for (Employee* person : staff)
        {
            Employee* temp = person->findEmployee(name, surname);
            if (temp)
            {
                return temp;
            }
        }
        return nullptr;
    }
}

// считает сумму зарплат - своей и всех подчиненных
long long Boss::salaryCount() const
{
    long long temp = 0;
    for (Employee* person : staff)
    {
        temp += person->salaryCount();
    }
    return salary + temp;
}

// вывод на экран
void Boss::print(int depth) const
{
    for (int i = 0; i < depth; i++)
        cout << "   ";
    cout << "Position - " << getPosition() << endl;
    for (int i = 0; i < depth; i++)
        cout << "   ";
    cout << surname << " " << name << " - " << salary << endl << endl;
    for (Employee* person : staff)
    {
        person->print(depth + 1);
    }
}

// запись в файл
ostream& Boss::saveInFail(ostream& fout) const
{
    fout << getStringToFail() << endl;
    for (Employee* person : staff)
    {
        person->saveInFail(fout);
    }
    return fout;
}



