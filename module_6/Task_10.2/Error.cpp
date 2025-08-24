#include <Windows.h>
#include <iostream>
#include <vector>
#include <memory>

class node
{
public:
    int m_value;

    //замена на weak_ptr
    //когда объекты ссылаются друг на друга счётчик не увеличивается
    std::weak_ptr<node> parent; 

    node(int value) : m_value{ value } {};

    ~node() { std::cout << "destructor called\n"; }
};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    auto node1 = std::make_shared<node>(1);

    auto node2 = std::make_shared<node>(2);

    node1->parent = node2;

    node2->parent = node1;
    
    //срабатывают оба деструктора

    return 0;
}
