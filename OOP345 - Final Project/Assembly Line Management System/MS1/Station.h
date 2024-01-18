// ***********************************************************
// File    Station.h
// Version 1.0
// Author  Dev Soni - dasoni4@myseneca.ca
// Stu #   130759210
// Description:
// Station Module
// -----------------------------------------------------------
// I have done all the coding myself and only copied the
// code that my professor provided to complete this workshop
// ***********************************************************

#ifndef SDDS_STATION_H_
#define SDDS_STATION_H_

#include <iostream>
#include <sstream>
#include <string>

namespace sdds {
    class Station {
        size_t m_stationId{};
        std::string m_itemName{};
        std::string m_description{};
        size_t m_nextSerial{};
        size_t m_stockCount{};
        static size_t m_widthField;
        static size_t m_idGenerator;
        // convert string to size_t
        static std::size_t stringToSize_t(std::string str) {
            std::stringstream sstream(str);
            size_t result;
            sstream >> result;
            return result;
        }
    public:
        Station(const std::string& str);
        const std::string& getItemName() const;
        size_t getQuantity() const;
        size_t getNextSerialNumber();
        void updateQuantity();
        void display(std::ostream& os, bool full) const;  
    };
}

#endif // !SDDS_STATION_H_