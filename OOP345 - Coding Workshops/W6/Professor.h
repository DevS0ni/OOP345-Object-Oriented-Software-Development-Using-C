/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210

 Workshop 6
-----------------------------------------------------------------------------
*/

#ifndef SDDS_PROFESSOR_H_
#define SDDS_PROFESSOR_H_

#include <iostream>
#include <string>
#include "Employee.h"

namespace sdds {
    // professor class inherits Employee
    class Professor : public Employee {
        std::string m_department{};
        // trim 'whitespace' from begining and end of 'str'
        static std::string trim(const std::string& str,
            const std::string& whitespace) {
            const auto strBegin = str.find_first_not_of(whitespace);
            if (strBegin == std::string::npos)
                return ""; // no content
            const auto strEnd = str.find_last_not_of(whitespace);
            const auto strRange = strEnd - strBegin + 1;
            return str.substr(strBegin, strRange);
        }
    public:
        Professor(std::istream& is = std::cin);
        void display(std::ostream& os) const;
        std::string status() const;
        std::string department() const;
    };
}

#endif // !SDDS_PROFESSOR_H_


