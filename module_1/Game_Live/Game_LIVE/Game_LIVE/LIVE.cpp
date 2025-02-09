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
	for (int i = 0; i < rows; i++)					// ����������� ��������� �������� � ��������
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

void neighbors(int* n, char** arr, int rows, int column, int i, int j)

{
	//��� ������� ������
	{
		if ((i == 0) && (j == 0))
		{*n = ngbhd_cells_number(arr, 0, i + 1, 0, j + 1, i, j);}	//������� �����

		if ((i == (rows - 1)) && (j == 0))
		{*n = ngbhd_cells_number(arr, i - 1, i, 0, j + 1, i, j);}	//������ �����

		if ((i == 0) && (j == (column - 1)))
		{*n = ngbhd_cells_number(arr, 0, i + 1, j - 1, j, i, j);}	//������� ������

		if ((i == (rows - 1)) && (j == (column - 1)))
		{*n = ngbhd_cells_number(arr, i - 1, i, j - 1, j, i, j);}	//������ ������
	}

	//��� ������ �� ������� ���������
	{
		if ((i == 0) && (j > 0) && (j < (column - 1)))
		{*n = ngbhd_cells_number(arr, 0, i + 1, j - 1, j + 1, i, j);}//������� �������

		if ((j == 0) && (i > 0) && (i < (rows - 1)))
		{*n = ngbhd_cells_number(arr, i - 1, i + 1, 0, j + 1, i, j);}//����� �������

		if ((i == (rows - 1)) && (j > 0) && (j < (column - 1)))
		{*n = ngbhd_cells_number(arr, i - 1, i, j - 1, j + 1, i, j);}//������ �������

		if ((j == (column - 1)) && (i > 0) && (i < (rows - 1)))
		{*n = ngbhd_cells_number(arr, i - 1, i + 1, j - 1, j, i, j);}//������ �������
	}

	//��� ���������� ������
	if ((i > 0) && (i < (rows - 1)) && (j > 0) && (j < (column - 1)))
	{*n = ngbhd_cells_number(arr, i - 1, i + 1, j - 1, j + 1, i, j);}
}

void print_inf(char** arr, int rows, int column, int* gen, int* cells)
{
	print_two_dim_array(arr, rows, column);
	std::cout << "��������� " << *gen << ". ";
	std::cout << "���������� ����� ������: " << *cells << std::endl;
}


int main()
{
	setlocale(LC_ALL, "Rus");


	std::ifstream file("universe.txt");
	std::string s;

	if (file.is_open())
	{
		file >> s;
		int rows = std::stoi(s);

		file >> s;
		int column = std::stoi(s);

		char** UNIV_past = create_array(rows, column);	//�������� ��������� 

		for (int i = 0; i < rows; i++)					// ���������� ��������� ������� ��������
		{
			for (int j = 0; j < column; j++)
			{
				UNIV_past[i][j] = '-';
			}
		}

		while (!file.eof())								// ���������� ��������� ������ ��������
		{
			file >> s;
			int i = std::stoi(s);

			file >> s;
			int j = std::stoi(s);

			UNIV_past[i][j] = '*';
		}

		file.close();									// �������� ����� ������������� ���������
		
		//---------------������������� ��������� ���������-----------------------------------------------//


		char** UNIV_cont = create_array(rows, column);		// �������� ��������� ��������

		copy_arrays(UNIV_past, UNIV_cont, rows, column);	// ��������� ����������� ���������

		print_two_dim_array(UNIV_past, rows, column);		// ����� ������� ���������
		std::cout << "��������� 1. ";
		std::cout << "���������� ����� ������: " << alive_cells_number(UNIV_past, rows, column) << "\n" << std::endl;
		

		if (alive_cells_number(UNIV_past, rows, column) == 0)	// ���� ��������� ������, ���� ����� �������������
		{
			std::cout << "����� ������ ���. ��������� ������.";
		}
		else
		{ 
			bool compare{ 0 };		//��������� ��������� - 1
			int alive_cells{ 0 };	//���������� ����� ������ �� ���������
			int gen{ 1 };			//���������

			while(1)
			{

				for (int i = 0; i < rows; i++)	// ������� � �������� ������ ���������
				{
					for (int j = 0; j < column; j++)
					{
						if (UNIV_past[i][j] == '*') //���� ������ �����
						{
							int ngbhd_cells{ 0 };

							neighbors(&ngbhd_cells, UNIV_past, rows, column, i, j);	//������� �������
														
							if (ngbhd_cells == 2 || ngbhd_cells == 3) { continue; }	//���� � ����� ������ 2 ��� 3 ����� �������, ��� ����
							else { UNIV_cont[i][j] = '-'; }							//�����, �������

						}
						else //���� ������ ������
						{
							int ngbhd_cells{ 0 };

							neighbors(&ngbhd_cells, UNIV_past, rows, column, i, j); //������� �������
														
							if (ngbhd_cells == 3) { UNIV_cont[i][j] = '*'; }		//���� � ������ ������ 3 ����� �������, ��� �������
							else { continue; }										//�����, ��� ������

						}
					}
				}

				gen++;

				alive_cells = alive_cells_number(UNIV_cont, rows, column);		// ������� ����� ������
				if (alive_cells == 0)											// ������� ������ ���������
				{
					print_inf(UNIV_cont, rows, column, &gen, &alive_cells);

					std::cout << "����� ������ ���. ��������� ������.";
					break;
				}

				compare = compare_arrays(UNIV_past, UNIV_cont, rows, column);	// �������� ����������� ���������
				if (compare)													// ������� ���������� ���������
				{				
					print_inf(UNIV_cont, rows, column, &gen, &alive_cells);
					
					std::cout << "��������� ���������. ����� ����.";
					break;
				}

				print_inf(UNIV_cont, rows, column, &gen, &alive_cells);
				std::cout << std::endl;
								
				copy_arrays(UNIV_cont, UNIV_past, rows, column);
			}
		}

		delete_two_dim_array(UNIV_past, rows, column);
		delete_two_dim_array(UNIV_cont, rows, column);
	}
	else { std::cout << "�� ������� ������� ����."; }

	return EXIT_SUCCESS;
}