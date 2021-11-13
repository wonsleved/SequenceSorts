#include "SortingMenu.h"



void sortingMenu() {
    ContContainer arrayContainer;
    Menu mainMenu = getMainMenu(arrayContainer);
    mainMenu.chooseOption();
}

Menu getMainMenu(ContContainer& arrContainer) {
    Menu menu;
    menu.addOption("Add new data",[&arrContainer]() {
        std::cout << std::endl;
        Container<Type> container;
        int size;
        std::cout << "\tEnter size: ";
        size = getInteger(0);
        Type value;
        for (int i = 0; i < size; ++i) {
            std::cout << "\t" << i + 1 << ": ";
            value = getValue();
            container.append(value);
        }
        arrContainer.append(container);
        std::cout << "\tADDED" << std::endl;
        std::cout << std::endl;
    });
    menu.addOption("Remove data", [&arrContainer]() {
        std::cout << std::endl;
        if (arrContainer.getSize() == 0) {
            std::cout << "\tThere is no data" << std::endl;
        } else {
            std::cout << "\tEnter ID(-1 to exit): ";
            int index = getInteger(-1, arrContainer.getSize() - 1);
            if (index != -1) {
                arrContainer.remove(index);
                std::cout << "\tREMOVED" << std::endl;
            }
        }
        std::cout << std::endl;
    });
    menu.addOption("Show all data", [&arrContainer]() {
        std::cout << std::endl;
        if (arrContainer.getSize() == 0)
            std::cout << "\tThere is no data" << std::endl;

        ContContainer::iterator mainIt = arrContainer.begin();
        while(mainIt != arrContainer.end()) {
            Container<Type>::iterator it = (*mainIt).begin();
            Container<Type>::iterator endIt = (*mainIt).end();

            std::cout << "\tID " << mainIt - arrContainer.begin() << ": [ ";
            while (it != endIt) {
                std::cout << *it << ((it + 1 == endIt) ? " " : ", ");
                ++it;
            }
            std::cout << "]" << std::endl;
            ++mainIt;
        }
        std::cout << std::endl;
    });
    menu.addOption("Sort data", [&arrContainer]() {
        std::cout << std::endl;
        if (arrContainer.getSize() == 0)
            std::cout << "\tThere is no data" << std::endl;
        else {
            std::cout << "\tEnter ID(-1 to exit): ";
            int index = getInteger(-1, arrContainer.getSize() - 1);
            if (index != -1) {
                Menu replMenu = replaceWithSortedDataMenu( *(arrContainer.begin() + index));
                replMenu.chooseSingleOption();
            }
        }
        std::cout << std::endl;
    });
    menu.addOption("Test algorithm with random data", []() {
        std::cout << std::endl;
        std::cout << "Choose algorithm to test" << std::endl;
        Menu algTestMenu = testSortAlgorithmMenu();
        algTestMenu.chooseSingleOption();
        std::cout << std::endl;
    });
    menu.addOption("Compare algorithms", []() {
        std::cout << std::endl;
        std::cout << "\tEnter size of each container: ";
        int size = getInteger(0);
        std::cout << "\tEnter amount of tests: ";
        int amount = getInteger(0);

        std::cout << std::endl;
        Menu compSortsMenu = compareSortsMenu(size, amount);
        compSortsMenu.displayMenu();
        compSortsMenu.chooseOption(false);
        std::cout << std::endl;
    });



    return menu;
}

Menu chooseSortAlgorithmMenu(Container<Type>& container) {
    Menu chooseSortAlgorithm;
    chooseSortAlgorithm.addOption("BubbleSort", [&container](){
        BubbleSort(container.begin(), container.end());
    });
    chooseSortAlgorithm.addOption("ShakerSort", [&container](){
        ShakerSort(container.begin(), container.end());
    });
    chooseSortAlgorithm.addOption("InsertionSort", [&container](){
        InsertionSort(container.begin(), container.end());
    });
    chooseSortAlgorithm.addOption("SelectionSort", [&container](){
        SelectionSort(container.begin(), container.end());
    });
    chooseSortAlgorithm.addOption("BinaryInsertionSort", [&container](){
        BinaryInsertionSort(container.begin(), container.end());
    });
    chooseSortAlgorithm.addOption("MergeSort", [&container](){
        MergeSort(container.begin(), container.end());
    });
    chooseSortAlgorithm.addOption("QuickSort", [&container](){
        QuickSort(container.begin(), container.end());
    });
    return chooseSortAlgorithm;
}

