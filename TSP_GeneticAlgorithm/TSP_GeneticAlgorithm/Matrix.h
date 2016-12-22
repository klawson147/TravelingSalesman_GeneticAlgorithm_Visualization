#include <iostream>

#pragma once
class Matrix
{
private:
	unsigned _int8 size_;
	unsigned _int16** storage_;

public:
	Matrix();
	Matrix(_int8);
	~Matrix();

	void setSize(_int8);
	void createTable();
	void setElement(_int8 x, _int8 y, _int16 data);
	void printMatrix();
	int getSize();
	unsigned _int16 getElement(unsigned _int8, unsigned _int8);
};
