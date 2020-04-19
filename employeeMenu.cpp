// Kimberly Wilkes
// CIT 237 - C++
// April 13, 2020
// Employee Management System

#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
using namespace std;

const int NUM_RECORDS = 3;
const int NAME_SIZE = 51, DATE_SIZE = 10, NUM_SIZE = 14, ADDRESS_SIZE = 51;

/*
// primitive data types for testing
    int idNumber;
    string employeeName;
    Date birthDate;
    string employeeAddress1;
    string employeeAddress2;
    int mobileNumber;
    string emailID;
    string department;
    Date hireDate;
    double employeeSalary;

    char[arr] for actual structures since structures don't like strings
    struct Employee_record {
    int idNumber;
    char employeeName[NAME_SIZE];
    Date birthDate;
    char employeeAddress1[ADDRESS_SIZE];
    char employeeAddress2[ADDRESS_SIZE];
    char mobileNumber[NUM_SIZE];
    char emailID[NAME_SIZE];
    char department[NAME_SIZE];
    Date hireDate;
    double employeeSalary;
};

    char idNumber[NUM_SIZE];
    char employeeName[NAME_SIZE];
    char birthDate[DATE_SIZE];
    char employeeAddress1[ADDRESS_SIZE];
    char employeeAddress2[ADDRESS_SIZE];
    char mobileNumber[NUM_SIZE];
    char emailID[NAME_SIZE];
    char department[NAME_SIZE];
    char hireDate[DATE_SIZE];
    char employeeSalary[NUM_SIZE];
*/
struct Date {
    // in MM-DD-YYYY format
    int month;
    int day;
    int year;

};
struct Employee_record {
    int idNumber;
    char employeeName[NAME_SIZE];
    Date birthDate;
    char employeeAddress1[ADDRESS_SIZE];
    char employeeAddress2[ADDRESS_SIZE];
    char mobileNumber[NUM_SIZE];
    char emailID[NAME_SIZE];
    char department[NAME_SIZE];
    Date hireDate;
    double employeeSalary;
};

void showMenu() {
    cout << "\n\t\tMenu" << "\n----------------------------------------\n";
    cout << "1. List by hire date\n" << "2. Add new record\n" << "3. Delete a record\n" << "4. Search employee mobile number\n"
        << "5. Find employees hired for longer than 5 years\n" << "6. Update telephone number\n" << "7. Increase employees' salaries\n"
        << "8. Show total payroll of company\n" << "9. Display all records\n" << "10. Exit\n";
    cout << "Enter a menu option: ";
}
// Prototype function list
void showRecords(Employee_record [], int);
void sortByHireDate(Employee_record[], int); //option 1
void addRecord(Employee_record [], int); // option 2
void deleteRecord(Employee_record [], int); // option 3
int searchForId(Employee_record [], int, int); //helper for option 3
void writeToFile(Employee_record [], int); // helper
void getMobileNumber(Employee_record employee_arr[NUM_RECORDS]); // option 4
int searchForBirthDate(Employee_record [], int, int, int, int); // helper for option 4
void find5YearStaff(Employee_record [], int); // option 5
void editMobileNumber(Employee_record [], int); // option 6
void increaseSalary(Employee_record [], int); // option 7
void showTotalPayroll(Employee_record[], int); // option 8

int main()
{
    int userChoice, quit = 10;
    struct Employee_record employee = {};
    struct Employee_record employee_arr[NUM_RECORDS] = {};
/*
    fstream employeeFile("employee.txt");
    {
        int countRecords = 0;
        Employee_record tempEmployee;
        ifstream employeeFile("employee.txt", ios::in | ios::binary);
        if (employeeFile.is_open()) {
            employeeFile >> tempEmployee.idNumber; // check that there is a record and pull the first piece.
            cout << "First record id number is " << tempEmployee.idNumber;
            while (countRecords < NUM_RECORDS) {
                // read the rest of the first record
                employeeFile
                    >> tempEmployee.employeeName
                    >> tempEmployee.birthDate.month >> tempEmployee.birthDate.day >> tempEmployee.birthDate.year
                    >> tempEmployee.employeeAddress1 >> tempEmployee.employeeAddress2
                    >> tempEmployee.mobileNumber >> tempEmployee.emailID >> tempEmployee.department
                    >> tempEmployee.hireDate.month >> tempEmployee.hireDate.day >> tempEmployee.hireDate.year
                    >> tempEmployee.employeeSalary;
                cout << "Reading record " << countRecords;
                employee_arr[NUM_RECORDS] = tempEmployee;
                countRecords++;
                employeeFile >> tempEmployee.idNumber;
            }
            employeeFile.close();
        }
    }
*/

    do {
        showMenu(); //show menu options
        cin >> userChoice;
        while (cin.bad() || userChoice < 1 || userChoice > 10) //validate userChoice
        {
            cout << "\tInvalid Option. Enter your choice again: ";
            cin.clear(); // reset cin flags so we don't have infinite loop
            cin.ignore(1000, '\n'); // disregard up to 1000 characters or the last newline
            cin >> userChoice; // ask for input again
        }
        switch (userChoice) {
        case 1:
            cout << "\n\tYou selected: 1. List by Hire Date.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            the program need to sorting (use bubble sort) the records in the text file by hire date and then display the entire data set.
            Be sure that the entire data is written in an organized and readable format. */
            //sortByHireDate(employee_arr);
            // Bubble sort
            cout << "The current records as listed by order of creation: \n";
            showRecords(employee_arr, NUM_RECORDS);
            sortByHireDate(employee_arr, NUM_RECORDS);
            cout << "The sorted records as listed by order of oldest hiring date: \n";
            showRecords(employee_arr, NUM_RECORDS);
            cout << endl;
            break;
        case 2:
            cout << "\n\tYou selected: 2. Add a new record.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            If the user selects 2, the program adds new employee details in the text file.
            */
            addRecord(employee_arr, NUM_RECORDS);
            {
            }
            break;
        case 3:
            cout << "\n\tYou selected: 3. Delete a record.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            If the user selects 3, the program deletes a record by employee id.
            If a wrong employee id is provided, the program reports it.
            */
            deleteRecord(employee_arr, NUM_RECORDS);
            cout << endl;
            break;
        case 4:
            cout << "\n\tYou selected: 4. Search employee mobile number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            If the user selects 4, the program searches (use linear search) an employee mobile number by employee’s birth date
                and display mobile number with employee id and name.
            If a wrong employee’s birth date is provided, the program reports it.
            */
            getMobileNumber(employee_arr);
            cout << endl;
            break;
        case 5:
            cout << "\n\tYou selected: 5. Find employees hired for longer than 5 years.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            If the user selects 5, the program finds how many employees have been with the company for more than 5 years
            and display their names.
            */
            find5YearStaff(employee_arr, NUM_RECORDS);
            cout << endl;
            break;
        case 6:
            cout << "\n\tYou selected: 6. Update telephone number\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            If the user selects 6, the program updates telephone number of the employee by employee name in the text file.
            After performing the file update, the program should report the updated telephone number.
            If a wrong name is provided, the program reports this and doesn’t make any changes.
            */
            //editMobile(employee);
            cout << endl;
            break;
        case 7:
            cout << "\n\tYou selected: 7. Increase employees' salary.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            If the user selects 7, the program updates salary of the  employee in the text file based on the given condition
                    (if the employee has less than 5 years experience, increment salary by 2000,
                    if the employee has less than or equal to 10 years experience, increment salary by 5000,
                    if the employee has greater than 10 years experience, increment salary by 8000).
                After performing the file update, the program should report the updated salary.
            */
            increaseSalary(employee_arr, NUM_RECORDS);
            cout << endl;
            break;
        case 8:
            cout << "\n\tYou selected: 8. Show total payroll of company.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            If the user selects 8, the program calculates the
            sum of the salaries paid by the company
                per month and
                per year and
                displays them.
            */
            break;
        case 9:
            cout << "\n\tYou selected: 9. Display all records from file.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            If the user selects 9, the program displays all the records in the text file.
            */
            //showRecords(employee);
            {
            }
            cout << endl;
            break;
        case 10:
            cout << "\n\tYou selected: 10. Exit.\n\nGoodbye!\n";
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        }
    } while (userChoice != quit);
    return 0;
}

