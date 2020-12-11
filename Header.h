#pragma once
#include <iostream>
using namespace std;

class Matrix
{
	long int** arr;
	int line;
	int column;
public:
	Matrix(int line, int column);
	~Matrix();
	Matrix(const Matrix& other);
	Matrix& operator = (const Matrix& other);
	Matrix operator + (const Matrix& other);
	Matrix operator - (const Matrix& other);
	Matrix operator * (const Matrix& other);
	Matrix operator * (const int other);
	bool operator == (const Matrix& other);
	bool operator != (const Matrix& other);
	void filling();
	void print();


};
