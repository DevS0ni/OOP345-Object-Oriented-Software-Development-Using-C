/*
Name : Soni Dev Alpeshbhai.
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_RIDEREQUEST_H
#define SDDS_RIDEREQUEST_H

#include <iostream>
#include<fstream>
#include <iomanip>
#include<cstring>

using namespace std;

namespace sdds {

    class RideRequest {
        char m_customerName[10]{'\0'};
        string m_rideDescription;
        double m_price;
        bool m_discounted;

    public:
        RideRequest();  // Default constructor
        void read(std::istream& is);
        void display() const;
    };

    extern double g_taxrate;   // Global tax rate
    extern double g_discount;  // Global discount

}  // namespace sdds

#endif  // SDDS_RIDEREQUEST_H
