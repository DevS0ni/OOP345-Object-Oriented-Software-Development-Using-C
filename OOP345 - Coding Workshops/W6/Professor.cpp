/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210

 Workshop 6
-----------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include "Professor.h"
#include "Employee.h"

using namespace std;

namespace sdds {

    // build a professor using the employee constructor
    Professor::Professor(std::istream& is) : Employee(is){
        string dept{};
        getline(is, dept, '\n');
        m_department = trim(dept, " ");
    }
    // display professor using the display from Employee and adding the department
    void Professor::display(std::ostream& os) const {
        Employee::display(os); 
        os << m_department << "| Professor";
    }

    // queries
    std::string Professor::status() const {
        return "Professor";
    }
    std::string Professor::department() const {
        return m_department;
    }
}
