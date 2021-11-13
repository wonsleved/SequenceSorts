#ifndef SEQUENCESORTS_SORTINGMENU_H
#define SEQUENCESORTS_SORTINGMENU_H

#include "../Sorts/sorts.h"
#include "../Testing/SortTester.h"
#include "../Benchmark/Benchmark.h"
#include "../Menu/Menu.h"
#include "../Sequence/DynamicArraySequence.h"
#include <iostream>

using Type = int;
template<typename T, typename AllocT = std::allocator<T>>
using Container = DynamicArraySequence<T, AllocT>;


using ContContainer = Container< Container < Type > >;

void sortingMenu();
Menu getMainMenu(ContContainer& arrContainer);
Menu chooseSortAlgorithmMenu(Container<Type>& container);
Menu replaceWithSortedDataMenu(Container<Type>& container);
Menu testSortAlgorithmMenu();

typedef void (*sort_function)(Container<int>::iterator, Container<int>::iterator);
void test(sort_function sort);

int getInteger(int min, int max);
int getInteger(int min);
int getInteger();
Type getValue();

#endif
