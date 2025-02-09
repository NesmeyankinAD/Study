#include<iostream>
#include<fstream>
#include<string>
#include<locale.h>

char** create_array(int rows, int column)
{
	char** arr = new char* [rows];

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new char[column];
	}

	return arr;
}

void print_two_dim_array(char** arr, int rows, int column)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < column; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void delete_two_dim_array(char** arr, int rows, int column)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

int alive_cells_number(char** arr, int rows, int column)
{
	int n{0};

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (arr[i][j] == '*') n++;
		}
	}

	return n;
}

void copy_arrays(char** arr1, char** arr2, int rows, int column)
{
	for (int i = 0; i < rows; i++)					// копирование вселенной прошлого и будущего
	{
		for (int j = 0; j < column; j++)
		{
			arr2[i][j] = arr1[i][j];
		}
	}
}

bool compare_arrays(char** arr1, char** arr2, int rows, int column)
{
	bool comp{0};

	for (int i = 0; i < rows; i++)					
	{
		for (int j = 0; j < column; j++)
		{
			if (arr2[i][j] == arr1[i][j]) { comp = true;}
			else 
			{
				comp = false;
				break;
			}
		}

		if (!comp) break;
	}

	return comp;
}

int ngbhd_cells_number(char** arr, int i_min, int i_max, int j_min, int j_max, int i_cell, int j_cell)
{
	int n{ 0 };

	for (int k = i_min; k <= i_max; k++)
	{
		for (int m = j_min; m <= j_max; m++)
		{
			if (k == i_cell && m == j_cell) continue;
			if (arr[k][m] == '*') n++;
		}
	}

	return n;
}


