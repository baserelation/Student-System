#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include "student.h"

using namespace std;

// Define a constant for maximum number of students in roster array 
const int MAX_STUDENTS = 5;

// Declare Roster class 
class Roster {

public:
    
     // Declare constructor and destructor 
     Roster();
     ~Roster();

     // Declare add function 
     void Add(string id,
              string firstName,
              string lastName,
              string email,
