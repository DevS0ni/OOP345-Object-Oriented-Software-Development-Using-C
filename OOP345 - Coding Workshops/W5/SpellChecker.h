/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210

 Workshop 5
-----------------------------------------------------------------------------
*/

#ifndef SDDS_SPELLCHECKER_H_
#define SDDS_SPELLCHECKER_H_

#include <iostream>

namespace sdds {

    // SpellChecker functor
    class SpellChecker {
        std::string m_badWords[6]{};
        std::string m_goodWords[6]{};
        size_t m_replaceCount[6]{};
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
        SpellChecker(const char* filename);
        void operator()(std::string& text);
        void showStatistics(std::ostream& os) const;
    };
}

#endif // !SDDS_SPELLCHECKER_H_