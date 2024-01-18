/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210

 Workshop 4
-----------------------------------------------------------------------------
*/

#ifndef SDDS_CONFIRMORDER_H_
#define SDDS_CONFIRMORDER_H_

#include <iostream>
#include "Toy.h"

namespace sdds {

    class ConfirmOrder {
        const Toy** m_toys{};
        size_t m_numToys{ 0 };
    public:
        ConfirmOrder();
        // rule of 5
        ConfirmOrder(const ConfirmOrder& C);
        ConfirmOrder& operator=(const ConfirmOrder& C);
        ConfirmOrder(ConfirmOrder&& C) noexcept;
        ConfirmOrder& operator=(ConfirmOrder&& C) noexcept;
        ~ConfirmOrder();
        // overloads
        ConfirmOrder& operator+=(const Toy& toy);
        ConfirmOrder& operator-=(const Toy& toy);
        // display
        std::ostream& display(std::ostream& os = std::cout) const;
    };
    // display helper
    std::ostream& operator<<(std::ostream& os, const ConfirmOrder& C);
}

#endif // !SDDS_CONFIRMORDER_H_
