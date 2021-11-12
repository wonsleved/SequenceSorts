#ifndef MYLAB2_DYNAMICARRAY_H
#define MYLAB2_DYNAMICARRAY_H
#include <iterator> // For std::forward_iterator_tag
#include <cstddef>
#include "../dependencies.h"
#include "../Exceptions/Exceptions.h"




template <class T>
class DynamicArray
{
protected:
    T* m_data;
    int m_size;
public:
    class iterator {
    public:
        using iterator_category = std::random_access_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = T;
        using pointer           = T*;
        using reference         = T&;

        explicit iterator(pointer ptr) : m_ptr(ptr) {};

        reference   operator * () const { return *m_ptr; };
        pointer     operator -> () { return m_ptr; };
        iterator&   operator ++ () { m_ptr++; return *this; };
        iterator    operator ++ (T) { iterator tmp = *this; m_ptr++; return tmp; };
        iterator&   operator -- () { m_ptr--; return *this; };
        iterator    operator -- (T) { iterator tmp = *this; m_ptr--; return tmp; };

        iterator operator + (size_t offset) { return iterator(m_ptr + offset); };
        iterator operator - (size_t offset) { return iterator(m_ptr - offset); };

        difference_type operator - (const iterator& iterator) const
        { return m_ptr - iterator.m_ptr; };

        bool operator == (const iterator& iterator)
        { return m_ptr == iterator.m_ptr; };

        bool operator != (const iterator& iterator)
        { return m_ptr != iterator.m_ptr; };

        bool operator < (const iterator& iterator) const
        { return m_ptr < iterator.m_ptr; }

        bool operator <= (const iterator& iterator) const
        { return m_ptr <= iterator.m_ptr; }

        bool operator > (const iterator& iterator) const
        { return m_ptr > iterator.m_ptr; }

        bool operator >= (const iterator& iterator) const
        { return m_ptr >= iterator.m_ptr; }

        iterator& operator=(const iterator&) = default;
    private:
        pointer m_ptr;
    };

    iterator begin();
    iterator end();

    DynamicArray();
    explicit DynamicArray(int size);
    explicit DynamicArray(T* items, int count);
    DynamicArray(const DynamicArray<T>& another);


    DynamicArray<T>& operator= (const DynamicArray<T>& another);
    DynamicArray<T>& operator= (DynamicArray<T>* another);

    ~DynamicArray();

    int getSize() const;
    T getItem(int index) const;
    T getFirst() const;
    T getLast() const;

    DynamicArray<T>& clear();
    DynamicArray<T>& setItem(int index, T item);
    DynamicArray<T>& resize(int size);
    DynamicArray<T>& push(T item);
    DynamicArray<T>& unshift(T item);
    DynamicArray<T>& pop();
    DynamicArray<T>& shift();
    DynamicArray<T>& remove(int index);
    DynamicArray<T>& insert(int index, const T& item);
    DynamicArray<T>* map(T (*function)(const T& item)) const;
    DynamicArray<T>* filter(bool (*function)(const T& item)) const;
    DynamicArray<T>* concat(const DynamicArray<T>& array) const;
    DynamicArray<T>* getSubList(int startIndex, int endIndex) const;
    T reduce(T (*function)(const T& previousValue, const T& currentValue)) const;



    T& operator[] (int index);
};



#include "DynamicArray.inl"

#endif
