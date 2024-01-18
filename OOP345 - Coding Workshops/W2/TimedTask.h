/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210

 Workshop 2
-----------------------------------------------------------------------------
 */

#ifndef SDDS_TIMEDTASK_H_
#define SDDS_TIMEDTASK_H_

#include <iostream>
#include <chrono>
#include <string>

namespace sdds {

    // class to measure time between operations
    class TimedTask {
        std::chrono::steady_clock::time_point m_startTime{};
        std::chrono::steady_clock::time_point m_endTime{};
        int m_numStored{ 0 }; // number of tasks stored
        // task structure - max 10
        struct {
            char name[21]{};
            char timeUnits[12]{};
            std::chrono::steady_clock::duration duration{};
        } m_task[10];
    public:
        TimedTask();
        // used in main - must be public:
        void startClock();
        void stopClock();
        void addTask(const char* name);
        friend std::ostream& operator<<(std::ostream& os, const TimedTask& T);
    };
}

#endif // !SDDS_TIMEDTASK_H_