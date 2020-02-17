// Write a program that reads student scores, gets the best score and then assigns grads based on the following conditions:  
// Grade is A if score is >= best - 10;
// Grade is B if score is >= best - 20;
// Grade is C if score is >= best - 30;
// Grade is D if score is >= best - 40;
// Grade is F otherwise.
// The program prompts the user to enter the total number of students,
// then prompts the user to enter all of the scores and concludes by displaying the grades. (2 points)
#include <iostream>
#include <vector>

using namespace std;

int bestScore(vector<int>, int);
string assignLetterGrades(vector<int>, int, int);

int main() {
    int numberOfStudents;
    vector<int> studentScores;
    string grades;

    cout << "Enter the number of students: ";
    cin >> numberOfStudents;
    cout << "You have " << numberOfStudents << " students.\n\n";
    cout << "Enter the scores: ";
    for (int i = 0; i < numberOfStudents; i++) {
        int userGradeInput;
        cin >> userGradeInput;
        studentScores.push_back(userGradeInput);
    }
    int best = bestScore(studentScores, numberOfStudents);
    cout << "The best score is: " << best << endl;
    
    grades = assignLetterGrades(studentScores, best, numberOfStudents);
    
    cout << "Grades are " << grades << endl;
    return 0;
}
int bestScore(vector<int> scores, int numberOfStudents) {
    int bestScore = 0;
    for (int j = 0; j < numberOfStudents; j++) {
        if (scores[j] > bestScore) {
            bestScore = scores[j];
        }
    }
    return bestScore;
}
string assignLetterGrades(vector<int> scores, int best, int numberOfStudents) {
    string grades;
    for (int k = 0; k < numberOfStudents; k++) {
		if (scores[k] >= best - 10) {
		    grades += " A ";
		} else if (scores[k] <= best - 10 && scores[k] >= best - 20) {
		    grades += " B " ;
		} else if (scores[k] <= best - 20 && scores[k] >= best - 30) {
		    grades += " C ";
		} else if (scores[k] <= best - 30 && scores[k] >= best - 40) {
		    grades += " D ";
		} else {
		    grades += " F ";
		}
    }
    return grades;
}
