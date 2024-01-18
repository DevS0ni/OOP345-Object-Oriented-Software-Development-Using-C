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
#include <fstream>
#include <vector>
#include "Filesystem.h"
#include "Directory.h"
#include "File.h"

using namespace std;
namespace sdds
{
	void Filesystem::addResource(std::string& Path, const std::string& Content)
	{
		bool check = false;
		Directory* current = m_root;
		do
		{
			check = Path.find("/") == string::npos;
			if (!check)
			{
				string NameofDir = Path.substr(0, Path.find("/") + 1);
				Directory* newDir = nullptr;
				Path = Path.substr(Path.find("/") + 1);
				newDir = dynamic_cast<Directory*>(m_root->find(NameofDir));

				if (!newDir)
				{
					newDir = new Directory(NameofDir);
					*current += newDir;
				}
				current = newDir;
			}
			else if (Content.length() && !m_root->find(Path))
			{
				*current += new File(Path.c_str(), Content.c_str());
			}

		} while (!check);
	}
	Filesystem::Filesystem(const char* fName, const std::string& currRoot)
	{
		m_root = new Directory(currRoot);
		m_current = m_root;

		fstream file(fName);
		if (file)
		{
			string line{};
			do
			{
				bool isFile{};
				getline(file, line);

				isFile = line.find('|') != string::npos;

				if (isFile)
				{
					string path = line.substr(0, line.find('|'));
					trimString(path);
					string contents = line.substr(line.find('|') + 1);
					trimString(contents);
					addResource(path, contents);
				}
				else
				{
					trimString(line);
					addResource(line);
				}

			} while (file);
		}
		else
		{
			delete m_root;
			throw "ERROR READING FILE";
		}
	}
	Filesystem::Filesystem(Filesystem&& move) noexcept
	{
		*this = std::move(move);
	}
	Filesystem& Filesystem::operator=(Filesystem&& move) noexcept
	{
		if (this != &move)
		{
			delete m_root;
			m_root = move.m_root;
			delete move.m_root;
			move.m_current = nullptr;
			m_current = m_root;
		}
		return *this;
	}
	Filesystem& Filesystem::operator+=(Resource* res)
	{
		*m_current += res;
		return *this;
	}
	Directory* Filesystem::change_directory(const std::string& NameOfDir)
	{
		if (NameOfDir.length())
		{
			Resource* targetDir = m_root->find(NameOfDir, vector<OpFlags>{OpFlags::RECURSIVE});
			if (targetDir && targetDir->type() == NodeType::DIR)
			{
				m_current = dynamic_cast<Directory*>(targetDir);
			}
			else
			{
				throw std::invalid_argument("Cannot change directory! " + NameOfDir + " not found!");
			}
		}
		else
		{
			m_current = m_root;
		}
		return m_current;
	}
	Directory* Filesystem::get_current_directory() const
	{
		return m_current;
	}
	Filesystem::~Filesystem()
	{
		delete m_root;
		m_current = nullptr;
	}
	void trimString(std::string& src)
	{
		size_t begin = src.find_first_not_of(" \t\n");
		size_t end = src.find_last_not_of(" \t\n");
		string res{};
		if (begin != string::npos && end != string::npos)
		{
			res = src.substr(begin, end - begin + 1);
		}
		else
		{
			res = "";
		}
		src = res;
	}
}