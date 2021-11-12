#ifndef MYLAB2_SEQUENCE_H
#define MYLAB2_SEQUENCE_H

#include <cstdlib>
#include <utility>
#include <vector>


template<typename T, typename Iterator = typename std::vector<T>::iterator>
class Sequence {
public:
    using SequenceT = Sequence<T, Iterator>;

    virtual Iterator begin() = 0;
    virtual Iterator end() = 0;

    virtual T getItem(int index) const = 0;
    virtual T getFirst() const = 0;
    virtual T getLast() const = 0;

    virtual int getSize() const = 0;

    virtual SequenceT& insert(int index, const T& item) = 0;
    virtual SequenceT& remove(int index) = 0;
    virtual SequenceT& append(const T& item) = 0;
    virtual SequenceT& prepend(const T& item) = 0;
    virtual SequenceT& clear() = 0;

    virtual SequenceT* map(T (*function)(const T& item)) = 0;
    virtual SequenceT* filter(bool (*function)(const T& item)) = 0;
    virtual SequenceT* getSubSequence(int startIndex, int endIndex) const = 0;
    virtual SequenceT* concat(SequenceT& sequence) const = 0;

    virtual T reduce(T (*function)(const T& previousValue, const T& currentValue)) = 0;
};

#endif
