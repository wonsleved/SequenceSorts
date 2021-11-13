#ifndef SEQUENCESORTS_SORTINGMENU_H
#define SEQUENCESORTS_SORTINGMENU_H

#include "../Sorts/sorts.h"
#include "../Menu/Menu.h"
#include "../Sequence/DynamicArraySequence.h"
#include <iostream>

using Type = int;
template<typename T>
using Container = DynamicArraySequence<T>;
using ContContainer = Container< Container < Type > >;

void sortingMenu();
Menu getMainMenu(ContContainer& arrContainer);

int getInteger(int min, int max);
int getInteger(int min);
int getInteger();
Type getValue();

#endif
