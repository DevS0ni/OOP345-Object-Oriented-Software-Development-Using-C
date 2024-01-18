/*
Name : Soni Dev Alpeshbhai.
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "RideRequest.h"

namespace sdds {

    double g_taxrate = 0.0;    // Initialize global tax rate
    double g_discount = 0.0;   // Initialize global discount

    RideRequest::RideRequest() {
        // Initialize the member variables
        m_customerName[0] = '\0';
        m_rideDescription[0] = '\0';
        m_price = 0.0;
        m_discounted = false;
    }

    void RideRequest::read(std::istream& is) {

        static size_t counter = 0;

        // Read data from the input stream
        is.getline(m_customerName, 10, ',');
        getline(is,m_rideDescription, ',');
        is >> m_price;
        is.ignore(1, ',');
        
        char discountStatus[2];
        
        is.get(discountStatus, 2);
        
        if (discountStatus[0] == 'N') {
            m_discounted = false;
        }
        else {
            m_discounted = true;
        }
        ++counter;

    }

    void RideRequest::display() const {
	char *f_d_any_length = new char[m_rideDescription.length() + 1];

	strcpy(f_d_any_length, m_rideDescription.c_str());

        // static will prevent 'counter' from getting re-initialised with 1.
        static size_t counter{ 1 };
        double taxed_price = (m_price + (m_price * g_taxrate));
        double special_price = taxed_price - g_discount;

        if (strlen(m_customerName) == 0)
        {
            cout << left;
            cout << setw(2) << counter << ". "
                << "No Ride Request" << endl;
        }
        else
        { // left-align, right-align, setw() together form the specified format.
            cout << left;
            cout << setw(2) << counter << setw(2) << "." << setw(10) << m_customerName << "|" << setw(25) << f_d_any_length << "|";
            cout << setprecision(2);
            cout << fixed;
            cout << setw(12) << taxed_price << "|";

            if (m_discounted)
            {
                cout << right;
                cout << setw(13) << special_price << endl;
            }
            else
            {
                cout << endl;
            }
        }

        ++counter;

	// P2*****************************************************************************
    	// dynamic memory returned
    	delete[] f_d_any_length;
    	f_d_any_length = nullptr;
    	// P2*****************************************************************************
    }

}  // namespace sdds
