#include <iostream>
#include <cassert>
#include "singlelist.hpp"

int main() {
    SingleList<int> list1;
    assert(list1.empty() == true);
    assert(list1.size() == 0);

    list1.push_front(10);
    assert(list1.empty() == false);
    assert(list1.size() == 1);
    assert(list1.front() == 10);
    assert(list1.back() == 10);

    list1.push_front(20);
    assert(list1.size() == 2);
    assert(list1.front() == 20);
    assert(list1.back() == 10);

    list1.push_back(30);
    assert(list1.size() == 3);
    assert(list1.front() == 20);
    assert(list1.back() == 30);

    list1.pop_front();
    assert(list1.size() == 2);
    assert(list1.front() == 10);
    assert(list1.back() == 30);

    list1.pop_back();
    assert(list1.size() == 1);
    assert(list1.front() == 10);
    assert(list1.back() == 10);

    list1.clear();
    assert(list1.empty() == true);
    assert(list1.size() == 0);

    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    SingleList<int> list2(list1);
    assert(list2.size() == 3);
    assert(list2.front() == 1);
    assert(list2.back() == 3);

    SingleList<int> list3;
    list3 = list1;
    assert(list3.size() == 3);
    assert(list3.front() == 1);
    assert(list3.back() == 3);

    std::cout << "Wszystkie testy zakonczone sukcesem!" << std::endl;
    return 0;
}