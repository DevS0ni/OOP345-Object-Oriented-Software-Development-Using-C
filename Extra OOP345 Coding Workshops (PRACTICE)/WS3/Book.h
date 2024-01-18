/**********************************************************************************************************************************
				Workshop - 3 (Part-2)
Full Name  : Dev Soni

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************************************************************************/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
namespace sdds {
    class Book
    {
        std::string title{};
        unsigned totalChapters{};
        unsigned totalPages{};
    public:
        Book();
        Book(const std::string& title, unsigned nChapters, unsigned nPages);
        double ratio() const;
        std::ostream& print(std::ostream& os) const;
        operator bool() const;
        Book& operator=(const Book& rightOp);
        bool operator<(const Book& rightOp);
        bool operator>(const Book& rightOp);
    };
    std::ostream& operator<<(std::ostream& os, const Book& bk);
}


#endif 