void writeToFile(Employee_record arr[], int size) {
    fstream employeeFile("employee.txt", ios::out);
    if (employeeFile.is_open()) {
        for (int row = 0; row < size; row++) {
            employeeFile
                << arr[row].idNumber << arr[row].employeeName
                << arr[row].birthDate.month << arr[row].birthDate.day << arr[row].birthDate.year
                << arr[row].employeeAddress1 << arr[row].employeeAddress2
                << arr[row].mobileNumber << arr[row].emailID << arr[row].department
                << arr[row].hireDate.month << arr[row].hireDate.day << arr[row].hireDate.year
                << arr[row].employeeSalary << endl;
        }
        employeeFile.close();
    }
    else {
        cout << "Error opening file.\n";
    }
};

void showRecords(Employee_record arr[], int size) {
    for (int row = 0; row < size; row++) {
        cout << "Employee ID: " << arr[row].idNumber << endl;
        cout << "Employee Name: " << arr[row].employeeName << endl;
        cout << "Employee Birth Date: "
            << arr[row].birthDate.month << "/"
            << arr[row].birthDate.day << "/"
            << arr[row].birthDate.year << endl;
        cout << "Employee Address Line 1: " << arr[row].employeeAddress1 << endl;
        cout << "Employee Address Line 2: " << arr[row].employeeAddress2 << endl;
        cout << "Employee Mobile Number: " << arr[row].mobileNumber << endl;
        cout << "Employee Email ID: " << arr[row].emailID << endl;
        cout << "Employee Department: " << arr[row].department << endl;
        cout << "Employee Hire Date: "
            << arr[row].hireDate.month << "/"
            << arr[row].hireDate.day << "/"
            << arr[row].hireDate.year << endl;
        cout << "Employee Salary: " << arr[row].employeeSalary << endl;
        cout << "-----------------------------------------------------------\n";
    }
    cout << "\nEnd of records.\n";
};
void sortByHireDate(Employee_record arr[], int size) {
    //bubble sort
    bool needNextPass = true;
    cout << endl;
    for (int i = 1; i < size; i++) {
        needNextPass = false;
        for (int j = 0; j < NUM_RECORDS - i; j++) {
            // if 0 is greater than 0 + 1 then swap
            if (arr[j].hireDate.year > arr[j + 1].hireDate.year) {
                if (arr[j].hireDate.month > arr[j + 1].hireDate.month) {
                    if (arr[j].hireDate.day > arr[j + 1].hireDate.day) {
                        // swap(arr[j], arr[j + 1]);
                        Employee_record temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                        needNextPass = true;
                    }
                }
            }
        }
    }
};
void addRecord(Employee_record  arr[], int size) { //option 2
    // currently requires user to enter all records up to the const variable for array size;
    // currently array is set to 3 for testing
    cout << "\nEnter employee details:\n";
    for (int i = 0; i < size; i++) {
        cout << "\tEmployee ID: "; cin >> arr[i].idNumber;
        cin.ignore();
        cout << "\tEmployee Name: "; cin.getline(arr[i].employeeName, NAME_SIZE);
        cout << "\tEmployee Birth Date in MM-DD-YYYY\n";
        cout << "\t\tEmployee Birth Month: "; cin >> arr[i].birthDate.month;
        cout << "\t\tEmployee Birth Day: "; cin >> arr[i].birthDate.day;
        cout << "\t\tEmployee Birth Year: "; cin >> arr[i].birthDate.year;
        cin.ignore(); // disregard remaining newline after all date struct is entered
        cout << "\tEmployee Address Line 1: "; cin.getline(arr[i].employeeAddress1, ADDRESS_SIZE);
        cout << "\tEmployee Address Line 2: "; cin.getline(arr[i].employeeAddress2, ADDRESS_SIZE);
        cout << "\tEmployee Mobile Number: "; cin.getline(arr[i].mobileNumber, NUM_SIZE);
        cout << "\tEmployee Email ID: "; cin.getline(arr[i].emailID, NAME_SIZE);
        cout << "\tEmployee Department: "; cin.getline(arr[i].department, NAME_SIZE);
        cout << "\tEmployee Hire Date in MM-DD-YYYY\n";
        cout << "\t\tEmployee Hire Month: "; cin >> arr[i].hireDate.month;
        cout << "\t\tEmployee Hire Day: "; cin >> arr[i].hireDate.day;
        cout << "\t\tEmployee Hire Year: "; cin >> arr[i].hireDate.year;
        cin.ignore(); // disregard remaining newline after all date struct is entered
        cout << "\tEmployee Salary: "; cin >> arr[i].employeeSalary;
        cin.ignore();
        cout << "-----------------------------------------------------------\n";
    }
    writeToFile(arr, size);
    cout << endl;
}

