#include "Header.h"

template<class T>
Matrix<T>::Matrix()
{
	arr = nullptr;
	this->line = 0;
	this->column = 0;
}

template<class T>
Matrix<T>::Matrix(int line, int column)
{
	this->line = line;
	this->column = column;

	arr = new T * [line];

	for (int i = 0; i < line; i++)
	{
		arr[i] = new T[column];
	}
}

template<class T>
Matrix<T>::~Matrix()
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

template<class T>
Matrix<T>::Matrix(const Matrix& temp)
{
	this->line = temp.line;
	this->column = temp.column;
	this->arr = new T * [line];

	for (int i = 0; i < line; i++)
	{
		this->arr[i] = new T[column];
	}

	for (int i = 0; i < line; i++) {
		for (int j = 0; j < column; j++) {
			this->arr[i][j] = temp.arr[i][j];
		}
	}
}

template<class T>
bool Matrix<T>::operator==(const Matrix& temp)
{
	if (line == temp.line && column == temp.column)
	{
		for (int i = 0; i < line; i++)
		{
			for (int j = 0; j < column; j++)
			{
				if (arr[i][j] != temp.arr[i][j])
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

template<class T>
Matrix<T> Matrix<T>::operator=(const Matrix& temp)
{
	if (arr == nullptr)
	{
		this->line = temp.line;
		this->column = temp.column;
		this->arr = new T * [line];

		for (int i = 0; i < line; i++)
		{
			this->arr[i] = new T[column];
		}

		for (int i = 0; i < line; i++) {
			for (int j = 0; j < column; j++) {
				this->arr[i][j] = temp.arr[i][j];
			}
		}
		return*this;
	}
	else
	{
		for (int i = 0; i < line; i++)
		{
			delete[] arr[i];
		}

		delete[] arr;

		this->line = temp.line;
		this->column = temp.column;
		this->arr = new T * [line];

		for (int i = 0; i < line; i++)
		{
			this->arr[i] = new T[column];
		}

		for (int i = 0; i < line; i++) {
			for (int j = 0; j < column; j++) {
				this->arr[i][j] = temp.arr[i][j];
			}
		}
		return*this;
	}
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix& temp)
{
	if (line == temp.line && column == temp.column)
	{
		Matrix temp(line, column);
		for (int i = 0; i < line; i++)
		{
			for (int j = 0; j < column; j++)
			{
				temp.arr[i][j] = this->arr[i][j] + temp.arr[i][j];
			}
		}
		return temp;
	}
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix& temp)
{
	if (line == temp.line && column == temp.column)
	{
		Matrix temp(line, column);
		for (int i = 0; i < line; i++)
		{
			for (int j = 0; j < column; j++)
			{
				temp.arr[i][j] = this->arr[i][j] - temp.arr[i][j];
			}
		}
		return temp;
	}
}

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix& temp)
{
	if (column == temp.line)
	{
		Matrix temp(line, temp.column);

		for (int i = 0; i < line; i++)
		{
			for (int j = 0; j < temp.column; j++)
			{
				temp.arr[i][j] = 0;
			}
		}

		for (int j = 0; j < temp.column; j++)
		{
			for (int l = 0; l < line; l++)
			{
				for (int k = 0; k < column; k++)
				{
					temp.arr[l][j] = temp.arr[l][j] + this->arr[l][k] * temp.arr[k][j];
				}
			}
		}

		return temp;
	}
}

template<class T>
Vector<T>::Vector(int size)
{
	Size = size;
	vector = new T[Size];
	for (int i = 0; i < Size; i++)
	{
		vector[i] = 0;
	}
}

template<class T>
Vector<T>::~Vector()
{
	delete[] vector;
}

template<class T>
Vector<T>::Vector(const Vector& temp)
{
	Size = temp.Size;
	vector = new T[Size];
	for (int i = 0; i < Size; i++)
	{
		vector[i] = temp.vector[i];
	}
}

template<class T>
bool Vector<T>::operator==(const Vector& temp)
{
	if (Size == temp.Size)
	{
		for (int i = 0; i < Size; i++)
		{
			if (vector[i] != temp.vector[i])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
Vector<T> Vector<T>::operator=(const Vector& temp)
{
	if (this != &temp)
	{
		delete[] vector;
		Size = temp.Size;
		vector = new T[Size];
		for (int i = 0; i < Size; i++)
		{
			vector[i] = temp.vector[i];
		}
	}
	return *this;
}

template<class T>
Vector<T> Vector<T>::operator+(const T& temp)
{
	Vector temp(Size);
	for (int i = 0; i < Size; i++)
	{
		temp.vector[i] = temp + vector[i];
	}
	return temp;
}

template<class T>
Vector<T> Vector<T>::operator-(const T& temp)
{
	Vector temp(Size);
	for (int i = 0; i < Size; i++)
	{
		temp.vector[i] = vector[i] - temp;
	}
	return temp;
}

template<class T>
Vector<T> Vector<T>::operator*(const T& temp)
{
	Vector temp(Size);
	for (int i = 0; i < Size; i++)
	{
		temp.vector[i] = vector[i] * temp;
	}
	return temp;
}

template<class T>
Vector<T> Vector<T>::operator+(const Vector& temp)
{
	if (Size == temp.Size)
	{
		Vector temp(Size);
		for (int i = 0; i < Size; i++)
		{
			temp.vector[i] = vector[i] + temp.vector[i];
		}
		return temp;
	}
	else
	{
		cout << "size != temp.size" << endl;
		return Vector();
	}
}

template<class T>
Vector<T> Vector<T>::operator-(const Vector& temp)
{
	if (Size == temp.Size)
	{
		Vector temp(Size);
		for (int i = 0; i < Size; i++)
		{
			temp.vector[i] = vector[i] - temp.vector[i];
		}
		return temp;
	}
	else
	{
		cout << "size != temp.size" << endl;
		return Vector();
	}
}

template<class T>
Vector<T> Vector<T>::operator*(const Vector& temp)
{
	if (Size == temp.Size)
	{
		Vector temp(Size);
		for (int i = 0; i < Size; i++)
		{
			temp.vector[i] = vector[i] * temp.vector[i];
		}
		return temp;
	}
	else
	{
		cout << "size != temp.size" << endl;
		return Vector();
	}
}

template<class T>
T& Vector<T>::operator[](int index)
{
	if (index < Size && index > -1)
	{
		return vector[index];
	}
	else
	{
		cout << "size != temp.size" << endl;
		//return T();
	}
}



