/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210

 Workshop 4
-----------------------------------------------------------------------------
*/

#ifndef SDDS_CHILD_H_
#define SDDS_CHILD_H_

#include <iostream>
#include <string>
#include "Toy.h"

namespace sdds {

    class Child {
        std::string m_name{};
        int m_age{};
        const Toy** m_toys{};
        size_t m_numToys{};
    public:
        // constructors
        Child() {}
        Child(std::string name, int age, const Toy* toys[], size_t count);
        // rule of 5
        Child(const Child& C);
        Child& operator=(const Child& C);
        Child(Child&& C) noexcept;
        Child& operator=(Child&& C) noexcept;
        ~Child();
        // size query
        size_t size() const;
        // output
        std::ostream& display(std::ostream& os = std::cout) const;
    };
    std::ostream& operator<<(std::ostream& os, const Child& C);
}
#endif // !SDDS_CHILD_H_
