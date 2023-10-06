#include <vector>

class List {
private:
    std::vector<int> list_;
public:
    void insert(int number);
    void remove(int index);
    void print();
    void push_back(int number);
    void push_front(int number);
    int front();
    int back();
    void removeFront();
    void removeBack();
    void insertMid(int number);
};
