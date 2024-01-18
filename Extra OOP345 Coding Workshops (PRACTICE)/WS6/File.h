/*
*******************************************************************************************
                             W-6  part 2
 NAME      : Dev Soni

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*******************************************************************************************
*/

#ifndef SDDS_FILE_H
#define SDDS_FILE_H

#include <string>
#include <vector>
#include "Resource.h"

namespace sdds
{
	class File : public Resource
	{
		std::string m_contents{};
	public:
		File(const char* Name, const char* Contents = "");
		void update_parent_path(const std::string&);
		NodeType type() const;
		std::string path() const;
		std::string name() const;
		int count() const;
		size_t size() const;
		~File() = default;
	};
}

#endif