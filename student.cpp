#include <iostream>
#include "student.h"

using namespace std;

// Define the accessors for each instance variable

string Student::GetStudentID() const {
    return studentID;
}

string Student::GetFirstName() const {
    return firstName;
}

string Student::GetLastName() const {
    return lastName;
}

string Student::GetEmail() const {
    return email;
}

int Student::GetAge() const {
    return age;
}

int* Student::GetDaysToComplete() {
    return daysToComplete;
}

DegreeProgram Student::GetDegreeProgram() const {
    return degreeProgram;
}

// Define the mutators for each instance variable

void Student::SetStudentID(string id) {
    studentID = id;
}

void Student::SetFirstName(string name) {
    firstName = name;
}

void Student::SetLastName(string name) {
    lastName = name;
}

void Student::SetEmail(string email) {
    this->email = email;
}

void Student::SetAge(int age) {
    this->age = age;
}

void Student::SetDaysToComplete(int days[NUM_COURSES]) {
    for (int i = 0; i < NUM_COURSES; i++) {
        daysToComplete[i] = days[i];
    }
}

void Student::SetDegreeProgram(DegreeProgram degree) {
    degreeProgram = degree;
}

// Define the constructor with all input parameters

Student::Student(string id,
                 string firstName,
                 string lastName,
                 string email,
                 int age,
                 int days[NUM_COURSES],
                 DegreeProgram degree) {

    SetStudentID(id);
    SetFirstName(firstName);
    SetLastName(lastName);
    SetEmail(email);
    SetAge(age);
    SetDaysToComplete(days);
    SetDegreeProgram(degree);
}

// Define the print function to print specific student data

void Student::Print() const {

    // Print out each instance variable separated by tabs

    cout << GetStudentID() << "\t";
    cout << "First Name: " << GetFirstName() << "\t";
    cout << "Last Name: " << GetLastName() << "\t";
    cout << "Email: " << GetEmail() << "\t";
    cout << "Age: " << GetAge() << "\t";
    
    // Print out an array of days to complete each course enclosed by braces
    
    cout << "daysInCourse: {";
    
    for (int i = 0; i < NUM_COURSES; i++) {
        
        cout << GetDaysToComplete()[i];
        
        if (i < NUM_COURSES - 1) {
            cout << ", ";
        }
        
    }
    
    cout << "}\t";

    // Print out the degree program based on its enum value
    
    switch (GetDegreeProgram()) {

        case SECURITY:
            cout << "Degree Program: Security" << endl;
            break;

        case NETWORK:
            cout << "Degree Program: Network" << endl;
            break;

        case SOFTWARE:
            cout << "Degree Program: Software" << endl;
            break;

        default:
            cout << "Invalid Degree Program" << endl;
            break;

    }
}
