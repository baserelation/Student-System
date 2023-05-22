
#include <iostream>
#include "roster.h"

using namespace std;

// Define a constant for number of students in studentData array
const int NUM_STUDENTS = 5;

// Define a constant for number of fields per student
const int NUM_FIELDS = 9;

// Define a constant for maximum length of each field
const int MAX_LENGTH = 15;

// Define a constant for delimiter character
const char DELIMITER = ',';

// Define a constant for course title
const string COURSE_TITLE = "Scripting and Programming - Applications – C867";

// Define a constant for programming language
const string LANGUAGE = "C++";

// Define a constant for WGU student ID
const string STUDENT_ID = "W12345678";

// Define a constant for name
const string NAME = "Bing Bot";

// Declare studentData array as provided in requirements
const string studentData[NUM_STUDENTS] =
        {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
         "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
         "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
         "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
         "A5,Bing,Bot,Bing.bot@wgu.edu,25,25,30,35,SOFTWARE"};

// Declare a function to parse each student data and call add() function
void ParseAndAdd(string data);

// Declare a function to convert a string to a DegreeProgram enum value
DegreeProgram StringToDegree(string degree);

// Write the main function
int main() {

    // Print out course title, language used, student ID and name
    cout << COURSE_TITLE << endl;
    cout << "Language used: " << LANGUAGE << endl;
    cout << "Student ID: " << STUDENT_ID << endl;
    cout << "Name: " << NAME << endl;
    cout << endl;

    // Create an instance of Roster class called classRoster
    Roster classRoster;

    // Add each student to classRoster by parsing studentData array
    for (int i = 0; i < NUM_STUDENTS; i++) {
        ParseAndAdd(studentData[i]);
    }

    // Convert pseudo code to complete the rest of main function

    // Print out all students in classRosterArray
    classRoster.PrintAll();
    cout << endl;

    // Print out invalid emails
    classRoster.PrintInvalidEmails();
    cout << endl;

    // Loop through classRosterArray and print average days in course for each student
    for (int i = 0; i < NUM_STUDENTS; i++) {
        classRoster.PrintAverageDaysInCourse(classRoster.GetStudentAt(i)->GetStudentID());
    }
    cout << endl;

    // Print out students by degree program SOFTWARE
    classRoster.PrintByDegreeProgram(SOFTWARE);
    cout << endl;

    // Remove student with ID A3
    classRoster.Remove("A3");
    cout << endl;

    // Print out all students in classRosterArray
    classRoster.PrintAll();
    cout << endl;

    // Remove student with ID A3 again
    classRoster.Remove("A3");
    cout << endl;

    // Return 0 from main function
    return 0;
}

// Define ParseAndAdd function
void ParseAndAdd(string data) {

    // Declare an array of strings to store parsed fields
    string fields[NUM_FIELDS];

    // Declare an index variable to keep track of fields array position
    int index = 0;

    // Declare a temporary string variable to store each field value
    string temp = "";

    // Loop through each character in data string
    for (char c : data) {

        // If character is not delimiter, append it to temp string
        if (c != DELIMITER) {
            temp += c;
        }
        else {
            // If character is delimiter, store temp string in fields array at index position
            fields[index] = temp;

            // Increment index by 1
            index++;

            // Reset temp string to empty
            temp = "";
        }
        
        // If end of data string is reached,
        if (c == data.back()) {

            // Store temp string in fields array at index position 
            fields[index] = temp;
        }
        
        }

        // Declare an array of integers to store days to complete each course 
        int days[NUM_COURSES];

        // Convert fields[5], fields[6] and fields[7] from string to integer and store them in days array 
        days[0] = stoi(fields[5]);
        days[1] = stoi(fields[6]);
        days[2] = stoi(fields[7]);

        // Convert fields[8] from string to DegreeProgram enum value and store it in degree variable 
        DegreeProgram degree = StringToDegree(fields[8]);

        // Call add() function with parsed fields as arguments 
        classRoster.Add(fields[0], fields[1], fields[2], fields[3], stoi(fields[4]), days,
                        degree);
}

// Define StringToDegree function 
DegreeProgram StringToDegree(string degree) {

     // Declare a DegreeProgram variable called result 
     DegreeProgram result;

     // Use if-else statements to compare degree string with enum values and assign result accordingly 
     if (degree == "SECURITY") {
         result = SECURITY;
     }
     else if (degree == "NETWORK") {
         result = NETWORK;
     }
     else if (degree == "SOFTWARE") {
         result = SOFTWARE;
     }
     else {
         result = INVALID;
     }

     // Return result 
     return result;
}

