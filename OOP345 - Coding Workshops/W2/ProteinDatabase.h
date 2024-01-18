/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210

 Workshop 2
-----------------------------------------------------------------------------
 */

#ifndef SDDS_PROTEINDATABASE_H_
#define SDDS_PROTEINDATABASE_H_

#include <string>

namespace sdds {
    class ProteinDatabase {
        std::string* m_sequences{};
        size_t m_numStrings{};
    public:
        // default / one arg constructor
        ProteinDatabase(const char* str = nullptr);
        // rule of 5 for classes with a resource
        ProteinDatabase(const ProteinDatabase& P);
        ProteinDatabase& operator=(const ProteinDatabase& P);
        ProteinDatabase(ProteinDatabase&& P) noexcept;
        ProteinDatabase& operator=(ProteinDatabase&& P )noexcept;
        ~ProteinDatabase();
        // size query - number of strings stored
        size_t size() const;
        // subscript operator - return index at 'size'
        std::string operator[](size_t size) const;
    };
}
#endif // !SDDS_PROTEINDATABASE_H_