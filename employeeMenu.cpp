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
void readFromFile();
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
            editMobileNumber(employee_arr, NUM_RECORDS);
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
            showTotalPayroll(employee_arr, NUM_RECORDS);
            break;
        case 9:
            cout << "\n\tYou selected: 9. Display all records from file.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            /*
            If the user selects 9, the program displays all the records in the text file.
            */
            //showRecords(employee);
            readFromFile();
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

void readFromFile()
{
    fstream employeeFile("employee.txt", ios::in);
    char ch;
    if (employeeFile.is_open()) {
        employeeFile.get(ch);
        while (employeeFile) {
            cout << ch;
            employeeFile.get(ch);
        }
        cout << "\nEnd of File Records.\n";
        employeeFile.close();
    }
    else {
        cout << "Error opening file.\n";
    }
}

void writeToFile(Employee_record arr[], int size) {
    fstream employeeFile("employee.txt", ios::out);
    if (employeeFile.is_open()) {
        //employeeFile << "ID\tName\tBirth Date\tAddress Line 1\tAddress Line 2"
           // <<"\tMobile Number\tEmail ID\tDepartment\tHire Date\tSalary\n";
        for (int row = 0; row < size; row++) {
            employeeFile
                << arr[row].idNumber << " \t" << arr[row].employeeName << " \t"
                << arr[row].birthDate.month << "/" << arr[row].birthDate.day << "/" << arr[row].birthDate.year << " \t"
                << arr[row].employeeAddress1 << " \t" << arr[row].employeeAddress2 << " \t"
                << arr[row].mobileNumber << " \t" << arr[row].emailID << " " << arr[row].department << " \t"
                << arr[row].hireDate.month << "/" << arr[row].hireDate.day << "/" << arr[row].hireDate.year << " \t"
                << fixed << setprecision(2) << arr[row].employeeSalary << endl;
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
    if (result == -1) { 
        cout << "\n\nThat birth date does not exist in the records.\n";
    }
    else { // if it exists, return the phone number of the employee.
        cout << "\n\nSuccess! Found the record.\n" << "\tEmployee ID: " << employee_arr[result].idNumber << " Name: "
            << employee_arr[result].employeeName << "'s Mobile Number is: " << employee_arr[result].mobileNumber;
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

int searchForEmployeeName(Employee_record arr[], int size, char query[], int querySize) {
    for (int i = 0; i < size; i++) {
        if (arr[i].employeeName == query) {
            return i;
        }
        else {
            return -1;
        }
    }
};

void editMobileNumber(Employee_record arr[], int size) { // option 6
    char userEmployeeName[NAME_SIZE];
    int result;
    cout << "Enter the Employee Name: ";
    cin.getline(userEmployeeName, NAME_SIZE);
    result = searchForEmployeeName(arr, size, userEmployeeName, NAME_SIZE);
    if (result != -1) {
        cout << "Enter the new Mobile Number: ";
        cin.getline(arr[result].mobileNumber, NUM_SIZE);
        writeToFile(arr, NUM_RECORDS);
    }
    else {
        cout << "That Employee does not exist.\nReturning to Main Menu.\n";
    }
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
void showTotalPayroll(Employee_record arr[], int size) { // option 8
    /*
If the user selects 8, the program calculates the
sum of the salaries paid by the company
    per month (salary/ 12) and
    per year and
    displays them.
*/
    double totalMonth = 0, totalYear = 0;
    int month, year;
    for (int i = 0; i < size; i++) {
        // assuming that salary entered was for a given year?
        totalYear += arr[i].employeeSalary;
        totalMonth += (arr[i].employeeSalary / 12);
    }
    cout << "\nTotal MONTHLY Salary Paid: " << totalMonth << endl;
    cout << "Total YEARLY Salary Paid: " << totalYear << endl;
};
void readFromFile(Employee_record emp) {
    fstream employeeFile("employee.txt", ios::out);
    if (employeeFile.is_open()) {
        cout << "Read from file function is open\n";
    }
    employeeFile.close();
}
