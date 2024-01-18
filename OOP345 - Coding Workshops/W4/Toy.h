/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210

 Workshop 4
-----------------------------------------------------------------------------
*/

#ifndef SDDS_TOY_H_
#define SDDS_TOY_H_

#include <iostream>
#include <string>

namespace sdds {

    class Toy {
        int m_orderID{};
        std::string m_name{};
        int m_numOrdered{};
        double m_pricePer{};
        double m_hst{ 0.13 };
        // string functions to deal with whitespace
        static std::string trim(const std::string& str,
            const std::string& whitespace);
        static std::string reduce(const std::string& str,
            const std::string& fill, const std::string& whitespace);
        static void setPos(std::string::size_type& end, 
            const char* ch, std::string& str);
    public:
        Toy();
        void update(int numToys);
        Toy(const std::string& T);
        std::ostream& display(std::ostream& os = std::cout) const;
    };
    std::ostream& operator<<(std::ostream& os, const Toy& T);
}
#endif // !SDDS_TOY_H_
