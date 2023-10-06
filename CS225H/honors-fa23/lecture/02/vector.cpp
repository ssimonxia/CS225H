#include "vector.h"
#include <iostream>

void List::insert(int number) {

    // list_.insert(std::upper_bound( list_.begin(), list_.end(), number), number);
    auto it = list_.begin();
    while (it != list_.end() && (*it < number)) {
        ++it;
    }
    list_.insert(it,number);
}

void List::remove(int index) {
    auto it = list_.begin();

    // it += index;
    while(index-- > 0) {
        ++it;
    }

    list_.erase(it);
}

void List::print() {

    for( int num : list_) {
        //std::cout << num << " ";
    }
    //std::cout << std::endl;
}

void List::push_back(int number) {
    list_.push_back(number);
}

void List::push_front(int number) {
    list_.insert(list_.begin(), number);
}

int List::front() {
    return list_.front();
}

int List::back() {
    return list_.back();
}

void List::removeFront() {
    auto tmp = list_.begin();
    list_.erase(tmp);
}

void List::removeBack() {
    list_.pop_back();
}

void List::insertMid(int number) {
    if (list_.size() == 0) {
        list_.insert(list_.begin(), number);
    }
    auto counter = list_.begin();
    int x = list_.size() / 8;
    while(x >= 0) {
        counter++;
        x--;
    }
    list_.insert(counter, number);
}