int searchForId(Employee_record arr[], int size, int query) { //helper for option 3
    for (int i = 0; i < size; i++)
        if (arr[i].idNumber == query)
            return i;
    return -1;
};

void deleteRecord(Employee_record arr[], int size) //option 3
{
    int userSearchId, result;
    char confirmDelete;
    cout << "Enter the Employee ID you wish to delete: ";
    cin >> userSearchId;
    while (cin.bad()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "You must enter an integer for Employee Id.\n";
        cin >> userSearchId;
    }
    result = searchForId(arr, size, userSearchId);
    if (result != -1) {
        cout << "Confirm delete for Employee " << arr[result].idNumber << "with 'Y' or 'y': ";
        cin >> confirmDelete;
        if (confirmDelete == 'y' || confirmDelete == 'Y') {
            arr[result] = {};
            writeToFile(arr, size);
            cout << "Successfully Deleted. Returning to main menu.\n";
        }
        else {
            cout << "Did not delete. Returning to main menu.\n";
        }
    }
    else {
        cout << "\nThat record does not exist.\n";
    }
}


int searchForBirthDate(Employee_record arr[], int size, int month, int day, int year) { //helper for option 4
    for (int i = 0; i < size; i++) {
        if (arr[i].birthDate.month == month) {
            if (arr[i].birthDate.day == day) {
                if (arr[i].birthDate.year == year) {
                    return i;
                }
                return -1;
            }
            return -1;
        }
        return -1;
    }
};

void getMobileNumber(Employee_record employee_arr[NUM_RECORDS]) { //option 4
    // only works for finding the 1st entry. doesn't actually find numbers for other dates?
    int userSearchDay, userSearchMonth, userSearchYear, result;
    cout << "Enter the Employee Birth Date you wish to find (MM-DD-YYYY).\n\tEnter the month: ";
    cin >> userSearchMonth;
    cout << "\tEnter the day: ";
    cin >> userSearchDay;
    cout << "\tEnter the year: ";
    cin >> userSearchYear;
    result = searchForBirthDate(employee_arr, NUM_RECORDS, userSearchMonth, userSearchDay, userSearchYear);
    if (result != -1) { // if it exists, return the phone number of the employee.
        cout << "\n\nSuccess! Found the record.\n" << "\tEmployee "
            << employee_arr[result].employeeName << "'s Mobile Number is: " << employee_arr[result].mobileNumber;
    }
    else { //
        cout << "\n\nThat birth date does not exist in the records.\n";
    }
};


void find5YearStaff(Employee_record arr[], int size) { // option 5
    int  result, currentYear = 2020;
    cout << "These are the employees who have worked for at least 5 years.\n";
    for (int i = 0; i < size; i++) {
        result = currentYear - arr[i].hireDate.year;
        if (result >= 5) {
            cout << "\tEmployee ID: " << arr[i].idNumber << " Name: " << arr[i].employeeName << endl;
        }
    }
    cout << "\nEnd of senior staff search.\n";
};

void editMobileNumber(Employee_record arr[], int size) { // option 6

};

void increaseSalary(Employee_record arr[], int size) { // option 7
    /*
If the user selects 7, the program updates salary of the  employee in the text file based on the given condition
        (if the employee has less than 5 years experience, increment salary by 2000,
        if the employee has less than or equal to 10 years experience, increment salary by 5000,
        if the employee has greater than 10 years experience, increment salary by 8000).
    After performing the file update, the program should report the updated salary.
*/
    int currentYear = 2020;
    for (int i = 0; i < size; i++) {
        if (currentYear - arr[i].hireDate.year < 5) {
            arr[i].employeeSalary += 2000;
            cout << "Employee " << arr[i].employeeName << "'s salary is " << arr[i].employeeSalary << endl;
        }
        else if (currentYear - arr[i].hireDate.year >= 10) {
            arr[i].employeeSalary += 5000;
            cout << "Employee " << arr[i].employeeName << "'s salary is " << arr[i].employeeSalary << endl;
        }
        else if (currentYear - arr[i].hireDate.year > 10) {
            arr[i].employeeSalary += 8000;
            cout << "Employee " << arr[i].employeeName << "'s salary is " << arr[i].employeeSalary << endl;
        }
    }
    writeToFile(arr, size);
};
void showTotalPayroll(Employee_record arr) { // option 8
    /*
If the user selects 8, the program calculates the
sum of the salaries paid by the company
    per month and
    per year and
    displays them.
*/
    double total;
};
char emailID[NAME_SIZE];
    char department[NAME_SIZE];
    Date hireDate;
    double employeeSalary;
};

    char idNumber[NUM_SIZE];
    char employeeName[NAME_SIZE];
    char birthDate[DATE_SIZE];
    char employeeAddress1[ADDRESS_SIZE];
    char employeeAddress2[ADDRESS_SIZE];
    char mobileNumber[NUM_SIZE];
    char emailID[NAME_SIZE];
    char department[NAME_SIZE];
    char hireDate[DATE_SIZE];
    char employeeSalary[NUM_SIZE];
