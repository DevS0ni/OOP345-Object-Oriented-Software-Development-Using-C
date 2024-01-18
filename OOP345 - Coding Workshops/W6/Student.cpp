/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210

 Workshop 6
-----------------------------------------------------------------------------
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "Student.h"

using namespace std;

namespace sdds {

    // Student constructor
    Student::Student(std::istream& is) {
        string str{};
        getline(is, str, ',');
        m_name = trim(str, " ");
        getline(is, str, ',');
        m_age = trim(str, " ");
        try {
            stoi(m_age);
        } catch (std::invalid_argument&) {
            is.ignore(1000, '\n');
            throw(m_name + "++Invalid record!");
        }
        getline(is, str, ',');
        m_id = trim(str, " ");
        if (m_id[0] != 'S') {
            is.ignore(1000, '\n');
            throw(m_name + "++Invalid record!");
        }
        getline(is, str, ',');
        m_numCourses = stoi(str);
        if (m_numCourses) {
            m_courses = new string[m_numCourses];
            for (int i = 0; i < m_numCourses - 1; ++i) {
                getline(is, str, ',');
                m_courses[i] = trim(str, " ");
            }
            getline(is, str, '\n');
            m_courses[m_numCourses - 1] = trim(str, " ");
        }
    }

    // queries
    std::string Student::status() const {
        return "Student";
    }
    std::string Student::name() const {
        return m_name;
    }
    std::string Student::age() const {
        return m_age;
    }
    std::string Student::id() const {
        return m_id;
    }

    // display student
    void Student::display(std::ostream& os) const {
        os << "| " << setw(10) << status() << "| " << setw(10) << m_id
            << "| " << setw(20) << m_name << " | " << setw(3) << m_age << " |";
        for (int i = 0; i < m_numCourses; ++i) {
            os << m_courses[i];
            if (i != m_numCourses - 1) os << ", ";
        }
    }

    // clean-up
    Student::~Student() {
        delete[] m_courses;
    }
}