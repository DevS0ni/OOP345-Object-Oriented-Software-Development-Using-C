/**********************************************************************************************************************************
				Workshop - 2 (Part-2)
Full Name  : Dev Soni

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************************************************************************/

#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H
#include <chrono>
namespace sdds {
	class Timer {
	private:
		std::chrono::steady_clock::time_point start_time;
	public:
		void start();
		long long stop();
	};
}
#endif // !SDDS_TIMER_H