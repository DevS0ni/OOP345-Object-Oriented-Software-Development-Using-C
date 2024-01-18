/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Workshop 1
-----------------------------------------------------------------------------
 */

#ifndef SDDS_FOODORDER_H_
#define SDDS_FOODORDER_H_

#include <iostream>

namespace sdds {

    class FoodOrder {
        char m_custName[10]{};
        char* m_foodDesc{}; // dynamic
        double m_price{};
        bool m_special{};
        // my cstring functions for length and copy
        static int strlen(const char* str);
        static void strcpy(char* des, const char* src, int len = -1);
        // get a string of an unknown length and 
        // store the result in str dynamically
        static void getString(char*& str, std::istream& is = std::cin);
    public:
        FoodOrder();
        // rule of three for class w/resource
        FoodOrder(const FoodOrder& F);
        FoodOrder& operator=(const FoodOrder& F);
        ~FoodOrder();
        // I/O
        std::istream& read(std::istream& is = std::cin);
        void display() const;
    };
}

// declare external variables
extern double g_taxrate;
extern double g_dailydiscount;

#endif // SDDS_FOODORDER_H_
