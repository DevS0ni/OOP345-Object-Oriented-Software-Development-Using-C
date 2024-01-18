/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210

 Workshop 6
-----------------------------------------------------------------------------
*/

#include "Employee.h"
#include "Student.h"
#include "Professor.h"
#include "Utilities.h"
#include "Person.h"

namespace sdds {
    
    // builds an instance of a person depending on the KEY from input file
    Person* buildInstance(std::istream& in) {
        char ch{};
        Person* p{};
        in >> ch;
        in.ignore(); 
        if (ch == 'e' || ch == 'E')
            p = new Employee(in);
        else if (ch == 's' || ch == 'S')
            p = new Student(in);
        else if (ch == 'p' || ch == 'P')
            p = new Professor(in);        
        return p;
    }
}