#ifndef MYLAB2_SORTS_H
#define MYLAB2_SORTS_H

#include "./Secrecy.h"
#include "../Sequence/Sequence.h"

//  Bubble sort

template<typename Iterator, typename Comparator>
void BubbleSort(Iterator begin, Iterator end, Comparator comparator);

template<typename Iterator>
void BubbleSort(Iterator begin, Iterator end);

#include "./BubbleSort.inl"


//  Shaker sort

template<typename Iterator, typename Comparator>
void ShakerSort(Iterator begin, Iterator end, Comparator comparator);

template<typename Iterator>
void ShakerSort(Iterator begin, Iterator end);

#include "./ShakerSort.inl"


//  Insertion sort

template<typename Iterator, typename Comparator>
void InsertionSort(Iterator begin, Iterator end, Comparator comparator);

template<typename Iterator>
void InsertionSort(Iterator begin, Iterator end);

#include "./InsertionSort.inl"


//  Selection sort

template<typename Iterator, typename Comparator>
void SelectionSort(Iterator begin, Iterator end, Comparator comparator);

template<typename Iterator>
void SelectionSort(Iterator begin, Iterator end);

#include "./SelectionSort.inl"


//  Binary Insertion sort

template<typename Iterator, typename Comparator>
void BinaryInsertionSort(Iterator begin, Iterator end, Comparator comparator);

template<typename Iterator>
void BinaryInsertionSort(Iterator begin, Iterator end);

#include "./BinaryInsertionSort.inl"


//  Merge sort

template<typename Iterator, typename Comparator>
void MergeSort(Iterator begin, Iterator end, Comparator comparator);

template<typename Iterator>
void MergeSort(Iterator begin, Iterator end);

#include "./MergeSort.inl"


//  Merge sort

template<typename Iterator, typename Comparator>
void QuickSort(Iterator begin, Iterator end, Comparator comparator);

template<typename Iterator>
void QuickSort(Iterator begin, Iterator end);

#include "./QuickSort.inl"


#endif