*/
struct Date {
    // in MM-DD-YYYY format
    int month;
    int day;
    int year;

};
struct Employee_record {
    int idNumber;
    string employeeName;
    Date birthDate;
    string employeeAddress1;
    string employeeAddress2;
    int mobileNumber;
    string emailID;
    string department;
    Date hireDate;
    double employeeSalary;
};

void showMenu();
void writeToFile(Employee_record[], int);
void sortByHireDate(Employee_record employee_arr[NUM_RECORDS]);

void addRecord(Employee_record employee_arr[NUM_RECORDS]);

void deleteRecord(Employee_record  employee_arr[NUM_RECORDS]);
int searchForId(Employee_record employee_arr[NUM_RECORDS], int);

void getMobileNumber(Employee_record employee_arr[NUM_RECORDS]);
int searchForBirthDate(Employee_record employee_arr[NUM_RECORDS], int, int, int);

void showSeniorStaff();
int searchHireYear(Employee_record);
void editMobileNumber(Employee_record);
void increaseSalary(Employee_record);
void showTotalPayroll(Employee_record);
void showRecords(Employee_record employee_arr[NUM_RECORDS]);


int main()
{
    int userChoice, quit = 10;
    Employee_record employee;
    Employee_record employee_arr[NUM_RECORDS];
    fstream employeeFile("employee.txt");
    do {
        showMenu(); //show menu options
        cin >> userChoice;
        while (cin.bad() || userChoice < 1 || userChoice > 10) //validate userChoice
        {
            cout << "\tInvalid Option. Enter your choice again: ";
            cin.clear(); // reset cin flags so we don't have infinite loop
            cin.ignore(1000, '\n'); // disregard up to 1000 characters or the last newline
            cin >> userChoice; // ask for input again
        }
        switch (userChoice) {
        case 1:
            cout << "\n\tYou selected: 1. List by Hire Date.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            the program need to sorting (use bubble sort) the records in the text file by hire date and then display the entire data set.
            Be sure that the entire data is written in an organized and readable format. */
            //sortByHireDate(employee_arr);
            // Bubble sort
            cout << "The current records as listed by order of creation: \n";
            showRecords(employee_arr);
            sortByHireDate(employee_arr);
            cout << "The sorted records as listed by order of oldest hiring date: \n";
            showRecords(employee_arr);
            cout << endl;
            break;
        case 2:
            cout << "\n\tYou selected: 2. Add a new record.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            If the user selects 2, the program adds new employee details in the text file.
            */
            addRecord(employee_arr);
            break;
        case 3:
            cout << "\n\tYou selected: 3. Delete a record.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            If the user selects 3, the program deletes a record by employee id.
            If a wrong employee id is provided, the program reports it.
            */
            deleteRecord(employee_arr);
            cout << endl;
            break;
        case 4:
            cout << "\n\tYou selected: 4. Search employee mobile number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            If the user selects 4, the program searches (use linear search) an employee mobile number by employee’s birth date
                and display mobile number with employee id and name.
            If a wrong employee’s birth date is provided, the program reports it.
            */
            getMobileNumber(employee_arr);
            cout << endl;
            break;
        case 5:
            cout << "\n\tYou selected: 5. Find employees hired for longer than 5 years.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            If the user selects 5, the program finds how many employees have been with the company for more than 5 years
            and display their names.
            */
            cout << endl;
            break;
        case 6:
            cout << "\n\tYou selected: 6. Update telephone number\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            If the user selects 6, the program updates telephone number of the employee by employee name in the text file.
            After performing the file update, the program should report the updated telephone number.
            If a wrong name is provided, the program reports this and doesn’t make any changes.
            */
            //editMobile(employee);
            cout << endl;
            break;
        case 7:
            cout << "\n\tYou selected: 7. Increase employees' salary.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            If the user selects 7, the program updates salary of the  employee in the text file based on the given condition
                    (if the employee has less than 5 years experience, increment salary by 2000,
                    if the employee has less than or equal to 10 years experience, increment salary by 5000,
                    if the employee has greater than 10 years experience, increment salary by 8000).
                After performing the file update, the program should report the updated salary.
            */
            cout << endl;
            break;
        case 8:
            cout << "\n\tYou selected: 8. Show total payroll of company.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            If the user selects 8, the program calculates the 
            sum of the salaries paid by the company 
                per month and 
                per year and 
                displays them.
            */
            break;
        case 9:
            cout << "\n\tYou selected: 9. Display all records.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            If the user selects 9, the program displays all the records in the text file.
            */
            //showRecords(employee);
            showRecords(employee_arr);
            cout << endl;
            break;
        case 10:
            cout << "\n\tYou selected: 10. Exit.\n\nGoodbye!\n";
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        }
    } while (userChoice != quit);
    return 0;
}

void showMenu() {
    cout << "\n\t\tMenu" << "\n----------------------------------------\n";
    cout << "1. List by hire date\n" << "2. Add new record\n" << "3. Delete a record\n" << "4. Search employee mobile number\n"
        << "5. Find employees hired for longer than 5 years\n" << "6. Update telephone number\n" << "7. Increase employees' salaries\n"
        << "8. Show total payroll of company\n" << "9. Display all records\n" << "10. Exit\n";
    cout << "Enter a menu option: ";
}

