/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210

 Workshop 7
-----------------------------------------------------------------------------
*/

#ifndef SDDS_BAKERY_H_
#define SDDS_BAKERY_H_

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>

namespace sdds {

    // item type 
    enum class BakedType {
        BREAD = 0, PASTERY = 1
    };

    // BakedGood information
    struct BakedGood {
        BakedType m_type{};
        std::string m_desc{};
        size_t m_shelfLife{};
        size_t m_stockCount{};
        double m_itemPrice{};
    };

    class Bakery {
        // data
        std::vector<BakedGood> m_bakedGoods{};

        // std::string helpers
        // trim 'whitespace' from begining and end of 'str'
        static std::string trim(const std::string& str,
            const std::string& whitespace) {
            const auto strBegin = str.find_first_not_of(whitespace);
            if (strBegin == std::string::npos)
                return ""; // no content
            const auto strEnd = str.find_last_not_of(whitespace);
            const auto strRange = strEnd - strBegin + 1;
            return str.substr(strBegin, strRange);
        }
        // convert string to size_t
        static std::size_t stringToSize_t(std::string str) {
            std::stringstream sstream(str);
            size_t result;
            sstream >> result;
            return result;
        }
    public:
        // custom constructor
        Bakery(const char* file);
        // queries
        void showGoods(std::ostream& os) const;
        bool inStock(const char* desc, const BakedType& type) const;
        std::list<BakedGood> outOfStock(const BakedType& type) const;
        // modifiers
        void sortBakery(std::string str);
        std::vector<BakedGood> combine(Bakery& B);
    };
    // showGoods() helper for output
    std::ostream& operator<<(std::ostream& os, const BakedGood& B);
}
#endif // !SDDS_BAKERY_H_

