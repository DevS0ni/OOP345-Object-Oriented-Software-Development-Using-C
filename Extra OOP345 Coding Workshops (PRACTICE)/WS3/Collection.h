/**********************************************************************************************************************************
				Workshop - 3 (Part-2)
Full Name  : Dev Soni

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************************************************************************/
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include "Book.h"
#include <iomanip>
namespace sdds {
    template<typename T, unsigned C>
    class Collection {
        T no_of_items[C];
        static T smallestItem;
        static T largestItem;
        unsigned item_size = 0;
    protected:
        void setSmallestItem(const T& smallest) {
            if (smallest < smallestItem) {
                smallestItem = smallest;
            }
        }
        void setLargestItem(const T& largest) {
            if (largestItem < largest) {
                largestItem = largest;
            }
        }
        T& operator[](unsigned index) {
            return no_of_items[index];
        }
        unsigned incrSize() {
            return ++item_size;
        }
    public:
        static T getSmallestItem() {
            return smallestItem;
        }
        static T getLargestItem() {
            return largestItem;
        }
        unsigned size() const {
            return item_size;
        }
        unsigned capacity() const {
            return C;
        }
        virtual bool operator+=(const T& newThing) {
            bool flag = false;
            if (size() < capacity()) {
                setSmallestItem(newThing);
                setLargestItem(newThing);
                no_of_items[item_size++] = newThing;
                flag = true;
            }
            return flag;
        }
        void print(std::ostream& os) const {
            os << "[";
            for (unsigned i = 0; i < size(); i++) {
                os << no_of_items[i];
                if (i < item_size - 1) {
                    os << ",";
                }
            }
            os << "]" << std::endl;
        }
    };
    template<>
    class Collection<Book, 10> {
        Book no_of_items[10];
        Book smallestItem = { "", 1, 10000 };
        Book largestItem = { "", 10000, 1 };
        unsigned item_size = 0;
    protected:
        void setSmallestItem(const sdds::Book& smallest) {
            if (smallest.ratio() < smallestItem.ratio()) {
                smallestItem = smallest;
            }
        }

        void setLargestItem(const sdds::Book& largest) {
            if (largestItem.ratio() < largest.ratio()) {
                largestItem = largest;
            }
        }
        Book& operator[](unsigned index) {
            return no_of_items[index];
        }
    public:
        Book& getSmallestItem() {
            return smallestItem;
        }

        Book& getLargestItem() {
            return largestItem;
        }

        unsigned size() const {
            return item_size;
        }

        unsigned capacity() const {
            return 10;
        }
        virtual bool operator+=(const Book& newThing) {
            bool flag = false;
            if (size() < capacity()) {
                setSmallestItem(newThing);
                setLargestItem(newThing);
                no_of_items[item_size++] = newThing;
                flag = true;
            }
            return flag;
        }
        void print(std::ostream& os) const {
            os << "| " <<
                std::setfill('-') << std::setw(75) <<
                "-" << std::setfill(' ') <<
                "|" << std::endl;
            for (unsigned i = 0; i < size(); i++) {
                os << "| ";
                os << no_of_items[i];
                os << " |" << std::endl;
            }
            os << "| " <<
                std::setfill('-') << std::setw(75) <<
                "-" << std::setfill(' ') <<
                "|" << std::endl;
        }
    };

    template<>
    class Collection<Book, 72> {
        Book no_of_items[72];
        Book smallestItem = { "", 1, 10000 };
        Book largestItem = { "", 10000, 1 };
        unsigned item_size = 0;
    protected:
        void setSmallestItem(const sdds::Book& smallest) {
            if (smallest.ratio() < smallestItem.ratio()) {
                smallestItem = smallest;
            }
        }

        void setLargestItem(const sdds::Book& largest) {
            if (largest.ratio() > largestItem.ratio()) {
                largestItem = largest;
            }
        }
        Book& operator[](unsigned index) {
            return no_of_items[index];
        }
    public:
        Book& getSmallestItem() {
            return smallestItem;
        }

        Book& getLargestItem() {
            return largestItem;
        }

        unsigned size() const {
            return item_size;
        }

        unsigned capacity() const {
            return 72;
        }
        virtual bool operator+=(const Book& newThing) {
            bool flag = false;
            if (size() < capacity()) {
                setSmallestItem(newThing);
                setLargestItem(newThing);
                no_of_items[item_size++] = newThing;
                flag = true;
            }
            return flag;
        }
        void print(std::ostream& os) const {
            os << "| " <<
                std::setfill('-') << std::setw(75) <<
                "-" << std::setfill(' ') <<
                "|" << std::endl;
            for (unsigned i = 0; i < size(); i++) {
                os << "| ";
                os << no_of_items[i];
                os << " |" << std::endl;
            }
            os << "| " <<
                std::setfill('-') << std::setw(75) <<
                "-" << std::setfill(' ') <<
                "|" << std::endl;
        }

    };

    template <typename T, unsigned C>
    T Collection<T, C>::smallestItem = 9999;
    template <typename T, unsigned C>
    T Collection<T, C>::largestItem = -9999;
}


#endif