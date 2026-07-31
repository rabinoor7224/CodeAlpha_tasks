#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

// Structure to store course details
struct Course {
    string name;
    float creditHours;
    char grade;
    float gradePoint;
};

// Function to convert letter grade to grade points
float getGradePoint(char grade) {
    grade = toupper(grade); // Convert to uppercase for uniformity
    switch (grade) {
        case 'A': return 4.0f;
        case 'B': return 3.0f;
        case 'C': return 2.0f;
        case 'D': return 1.0f;
        case 'F': return 0.0f;
        default:  return -1.0f; // Invalid grade
    }
}

int main() {
    int totalCourses;

    cout << "=========================================\n";
    cout << "        STUDENT CGPA CALCULATOR          \n";
    cout << "=========================================\n\n";

    cout << "Enter total number of courses taken: ";
    cin >> totalCourses;

    if (totalCourses <= 0) {
        cout << "Invalid number of courses. Exiting program.\n";
        return 1;
    }

    vector<Course> courses(totalCourses);
    float totalCreditHours = 0.0f;
    float totalGradePoints = 0.0f;

    // Input loop for courses
    for (int i = 0; i < totalCourses; i++) {
        cout << "\n--- Course " << (i + 1) << " Details ---\n";
        
        courses[i].name = "Course " + to_string(i + 1);

        // Credit Hours Input
        cout << "Enter Credit Hours: ";
        cin >> courses[i].creditHours;
        while (courses[i].creditHours <= 0) {
            cout << "Credit hours must be greater than 0. Enter again: ";
            cin >> courses[i].creditHours;
        }

        // Grade Input & Validation
        cout << "Enter Grade obtained (A, B, C, D, F): ";
        cin >> courses[i].grade;
        
        courses[i].gradePoint = getGradePoint(courses[i].grade);
        while (courses[i].gradePoint == -1.0f) {
            cout << "Invalid grade! Please enter a valid grade (A, B, C, D, F): ";
            cin >> courses[i].grade;
            courses[i].gradePoint = getGradePoint(courses[i].grade);
        }

        // Cumulative Calculations
        totalCreditHours += courses[i].creditHours;
        totalGradePoints += (courses[i].gradePoint * courses[i].creditHours);
    }

    // Calculate final CGPA
    float cgpa = totalGradePoints / totalCreditHours;

    // Display Course Details & Results
    cout << "\n=========================================\n";
    cout << "             SUMMARY REPORT              \n";
    cout << "=========================================\n";
    cout << left << setw(12) << "Course" 
         << setw(15) << "Credit Hours" 
         << setw(10) << "Grade" 
         << setw(12) << "Grade Points" << endl;
    cout << "-----------------------------------------\n";

    for (int i = 0; i < totalCourses; i++) {
        cout << left << setw(12) << courses[i].name
             << setw(15) << fixed << setprecision(1) << courses[i].creditHours
             << setw(10) << (char)toupper(courses[i].grade)
             << setw(12) << fixed << setprecision(2) << courses[i].gradePoint << endl;
    }

    cout << "-----------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Total Credit Hours Calculated : " << totalCreditHours << endl;
    cout << "Total Grade Points Earned     : " << totalGradePoints << endl;
    cout << "-----------------------------------------\n";
    cout << "FINAL CGPA / GPA              : " << cgpa << " / 4.00" << endl;
    cout << "=========================================\n";

    return 0;
}