Menu replaceWithSortedDataMenu(Container<Type>& container) {
    Menu replaceDataMenu;

    replaceDataMenu.addOption("Replace data", [&container](){
        Menu chooseSortingAlgorithm = chooseSortAlgorithmMenu(container);
        chooseSortingAlgorithm.chooseSingleOption();
        std::cout << std::endl;
        std::cout <<  "\t[ ";
        Container<Type>::iterator it = container.begin();
        Container<Type>::iterator endIt = container.end();
        while (it != endIt) {
            std::cout << *it << ((it + 1 == endIt) ? " " : ", ");
            ++it;
        }
        std::cout << "]" << std::endl;
    });
    replaceDataMenu.addOption("DON`T replace data", [&container](){
        Container<Type> containerCopy = container;
        Menu chooseSortingAlgorithm = chooseSortAlgorithmMenu(containerCopy);
        chooseSortingAlgorithm.chooseSingleOption();
        std::cout << std::endl;
        std::cout <<  "\t[ ";
        Container<Type>::iterator it = containerCopy.begin();
        Container<Type>::iterator endIt = containerCopy.end();
        while (it != endIt) {
            std::cout << *it << ((it + 1 == endIt) ? " " : ", ");
            ++it;
        }
        std::cout << "]" << std::endl;
    });
    return replaceDataMenu;
}

Menu testSortAlgorithmMenu() {
    Menu chooseSortAlgorithm;
    chooseSortAlgorithm.addOption("BubbleSort", [](){
        test(BubbleSort);
    });
    chooseSortAlgorithm.addOption("ShakerSort", [](){
        test(ShakerSort);
    });
    chooseSortAlgorithm.addOption("InsertionSort", [](){
        test(InsertionSort);
    });
    chooseSortAlgorithm.addOption("SelectionSort", [](){
        test(SelectionSort);
    });
    chooseSortAlgorithm.addOption("BinaryInsertionSort", [](){
        test(BinaryInsertionSort);
    });
    chooseSortAlgorithm.addOption("MergeSort", [](){
        test(MergeSort);
    });
    chooseSortAlgorithm.addOption("QuickSort", [](){
        test(QuickSort);
    });
    chooseSortAlgorithm.addOption("Test All", [](){
        std::cout << "\tEnter size of each container: ";
        int size = getInteger(0);
        std::cout << "\tEnter amount of tests: ";
        int amount = getInteger(0);

        std::cout << "BubbleSort" << std::endl;
        SortTester<Container>::test(BubbleSort, size, amount);

        std::cout << "ShakerSort" << std::endl;
        SortTester<Container>::test(ShakerSort, size, amount);


        std::cout << "InsertionSort" << std::endl;
        SortTester<Container>::test(InsertionSort, size, amount);


        std::cout << "SelectionSort" << std::endl;
        SortTester<Container>::test(SelectionSort, size, amount);


        std::cout << "BinaryInsertionSort" << std::endl;
        SortTester<Container>::test(BinaryInsertionSort, size, amount);


        std::cout << "MergeSort" << std::endl;
        SortTester<Container>::test(MergeSort, size, amount);


        std::cout << "QuickSort" << std::endl;
        SortTester<Container>::test(QuickSort, size, amount);

    });
    return chooseSortAlgorithm;
}

void test(sort_function sort) {
    std::cout << "\tEnter size of each container: ";
    int size = getInteger(0);
    std::cout << "\tEnter amount of tests: ";
    int amount = getInteger(0);
    SortTester<Container>::test(sort, size, amount);
}





