/**********************************************************************************************************************************
				Workshop - 2 (Part-2)
Full Name  : Dev Soni

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************************************************************************/

#include <chrono>
#include "Timer.h"

namespace sdds {
	// Start timer
	void Timer::start() {
    		start_time = std::chrono::steady_clock::now();
	}

	// Stop timer and get duration in nanoseconds
	long long Timer::stop() {
    		auto end_time = std::chrono::steady_clock::now();
    		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
    		return duration.count();
	}
}