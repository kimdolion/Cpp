
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
const int NAME_SIZE = 51, DATE_SIZE = 10, NUM_SIZE = 14, ADDRESS_SIZE = 51;
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
    char idNumber[NUM_SIZE] = {0};
    char employeeName[NAME_SIZE] = "";
    char birthDate[DATE_SIZE] = "";
    char employeeAddress1[ADDRESS_SIZE] = "";
    char employeeAddress2[ADDRESS_SIZE] = "";
    char mobileNumber[NUM_SIZE] = "";
    char emailID[NAME_SIZE] = "";
    char department[NAME_SIZE] = "";
    char hireDate[DATE_SIZE] = "";
    char employeeSalary[NUM_SIZE] = { 0 };
} employees[NUM_RECORDS][NUM_COL];

void menu(Employee_record &);
void showMenu();
void showRecords(Employee_record);
void addRecord(Employee_record &);
//void deleteRecord(Employee_record&);
void editMobile(Employee_record&);
void editSalary(Employee_record&);

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
    while (cin.bad() || userChoice < 1 || userChoice > 10)
    {
        cout << "\t- Invalid Option. Enter your choice again: ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> userChoice;
    }
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
        showMenu();
        menu(employee);
        break;
    case 3:
        cout << "You selected: 3. Delete a record.\n";
        /*
        If the user selects 3, the program deletes a record by employee id.
        If a wrong employee id is provided, the program reports it.
        */
        //deleteRecord(employee);
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
        editMobile(employee);
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
        editSalary(employee);
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
        showMenu();
        menu(employee);
        break;
    case 10:
        cout << "You selected: 10. Exit.\nGoodbye!\n";
        break;
    }
}

void showMenu() {
    cout << "1. List by hire date\n" << "2. Add new record\n" << "3. Delete a record\n" << "4. Search employee mobile number\n"
        << "5. Find employees hired for longer than 5 years\n" << "6. Update telephone number\n" << "7. Update salary\n"
        << "8. Total payroll of company\n" << "9. Display all records\n" << "10. Exit\n";
    cout << "Enter a menu option: ";
};

void showRecords(Employee_record employee) {
    char next;
    fstream employeeFile("employee.txt", ios::in | ios::binary);
    if (employeeFile.is_open()) {
        employeeFile.read(reinterpret_cast<char*>(&employee), sizeof(employee));
        while (!employeeFile.eof()) {
            cout << "Employee ID: " << employee.idNumber << endl;
            cout << "Employee Name: " << employee.employeeName << endl;
            cout << "Employee Birth Date: " << employee.birthDate << endl;
            cout << "Employee Address Line 1: " << employee.employeeAddress1 << endl;
            cout << "Employee Address Line 2: " << employee.employeeAddress2 << endl;
            cout << "Employee Mobile Number: " << employee.mobileNumber << endl;
            cout << "Employee Email ID: " << employee.emailID << endl;
            cout << "Employee Department: " << employee.department << endl;
            cout << "Employee Hire Date: " << employee.hireDate << endl;
            cout << "Employee Salary: " << employee.employeeSalary << endl << endl;
            employeeFile.read(reinterpret_cast<char *>(&employee), sizeof(employee));
        }
        cout << "\nEnd of records.\n";
        employeeFile.close();
    }
    else cout << "Unable to open file.\n";
}

void addRecord(Employee_record &employee) {
    cout << "\nEnter employee details:\n";
    fstream employeeFile("employee.txt", ios::out | ios::app | ios::binary);
    if (employeeFile.is_open())
    {   
        cout << "\tEmployee ID: ";
        cin.getline(employee.idNumber, NUM_SIZE);
        cout << "\tEmployee Name: ";
        cin.getline(employee.employeeName, NAME_SIZE);
        cout << "\tEmployee Birth Date: ";
        cin.getline(employee.birthDate, DATE_SIZE);
        cout << "\tEmployee Address Line 1: ";
        cin.getline(employee.employeeAddress1, ADDRESS_SIZE);
        cout << "\tEmployee Address Line 2: ";
        cin.getline(employee.employeeAddress2, ADDRESS_SIZE);
        cout << "\tEmployee Mobile Number: ";
        cin.getline(employee.mobileNumber, NUM_SIZE);
        cout << "\tEmployee Email ID: ";
        cin.getline(employee.emailID, NAME_SIZE);
        cout << "\tEmployee Department: ";
        cin.getline(employee.department, NAME_SIZE);
        cout << "\tEmployee Hire Date: ";
        cin.getline(employee.hireDate, DATE_SIZE);
        cout << "\tEmployee Salary: ";
        cin.getline(employee.employeeSalary, NUM_SIZE);
        employeeFile.write(reinterpret_cast<char *>(&employee), sizeof(employee));
        employeeFile << endl;
        employeeFile.close();
    }
    else cout << "Unable to open file";
}
/*
void deleteRecord(Employee_record& employee) {
    char deleteNum[NUM_SIZE];
    fstream employeeFile("employee.txt", ios::in | ios::out | ios::app | ios::binary);
    cout << "What is the record number you wish to delete? ";
    cin >> deleteNum;
    employeeFile.seekg(deleteNum * sizeof(employee), ios::beg);
    employeeFile.read(reinterpret_cast<char*>(&employee), sizeof(employee));
    cout << "Employee record was deleted.\n ";
}
*/

void editMobile(Employee_record &employee) {
    int editNum;
    fstream employeeFile("employee.txt", ios::in | ios::out | ios::binary);
    cout << "What is the record number you wish to edit? ";
    cin >> editNum;
    cin.ignore();
    employeeFile.seekg(editNum * sizeof(employee), ios::beg);
    employeeFile.read(reinterpret_cast<char*>(&employee), sizeof(employee));
    // display the record for verification?
    cout << "\nEmployee ID: " << employee.idNumber << endl;
    cout << "Employee Mobile Number: " << employee.mobileNumber << endl;
    
    cout << "\tEmployee Mobile Number: ";
    cin.getline(employee.mobileNumber, NUM_SIZE);
    employeeFile.write(reinterpret_cast<char*>(&employee), sizeof(employee));
    cout << "Employee mobile number is: " << employee.mobileNumber;
    employeeFile.seekp(editNum * sizeof(employee), ios::beg);
    employeeFile.write(reinterpret_cast<char*>(&employee), sizeof(employee));
    employeeFile.close();
}

void editSalary(Employee_record& employee) {
    cout << "Employee salary is: " << employee.employeeSalary;
}