void sortByHireDate(Employee_record employee_arr[NUM_RECORDS]) {
    bool needNextPass = true;
    cout << endl;
    for (int i = 1; i < NUM_RECORDS; i++) {
        needNextPass = false;
        for (int j = 0; j < NUM_RECORDS - i; j++) {
            // if 0 is greater than 0 + 1 then swap
            if (employee_arr[j].hireDate.year > employee_arr[j + 1].hireDate.year) {
                if (employee_arr[j].hireDate.month > employee_arr[j + 1].hireDate.month) {
                    if (employee_arr[j].hireDate.day > employee_arr[j + 1].hireDate.day) {
                        // swap(arr[j], arr[j + 1]);
                        Employee_record temp = employee_arr[j];
                        employee_arr[j] = employee_arr[j + 1];
                        employee_arr[j + 1] = temp;
                        needNextPass = true;
                    }
                }
            }
        }
    }
};

void writeToFile(Employee_record arr[], int size) {
    fstream employeeFile("employee.txt", ios::out | ios::app | ios::binary);
    if (employeeFile.is_open()) {
        for (int row = 0; row < size; row++) {
            employeeFile << arr[row].idNumber;
            employeeFile << arr[row].employeeName;
            employeeFile << arr[row].birthDate.month;
            employeeFile << arr[row].birthDate.day;
            employeeFile << arr[row].birthDate.year;
            employeeFile << arr[row].employeeAddress1;
            employeeFile << arr[row].employeeAddress2;
            employeeFile << arr[row].mobileNumber;
            employeeFile << arr[row].emailID;
            employeeFile << arr[row].department;
            employeeFile << arr[row].hireDate.month;
            employeeFile << arr[row].hireDate.day;
            employeeFile << arr[row].hireDate.year;
            employeeFile << arr[row].employeeSalary << endl;
        }
        employeeFile.close();
    }
    else {
        cout << "Error opening file.\n";
    }

};

void addRecord(Employee_record  employee_arr[NUM_RECORDS]) {
    // currently requires user to enter all records up to the const variable for array size;
    // currently array is set to 3 for testing
    cout << "\nEnter employee details:\n";
    for (int i = 0; i < NUM_RECORDS; i++) {
        cout << "\tEmployee ID: ";
        cin >> employee_arr[i].idNumber;
        cin.ignore();
        cout << "\tEmployee Name: ";
        cin >> employee_arr[i].employeeName;
        cout << "\tEmployee Birth Date in MM-DD-YYYY\n";
        cout << "\t\tEmployee Birth Month: ";
        cin >> employee_arr[i].birthDate.month;
        cout << "\t\tEmployee Birth Day: ";
        cin >> employee_arr[i].birthDate.day;
        cout << "\t\tEmployee Birth Year: ";
        cin >> employee_arr[i].birthDate.year;
        cin.ignore(); // disregard remaining newline after all date struct is entered
        cout << "\tEmployee Address Line 1: ";
        cin >> employee_arr[i].employeeAddress1;
        cout << "\tEmployee Address Line 2: ";
        cin >> employee_arr[i].employeeAddress2;
        cout << "\tEmployee Mobile Number: ";
        cin >> employee_arr[i].mobileNumber;
        cin.ignore();
        cout << "\tEmployee Email ID: ";
        cin >> employee_arr[i].emailID;
        cout << "\tEmployee Department: ";
        cin >> employee_arr[i].department;
        cout << "\tEmployee Hire Date in MM-DD-YYYY\n";
        cout << "\t\tEmployee Hire Month: ";
        cin >> employee_arr[i].hireDate.month;
        cout << "\t\tEmployee Hire Day: ";
        cin >> employee_arr[i].hireDate.day;
        cout << "\t\tEmployee Hire Year: ";
        cin >> employee_arr[i].hireDate.year;
        cin.ignore(); // disregard remaining newline after all date struct is entered
        cout << "\tEmployee Salary: ";
        cin >> employee_arr[i].employeeSalary;
        cin.ignore();
        cout << "-----------------------------------------------------------\n";
    }
    writeToFile(employee_arr, NUM_RECORDS);
    cout << endl;
}

void deleteRecord(Employee_record  employee_arr[NUM_RECORDS])
{
    int userSearchId, result;
    char confirmDelete;
    cout << "Enter the Employee ID you wish to delete: ";
    cin >> userSearchId;
    while (cin.bad()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "You must enter an integer for Employee Id.\n";
        cin >> userSearchId;
    }
    result = searchForId(employee_arr, userSearchId);
    if (result != -1) {
        cout << "Confirm delete for Employee " << employee_arr[result].idNumber << "with 'Y' or 'y': ";
        cin >> confirmDelete;
        if (confirmDelete == 'y' || confirmDelete == 'Y') {
            employee_arr[result] = {};
            cout << "Successfully Deleted. Returning to main menu.\n";
        }
        else {
            cout << "Did not delete. Returning to main menu.\n";
        }
    }
    else {
        cout << "That record does not exist.\n";
    }
}
int searchForId(Employee_record employee_arr[NUM_RECORDS], int query) {
    for (int i = 0; i < NUM_RECORDS; i++)
        if (employee_arr[i].idNumber == query)
            return i;
    return -1;
};

