/**********************************************************************************************************************************
				Workshop - #5 (Part-2)
Full Name  : Soni Dev Alpeshbhai.

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************************************************************************/
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>

namespace sdds
{
	template <typename T>
	class Collection
	{
		std::string collectionName{};
		T* collectionItems{};
		unsigned collectionSize{};
		void (*collectionObserver)(const Collection<T>&, const T&) {};

	public:
		Collection() = default;
		Collection(const std::string& name) : Collection<T>()
		{
			collectionName = name;
		}
		Collection(const Collection& other) = delete;
		Collection(const Collection&& other) = delete;
		Collection& operator=(const Collection& other) = delete;
		Collection& operator=(const Collection&& other) = delete;
		~Collection()
		{
			delete[] collectionItems;
		}
		operator bool() const
		{
			return (collectionSize > 0);
		}

		const std::string& name() const
		{
			return collectionName;
		}

		size_t size() const
		{
			return collectionSize;
		}
		void setObserver(void (*observer)(const Collection<T>&, const T&))
		{
			collectionObserver = observer;
		}
		Collection<T>& operator+=(const T& item)
		{
			bool dupe = false;
			for (size_t i = 0; i < collectionSize && !dupe; i++)
				dupe = (collectionItems[i].title() == item.title());

			if (!dupe)
			{
				T* newArr = new T[collectionSize + 1];
				for (size_t i = 0; i < collectionSize; i++)
					newArr[i] = collectionItems[i];
				newArr[collectionSize] = item;
				delete[] collectionItems;
				collectionItems = newArr;
				collectionSize++;
				if (collectionObserver != nullptr)
					collectionObserver(*this, item);
			}
			return *this;
		}
		T& operator[](size_t idx) const
		{
			if (idx >= collectionSize)
			{
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(collectionSize) + "] items.");
			}
			else
			{
				return collectionItems[idx];
			}
		}
		T* operator[](const char* title) const
		{
			T* item = nullptr;
			for (size_t i = 0; i < collectionSize; i++)
			{
				if (collectionItems[i].title() == title)
					item = &collectionItems[i];
			}
			return item;
		}

		std::ostream& print(std::ostream& out) const
		{
			for (size_t i = 0; i < collectionSize; i++)
			{
				out << collectionItems[i];
			}
			return out;
		}

		friend std::ostream& operator<<(std::ostream& out, Collection& coll)
		{
			return coll.print(out);
		}
	};
}

#endif
