
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"

using namespace std;

// Define a constant for the number of courses per student
const int NUM_COURSES = 3;

// Declare the class Student
class Student {
    public:
        // Declare the accessors for each instance variable
        string GetStudentID() const;
        string GetFirstName() const;
        string GetLastName() const;
        string GetEmail() const;
        int GetAge() const;
        int* GetDaysToComplete();
        DegreeProgram GetDegreeProgram() const;

        // Declare the mutators for each instance variable
        void SetStudentID(string id);
        void SetFirstName(string name);
        void SetLastName(string name);
        void SetEmail(string email);
        void SetAge(int age);
        void SetDaysToComplete(int days[NUM_COURSES]);
        void SetDegreeProgram(DegreeProgram degree);

        // Declare the constructor with all input parameters
        Student(string id,
                string firstName,
                string lastName,
                string email,
                int age,
                int days[NUM_COURSES],
                DegreeProgram degree);

        // Declare the print function to print specific student data
        void Print() const;

    private:
        // Declare the instance variables for Student class
        string studentID;
        string firstName;
        string lastName;
        string email;
        int age;
        int daysToComplete[NUM_COURSES];
        DegreeProgram degreeProgram;
};

#endif
