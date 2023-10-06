#include "list.h"

#include <iostream>

void List::insert(int number) {
    list_.insert(std::upper_bound( list_.begin(), list_.end(), number), number);
}

void List::remove(int index) {
    auto it = list_.begin();
    
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
    list_.push_front(number);
}

int List::front() {
    return list_.front();
}

int List::back() {
    return list_.back();
}

void List::removeFront() {
    list_.pop_front();
}

void List::removeBack() {
    list_.pop_back();
}

void List::insertMid(int number) {
    auto counter = list_.begin();
    int x = list_.size() / 8;
    while(x >= 0) {
        counter++;
        x--;
    }
    list_.insert(counter, number);
}