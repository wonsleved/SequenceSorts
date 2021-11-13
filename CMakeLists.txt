cmake_minimum_required(VERSION 3.20)
project(SequenceSorts)

set(CMAKE_CXX_STANDARD 14)




add_executable(SequenceSorts
        base/DynamicArray.h
        base/DynamicArray.inl
        base/LinkedList.h
        base/LinkedList.inl
        Exceptions/Exceptions.cpp
        Exceptions/Exceptions.h
        Sequence/DynamicArraySequence.h
        Sequence/DynamicArraySequence.inl
        Sequence/LinkedListSequence.h
        Sequence/LinkedListSequence.inl
        Sequence/Sequence.h
        dependencies.h
        main.cpp Sorts/sorts.h
        Sorts/BubbleSort.inl
        Sorts/Secrecy.h
        Sorts/ShakerSort.inl
        Sorts/InsertionSort.inl
        Sorts/BinaryInsertionSort.inl
        Sorts/SelectionSort.inl
        Sorts/MergeSort.inl
        Sorts/QuickSort.inl
        Benchmark/Timer.cpp
        Benchmark/Timer.h
        Benchmark/Benchmark.h
        Testing/SortTester.h
        Menu/Menu.cpp
        Menu/Menu.h
        SortingMenu/SortingMenu.cpp
        SortingMenu/SortingMenu.h)
