#ifndef MYLAB2_BENCHMARK_H
#define MYLAB2_BENCHMARK_H

#include <random>
#include <algorithm>
#include <memory>
#include "Timer.h"

template <template <typename T, typename AllocatorT = std::allocator<T>> class ContainerT>
class Benchmark
{
    using Type = int;
    using MS = double;
    using Iterator = typename ContainerT<Type>::iterator;
    typedef void (*sort_function)(Iterator, Iterator);

public:
    static MS benchmark( sort_function sort, size_t dataSize, size_t testsCount )
    {
        Timer timer;
        MS totalTime = 0;
        for( size_t round = 0; round < testsCount; ++round )
        {
            ContainerT< Type > data( (int) dataSize );
            std::default_random_engine generator;
            std::generate( data.begin(), data.end(), generator );
            std::shuffle( data.begin(), data.end() , std::mt19937(std::random_device()()));

            timer.start();
            sort( data.begin(), data.end() );
            timer.stop();
            totalTime += timer.getElapsedTimeInMs() * 1000;
        }

        return testsCount == 0 ? 0 : totalTime / (double ) testsCount;
    }

private:
    Benchmark() = default;
    ~Benchmark() = default;
};


#endif
