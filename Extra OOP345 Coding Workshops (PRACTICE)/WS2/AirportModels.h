/**********************************************************************************************************************************
				Workshop - 2 (Part-2)
Full Name  : Dev Soni

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************************************************************************/


#ifndef SDDS_AIRPORTMODELS_H
#define SDDS_AIRPORTMODELS_H

#include <iostream>
#include <string>

namespace sdds {

struct Airport {
    std::string code;
    std::string name;
    std::string city;
    std::string state;
    std::string country;
    double latitude;
    double longitude;
    bool empty;

    Airport();
    Airport(const std::string& code, const std::string& name, const std::string& city, 
            const std::string& state, const std::string& country, double latitude, double longitude);
    friend std::ostream& operator<<(std::ostream& os, const Airport& airport);
};

class AirportLog {
    Airport* airports;
    size_t numAirports;

    void resize(size_t newSize);

public:
    AirportLog();
    AirportLog(const char* filename);

    void addAirport(const Airport& airport);
    AirportLog findAirport(const char* state, const char* country) const;
    Airport operator[](size_t idx) const;
    operator size_t() const;

    // Rule-of-5:
    ~AirportLog();
    AirportLog(const AirportLog& other);
    AirportLog(AirportLog&& other) noexcept;
    AirportLog& operator=(const AirportLog& other);
    AirportLog& operator=(AirportLog&& other) noexcept;
};

} // namespace sdds

#endif // SDDS_AIRPORTMODELS_H
