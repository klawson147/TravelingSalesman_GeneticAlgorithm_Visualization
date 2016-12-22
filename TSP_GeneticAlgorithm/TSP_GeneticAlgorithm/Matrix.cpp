#include "Matrix.h"
#include "Matrix.h"


Matrix::Matrix()
{
}


Matrix::Matrix(_int8 size)
{
	size_ = size;
	createTable();
}


Matrix::~Matrix()
{
	
}

void Matrix::setSize(_int8 size)
{
	size_ = size;
	
}

int Matrix::getSize()
{
	return size_;
}

void Matrix::createTable()
{
	storage_ = new unsigned _int16*[size_];
	
	for (int i = 0; i < size_; i++)
	{
		storage_[i] = new unsigned _int16[size_];
	}
}

unsigned _int16 Matrix::getElement(unsigned _int8 x, unsigned _int8 y)
{
	return storage_[x][y];
}

void Matrix::setElement(_int8 x, _int8 y, _int16 data)
{
	storage_[x][y] = data;
}

void Matrix::printMatrix()
{
	for (int i = 0; i < size_; i++)
	{
		for (int j = 0; j < size_; j++)
		{
			std::cout << storage_[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}


