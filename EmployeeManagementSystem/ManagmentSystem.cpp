#include "ManagmentSystem.h"


// основное меню
void ManagmentSystem::mainMenu() const
{
    cout << "\t\tMenu\n";
    cout << "1 - add new emploee\n";
    cout << "2 - delete employee\n";
    cout << "3 - print employees\n";
    cout << "4 - print department employees\n";
    cout << "5 - the amount of salaries\n";
    cout << "6 - the amount of salaries of the department\n";
    cout << "0 - exit\n- ";
}

// вспомогательное меню для добавления работника
void ManagmentSystem::addMenu(string& name, string& surname, long long* salary, string& depName) const
{
    int i;
    cout << "Is this the boss? 1 - yes | 2 - no\n- ";
    try
    {
        cin >> i;
        if (i < 1 || i > 2) { throw runtime_error("Wrong number"); }
        switch (i)
        {
        case 1:
            cout << "Enter department name - ";
            cin.ignore();
            getline(cin, depName);
            cin.clear();
            break;
        case 2:
            break;
        }
        cout << "Enter name - ";

        cin >> name;
        cout << "Enter surname - ";

        cin >> surname;
        cout << "Enter salary - ";
        while (!(cin >> *salary)) {
            cout << "Incorrect input. Please try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    catch (exception& ex)
    {
        cout << ex.what();
        addMenu(name, surname, salary, depName);
    }
}

// функция добавления сотрудника
void ManagmentSystem::addEmployee()
{
    print();
    string bossName;
    string bossSurname;
    cout << "Enter Boss name - ";
    cin >> bossName;
    cout << "Enter Boss surname - ";
    cin >> bossSurname;
    Employee* temp = director->findEmployee(bossName, bossSurname);
    if (temp) {
        if (temp->getDepartment().size() == 0)
        {
            throw runtime_error("It's not the boss");
        }
        string name, surname, depName;
        long long salary;
        addMenu(name, surname, &salary, depName);
        if (depName.size() > 0)
        {
            temp->addEmployee(new Boss(name, surname, salary, depName));
        }
        else {
            int choice = 0;
            while (choice < 1 || choice > 2) {
                cout << "Choise position 1 - programmer | 2 - designer\n- ";
                while (!(cin >> choice)) {
                    cout << "Incorrect input. Please try again.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            switch (choice) {
            case 1:
                temp->addEmployee(new Programmer(name, surname, salary));
                break;
            case 2:
                temp->addEmployee(new Designer(name, surname, salary));
                break;
            }
        }
    }
    else
    {
        cout << "Not found employee" << endl;
    }
}

// функция удаления сотрудника
void ManagmentSystem::deleteEmployee()
{
    print();
    cout << "Enter name- ";
    string name, surname;
    cin >> name;
    cout << "Enter surname- ";
    cin >> surname;
    if (director->deleteEmployee(name, surname))
    {
        cout << "Success!!!" << endl;
    }
    else
    {
        cout << "Cant find employee..." << endl;
    }
}

// распечатать сотрудников конкретного отдела
void ManagmentSystem::printDepartment() const
{
    string depName;
    cout << "Enter department name - ";
    cin >> depName;
    Employee* temp = director->findDepartmentBoss(depName);
    if (temp) {
        temp->print(0);
    }
    else
    {
        throw runtime_error("Not found department");
    }
}

// посчитать сумму зарплат конкретного отдела
long long ManagmentSystem::departmentSalaryCount() const
{
    string depName;
    cout << "Enter department name - ";
    cin >> depName;
    Employee* temp = director->findDepartmentBoss(depName);
    if (temp) {
        return temp->salaryCount();
    }
    else
    {
        throw runtime_error("Not found department");
    }
}

// вся работа  с классом
void ManagmentSystem::start()
{
    int choice = 1;
    while (choice != 0)
    {
        mainMenu();
        try
        {
            cin >> choice;
            if (choice < 0 || choice > 6)
            {
                throw runtime_error("Wrong choice!!!\n");
            }
            switch (choice)
            {
            case 1:
                addEmployee();
                break;
            case 2:
                deleteEmployee();
                break;
            case 3:
                print();
                break;
            case 4:
                printDepartment();
                break;
            case 5:
                cout << salaryCount() << endl;
                break;
            case 6:
                cout << departmentSalaryCount() << endl;
                break;
            case 0:
                saveInFail("employees.txt");
                return;
            }
        }
        catch (exception& ex)
        {
            cerr << ex.what() << endl;
        }
    }
}