int main()
{
	setlocale(LC_ALL, "Rus");


	std::ifstream file("C:\\Users\\mrsas\\Desktop\\Cpp_Folder\\Game_Live\\Game_LIVE\\universe.txt");
	std::string s;

	if (file.is_open())
	{
		file >> s;
		int rows = std::stoi(s);

		file >> s;
		int column = std::stoi(s);

		char** UNIV_past = create_array(rows, column);	//создание вселенной 

		for (int i = 0; i < rows; i++)					// заполнение вселенной мёртвыми клетками
		{
			for (int j = 0; j < column; j++)
			{
				UNIV_past[i][j] = '-';
			}
		}

		while (!file.eof())								// заполнение вселенной живыми клетками
		{
			file >> s;
			int i = std::stoi(s);

			file >> s;
			int j = std::stoi(s);

			UNIV_past[i][j] = '*';
		}

		file.close();									// закрытие файла инициализации вселенной
		
		//---------------инициализация вселенной завершена-----------------------------------------------//

		char** UNIV_cont = create_array(rows, column);		// создание вселенной будущего

		copy_arrays(UNIV_past, UNIV_cont, rows, column);	// первичное копирование вселенных

		print_two_dim_array(UNIV_past, rows, column);		// вывод первого поколения
		std::cout << "Поколение 1. ";
		std::cout << "Количество живых клеток: " << alive_cells_number(UNIV_past, rows, column) << "\n" << std::endl;
		
		if (alive_cells_number(UNIV_past, rows, column) == 0)	// если вселенная мертва, игра сразу заканчивается
		{
			std::cout << "Живых клеток нет. Вселенная мертва.";
		}
		else
		{
			bool dead{ 0 };			//вселенная мертва, живых клеток нет - 1 
			bool compare{ 0 };		//вселенная устойчива - 1
			int alive_cells{ 0 };	//количество живых клеток во вселенной
			int gen{ 1 };			//поколение

			do
			{

				for (int i = 0; i < rows; i++)	// перебор и проверка клеток вселенной
				{
					for (int j = 0; j < column; j++)
					{

						if (UNIV_past[i][j] == '*') //если клетка живая
						{
							int ngbhd_cells{ 0 };

							//для угловых клеток
							{
								if ((i == 0) && (j == 0)) //верхний левый
								{
									for (int k = 0; k <= i + 1; k++)
									{
										for (int m = 0; m <= j + 1; m++)
										{
											if (k == i && m == j) continue;
											if (UNIV_past[k][m] == '*') ngbhd_cells++;
										}
									}
								}
								if ((i == (rows - 1)) && (j == 0)) //нижний левый
								{
									for (int k = i - 1; k <= i; k++)
									{
										for (int m = 0; m <= j + 1; m++)
										{
											if (k == i && m == j) continue;
											if (UNIV_past[k][m] == '*') ngbhd_cells++;
										}
									}
								}
								if ((i == 0) && (j == (column - 1))) //верхний правый
								{
									for (int k = 0; k <= i + 1; k++)
									{
										for (int m = j - 1; m <= j; m++)
										{
											if (k == i && m == j) continue;
											if (UNIV_past[k][m] == '*') ngbhd_cells++;
										}
									}
								}
								if ((i == (rows - 1)) && (j == (column - 1))) //нижний правый
								{
									for (int k = i - 1; k <= i; k++)
									{
										for (int m = j - 1; m <= j; m++)
										{
											if (k == i && m == j) continue;
											if (UNIV_past[k][m] == '*') ngbhd_cells++;
										}
									}
								}
							}

							//для клеток по границе вселенной
							{
								if ((i == 0) && (j > 0) && (j < (column - 1))) //верхняя граница
								{
									for (int k = 0; k <= i + 1; k++)
									{
										for (int m = j - 1; m <= j + 1; m++)
										{
											if (k == i && m == j) continue;
											if (UNIV_past[k][m] == '*') ngbhd_cells++;
										}
									}
								}

								if ((j == 0) && (i > 0) && (i < (rows - 1))) //левая граница
								{
									for (int k = i - 1; k <= i + 1; k++)
									{
										for (int m = 0; m <= j + 1; m++)
										{
											if (k == i && m == j) continue;
											if (UNIV_past[k][m] == '*') ngbhd_cells++;
										}
									}
								}

								if ((i == (rows - 1)) && (j > 0) && (j < (column - 1))) //нижняя граница
								{
									for (int k = i - 1; k <= i; k++)
									{
										for (int m = j - 1; m <= j + 1; m++)
										{
											if (k == i && m == j) continue;
											if (UNIV_past[k][m] == '*') ngbhd_cells++;
										}
									}
								}

								if ((j == (column - 1)) && (i > 0) && (i < (rows - 1))) //правая граница
								{
									for (int k = i - 1; k <= i + 1; k++)
									{
										for (int m = j - 1; m <= j; m++)
										{
											if (k == i && m == j) continue;
											if (UNIV_past[k][m] == '*') ngbhd_cells++;
										}
									}
								}
							}

							//для внутренних клеток
							if ((i > 0) && (i < (rows - 1)) && (j > 0) && (j < (column - 1)))
							{
								for (int k = i - 1; k <= i + 1; k++)	//подсчёт соседних живых клеток
								{
									for (int m = j - 1; m <= j + 1; m++)
									{
										if (k == i && m == j) continue;
										if (UNIV_past[k][m] == '*') ngbhd_cells++;
									}
								}
							}

							if (ngbhd_cells == 2 || ngbhd_cells == 3) { continue; }	//если у живой клетки 2 или 3 живых соседки, она живёт
							else { UNIV_cont[i][j] = '-'; }							//иначе, умирает

						}
						else //если клетка мёртвая
						{
							int ngbhd_cells{ 0 };

							//для угловых клеток
							{
								if ((i == 0) && (j == 0)) //верхний левый
								{
									for (int k = 0; k <= i + 1; k++)
									{
										for (int m = 0; m <= j + 1; m++)
										{
											if (k == i && m == j) continue;
											if (UNIV_past[k][m] == '*') ngbhd_cells++;
										}
									}
								}
								if ((i == (rows - 1)) && (j == 0)) //нижний левый
								{
									for (int k = i - 1; k <= i; k++)
									{
										for (int m = 0; m <= j + 1; m++)
										{
											if (k == i && m == j) continue;
											if (UNIV_past[k][m] == '*') ngbhd_cells++;
										}
									}
								}
								if ((i == 0) && (j == (column - 1))) //верхний правый
								{
									for (int k = 0; k <= i + 1; k++)
									{
										for (int m = j - 1; m <= j; m++)
										{
											if (k == i && m == j) continue;
											if (UNIV_past[k][m] == '*') ngbhd_cells++;
										}
									}
								}
								if ((i == (rows - 1)) && (j == (column - 1))) //нижний правый
								{
									for (int k = i - 1; k <= i; k++)
									{
										for (int m = j - 1; m <= j; m++)
										{
											if (k == i && m == j) continue;
											if (UNIV_past[k][m] == '*') ngbhd_cells++;
										}
									}
								}
							}

							//для клеток по границе вселенной
							{
								if ((i == 0) && (j > 0) && (j < (column - 1))) //верхняя граница
								{
									for (int k = 0; k <= i + 1; k++)
									{
										for (int m = j - 1; m <= j + 1; m++)
										{
											if (k == i && m == j) continue;
											if (UNIV_past[k][m] == '*') ngbhd_cells++;
										}
									}
								}

								if ((j == 0) && (i > 0) && (i < (rows - 1))) //левая граница
								{
									for (int k = i - 1; k <= i + 1; k++)
									{
										for (int m = 0; m <= j + 1; m++)
										{
											if (k == i && m == j) continue;
											if (UNIV_past[k][m] == '*') ngbhd_cells++;
										}
									}
								}

								if ((i == (rows - 1)) && (j > 0) && (j < (column - 1))) //нижняя граница
								{
									for (int k = i - 1; k <= i; k++)
									{
										for (int m = j - 1; m <= j + 1; m++)
										{
											if (k == i && m == j) continue;
											if (UNIV_past[k][m] == '*') ngbhd_cells++;
										}
									}
								}

								if ((j == (column - 1)) && (i > 0) && (i < (rows - 1))) //правая граница
								{
									for (int k = i - 1; k <= i + 1; k++)
									{
										for (int m = j - 1; m <= j; m++)
										{
											if (k == i && m == j) continue;
											if (UNIV_past[k][m] == '*') ngbhd_cells++;
										}
									}
								}
							}

							//для внутренних клеток
							if ((i > 0) && (i < (rows - 1)) && (j > 0) && (j < (column - 1)))
							{
								for (int k = i - 1; k <= i + 1; k++)	//подсчёт соседних живых клеток
								{
									for (int m = j - 1; m <= j + 1; m++)
									{
										if (k == i && m == j) continue;
										if (UNIV_past[k][m] == '*') ngbhd_cells++;
									}
								}
							}

							if (ngbhd_cells == 3) { UNIV_cont[i][j] = '*'; }	//если у мёртвой клетки 3 живых соседки, она оживает
							else { continue; }									//иначе, она мертва

						}
					}
				}

				alive_cells = alive_cells_number(UNIV_cont, rows, column);		// счётчик живых клеток
				if (alive_cells == 0)											// условие мёртвой вселенной
				{
					dead = true;
					gen++;
					print_two_dim_array(UNIV_cont, rows, column);
					std::cout << "Поколение " << gen << ". ";
					std::cout << "Количество живых клеток: " << alive_cells << std::endl;
					std::cout << "Живых клеток нет. Вселенная мертва.";
					break;
				}

				compare = compare_arrays(UNIV_past, UNIV_cont, rows, column);	// проверка статичности вселенной
				if (compare)													// условие устойчивой вселенной
				{
					gen++;
					print_two_dim_array(UNIV_cont, rows, column);
					std::cout << "Поколение " << gen << ". ";
					std::cout << "Количество живых клеток: " << alive_cells << std::endl;
					std::cout << "Вселенная устойчива. Конец игры.";
					break;
				}


				gen++;
				print_two_dim_array(UNIV_cont, rows, column);
				std::cout << "Поколение " << gen << ". ";
				std::cout << "Количество живых клеток: " << alive_cells << "\n" << std::endl;

				copy_arrays(UNIV_cont, UNIV_past, rows, column);

				//break;		//для отладки

			} while (1);
		}

		delete_two_dim_array(UNIV_past, rows, column);
		delete_two_dim_array(UNIV_cont, rows, column);
	}
	else { std::cout << "Не удалось открыть файл."; }

	return EXIT_SUCCESS;
}