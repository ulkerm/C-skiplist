#include <iostream>
#include "Skipset.h"

void testSkipSet() {
    skip_set<int> skipSet;
    skipSet.insert(3);
    skipSet.insert(6);
    skipSet.insert(2);
    skipSet.insert(5);
    skipSet.insert(8);

    std::cout << "Skip; List: \n" << skipSet << std::endl;
    std::cout << "Is 5 in the set? " << std::boolalpha << skipSet.find(5) << std::endl;
    skipSet.erase(5);
    std::cout << "Skip List after removal: \n" << skipSet << std::endl;
    std::cout << "Is 5 in the set? " << std::boolalpha << skipSet.find(5) << "\n" << std::endl;
}

void testWithRandom() {
    skip_set<int> skipSet;
    int count = 15;
    int seed = 30;
    for (int i = 0; i < count; i++)
        skipSet.insert(rand() % seed);
    std::cout << "Skip; List: \n" << skipSet << std::endl;
    std::cout << "Is 7 in the set? " << std::boolalpha << skipSet.find(7) << std::endl;
    skipSet.erase(7);
    std::cout << "Skip List after removal: \n" << skipSet << std::endl;
    std::cout << "Is 7 in the set? " << std::boolalpha << skipSet.find(7) << "\n" << std::endl;
}

int main() {
    testSkipSet();
    testWithRandom();
    return 0;
}
