#ifndef MYLAB2_DYNAMICARRAYSEQUENCE_H
#define MYLAB2_DYNAMICARRAYSEQUENCE_H

#include "Sequence.h"
#include "../base/DynamicArray.h"



template <typename T, typename AllocatorT = std::allocator<T>>
        //  AllocatorT is NOT used
class DynamicArraySequence : public Sequence<T, typename DynamicArray<T>::iterator> {
public:
    using SequenceT     = Sequence<T, typename DynamicArray<T>::iterator>;
    using DASequenceT   = DynamicArraySequence<T, AllocatorT>;
    using iterator      = typename DynamicArray<T>::iterator;

    virtual iterator begin() {return m_array->begin();};
    virtual iterator end() {return m_array->end();};

    DynamicArraySequence();
    DynamicArraySequence(int size);
    DynamicArraySequence(T* items, int size);
    DynamicArraySequence(const DASequenceT& another);
    DynamicArraySequence(const DynamicArray<T>& array);


    DASequenceT& operator= (const DASequenceT& another);
    DASequenceT& operator= (DASequenceT* another);

    ~DynamicArraySequence();

    virtual int getSize() const;
    virtual T getItem(int index) const;
    virtual T getFirst() const;
    virtual T getLast() const;

    virtual SequenceT& insert(int index, const T& item);
    virtual SequenceT& remove(int index);
    virtual SequenceT& append(const T& item);
    virtual SequenceT& prepend(const T& item);
    virtual SequenceT& clear();
    SequenceT& pop();
    SequenceT& shift();

    virtual SequenceT* map(T (*function)(const T& item));
    virtual SequenceT* filter(bool (*function)(const T& item));
    virtual SequenceT* getSubSequence(int startIndex, int endIndex) const;
    virtual SequenceT* concat(SequenceT& sequence) const;

    virtual T reduce(T (*function)(const T& previousValue, const T& currentValue));

    T& operator[] (int index);

private:
    DynamicArray<T>* m_array;
};


#include "DynamicArraySequence.inl"

#endif