int getInteger(int min, int max) {
    int num;
    bool isBad = true;
    do {
        std::cin >> num;

        // Обрабатываем случай, когда пользователь ввел нецелочисленное значение
        if (std::cin.fail())
        {
            std::cerr << "Enter correct number" << std::endl;
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            isBad = true;
            continue; // этот continue может показаться здесь лишним, но он явно указывает на готовность прекратить выполнение этой итерации цикла
        }
        else if ((num < min || num > max))
        {
            std::cerr << "Enter number from " << min << " to " << max << std::endl;
            isBad = true;
        } else {
            isBad = false;
        }
    } while (isBad);
    std::cin.ignore(32767,'\n');
    return num;
}
int getInteger(int min) {
    int num;
    bool isBad = true;
    do {
        std::cin >> num;

        // Обрабатываем случай, когда пользователь ввел нецелочисленное значение
        if (std::cin.fail())
        {
            std::cerr << "Enter correct number" << std::endl;
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            isBad = true;
            continue; // этот continue может показаться здесь лишним, но он явно указывает на готовность прекратить выполнение этой итерации цикла
        }
        else if (num < min)
        {
            std::cerr << "Enter number not less than " << min << std::endl;
            isBad = true;
        } else {
            isBad = false;
        }
    } while (isBad);
    std::cin.ignore(32767,'\n');
    return num;
}
int getInteger() {
    int num;
    bool isBad = true;
    do {
        std::cin >> num;
        if (std::cin.fail())
        {
            std::cerr << "Enter correct number" << std::endl;
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            isBad = true;
            continue;
        }
        else {
            isBad = false;
        }
    } while (isBad);
    std::cin.ignore(32767,'\n');
    return num;
}
Type getValue() {
    Type value;
    bool isBad = true;
    do {
        std::cin >> value;
        if (std::cin.fail())
        {
            std::cerr << "Enter correct value" << std::endl;
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            isBad = true;
            continue;
        }
        else {
            isBad = false;
        }
    } while (isBad);
    std::cin.ignore(32767,'\n');
    return value;
}


Menu compareSortsMenu(int size, int amount) {
    Menu compareSortsMenu;

    compareSortsMenu.addOption("BubbleSort", [size, amount](){
        double ms = Benchmark<Container>::benchmark(BubbleSort, size, amount);
        std::cout << "\tBubbleSort: " << ms << " ms" << std::endl;
    });
    compareSortsMenu.addOption("ShakerSort", [size, amount](){
        double ms = Benchmark<Container>::benchmark(ShakerSort, size, amount);
        std::cout << "\tShakerSort: " << ms << " ms" << std::endl;
    });
    compareSortsMenu.addOption("InsertionSort", [size, amount](){
        double ms = Benchmark<Container>::benchmark(InsertionSort, size, amount);
        std::cout << "\tInsertionSort: " << ms << " ms" << std::endl;
    });
    compareSortsMenu.addOption("SelectionSort", [size, amount](){
        double ms = Benchmark<Container>::benchmark(SelectionSort, size, amount);
        std::cout << "\tSelectionSort: " << ms << " ms" << std::endl;
    });
    compareSortsMenu.addOption("BinaryInsertionSort", [size, amount](){
        double ms = Benchmark<Container>::benchmark(BinaryInsertionSort, size, amount);
        std::cout << "\tBinaryInsertionSort: " << ms << " ms" << std::endl;
    });
    compareSortsMenu.addOption("MergeSort", [size, amount](){
        double ms = Benchmark<Container>::benchmark(MergeSort, size, amount);
        std::cout << "\tMergeSort: " << ms << " ms" << std::endl;
    });
    compareSortsMenu.addOption("QuickSort", [size, amount](){
        double ms = Benchmark<Container>::benchmark(QuickSort, size, amount);
        std::cout << "\tQuickSort: " << ms << " ms" << std::endl;
    });
    compareSortsMenu.addOption("Test All", [size, amount](){
        double ms;

        ms = Benchmark<Container>::benchmark(BubbleSort, size, amount);
        std::cout << "\tBubbleSort:\t\t\t\t" << ms << " ms" << std::endl;

        ms = Benchmark<Container>::benchmark(ShakerSort, size, amount);
        std::cout << "\tShakerSort:\t\t\t\t" << ms << " ms" << std::endl;

        ms = Benchmark<Container>::benchmark(InsertionSort, size, amount);
        std::cout << "\tInsertionSort:\t\t\t" << ms << " ms" << std::endl;

        ms = Benchmark<Container>::benchmark(SelectionSort, size, amount);
        std::cout << "\tSelectionSort:\t\t\t" << ms << " ms" << std::endl;

        ms = Benchmark<Container>::benchmark(BinaryInsertionSort, size, amount);
        std::cout << "\tBinaryInsertionSort:\t" << ms << " ms" << std::endl;

        ms = Benchmark<Container>::benchmark(MergeSort, size, amount);
        std::cout << "\tMergeSort:\t\t\t\t" << ms << " ms" << std::endl;

        ms = Benchmark<Container>::benchmark(QuickSort, size, amount);
        std::cout << "\tQuickSort:\t\t\t\t" << ms << " ms" << std::endl;

    });
    return compareSortsMenu;
}