void getMobileNumber(Employee_record employee_arr[NUM_RECORDS]) {
    int userSearchDay, userSearchMonth, userSearchYear, result;
    cout << "Enter the Employee Birth Date you wish to find (MM-DD-YYYY).\n\tEnter the month: ";
    cin >> userSearchMonth;
    cout << "\tEnter the day: ";
    cin >> userSearchDay;
    cout << "\tEnter the year: ";
    cin >> userSearchYear;
    cin.ignore();
    result = searchForBirthDate(employee_arr, userSearchMonth, userSearchDay, userSearchYear);
    if (result != -1) { // if it exists, return the phone number of the employee.
        cout << "\nSuccess! Found the record.\n" << "\tEmployee " << employee_arr[result].employeeName << "'s Mobile Number is: " << employee_arr[result].mobileNumber;
    }
    else { //
        cout << "\nThat birth date does not exist in the records.\n";
    }
};
int searchForBirthDate(Employee_record employee_arr[NUM_RECORDS], int month, int day, int year) {
    for (int i = 0; i < NUM_RECORDS; i++) {
        if (employee_arr[i].birthDate.month == month) {
            cout << "\n\tFound a matching birth month.";
            if (employee_arr[i].birthDate.day == day) {
                cout << "\n\tFound a matching day.";
                if (employee_arr[i].birthDate.year == year) {
                    cout << "\n\tFound a matching year.";
                    return i;
                }
                return -1;
            }
            return -1;
        }
        return -1;
    }
};

void showSeniorStaff() {

};
int find5YearStaff(Employee_record arr[], int size) {
    int currentYear = 2020, result;
    for (int i = 0; i < size; i++) {
        result = currentYear - arr[i].hireDate.year;
        if (result > 5) {
            cout << "Found a senior staff member!\n";
            return i;
        }
    }
        
};

void editMobileNumber(Employee_record arr) {

};
void increaseSalary(Employee_record arr) {

};
void showTotalPayroll(Employee_record arr) {

};
void showRecords(Employee_record employee_arr[NUM_RECORDS]) {
    fstream employeeFile;
    employeeFile.open("employee.txt", ios::in | ios::binary);
    if (employeeFile.is_open()) {
        for (int row = 0; row < NUM_RECORDS; row++) {
            cout << "Employee ID: " << employee_arr[row].idNumber << endl;
            cout << "Employee Name: " << employee_arr[row].employeeName << endl;
            cout << "Employee Birth Date: "
                << employee_arr[row].birthDate.month << "/"
                << employee_arr[row].birthDate.day << "/"
                << employee_arr[row].birthDate.year << endl;
            cout << "Employee Address Line 1: " << employee_arr[row].employeeAddress1 << endl;
            cout << "Employee Address Line 2: " << employee_arr[row].employeeAddress2 << endl;
            cout << "Employee Mobile Number: " << employee_arr[row].mobileNumber << endl;
            cout << "Employee Email ID: " << employee_arr[row].emailID << endl;
            cout << "Employee Department: " << employee_arr[row].department << endl;
            cout << "Employee Hire Date: "
                << employee_arr[row].hireDate.month << "/"
                << employee_arr[row].hireDate.day << "/"
                << employee_arr[row].hireDate.year << endl;
            cout << "Employee Salary: " << employee_arr[row].employeeSalary << endl;
            cout << "-----------------------------------------------------------\n";
        }
        cout << "\nEnd of records.\n";
        employeeFile.close();
    }
    else {
        cout << "Unable to open file.\n";
    }
};char department[NAME_SIZE];
    Date hireDate;
    double employeeSalary;
};
    
    char idNumber[NUM_SIZE];
    char employeeName[NAME_SIZE];
    char birthDate[DATE_SIZE];
    char employeeAddress1[ADDRESS_SIZE];
    char employeeAddress2[ADDRESS_SIZE];
    char mobileNumber[NUM_SIZE];
    char emailID[NAME_SIZE];
    char department[NAME_SIZE];
    char hireDate[DATE_SIZE];
    char employeeSalary[NUM_SIZE];

*/
struct Date {
    // in MM-DD-YYYY format
    int month;
    int day;
    int year;

};
struct Employee_record {
    int idNumber;
    string employeeName;
    Date birthDate;
    string employeeAddress1;
    string employeeAddress2;
    int mobileNumber;
    string emailID;
    string department;
    Date hireDate;
    double employeeSalary;
};

void showMenu();
void writeToFile(Employee_record [], int);
void sortByHireDate(Employee_record, int);
void addRecord(Employee_record employee_arr[NUM_RECORDS]);

void deleteRecord(Employee_record  employee_arr[NUM_RECORDS]);
int searchForId(Employee_record employee_arr[NUM_RECORDS], int);

void searchForMobile(Employee_record employee_arr[NUM_RECORDS]);
int searchForBirthDate(Employee_record employee_arr[NUM_RECORDS], int, int, int);

void searchSeniorStaff(Employee_record);
void editMobileNumber(Employee_record);
void increaseSalary(Employee_record);
void showTotalPayroll(Employee_record);
void showRecords(Employee_record);


