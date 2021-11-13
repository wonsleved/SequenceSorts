
#include <algorithm>
#include "Sequence/DynamicArraySequence.h"
#include "Sequence/LinkedListSequence.h"
#include "./Sorts/sorts.h"
#include "./Benchmark/Benchmark.h"
#include "./Testing/SortTester.h"
#include "./SortingMenu/SortingMenu.h"

int main() {
    SortTester<DynamicArraySequence>::test(BubbleSort, 5, 10);
//    sortingMenu();

    return 0;
}

