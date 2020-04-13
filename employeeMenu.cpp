
// Kimberly Wilkes
// CIT 237 - C++
// April 13, 2020
// Employee Management System

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int NUM_RECORDS = 20, NUM_COL = 10;
const int NAME_SIZE = 51, DATE_SIZE = 10, PHONE_SIZE = 14, ADDRESS_SIZE = 51;
/*
struct Employee_name {
    char firstName[NAME_SIZE];
    char lastName[NAME_SIZE];
};
struct Employee_address {
    char address1[ADDRESS_SIZE];
    char address2[ADDRESS_SIZE];
};
*/
struct Employee_record {
    //int idNumber = 0;
    char employeeName[NAME_SIZE];
    char birthDate[DATE_SIZE];
    char employeeAddress1[ADDRESS_SIZE];
    char employeeAddress2[ADDRESS_SIZE];
    char mobileNumber[PHONE_SIZE];
    char emailID[NAME_SIZE];
    char department[NAME_SIZE];
    char hireDate[DATE_SIZE];
    double employeeSalary = 0;
} employees[NUM_RECORDS][NUM_COL];

void menu(Employee_record &);
void showMenu();
void showRecords(Employee_record &);
void addRecord(Employee_record &);

int main() {
    Employee_record employee;
    cout << "Welcome to the Employee Management System.\n" << "You can use this to manage up to 20 records.\n" << "Here are the menu options:\n";
    showMenu();
    menu(employee);
    //system("pause");
    return 0;
}


void menu(Employee_record &employee) {
    int userChoice;
    cin >> userChoice;
    cin.ignore();
    switch (userChoice) {
    case 1:
        cout << "You selected: 1. List by Hire Date.\n";
        /*
        the program need to sorting (use bubble sort) the records in the text file by hire date and then display the entire data set.
        Be sure that the entire data is written in an organized and readable format.
        */
        break;
    case 2:
        cout << "You selected: 2. Add a new record.\n";
        /*
        If the user selects 2, the program adds new employee details in the text file.
        */
        addRecord(employee);
        break;
    case 3:
        cout << "You selected: 3. Delete a record.\n";
        /*
        If the user selects 3, the program deletes a record by employee id.
        If a wrong employee id is provided, the program reports it.
        */
        break;
    case 4:
        cout << "You selected: 4. Search employee mobile number.\n";
        /*
        If the user selects 4, the program searches (use linear search) an employee mobile number by employee’s birth date
            and display mobile number with employee id and name.
        If a wrong employee’s birth date is provided, the program reports it.
        */
        break;
    case 5:
        cout << "You selected: 5. Find employees hired for longer than 5 years.\n";
        /*
        If the user selects 5, the program finds how many employees have been with the company for more than 5 years and display their names.
        */
        break;
    case 6:
        cout << "You selected: 6. Update telephone number\n";
        /*
        If the user selects 6, the program updates telephone number of the employee by employee name in the text file.
        After performing the file update, the program should report the updated telephone number.
        If a wrong name is provided, the program reports this and doesn’t make any changes.
        */
        break;
    case 7:
        cout << "You selected: 7. Update salary.\n";
        /*
        If the user selects 7, the program updates salary of the  employee in the text file based on the given condition
                (if the employee has less than 5 years experience, increment salary by 2000,
                if the employee has less than or equal to 10 years experience, increment salary by 5000,
                if the employee has greater than 10 years experience, increment salary by 8000).
            After performing the file update, the program should report the updated salary.
        */
        break;
    case 8:
        cout << "You selected: 8. Write total payroll of company.\n";
        /*
        If the user selects 8, the program calculates the sum of the salaries paid by the company per month and per year and display them.
        */
        break;
    case 9:
        cout << "You selected: 9. Display all records.\n";
        /*
        If the user selects 9, the program displays all the records in the text file.
        */
        showRecords(employee);
        break;
    case 10:
        cout << "You selected: 10. Exit.\nGoodbye!";
        break;
    default:
        cout << "You entered an invalid choice. Pick from the menu.\n\n";
        showMenu();
        menu(employee);
        break;
    }
}

void showMenu() {
    cout << "1. List by hire date\n" << "2. Add new record\n" << "3. Delete a record\n" << "4. Search employee mobile number\n"
        << "5. Find employees hired for longer than 5 years\n" << "6. Update telephone number\n" << "7. Update salary\n"
        << "8. Total payroll of company\n" << "9. Display all records\n" << "10. Exit\n";
    cout << "Enter a menu option: ";
};

void showRecords(Employee_record &employee) {
    char next;
    fstream employeeFile("employee.txt", ios::in | ios::binary);
    if (employeeFile.is_open()) {
        employeeFile.read(reinterpret_cast<char*>(&employee), sizeof(employee));
        while (!employeeFile.eof()) {
            cout << "Name: ";
            cout << employee.employeeName << endl;
            cout << "Employee Birth Date: ";
            cout << employee.birthDate << endl;
            cout << "Employee Address Line 1: ";
            cout << employee.employeeAddress1 << endl;
            cout << "Employee Address Line 2: ";
            cout << employee.employeeAddress2 << endl;
            cout << "Employee Mobile Number: ";
            cout << employee.mobileNumber << endl;
            cout << "Employee Email ID: ";
            cout << employee.emailID << endl;
            cout << "Employee Department: ";
            cout << employee.department << endl;
            cout << "Employee Hire Date: ";
            cout << employee.hireDate << endl;
            cout << "Employee Salary: ";
            cout << employee.employeeSalary << endl;
            cout << "\n Press ENTER to see the next record.\n";
            cin.get(next);
            employeeFile.read(reinterpret_cast<char*>(&employee), sizeof(employee));
        }
        cout << "End of records.\n";
        employeeFile.close();
    }
    else cout << "Unable to open file.\n";
}

void addRecord(Employee_record &employee) {
    char again; //to enter employee info again
    cout << "Enter employee details:\n";
    fstream employeeFile("employee.txt", ios::out | ios::binary);
    if (employeeFile.is_open())
    {   
        do {
            cout << "Employee Name: ";
            cin.getline(employee.employeeName, NAME_SIZE);
            cout << "Employee Birth Date: ";
            cin.getline(employee.birthDate, DATE_SIZE);
            cout << "Employee Address Line 1: ";
            cin.getline(employee.employeeAddress1, ADDRESS_SIZE);
            cout << "Employee Address Line 2: ";
            cin.getline(employee.employeeAddress2, ADDRESS_SIZE);
            cout << "Employee Mobile Number: ";
            cin.getline(employee.mobileNumber, PHONE_SIZE);
            cout << "Employee Email ID: ";
            cin.getline(employee.emailID, NAME_SIZE);
            cout << "Employee Department: ";
            cin >> employee.department;
            cin.ignore();
            cout << "Employee Hire Date: ";
            cin.getline(employee.hireDate, DATE_SIZE);
            cout << "Employee Salary: ";
            cin >> employee.employeeSalary;
            employeeFile.write(reinterpret_cast<char *>(&employee), sizeof(employee));
            cout << "\nDo you want to enter another Employee record? Yes (Y) or No (N)? ";
            cin >> again;
            cin.ignore();
        } while (again == 'Y' || again == 'y');
        employeeFile << endl;
        employeeFile.close();
    }
    else cout << "Unable to open file";
}