int main()
{
    int userChoice, quit = 10;
    Employee_record employee;
    Employee_record employee_arr[NUM_RECORDS];
    fstream employeeFile("employee.txt");
    do {
        showMenu(); //show menu options
        cin >> userChoice;
        while (cin.bad() || userChoice < 1 || userChoice > 10) //validate userChoice
        {
            cout << "\tInvalid Option. Enter your choice again: ";
            cin.clear(); // reset cin flags so we don't have infinite loop
            cin.ignore(1000, '\n'); // disregard up to 1000 characters or the last newline
            cin >> userChoice; // ask for input again
        }
        switch (userChoice) {
        case 1:
            cout << "\n\tYou selected: 1. List by Hire Date.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            the program need to sorting (use bubble sort) the records in the text file by hire date and then display the entire data set.
            Be sure that the entire data is written in an organized and readable format. */
            // sortByHireDate(employee_arr, NUM_RECORDS);
            cout << endl;
            break;
        case 2:
            cout << "\n\tYou selected: 2. Add a new record.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            If the user selects 2, the program adds new employee details in the text file.
            */
            addRecord(employee_arr);
            break;
        case 3:
            cout << "\n\tYou selected: 3. Delete a record.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            If the user selects 3, the program deletes a record by employee id.
            If a wrong employee id is provided, the program reports it.
            */
            deleteRecord(employee_arr);
            cout << endl;
            break;
        case 4:
            cout << "\n\tYou selected: 4. Search employee mobile number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            If the user selects 4, the program searches (use linear search) an employee mobile number by employee’s birth date
                and display mobile number with employee id and name.
            If a wrong employee’s birth date is provided, the program reports it.
            */
            searchForMobile(employee_arr);
            cout << endl;
            break;
        case 5:
            cout << "\n\tYou selected: 5. Find employees hired for longer than 5 years.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            If the user selects 5, the program finds how many employees have been with the company for more than 5 years and display their names.
            */
            cout << endl;
            break;
        case 6:
            cout << "\n\tYou selected: 6. Update telephone number\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            If the user selects 6, the program updates telephone number of the employee by employee name in the text file.
            After performing the file update, the program should report the updated telephone number.
            If a wrong name is provided, the program reports this and doesn’t make any changes.
            */
            //editMobile(employee);
            cout << endl;
            break;
        case 7:
            cout << "\n\tYou selected: 7. Increase employees' salary.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            If the user selects 7, the program updates salary of the  employee in the text file based on the given condition
                    (if the employee has less than 5 years experience, increment salary by 2000,
                    if the employee has less than or equal to 10 years experience, increment salary by 5000,
                    if the employee has greater than 10 years experience, increment salary by 8000).
                After performing the file update, the program should report the updated salary.
            */
            //editSalary(employee);
            cout << endl;
            break;
        case 8:
            cout << "\n\tYou selected: 8. Show total payroll of company.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            If the user selects 8, the program calculates the sum of the salaries paid by the company per month and per year and display them.
            */
            break;
        case 9:
            cout << "\n\tYou selected: 9. Display all records.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            If the user selects 9, the program displays all the records in the text file.
            */
            //showRecords(employee);
            employeeFile.open("employee.txt", ios::in | ios::binary);
            if (employeeFile.is_open()) {
                for (int row = 0; row < 3; row++) {
                    cout << "Employee ID: " << employee_arr[row].idNumber << endl;
                    cout << "Employee Name: " << employee_arr[row].employeeName << endl;
                    cout << "Employee Birth Date: " 
                        << employee_arr[row].birthDate.month << "/" 
                        << employee_arr[row].birthDate.day << "/"
                        << employee_arr[row].birthDate.year << endl;
                    cout << "Employee Address Line 1: " << employee_arr[row].employeeAddress1 << endl;
                    cout << "Employee Address Line 2: " << employee_arr[row].employeeAddress2 << endl;
                    cout << "Employee Mobile Number: " << employee_arr[row].mobileNumber << endl;
                    cout << "Employee Email ID: " << employee_arr[row].emailID << endl;
                    cout << "Employee Department: " << employee_arr[row].department << endl;
                    cout << "Employee Hire Date: " 
                        << employee_arr[row].hireDate.month << "/" 
                        << employee_arr[row].hireDate.day << "/"
                        << employee_arr[row].hireDate.year << endl;
                    cout << "Employee Salary: " << employee_arr[row].employeeSalary << endl;
                    cout << "-----------------------------------------------------------\n";
                }
                cout << "\nEnd of records.\n";
                employeeFile.close();
            }
            else {
                cout << "Unable to open file.\n";
            }
            cout << endl;
            break;
        case 10:
            cout << "\n\tYou selected: 10. Exit.\n\nGoodbye!\n";
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        }
    }
    while (userChoice != quit);
    return 0;
}

void showMenu() {
    cout << "\n\t\tMenu" << "\n----------------------------------------\n";
    cout << "1. List by hire date\n" << "2. Add new record\n" << "3. Delete a record\n" << "4. Search employee mobile number\n"
        << "5. Find employees hired for longer than 5 years\n" << "6. Update telephone number\n" << "7. Increase employees' salaries\n"
        << "8. Show total payroll of company\n" << "9. Display all records\n" << "10. Exit\n";
    cout << "Enter a menu option: ";
}
/*
void sortHireDate(int arr, int size) {
    // Bubble sort
    bool needNextPass = true;
    cout << "The current records are listed by order of creation: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 1; i < size; i++) {
        needNextPass = false;
        for (int j = 0; j < size - i; j++) {
            // if 0 is greater than 0 + 1 then swap
            if (arr[j] > arr[j + 1]) {
                // swap(arr[j], arr[j + 1]);
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j + 1] = temp;
                needNextPass = true;
            }
        }
    }
    cout << "Now listing records by hire date (oldest to newest): ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
};
*/
void writeToFile(Employee_record arr[], int size) {
    fstream employeeFile("employee.txt", ios::out | ios::app | ios::binary);
    if (employeeFile.is_open()) {
        for (int row = 0; row < size; row++) {
            employeeFile << arr[row].idNumber;
            employeeFile << arr[row].employeeName;
            employeeFile << arr[row].birthDate.month;
            employeeFile << arr[row].birthDate.day;
            employeeFile << arr[row].birthDate.year;
            employeeFile << arr[row].employeeAddress1;
            employeeFile << arr[row].employeeAddress2;
            employeeFile << arr[row].mobileNumber;
            employeeFile << arr[row].emailID;
            employeeFile << arr[row].department;
            employeeFile << arr[row].hireDate.month;
            employeeFile << arr[row].hireDate.day;
            employeeFile << arr[row].hireDate.year;
            employeeFile << arr[row].employeeSalary << endl;
        }
        employeeFile.close();
    }
    else {
        cout << "Error opening file.\n";
    }

};

