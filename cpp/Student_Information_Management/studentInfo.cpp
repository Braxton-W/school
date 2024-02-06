/*
    Student Information System

    Created by Braxton Worsley
    November 20, 2023
*/

#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

// checks if given student ID is valid
// if invalid, request until given valid ID
// return valid ID
int getValidID(int id, int index) {
    while(id < 1 || id > index) {
        cout << "\nStudent ID must be between 1 and " << index
            << "\nPlease enter a valid student ID: ";
        cin >> id;
    }

    return id;
}

int main() {
    int arrID[100], choice, index = 0, id;
    string arrName[100], name;
    double arrGrade[100], grade, gradeHigh, gradeLow, gradeAvg;

    while(true) {
        cout << "*** CSCI 1010 Student Information Management System ***" 
            << "\n1. Add Student" 
            << "\n2. Search by ID" 
            << "\n3. Grade Statistics" 
            << "\n4. Remove Student" 
            << "\n5. All Students" 
            << "\n6. Exit System" 
            << "\n\nPlease enter your choice: ";
        cin >> choice;

        // exit loop
        if(choice == 6) {
            break;
        }

        // invalid choice
        if(choice < 1 || choice > 5) {
            cout << "\nInvalid choice." << endl;

            // chose to break here rather than
            // continue due to continue resulting
            // in an infinite loop where the user
            // would need to kill execution anyways
            break;
        }

        // no students to search, calc stats, remove, or view
        if(choice >= 2 && choice <= 5 && index == 0) {
            cout << "\nThere are no students in the system" 
                << "\nPlease add a student" << endl;

            choice = 1;
        }

        switch(choice) {
            // add student
            case 1:
                // max students
                if(index >= 99) {
                    cout << "\nMax students in database"
                        << "\nPlease remove a student to add a new student" << endl;

                    continue;
                }

                // input new student values
                cout << "The ID of the new student is " << index + 1
                    << "\nPlease enter the name of the student (Lastname,Firstname): ";
                cin >> name;
                cout << "Please enter the grade of the student: ";
                cin >> grade;

                // invalid grade
                while(grade < 0 || grade > 100) {
                    cout << "\nGrade must be between 0 and 100" 
                        << "\nPlease enter the new grade: ";
                    cin >> grade;
                }

                // add values to arrays
                arrID[index] = index + 1;
                arrName[index] = name;
                arrGrade[index] = grade;

                // output confirmation and new student info
                cout << "\nStudent successfully saved!"
                    << "\nID: " << arrID[index] 
                    << "\nName: " << arrName[index] 
                    << "\nGrade: " << arrGrade[index] << endl;

                // add to index for length of arrays
                index++;

                break;

            // search by id
            case 2:
                cout << "\nPlease enter the student's ID: ";
                cin >> id;

                id = getValidID(id, index);

                // output student info
                cout << "\nID" << "\t" << "Name" << "\t" << "Grade\n"
                    << arrID[id - 1] << "\t" << arrName[id - 1] << "\t" << arrGrade[id - 1] << endl;

                break;

            // grade stats
            case 3:
                // set baseline values as first value
                gradeHigh = arrGrade[0];
                gradeLow = arrGrade[0];
                gradeAvg = arrGrade[0];

                // find max, min, and add for average
                for(int i = 1; i < index; i++) {
                    // highest grade
                    if(gradeHigh < arrGrade[i]) {
                        gradeHigh = arrGrade[i];
                    }
                    // lowest grade
                    if(gradeLow > arrGrade[i]) {
                        gradeLow = arrGrade[i];
                    }
                    // add for average
                    gradeAvg += arrGrade[i];
                }

                // output stats
                cout << "\nThe highest grade is " << gradeHigh
                    << "\nThe lowest grade is " << gradeLow
                    << "\nThe average grade is " << gradeAvg / index << endl;

                break;

            // remove student
            case 4:
                cout << "\nPlease enter the ID of the student to remove: ";
                cin >> id;

                id = getValidID(id, index);

                // saves student name to be removed
                name = arrName[id - 1];

                // remove values in each array for id
                for(int i = id - 1; i < index; i++) {
                    arrID[i] = arrID[i + 1] - 1;
                    arrName[i] = arrName[i + 1];
                    arrGrade[i] = arrGrade[i + 1];
                }

                // output to confirm removal
                cout << "\n" << name << " has been removed from the database" << endl;

                // decrement index as a student was removed
                index--;

                break;

            // all students
            case 5:
                // output all students
                cout << "\nID\tName\t\tGrade" << endl;
                for(int i = 0; i < index; i++) {
                    cout << arrID[i] << "\t" << arrName[i] << "\t\t" << arrGrade[i] << endl;
                }

                break;
        }
    }

    // exit system message
    cout << "\nThank you for using the Student Information Management System!" << endl;

    return 0;
}
