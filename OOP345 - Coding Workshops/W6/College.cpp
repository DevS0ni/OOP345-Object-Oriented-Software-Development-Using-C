/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210

 Workshop 6
-----------------------------------------------------------------------------
*/

#include <iostream>
#include <iomanip>
#include "College.h"
#include "Employee.h"
#include "Person.h"

using namespace std;

namespace sdds {

    // add Person pointer to the vector
    College& College::operator+=(Person* thePerson) {
        m_persons.push_back(thePerson);
        return *this;
    }

    // Display tests one and two
    void College::display(std::ostream& os) const {
        os << "------------------------------------------------------------------------------------------------------------------------\n";
        os << "|                                        Test #1 Persons in the college!                                               |\n";
        os << "------------------------------------------------------------------------------------------------------------------------\n";
        for (auto it = m_persons.begin(); it != m_persons.end(); ++it) {
            (*it)->display(os);
            cout << endl;
        }
        os << "------------------------------------------------------------------------------------------------------------------------\n";
        os << "|                                        Test #2 Persons in the college!                                               |\n";
        os << "------------------------------------------------------------------------------------------------------------------------\n";
        for (auto it = m_persons.begin(); it != m_persons.end(); ++it)
            os << "| " << setw(10) << (*it)->status() << "| " << setw(10) << (*it)->id() << "| " << setw(20) << (*it)->name()
            << " | " << setw(3) << (*it)->age() << " |\n";
        os << "------------------------------------------------------------------------------------------------------------------------\n";
    }

    // ensure no memory leaks of m_persons
    College::~College() {
        for (auto it = m_persons.begin(); it != m_persons.end(); ++it) {
            delete *it;
        }
    }
}