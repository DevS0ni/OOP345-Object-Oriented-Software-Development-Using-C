/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210

 Workshop 3
-----------------------------------------------------------------------------
*/

#include <iostream>
#include <iomanip>
#include "Pair.h"

using namespace std;

namespace sdds {

    // default constructor
    Pair::Pair() {}

    // used to eliminate duplicates in Set
    bool Pair::operator==(const Pair& P) {
        return this->getKey() == P.m_key;
    }

    // display key and value
    std::ostream& Pair::display(std::ostream& os) const {
        os << right << setw(20) << m_key << ": " << left << m_value;
        return os;
    }

    // insertion helper for display
    std::ostream& operator<<(std::ostream& os, const Pair& P) {
        return P.display(os);
    }
}