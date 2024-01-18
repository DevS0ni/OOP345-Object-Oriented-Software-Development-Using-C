/**********************************************************************************************************************************
				Workshop - 3 (Part-2)
Full Name  : Dev Soni

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************************************************************************/

#ifndef SDDS_ORDEREDCOLLECTION_H
#define SDDS_ORDEREDCOLLECTION_H
#include <iostream>
#include "Collection.h"
namespace sdds {
    template<typename T>
    class OrderedCollection : public Collection<T, 72> {
    public:
        virtual bool operator+=(const T& newThing) {
            bool flag = Collection<T, 72>::operator+=(newThing);
            for (unsigned i = 0; i < Collection<T, 72>::size() - 1; i++) {
                for (unsigned j = 0; j < Collection<T, 72>::size() - i - 1; j++) {
                    if (Collection<T, 72>::operator[](j) > Collection<T, 72>::operator[](j + 1)) {
                        T temp = Collection<T, 72>::operator[](j);
                        Collection<T, 72>::operator[](j) = Collection<T, 72>::operator[](j + 1);
                        Collection<T, 72>::operator[](j + 1) = temp;
                    }
                }
                flag = true;
            }
            return flag;
        }
    };
}

#endif 