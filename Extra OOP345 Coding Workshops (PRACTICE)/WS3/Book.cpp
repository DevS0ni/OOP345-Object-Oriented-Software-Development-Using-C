/**********************************************************************************************************************************
				Workshop - 3 (Part-2)
Full Name  : Dev Soni

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************************************************************************/
#include <iostream>
#include <iomanip>
#include "Book.h"
using namespace std;
namespace sdds {
    
    Book::Book() {

    }
    Book::Book(const std::string& ntitle, unsigned nChapters, unsigned nPages) {
        title = ntitle;
        totalChapters = nChapters;
        totalPages = nPages;
    }

    Book::operator bool() const {
        bool flag = false;
        if (title[0] != '\0' && totalChapters != 0 && totalPages != 0) {
            flag = true;
        }
        return flag;
    }

    double Book::ratio() const {
        return double(totalPages) / double(totalChapters);
    }
    std::ostream& Book::print(std::ostream& os) const {
        if (*this) {
            if (totalChapters < 10) {
                os << " ";
            }
            os << right << setw(49) << title << "," << right << totalChapters << ","
                << right << totalPages << " | " << left << setprecision(6) << fixed
                << "(" << (double)totalPages / (double)totalChapters << left << setw(5) << ")";
            os << fixed << defaultfloat;
        }
        else {
            os << "| Invalid book data";
        }
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const Book& bk) {
        bk.print(os);
        return os;
    }

    Book& Book::operator=(const Book& rightOp) {
        title = rightOp.title;
        totalPages = rightOp.totalPages;
        totalChapters = rightOp.totalChapters;
        return *this;
    }
    bool Book::operator<(const Book& rightOp) {
        bool flag = false;
        if (ratio() < rightOp.ratio()) {
            flag = true;
        }
        return flag;
    }

    bool Book::operator>(const Book& rightOp) {
        bool flag = false;
        if (ratio() > rightOp.ratio()) {
            flag = true;
        }
        return flag;
    }
}