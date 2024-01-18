/**********************************************************************************************************************************
				Workshop - #5 (Part-2)
Full Name  : Soni Dev Alpeshbhai.

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************************************************************************/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <string>

namespace sdds
{
	class Book
	{
		std::string authorName{};
		std::string bookTitle{};
		std::string bookCountry{};
		size_t publicationYear{};
		double bookPrice{};
		std::string bookDescription{};

	public:
		Book() = default;
		Book(const std::string& strData);
		const std::string& title() const;
		const std::string& coutry() const;
		const size_t& year() const;
		double& price();
		std::ostream& print(std::ostream& out);
		friend std::ostream& operator<<(std::ostream& out, Book& book);

		template <typename T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(bookDescription);
		}
	};

	std::string removeSpaces(std::string str);
}

#endif 
