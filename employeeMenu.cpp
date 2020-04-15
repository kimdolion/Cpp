// Kimberly Wilkes
// CIT 237 - C++
// April 13, 2020
// Employee Management System

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int RECORD_SIZE = 20;
//const int NAME_SIZE = 51, DATE_SIZE = 10, NUM_SIZE = 14, ADDRESS_SIZE = 51;

struct Employee_address {
    string addressLine1;
    string addressLine2;
};

struct Employee_record {
    int idNumber;
    string employeeName;
    int birthYear;
    Employee_address employeeAddress;
    int mobileNumber;
    int emailID;
    string department;
    int hireYear;
    double employeeSalary;
};

void showMenu();
void writeToRecord(Employee_record [], int);
void listByHireDate(Employee_record [], int);
void addRecord(Employee_record [], int);
//void deleteRecord(Employee_record [], int);
void searchMobile(Employee_record [], int);
void editMobile(Employee_record[], int);
void upgradeSalary(Employee_record[], int);
void showRecords(fstream &);

int main() {
    Employee_record employee_records[RECORD_SIZE];
    fstream employeeFile;
    const int quit = 10;
    int userChoice;
    cout << "Welcome to the Employee Management System.\n" << "You can use this to manage up to 20 records.\n" << "Here are the menu options:\n";
    do {
        cin.clear();
        showMenu();
        cin >> userChoice;
        while (cin.bad() || userChoice < 1 || userChoice > 10)
        {
            cout << "\tInvalid Option. Enter your choice again: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> userChoice;
        }
        switch (userChoice) {
        case 1:
            cout << "\nYou selected: 1. List by Hire Date.\n";
            /*
            the program need to sorting (use bubble sort) the records in the text file by hire date and then display the entire data set.
            Be sure that the entire data is written in an organized and readable format.
            */
            listByHireDate(employee_records, RECORD_SIZE);
            cout << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        case 2:
            cout << "\nYou selected: 2. Add a new record.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            If the user selects 2, the program adds new employee details in the text file.
            */
            addRecord(employee_records, RECORD_SIZE);
            cout << endl;
            break;
        case 3:
            cout << "\nYou selected: 3. Delete a record.\n";
            /*
            If the user selects 3, the program deletes a record by employee id.
            If a wrong employee id is provided, the program reports it.
            */
            //deleteRecord(employee_records, RECORD_SIZE);
            cout << endl;
            break;
        case 4:
            cout << "\nYou selected: 4. Search employee mobile number.\n";
            /*
            If the user selects 4, the program searches (use linear search) an employee mobile number by employee’s birth date
                and display mobile number with employee id and name.
            If a wrong employee’s birth date is provided, the program reports it.
            */
            cout << endl;
            break;
        case 5:
            cout << "\nYou selected: 5. Find employees hired for longer than 5 years.\n";
            /*
            If the user selects 5, the program finds how many employees have been with the company for more than 5 years and display their names.
            */
            cout << endl;
            break;
        case 6:
            cout << "\nYou selected: 6. Update telephone number\n";
            /*
            If the user selects 6, the program updates telephone number of the employee by employee name in the text file.
            After performing the file update, the program should report the updated telephone number.
            If a wrong name is provided, the program reports this and doesn’t make any changes.
            */
            editMobile(employee_records, RECORD_SIZE);
            cout << endl;
            break;
        case 7:
            cout << "\nYou selected: 7. Update salary.\n" << "This will increase salaries of listed employees.\n";
            /*
            If the user selects 7, the program updates salary of the  employee in the text file based on the given condition
                    (if the employee has less than 5 years experience, increment salary by 2000,
                    if the employee has less than or equal to 10 years experience, increment salary by 5000,
                    if the employee has greater than 10 years experience, increment salary by 8000).
                After performing the file update, the program should report the updated salary.
            */
            // upgradeSalary(employee_records, RECORD_SIZE);
            cout << endl;
            break;
        case 8:
            cout << "\nYou selected: 8. Write total payroll of company.\n";
            /*
            If the user selects 8, the program calculates the sum of the salaries paid by the company per month and per year and display them.
            */
            break;
        case 9:
            cout << "\nYou selected: 9. Display all records.\n";
            /*
            If the user selects 9, the program displays all the records in the text file.
            */
            showRecords(employeeFile);
            cout << endl;
            break;
        case 10:
            cout << "\nYou selected: 10. Exit.\nGoodbye!\n";
            break;
        }
    } while (userChoice != quit);
    //system("pause");
    return 0;
}
void showMenu() {
    cout << "\t\tMenu" << "\n----------------------------------------\n";
    cout << "1. List by hire date\n" << "2. Add new record\n" << "3. Delete a record\n" << "4. Search employee mobile number\n"
        << "5. Find employees hired for longer than 5 years\n" << "6. Update telephone number\n" << "7. Update salary\n"
        << "8. Total payroll of company\n" << "9. Display all records\n" << "10. Exit\n";
    cout << "Enter a menu option: ";
};

