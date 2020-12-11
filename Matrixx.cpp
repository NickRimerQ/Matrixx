#include "Header.h"


Matrix::Matrix(int line_, int column_)
{
	line = line_;
	column = column_;

	arr = new long int* [line];

	for (int i = 0; i < line; i++)
	{
		arr[i] = new long int[column];
	}
}


Matrix::~Matrix()
{
	if (arr != nullptr)
	{
		for (int i = 0; i < line; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
	}
}


Matrix::Matrix(const Matrix& other)
{
	line = other.line;
	column = other.column;
	arr = new long int* [line];

	for (int i = 0; i < line; i++)
	{
		arr[i] = new long int[column];
	}

	for (int i = 0; i < line; i++) {
		for (int j = 0; j < column; j++) {
			arr[i][j] = other.arr[i][j];
		}
	}
}


Matrix& Matrix::operator = (const Matrix& other)
{
	for (int i = 0; i < line; i++)
	{
		delete[] arr[i];
	}

	delete[] arr;

	line = other.line;
	column = other.column;
	arr = new long int* [line];

	for (int i = 0; i < line; i++)
	{
		this->arr[i] = new long int[column];
	}

	for (int i = 0; i < line; i++) {
		for (int j = 0; j < column; j++) {
			this->arr[i][j] = other.arr[i][j];
		}
	}
	return*this;
	
}

Matrix Matrix::operator + (const Matrix& other)
{
	if (line == other.line && column == other.column)
	{
		Matrix temp(line, column);
		for (int i = 0; i < line; i++)
		{
			for (int j = 0; j < column; j++)
			{
				temp.arr[i][j] = arr[i][j] + other.arr[i][j];
			}
		}
		return temp;
	}
}

Matrix Matrix::operator - (const Matrix& other)
{
	if (line == other.line && column == other.column)
	{
		Matrix temp(line, column);
		for (int i = 0; i < line; i++)
		{
			for (int j = 0; j < column; j++)
			{
				temp.arr[i][j] = arr[i][j] - other.arr[i][j];
			}
		}
		return temp;
	}
}

Matrix Matrix::operator * (const Matrix& other)
{

	if (column == other.line)
	{
		Matrix temp(line, other.column);

		for (int i = 0; i < line; i++)
		{
			for (int j = 0; j < other.column; j++)
			{
				temp.arr[i][j] = 0;
			}
		}

		for (int j = 0; j < other.column; j++)
		{
			for (int l = 0; l < line; l++)
			{
				for (int k = 0; k < column; k++)
				{
					temp.arr[l][j] = temp.arr[l][j] + arr[l][k] * other.arr[k][j];
				}
			}
		}
		return temp;
	}
}

Matrix Matrix::operator * (const int other)
{
	Matrix temp(*this);
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			temp.arr[i][j] = temp.arr[i][j] * other;
		}
	}
	return temp;
}

bool Matrix::operator == (const Matrix& other)
{
	if (line == other.line && column == other.column)
	{
		for (int i = 0; i < line; i++)
		{
			for (int j = 0; j < column; j++)
			{
				if (arr[i][j] != other.arr[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool Matrix::operator != (const Matrix& other)
{
	return !(operator==(other));
}




void Matrix::filling()
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			arr[i][j] = i + j;
		}
	}
}

void Matrix::print()
{
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < column; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

