#include <Windows.h>
#include <iostream>
#include <vector>
#include <list>
#include <set>


template <typename Container>
void print_container(const Container& container)
{
    // итераторы на начало и конец контейнера
    auto it = container.begin();
    auto end = container.end();


    if (it != end)
    {
        std::cout << *it;
        it++;
    }
    for (; it != end; ++it) // it определён, указывает на второй элемент
    {
        std::cout << ", " << *it;
    }
    std::cout << '.' << std::endl;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    std::set<std::string> test_set = { "one", "two", "three", "four" };
    std::list<std::string> test_list = { "one", "two", "three", "four" };
    std::vector<std::string> test_vector = { "one", "two", "three", "four" };

    print_container(test_set);     // four, one, three, two , так как в set сортировка по возрастанию (здесь по алфавиту)
    print_container(test_list);    // one, two, three, four.
    print_container(test_vector);  // one, two, three, four.

    return 0;
}