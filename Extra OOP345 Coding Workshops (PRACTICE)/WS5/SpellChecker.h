/**********************************************************************************************************************************
				Workshop - #5 (Part-2)
Full Name  : Soni Dev Alpeshbhai.

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************************************************************************/
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <iostream>
#include <string>

namespace sdds
{
	const unsigned WORD_COUNT = 6;

	class SpellChecker
	{
		std::string inappropriateWords[WORD_COUNT]{};
		std::string appropriateWords[WORD_COUNT]{};
		unsigned wordFixCounts[WORD_COUNT]{};
	public:
		SpellChecker() = default;
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};

	void readWords(std::string line, std::string& inappropriateWords, std::string& appropriateWords);
}


#endif 