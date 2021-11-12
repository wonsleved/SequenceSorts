
#include <algorithm>
#include "Sequence/DynamicArraySequence.h"
#include "Sequence/LinkedListSequence.h"
#include "./Sorts/sorts.h"
#include "./Benchmark/Benchmark.h"
#include "./Testing/SortTester.h"

int main() {
    SortTester<DynamicArraySequence>::test(BubbleSort, 5, 10);
    return 0;
}

