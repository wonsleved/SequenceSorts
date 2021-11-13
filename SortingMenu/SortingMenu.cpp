#include "SortingMenu.h"



void sortingMenu() {
    ContContainer arrayContainer;
    Menu mainMenu = getMainMenu(arrayContainer);
    mainMenu.chooseOption();
}

Menu getMainMenu(ContContainer& arrContainer) {
    Menu menu;
    menu.addOption("Add new data",[&arrContainer]() {
        Container<Type> container;
        int size;
        std::cout << "Enter size: ";
        size = getInteger(0);
        Type value;
        for (int i = 0; i < size; ++i) {
            std::cout << i + 1 << ": ";
            value = getValue();
            container.append(value);
//            std::cout << std::endl;
        }
        arrContainer.append(container);
        std::cout << "OK!" << std::endl;
    });
    menu.addOption("Show all data", [&arrContainer]() {
        ContContainer::iterator mainIt = arrContainer.begin();
        while(mainIt != arrContainer.end()) {
            Container<Type>::iterator it = (*mainIt).begin();
            Container<Type>::iterator endIt = (*mainIt).end();

            std::cout << "[ ";
            while (it != endIt) {
                std::cout << *it << " ";
                ++it;
            }
            std::cout << "]" << std::endl;
            ++mainIt;
        }
    });
    return menu;
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
