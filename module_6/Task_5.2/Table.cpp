#include <Windows.h>
#include <iostream>
#include <vector>


template<typename T>
class Table
{
public:
    // Внутренний класс для строки таблицы со своими операторами []
    class Row
    {
    private:
        std::vector<T>& data;

    public:
        Row(std::vector<T>& rowData) : data(rowData) {}

        // Неконстантный оператор []
        // обращение по элементу строки
        T& operator[](size_t col)
        {
            return data[col];
        }

        // Константный оператор []
        // возврат элемента строки
        const T& operator[](size_t col) const
        {
            return data[col];
        }

    };

private:
    size_t nRows, nCols;
    std::vector<std::vector<T>> data; // двумерный массив

public:
    // Конструктор
    Table(size_t rows, size_t cols) : nRows(rows), nCols(cols), data(rows, std::vector<T>(cols)) {}

    // Неконстантный оператор []
    // обращение по элементу таблицы [][]
    Row operator[](size_t rowIndex)
    {
        return Row(data[rowIndex]);
    }

    // Константный оператор []
    // возврат элемента таблицы [][]
    const Row operator[](size_t rowIndex) const
    {
        return Row(const_cast<std::vector<T>&>(data[rowIndex]));
    }

    // Функция Size() возвращает размеры таблицы
    std::pair<size_t, size_t> Size() const
    {
        return { nRows, nCols };
    }
};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);


    Table<int> table(3, 4); // 3 строки, 4 столбца

    // Заполняем таблицу
    int n{ 0 };

    for (size_t i = 0; i < 3; ++i)
    {
        for (size_t j = 0; j < 4; ++j)
        {
            table[i][j] = static_cast<int>(n);

            n++;
        }
    }

    // Выводим значения
    for (size_t i = 0; i < 3; ++i)
    {
        for (size_t j = 0; j < 4; ++j)
        {
            std::cout << table[i][j] << '\t';
        }
        std::cout << std::endl;
    }

    // Проверка Size()
    auto size = table.Size();
    std::cout << "Размеры таблицы: " << size.first << " строк, " << size.second << " столбцов" << std::endl;

    return 0;
}