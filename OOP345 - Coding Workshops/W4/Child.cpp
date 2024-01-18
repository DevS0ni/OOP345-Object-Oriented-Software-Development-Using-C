/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210

 Workshop 4
-----------------------------------------------------------------------------
*/

#include <iostream>
#include "Child.h"
#include "Toy.h"

using namespace std;

namespace sdds {

    // copy and assignment
    Child::Child(const Child& C) { *this = C; }
    Child& Child::operator=(const Child& C) {
        if (this != &C) {
            for (auto i = 0ul; i < m_numToys; ++i)
                delete m_toys[i];
            delete[] m_toys;
            m_name = C.m_name;
            m_age = C.m_age;
            m_numToys = C.m_numToys;
            m_toys = new const Toy * [m_numToys];
            for (auto i = 0ul; i < m_numToys; ++i)
                m_toys[i] = new Toy(*C.m_toys[i]);
        }
        return *this;
    }

    // move copy and assignment
    Child::Child(Child&& C) noexcept { *this = move(C); }
    Child& Child::operator=(Child&& C) noexcept {
        if (this != &C) {
            for (auto i = 0ul; i < m_numToys; ++i)
                delete m_toys[i];
            delete[] m_toys;
            m_name = C.m_name;
            m_age = C.m_age;
            m_numToys = C.m_numToys;
            m_toys = C.m_toys; // move
            C.m_toys = nullptr;
            C.m_numToys = 0;
            C.m_age = 0;
            C.m_name = "";
        }
        return *this;
    }
    Child::~Child() {
        for (auto i = 0ul; i < m_numToys; ++i)
            delete m_toys[i];
        delete[] m_toys;
    }

    // constructor
    Child::Child(std::string name, int age, const Toy* toys[], size_t count) {
        m_name = name;
        m_age = age;
        m_numToys = count;
        m_toys = new const Toy * [count];
        for (auto i = 0ul; i < count; ++i)
            m_toys[i] = new Toy(*toys[i]);
    }

    // size query
    size_t Child::size() const {
        return m_numToys;
    }

    // output
    std::ostream& Child::display(std::ostream& os) const {
        static int count = 0;
        ++count;
        os << "--------------------------" << endl;
        os << "Child " << count << ": " << m_name << " " << m_age << " years old:" << endl;
        os << "--------------------------" << endl;
        if (m_toys != nullptr) {
            for (auto i = 0ul; i < m_numToys; ++i)
                os << *m_toys[i];
        } else {
            os << "This child has no toys!" << endl;
        }
        os << "--------------------------" << endl;

        return os;
    }
    std::ostream& operator<<(std::ostream& os, const Child& C) {
        return C.display(os);
    }
}
