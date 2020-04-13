// Kimberly Wilkes
// CIT 237 - C++
// April 13, 2020
// Employee Management System

#include <iostream>
#include <fstream>
using namespace std;

int menu(int);
void showMenu();
int main()
{
    int userChoice;
    //bool keepLooping = true;
    cout << "Welcome to the Employee Management System.\n" << "Here are the menu options:\n";
    showMenu();
    cin >> userChoice;
    menu(userChoice);
    return 0;
}


int menu(int userChoice) {
    switch(userChoice) {
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
            break;
        case 10:
            cout << "You selected: 10. Exit.\nGoodbye!";
            break;
        default:
            cout << "You entered an invalid choice. Pick from the menu.\n";
            int userChoice;
            showMenu();
            cin >> userChoice;
            menu(userChoice);
            break;
    }
}

void showMenu() {
    cout << "1. List by hire date\n" << "2. Add new record\n" << "3. Delete a record\n" << "4. Search employee mobile number\n" 
        << "5. Find employees hired for longer than 5 years\n" << "6. Update telephone number\n" << "7. Update salary " 
        <<  "8. Write total payroll of company\n" << "9. Display all records\n" << "10. Exit\n";
    cout << "Enter a menu option: ";
};
