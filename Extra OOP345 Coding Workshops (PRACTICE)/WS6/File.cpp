/*
*******************************************************************************************
                             W-6  part 2
 NAME      : Dev Soni

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*******************************************************************************************
*/

#include <string>
#include "File.h"
#include "Resource.h"

namespace sdds
{
	File::File(const char* Name, const char* Contents)
	{
		m_name = Name;
		m_contents = Contents;
	}
	void File::update_parent_path(const std::string& Path)
	{
		m_parent_path = Path;
	}
	NodeType File::type() const
	{
		return NodeType::FILE;
	}
	std::string File::path() const
	{
		return m_parent_path + m_name;
	}
	std::string File::name() const
	{
		return m_name;
	}
	int File::count() const
	{
		return -1;
	}
	size_t File::size() const
	{
		return m_contents.length();
	}
}