void addRecord(Employee_record  employee_arr[NUM_RECORDS]) {
    // currently requires user to enter all records up to the const variable for array size;
    // currently array is set to 3 for testing
    cout << "\nEnter employee details:\n";
    for (int i = 0; i < NUM_RECORDS; i++) {
        cout << "\tEmployee ID: ";
        cin >> employee_arr[i].idNumber;
        cin.ignore();
        cout << "\tEmployee Name: ";
        cin >> employee_arr[i].employeeName;
        cout << "\tEmployee Birth Date in MM-DD-YYYY\n";
        cout << "\t\tEmployee Birth Month: ";
        cin >> employee_arr[i].birthDate.month;
        cout << "\t\tEmployee Birth Day: ";
        cin >> employee_arr[i].birthDate.day;
        cout << "\t\tEmployee Birth Year: ";
        cin >> employee_arr[i].birthDate.year;
        cin.ignore(); // disregard remaining newline after all date struct is entered
        cout << "\tEmployee Address Line 1: ";
        cin >> employee_arr[i].employeeAddress1;
        cout << "\tEmployee Address Line 2: ";
        cin >> employee_arr[i].employeeAddress2;
        cout << "\tEmployee Mobile Number: ";
        cin >> employee_arr[i].mobileNumber;
        cin.ignore();
        cout << "\tEmployee Email ID: ";
        cin >> employee_arr[i].emailID;
        cout << "\tEmployee Department: ";
        cin >> employee_arr[i].department;
        cout << "\tEmployee Hire Date in MM-DD-YYYY\n";
        cout << "\t\tEmployee Hire Month: ";
        cin >> employee_arr[i].hireDate.month;
        cout << "\t\tEmployee Hire Day: ";
        cin >> employee_arr[i].hireDate.day;
        cout << "\t\tEmployee Hire Year: ";
        cin >> employee_arr[i].hireDate.year;
        cin.ignore(); // disregard remaining newline after all date struct is entered
        cout << "\tEmployee Salary: ";
        cin >> employee_arr[i].employeeSalary;
        cin.ignore();
        cout << "-----------------------------------------------------------\n";
    }
    writeToFile(employee_arr, NUM_RECORDS);
    cout << endl;
}

void deleteRecord(Employee_record  employee_arr[NUM_RECORDS])
{
    int userSearchId, result;
    char confirmDelete;
    cout << "Enter the Employee ID you wish to delete: ";
    cin >> userSearchId;
    while (cin.bad()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "You must enter an integer for Employee Id.\n";
        cin >> userSearchId;
    }
    result = searchForId(employee_arr, userSearchId);
    if (result != -1) {
        cout << "Confirm delete for Employee " << employee_arr[result].idNumber << "with 'Y' or 'y': ";
        cin >> confirmDelete;
        if (confirmDelete == 'y' || confirmDelete == 'Y') {
            employee_arr[result] = {};
            cout << "Successfully Deleted. Returning to main menu.\n";
        }
        else {
            cout << "Did not delete. Returning to main menu.\n";
        }
    }
    else {
        cout << "That record does not exist.\n";
    }
}
int searchForId(Employee_record employee_arr[NUM_RECORDS], int query) {
    for (int i = 0; i < NUM_RECORDS; i++)
        if (employee_arr[i].idNumber == query)
            return i;
    return -1;
};

void searchForMobile(Employee_record employee_arr[NUM_RECORDS]) {
    int userSearchDay, userSearchMonth, userSearchYear, result;
    cout << "Enter the Employee Birth Date you wish to find (MM-DD-YYYY).\n\tEnter the month: ";
    cin >> userSearchMonth;
    cout << "\tEnter the day: ";
    cin >> userSearchDay;
    cout << "\tEnter the year: ";
    cin >> userSearchYear;
    cin.ignore();
    result = searchForBirthDate(employee_arr, userSearchMonth, userSearchDay, userSearchYear);
    if (result != -1) { // if it exists, return the phone number of the employee.
        cout << "\nSuccess! Found the record.\n" << "\tEmployee " << employee_arr[result].employeeName << "'s Mobile Number is: " << employee_arr[result].mobileNumber;
    }
    else { //
        cout << "\nThat birth date does not exist in the records.\n";
    }
};
int searchForBirthDate(Employee_record employee_arr[NUM_RECORDS], int month, int day, int year) {
    for (int i = 0; i < NUM_RECORDS; i++) {
        if (month == employee_arr[i].birthDate.month) {
            if (day == employee_arr[i].birthDate.day) {
                if (year == employee_arr[i].birthDate.year) {
                    return i;
                }
            }
        }
        else {
            return -1;
        }
    }
};


void searchSeniorStaff(Employee_record arr) {

};
void editMobileNumber(Employee_record arr) {

};
void increaseSalary(Employee_record arr) {

};
void showTotalPayroll(Employee_record arr) {

};
void showRecords(Employee_record employee) {
    fstream employeeFile("employee.txt", ios::in | ios::binary);
    if (employeeFile.is_open()) {
        employeeFile.read(reinterpret_cast<char*>(&employee), sizeof(employee));
        //for (int row = 0; row < NUM_RECORDS; row++) {
        while (!employeeFile.eof()) {
            cout << "Employee ID: " << employee.idNumber << endl;
            cout << "Employee Name: " << employee.employeeName << endl;
            cout << "Employee Birth Date: " << employee.birthDate.month << "/" << employee.birthDate.day << "/" << employee.birthDate.year << endl;
            cout << "Employee Address Line 1: " << employee.employeeAddress1 << endl;
            cout << "Employee Address Line 2: " << employee.employeeAddress2 << endl;
            cout << "Employee Mobile Number: " << employee.mobileNumber << endl;
            cout << "Employee Email ID: " << employee.emailID << endl;
            cout << "Employee Department: " << employee.department << endl;
            cout << "Employee Hire Date: " << employee.hireDate.month << "/" << employee.hireDate.day << "/" << employee.hireDate.year << endl;
            cout << "Employee Salary: " << employee.employeeSalary << endl;
            cout << "____________________________\n";
            employeeFile.read(reinterpret_cast<char*>(&employee), sizeof(employee));
        }
        //}
        cout << "\nEnd of records.\n";
        employeeFile.close();
    }
    else cout << "Unable to open file.\n";
};
