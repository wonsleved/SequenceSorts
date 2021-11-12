#ifndef MYLAB2_SORTTESTER_H
#define MYLAB2_SORTTESTER_H


#include <random>
#include <algorithm>
#include <memory>
#include <iostream>

template <template <typename T, typename AllocatorT = std::allocator<T>> class ContainerT>
class SortTester
{
    using Type = int;
    using Iterator = typename ContainerT<Type>::iterator;
    typedef void (*sort_function)(Iterator, Iterator);

public:
    static void test( sort_function sort, size_t dataSize, size_t testsCount )
    {
        bool areEqual = true;
        for( size_t round = 0; round < testsCount && areEqual; ++round )
        {
            ContainerT< Type > initialData( (int) dataSize );
            std::default_random_engine generator;
            std::generate( initialData.begin(), initialData.end(), generator );
            std::shuffle( initialData.begin(), initialData.end() , std::mt19937(std::random_device()()));

            ContainerT< Type > dataForTestingSort( initialData );
            ContainerT< Type > dataForStandardSort( initialData );

            sort( dataForTestingSort.begin(), dataForTestingSort.end() );
            std::sort( dataForStandardSort.begin(), dataForStandardSort.end() );

            Iterator testItBegin = dataForTestingSort.begin();
            Iterator stdItBegin  = dataForStandardSort.begin();

            Iterator testIt = dataForTestingSort.begin();
            Iterator stdIt  = dataForStandardSort.begin();
            Iterator testEndIt = dataForTestingSort.end();
            Iterator stdEndIt  = dataForStandardSort.end();

            areEqual = areItemsEqual(stdItBegin, stdEndIt,
                                     testItBegin, testEndIt);
            if (!areEqual) {
                std::cout << "ERROR at " << round + 1 << "/" << testsCount << std::endl;
                outputFailedTests(  initialData.begin(), initialData.end(),
                                    stdItBegin, stdEndIt,
                                    testItBegin, testEndIt);
            }

        }

        if (areEqual)
            std::cout << "OK! " << testsCount << "/" << testsCount << std::endl;

    }

private:
    static void outputFailedTests(Iterator dataIt, Iterator dataEndIt,
                           Iterator stdIt, Iterator stdEndIt,
                           Iterator testIt, Iterator testEndIt)
    {
        std::cout << "\tInitial data set:\t";
        outputByIterator(dataIt, dataEndIt);
        std::cout << std::endl;

        std::cout << "\tExpected:\t\t\t";
        outputByIterator(stdIt, stdEndIt);
        std::cout << std::endl;

        std::cout << "\tYour:\t\t\t\t";
        outputByIterator(testIt, testEndIt);
        std::cout << std::endl;
    }

    static void outputByIterator(Iterator begin, Iterator end) {
        std::cout << "[ ";
        while (begin != end) {
            std::cout << *begin;
            ++begin;
            if (begin != end)
                std::cout << ", ";
        }
        std::cout << " ]";
    }

    static bool areItemsEqual(Iterator stdIt, Iterator stdEndIt,
                         Iterator testIt, Iterator testEndIt)
    {
        while ( testIt != testEndIt )
        {

            if (*testIt != *stdIt)
                break;

            ++testIt;
            ++stdIt;
        }

        return testIt == testEndIt;
    }

    SortTester() = default;
    ~SortTester() = default;
};



#endif
