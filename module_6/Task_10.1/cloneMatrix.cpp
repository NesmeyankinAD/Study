#include <Windows.h>
#include <iostream>
#include <vector>
#include <memory>

class tridiagonal_matrix
{
public:
    std::vector<double> m_down;
    std::vector<double> m_upper;
    std::vector<double> m_middle;

    tridiagonal_matrix( const std::vector<double>& down,
                        const std::vector<double>& upper,
                        const std::vector<double>& middle) :
                        m_down{ down }, m_upper{ upper }, m_middle{ middle } {}

    ~tridiagonal_matrix() { std::cout << "destructor called\n"; }

    
    std::unique_ptr<tridiagonal_matrix> clone() const 
    {
        // —оздаем новую копию текущего объекта через конструктор с теми же параметрами 
        // и возвращаем указатель unique_ptr
        return std::make_unique<tridiagonal_matrix>(m_down, m_upper, m_middle);
    }
};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    auto down = std::vector<double>{ -4.0, 5.0 };
    auto upper = std::vector<double>{ 14.0, 8.0 };
    auto middle = std::vector<double>{ 3.0, 1.0, 7.0 };

    auto matrix = std::make_unique<tridiagonal_matrix>(down, upper, middle);

    auto matrix_clone = matrix->clone();

    // ѕроверка по адресам оригинала и клона матрицы, адреса разные
    std::cout << "matrix adress: " << matrix.get() << std::endl;
    std::cout << "matrix_clone adress: " << matrix_clone.get() << std::endl;

    return 0;
}