void listByHireDate(Employee_record arr[], int size) {
    cout << "Listing by Hire Date\n";
}

void writeToFile(Employee_record arr[], int size) {
    ofstream employeeFile; // file object
    employeeFile.open("employee.txt", ios::app | ios::binary);
    if (employeeFile.is_open()) {
        for (int i = 0; i < size; i++) {
            employeeFile << endl;
            employeeFile << arr[i].idNumber;
            employeeFile << arr[i].employeeName;
            employeeFile << arr[i].birthYear;
            employeeFile << arr[i].employeeAddress.addressLine1;
            employeeFile << arr[i].employeeAddress.addressLine2;
            employeeFile << arr[i].mobileNumber;
            employeeFile << arr[i].emailID;
            employeeFile << arr[i].department;
            employeeFile << arr[i].hireYear;
            employeeFile << arr[i].employeeSalary;
        }
        employeeFile.close();
    }
    else {
        cout << "Error opening file.\n";
        exit(EXIT_FAILURE);
    }
};

void addRecord(Employee_record arr[], int size) {
    ofstream employeeFile("employee.txt", ios::out | ios::app | ios::binary); // file object
    if (employeeFile.is_open()) {
        cout << "\nEnter employee details:\n";
        for (int row = 0; row < size; row++) {
            cout << "\tEmployee ID: ";
            cin >> arr[row].idNumber;
            cin.ignore(1000, '\n');
            cout << "\tEmployee Name: ";
            getline(cin, arr[row].employeeName);
            cout << "\tEmployee Birth Year: ";
            cin >> arr[row].birthYear;
            cin.ignore(1000, '\n');
            while (cin.bad()) {
                cout << "Enter as integers.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                cin >> arr[row].birthYear;
            }
            cout << "\tEmployee Address Line 1: ";
            getline(cin, arr[row].employeeAddress.addressLine1);
            cout << "\tEmployee Address Line 2: ";
            getline(cin, arr[row].employeeAddress.addressLine2);
            cout << "\tEmployee Mobile Number as Integers: ";
            cin >> arr[row].mobileNumber;
            cin.ignore();
            cout << "\tEmployee Email ID: ";
            cin >> arr[row].emailID;
            cin.ignore();
            cout << "\tEmployee Department: ";
            getline(cin, arr[row].department);
            cout << "\tEmployee Hire Year: ";
            cin >> arr[row].hireYear;
            cin.ignore();
            while (cin.bad()) {
                cout << "Enter as integers.\n";
                cin.clear();
                cin.ignore();
                cin >> arr[row].hireYear;
            }
            cout << "\tEmployee Salary: ";
            cin >> arr[row].employeeSalary;
            while (cin.bad()) {
                cout << "Enter the decimal amount.\n";
                cin.clear();
                cin.ignore();
                cin >> arr[row].employeeSalary;
            }
            employeeFile.write(reinterpret_cast<char*>(&arr), sizeof(arr));
            employeeFile << endl;
            cout << "-----------------------------\n";
            break;
        }
        employeeFile.close();
    }
    else {
        cout << "Error opening file.\n";
    }
}

