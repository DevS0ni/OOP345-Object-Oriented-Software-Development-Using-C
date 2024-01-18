/**********************************************************************************************************************************
				Workshop - #5 (Part-2)
Full Name  : Soni Dev Alpeshbhai.

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
#include "Book.h"


using namespace std;
namespace sdds
{
	Book::Book(const std::string& strBook)
	{
		string temp{};
		string copy = strBook;
		size_t delim{};

		delim = copy.find_first_of(',');
		temp = copy.substr(0, delim);
		authorName = removeSpaces(temp);
		copy.erase(0, delim + 1);

		delim = copy.find_first_of(',');
		temp = copy.substr(0, delim);
		bookTitle = removeSpaces(temp);
		copy.erase(0, delim + 1);

		delim = copy.find_first_of(',');
		temp = copy.substr(0, delim);
		bookCountry = removeSpaces(temp);
		copy.erase(0, delim + 1);

		delim = copy.find_first_of(',');
		temp = copy.substr(0, delim);
		temp = removeSpaces(temp);
		bookPrice = stod(temp);
		copy.erase(0, delim + 1);

		delim = copy.find_first_of(',');
		temp = copy.substr(0, delim);
		temp = removeSpaces(temp);
		publicationYear = stoi(temp);
		copy.erase(0, delim + 1);

		delim = copy.find_first_of('\n');
		temp = copy.substr(0, delim);
		bookDescription = removeSpaces(temp);
	}
	const std::string& Book::title() const
	{
		return bookTitle;
	}
	const std::string& Book::coutry() const
	{
		return bookCountry;
	}
	const size_t& Book::year() const
	{
		return publicationYear;
	}
	double& Book::price()
	{
		return bookPrice;
	}

	std::ostream& Book::print(std::ostream& out)
	{
		out << setw(20) << authorName << " | "
			<< setw(22) << bookTitle << " | "
			<< setw(5) << bookCountry << " | "
			<< setw(4) << publicationYear << " | "
			<< setw(6) << setprecision(2) << setiosflags(ios::fixed) << bookPrice << " | "
			<< bookDescription << endl;

		return out;
	}

	std::ostream& operator<<(std::ostream& out, Book& book)
	{
		return book.print(out);
	}

	string removeSpaces(string str)
	{
		unsigned i = 0;

		while (isspace(str[i]) && i < str.length())
			i++;

		str = str.erase(0, i);

		i = str.length() - 1;
		while (isspace(str[i]) && i > 0)
			i--;

		if (i < str.length() - 1)
			str = str.erase(i + 1, str.length());

		return str;
	}
}