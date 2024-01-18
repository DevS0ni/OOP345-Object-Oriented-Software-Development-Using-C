/**********************************************************************************************************************************
				Workshop - 2 (Part-2)
Full Name  : Dev Soni

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************************************************************************/

#include "AirportModels.h"
#include <fstream>
#include <iomanip>
#include <stdexcept>

namespace sdds {


Airport::Airport() : empty(true) {}

Airport::Airport(const std::string& c, const std::string& n, const std::string& ci, 
                 const std::string& st, const std::string& co, double lat, double lon)
    : code(c), name(n), city(ci), state(st), country(co), latitude(lat), longitude(lon), empty(false) {}

std::ostream& operator<<(std::ostream& os, const Airport& airport) {
    if (airport.empty) {
        os << "Empty Airport";
    } else {
	os.fill('.');
        os << std::right << std::setw(20) << "Airport Code" <<" : "<< std::left << std::setw(30) << airport.code << std::endl
           << std::right << std::setw(20) << "Airport Name" <<" : "<< std::left << std::setw(30) << airport.name << std::endl
           << std::right << std::setw(20) << "City" <<" : "<< std::left << std::setw(30) << airport.city << std::endl
           << std::right << std::setw(20) << "State" <<" : "<< std::left << std::setw(30) << airport.state << std::endl
           << std::right << std::setw(20) << "Country"<<" : "<< std::left << std::setw(30) << airport.country << std::endl
           << std::right << std::setw(20) << "Latitude" <<" : "<< std::left << std::setw(30) << airport.latitude << std::endl
           << std::right << std::setw(20) << "Longitude"<<" : "<< std::left << std::setw(30) << airport.longitude << std::endl;
    }
    return os;
}


AirportLog::AirportLog() : airports(nullptr), numAirports(0) {}


AirportLog::AirportLog(const char* filename) : airports(nullptr), numAirports(0) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open the file.");
    }

    
    std::string line;
    std::getline(file, line); 
    while (std::getline(file, line)) {
        numAirports++;
    }

    
    airports = new Airport[numAirports];

    
    file.clear(); 
    file.seekg(0, std::ios::beg);
    std::getline(file, line); 

    
    for (size_t i = 0; i < numAirports && std::getline(file, line); i++) {
        
        std::istringstream iss(line);
        std::string field;
        
        std::getline(iss, airports[i].code, ',');
        std::getline(iss, airports[i].name, ',');
        std::getline(iss, airports[i].city, ',');
        std::getline(iss, airports[i].state, ',');
        std::getline(iss, airports[i].country, ',');
        std::getline(iss, field, ',');
        airports[i].latitude = std::stod(field);
        std::getline(iss, field, ',');
        airports[i].longitude = std::stod(field);
        airports[i].empty = false; 
    }

    file.close();
}

void AirportLog::addAirport(const Airport& airport) {
    
    Airport* newAirports = new Airport[numAirports + 1];
    
    for (size_t i = 0; i < numAirports; ++i) {
        newAirports[i] = airports[i];
    }

    newAirports[numAirports] = airport;

    delete[] airports;
    airports = newAirports;

    numAirports++;
}


AirportLog AirportLog::findAirport(const char* state, const char* country) const {
    AirportLog foundAirports;
    
    size_t matches = 0;
    for (size_t i = 0; i < numAirports; ++i) {
        if (airports[i].state == state && airports[i].country == country) {
            matches++;
        }
    }

    foundAirports.airports = new Airport[matches];
    foundAirports.numAirports = matches;

    size_t j = 0;
    for (size_t i = 0; i < numAirports && j < matches; ++i) {
        if (airports[i].state == state && airports[i].country == country) {
            foundAirports.airports[j++] = airports[i];
        }
    }

    return foundAirports;
}


Airport AirportLog::operator[](size_t idx) const {
    if (idx >= numAirports) {
        return Airport();
    }
    return airports[idx];
}

AirportLog::operator size_t() const {
    return numAirports;
}


// Destructor
AirportLog::~AirportLog() {
    delete[] airports;
}

// Copy Constructor
AirportLog::AirportLog(const AirportLog& other) 
    : airports(new Airport[other.numAirports]), numAirports(other.numAirports) {
    for (size_t i = 0; i < numAirports; ++i) {
        airports[i] = other.airports[i];
    }
}

// Move Constructor
AirportLog::AirportLog(AirportLog&& other) noexcept 
    : airports(other.airports), numAirports(other.numAirports) {
    other.airports = nullptr;
    other.numAirports = 0;
}

// Copy Assignment Operator
AirportLog& AirportLog::operator=(const AirportLog& other) {
    if (this != &other) {
        delete[] airports;

        airports = new Airport[other.numAirports];
        numAirports = other.numAirports;

        for (size_t i = 0; i < numAirports; ++i) {
            airports[i] = other.airports[i];
        }
    }
    return *this;
}

// Move Assignment Operator
AirportLog& AirportLog::operator=(AirportLog&& other) noexcept {
    if (this != &other) {
        delete[] airports;

        airports = other.airports;
        numAirports = other.numAirports;

        other.airports = nullptr;
        other.numAirports = 0;
    }
    return *this;
}


} // namespace sdds