void deleteRecord(Employee_record arr[], int size) {
    int deleteNum;
    fstream employeeFile("employee.txt", ios::in | ios::out | ios::app | ios::binary);
    cout << "What is the record number you wish to delete? ";
    cin >> deleteNum;
    employeeFile.seekg(deleteNum * sizeof(arr), ios::beg);
    employeeFile.read(reinterpret_cast<char*>(&arr), sizeof(arr));
    cout << "\nEmployee record was deleted.\n ";
}
void searchMobile(Employee_record arr[], int size) {
    cout << "Enter the employee's birth date: ";
};
void editMobile(Employee_record arr[], int size) {
    int editNum;
    fstream employeeFile("employee.txt", ios::in | ios::out | ios::binary);
    cout << "What is the record number you wish to edit? ";
    cin >> editNum;
    cin.ignore();
    employeeFile.seekg(editNum * sizeof(arr), ios::beg);
    employeeFile.read(reinterpret_cast<char*>(&arr), sizeof(arr));
    // display the record for verification?
    cout << "\nEmployee ID: " << arr[editNum].idNumber << endl;
    cout << "Employee Mobile Number: " << arr[editNum].mobileNumber << endl;
    
    cout << "\tNew Mobile Number: ";
    cin >> arr[editNum].mobileNumber;
    employeeFile.write(reinterpret_cast<char*>(&arr), sizeof(arr));
    cout << "Employee mobile number is: " << arr[editNum].mobileNumber;
    employeeFile.seekp(editNum * sizeof(arr), ios::beg);
    employeeFile.write(reinterpret_cast<char*>(&arr), sizeof(arr));
    employeeFile.close();
}

void upgradeSalary(Employee_record arr[], int size) {
    int currentYear = 2020;
    /*
    The program updates salary of the  employee in the text file based on the given condition
    if the employee has less than 5 years experience, increment salary by 2000,
    if the employee has less than or equal to 10 years experience, increment salary by 5000,
    if the employee has greater than 10 years experience, increment salary by 8000).*/
    for (int h = 0; h < size; h++) {
        if ((currentYear - arr[h].hireYear) < 5) {
            arr[h].employeeSalary += 2000;
        }
        else if ((currentYear - arr[h].hireYear) <= 10) {
            arr[h].employeeSalary += 5000;
        }
        else {
            arr[h].employeeSalary += 8000;
        }
    }
    cout << "Salaries have been increased.\n";
    for (int i = 0; i < size; i++) {
        cout << "Employee salary for Employee " << i << " is: " << arr[i].employeeSalary << endl;
    }
}

void showRecords(fstream &file) {
    string line;
    while (file >> line) {
        /*
        for (int i = 0; i < size; i++) {
            cout << "Employee ID: " << arr[i].idNumber << endl;
            cout << "Employee Name: " << arr[i].employeeName << endl;
            cout << "Employee Birth Year: " << arr[i].birthYear << endl;
            cout << "Employee Address Line 1: " << arr[i].employeeAddress.addressLine1 << endl;
            cout << "Employee Address Line 2: " << arr[i].employeeAddress.addressLine2 << endl;
            cout << "Employee Mobile Number: " << arr[i].mobileNumber << endl;
            cout << "Employee Email ID: " << arr[i].emailID << endl;
            cout << "Employee Department: " << arr[i].department << endl;
            cout << "Employee Hire Year: " << arr[i].hireYear;
            cout << "Employee Salary: " << arr[i].employeeSalary << endl;
            cout << "--------------------------\n";
        }
        */
        cout << line << endl;
    }
}
