/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210

 Workshop 2
-----------------------------------------------------------------------------
 */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstring>
#include "TimedTask.h"

using namespace std;

namespace sdds {
    TimedTask::TimedTask() {}

    void TimedTask::startClock() { // start time
        m_startTime = chrono::steady_clock::now();
    }

    void TimedTask::stopClock() { // stop time
        m_endTime = chrono::steady_clock::now();
    }

    // add a new Task member
    void TimedTask::addTask(const char* name) { 
        strcpy(m_task[m_numStored].name, name);
        strcpy(m_task[m_numStored].timeUnits, "nanoseconds");
        m_task[m_numStored].duration = 
            chrono::duration_cast<chrono::nanoseconds>(m_endTime - m_startTime);
        ++m_numStored;
    }

    // output tasks
    ostream& operator<<(std::ostream& os, const TimedTask& T) {
        os << "--------------------------\n";
        os << "Execution Times:\n";
        os << "--------------------------\n";
        for (int i = 0; i < T.m_numStored; ++i) {
            os << left << setw(21) << T.m_task[i].name;
            os << right << setw(12) << 
                chrono::nanoseconds(T.m_task[i].duration).count();
            os << " " << T.m_task[i].timeUnits << endl;
        }
        os << "--------------------------\n";
        return os;
    }
}