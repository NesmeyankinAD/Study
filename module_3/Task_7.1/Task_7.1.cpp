#include <iostream>
#include <fstream>
#include <Windows.h>


void dfs(int vertex_num, int** adjacency_matrix, bool* visited, int N) 
{
    visited[vertex_num] = true;         
    
    std::cout << vertex_num + 1 << " "; 

    for (int i = 0; i < N; i++)
    {
        if (adjacency_matrix[vertex_num][i] == 1 && !visited[i]) 
        {
            dfs(i, adjacency_matrix, visited, N);
        }
    }
}

int main() 
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    std::ifstream inputFile("graph.txt");
    if (!inputFile.is_open()) 
    {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return 1;
    }

    int N{0};
    inputFile >> N; 

    //Выделение памяти
    int** adjacency_matrix = new int* [N] {};
    bool* visited = new bool[N] {};

    for (int i = 0; i < N; i++)
    {
        adjacency_matrix[i] = new int [N] {};
    }

    //Заполнение матрицы смежности
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
            {inputFile >> adjacency_matrix[i][j];}
    }

    inputFile.close();


    std::cout << "Обход в глубину: ";
    dfs(0, adjacency_matrix, visited, N); std::cout << std::endl;


    //Очистка памяти
    for (int i = 0; i < N; i++)
    {
        delete[] adjacency_matrix[i];
    }
    delete[] adjacency_matrix;

    delete[] visited;


    return EXIT_SUCCESS;
}