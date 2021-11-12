#ifndef MYLAB2_LINKEDLISTSEQUENCE_H
#define MYLAB2_LINKEDLISTSEQUENCE_H

#include "Sequence.h"
#include "../base/LinkedList.h"
template <typename T, typename AllocatorT = std::allocator<T>>
        //  AllocatorT is NOT used
class LinkedListSequence : public Sequence<T, typename LinkedList<T>::iterator> {
public:
    using SequenceT     = Sequence<T, typename LinkedList<T>::iterator>;
    using LLSequenceT   = LinkedListSequence<T, AllocatorT>;
    using iterator      = typename LinkedList<T>::iterator;

    virtual iterator begin() { return m_list->begin();};
    virtual iterator end() { return m_list->end();};


    LinkedListSequence();
    LinkedListSequence(int size);
    LinkedListSequence(T* items, int size);
    LinkedListSequence(const LLSequenceT& another);
    LinkedListSequence(const LinkedList<T>& list);

    LLSequenceT& operator= (const LLSequenceT& another);
    LLSequenceT& operator= (LLSequenceT* another);

    ~LinkedListSequence();

    virtual int getSize() const;
    virtual T getItem(int index) const;
    virtual T getFirst() const;
    virtual T getLast() const;

    virtual SequenceT& insert(int index, const T& item);
    virtual SequenceT& remove(int index);
    virtual SequenceT& append(const T& item);
    virtual SequenceT& prepend(const T& item);
    virtual SequenceT& clear();

    virtual SequenceT* map(T (*function)(const T& item));
    virtual SequenceT* filter(bool (*function)(const T& item));
    virtual SequenceT* getSubSequence(int startIndex, int endIndex) const;
    virtual SequenceT* concat(SequenceT& sequence) const;

    virtual T reduce(T (*function)(const T& previousValue, const T& currentValue));

private:
    LinkedList<T>* m_list;
};


#include "LinkedListSequence.inl"

#endif
