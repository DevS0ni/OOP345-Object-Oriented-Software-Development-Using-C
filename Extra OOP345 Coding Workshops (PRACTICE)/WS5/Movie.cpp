/**********************************************************************************************************************************
				Workshop - #5 (Part-2)
Full Name  : Soni Dev Alpeshbhai.

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include "Movie.h"
#include "Book.h"

using namespace std;
namespace sdds
{
	Movie::Movie(const std::string& movieData)
	{
		string temp{};
		string copy = movieData;
		size_t delim{};

		delim = copy.find_first_of(',');
		temp = copy.substr(0, delim);
		movieName = removeSpaces(temp);
		copy.erase(0, delim + 1);

		delim = copy.find_first_of(',');
		temp = copy.substr(0, delim);
		temp = removeSpaces(temp);
		releaseYear = stoi(temp);
		copy.erase(0, delim + 1);

		temp = copy.substr(0, movieData.length() - 1);
		movieDescription = removeSpaces(temp);
	}
	const std::string& sdds::Movie::title() const
	{
		return movieName;
	}
	std::ostream& Movie::print(std::ostream& out) const
	{
		out << setw(40) << movieName << " | "
			<< setw(4) << releaseYear << " | "
			<< setw(5) << movieDescription << endl;;
		return out;
	}
	std::ostream& operator<<(std::ostream& out, const Movie& movie)
	{
		return movie.print(out);
	}
}