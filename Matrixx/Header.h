#pragma once
#include <iostream>
using namespace std;


template<class T>
class Vector
{
	T* vector;
	int Size;
public:
	Vector(int size = 2);
	~Vector();
	Vector(const Vector& temp);
	int GetSize()
	{
		return Size;
	}
	bool operator==(const Vector& temp);
	Vector operator=(const Vector& temp);
	Vector operator+(const T& temp);
	Vector operator-(const T& temp);
	Vector operator*(const T& temp);
	Vector operator+(const Vector& temp);
	Vector operator-(const Vector& temp);
	Vector operator*(const Vector& temp);
	friend istream& operator>>(istream& stream, const Vector& temp)
	{
		for (int i = 0; i < temp.Size; i++)
		{
			stream >> temp.vector[i];
		}
		return stream;
	}
	friend ostream& operator<<(ostream& stream, const Vector& temp)
	{
		for (int i = 0; i < temp.Size; i++)
		{
			stream << temp.vector[i] << " ";
		}
		stream << endl;
		return stream;
	}
	T& operator[](int index);
};


template<class T>
class Matrix
{
	T** arr;
	int line;
	int column;
public:
	Matrix();
	Matrix(int line, int column);
	~Matrix();
	Matrix(const Matrix& temp);
	bool operator == (const Matrix& temp);
	Matrix operator = (const Matrix<T>& temp);
	Matrix operator + (const Matrix& temp);
	Matrix operator - (const Matrix& temp);
	Matrix operator * (const Matrix& temp);
	friend istream& operator>>(istream& stream, Matrix& temp)
	{
		if (temp.arr != nullptr)
		{


			for (int i = 0; i < temp.line; i++) {
				for (int j = 0; j < temp.column; j++) {
					stream >> temp.arr[i][j];
				}
			}
			return stream;
		}
		else
		{
			Vector<T> vector;

			temp.arr = new T * [vector.GetSize()];

			for (int i = 0; i < vector.GetSize(); i++)
			{
				temp.arr[i] = new T[vector.GetSize()];
			}

			temp.line = vector.GetSize();
			temp.column = vector.GetSize();

			for (int i = 0; i < vector.GetSize(); i++)
			{
				cin >> vector;
				for (int j = 0; j < vector.GetSize(); j++)
				{
					temp.arr[i][j] = vector[j];
				}
			}
		}
	}
	friend ostream& operator<< (ostream& stream, const Matrix& temp)
	{
		for (int i = 0; i < temp.line; i++) {
			for (int j = 0; j < temp.column; j++) {
				stream << temp.arr[i][j] << "\t";
			}
			stream << endl;
		}
		return stream;
	}
};