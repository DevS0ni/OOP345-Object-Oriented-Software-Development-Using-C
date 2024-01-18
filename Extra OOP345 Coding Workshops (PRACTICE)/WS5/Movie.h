/**********************************************************************************************************************************
				Workshop - #5 (Part-2)
Full Name  : Soni Dev Alpeshbhai.

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************************************************************************/
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>
#include <string>


namespace sdds
{
	class Movie
	{
		std::string movieName{};
		size_t releaseYear{};
		std::string movieDescription{};

	public:
		Movie() = default;
		Movie(const std::string& movieData);
		const std::string& title() const;
		std::ostream& print(std::ostream& out) const;
		template <typename T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(movieName);
			spellChecker(movieDescription);
		}

		friend std::ostream& operator<<(std::ostream& out, const Movie& movie);

	};
}

#endif