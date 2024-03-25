#include <iostream>
#include "q2.h"
using namespace std;

Matrices :: Matrices(int r = 0, int c = 0)
{
	rows = r;
	cols = c;

	matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
		*(matrix + i) = new int[cols];
}


void Matrices::fillMatrix()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			cin >> *(*(matrix + i) + j);
}


void Matrices::printMatrix()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << *(*(matrix + i) + j) << "\t";

		cout << endl;
	}
}


Matrices :: Matrices(Matrices& m2)
{
	rows = m2.rows;
	cols = m2.cols;

	matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
		*(matrix + i) = new int[cols];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			*(*(matrix + i) + j) = *(*(m2.matrix + i) + j);
}


Matrices& Matrices :: operator = (Matrices& m2)
{
	rows = m2.rows;
	cols = m2.cols;

	matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
		*(matrix + i) = new int[cols];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			*(*(matrix + i) + j) = *(*(m2.matrix + i) + j);

	return *this;
}


Matrices& Matrices :: operator + (Matrices& m2)
{
	Matrices sum(rows, cols);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			*(*(sum.matrix + i) + j) = *(*(this->matrix + i) + j) + *(*(m2.matrix + i) + j);

	return sum;
}


Matrices& Matrices :: operator - (Matrices& m2)
{
	Matrices subt(rows, cols);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			*(*(subt.matrix + i) + j) = *(*(this->matrix + i) + j) - *(*(m2.matrix + i) + j);

	return subt;
}


Matrices& Matrices :: operator * (Matrices& m2)
{
	if (this->cols != m2.rows)
		cout << "Multiplication cannot take place!\n";

	else
	{
		Matrices mult(this->rows, m2.cols);

		for (int i = 0; i < this->rows; i++)
			for (int j = 0; j < m2.cols; j++)
			{
				*(*(mult.matrix + i) + j) = 0;

				for (int k = 0; k < m2.rows; k++)
					*(*(mult.matrix + i) + j) += *(*(this->matrix + i) + k) * *(*(m2.matrix + k) + j);
			}

		return mult;
	}
}


bool Matrices :: operator == (Matrices& m2)
{
	if (this->rows != m2.rows && this->cols != m2.cols)
		return 0;

	else
	{
		int equalCount = 0;
		bool equalCheck = 0;

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				if (*(*(this->matrix + i) + j) == *(*(m2.matrix + i) + j))
					equalCount++;

		(equalCount == rows * cols) ? equalCheck = 1 : equalCheck = 0;
		return equalCheck;
	}
}


Matrices :: ~Matrices()
{
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
}


int main()
{
	int r, c;

	cout << "Enter rows: ";
	cin >> r;

	cout << "Enter columns: ";
	cin >> c;


	Matrices m1(r, c);
	cout << "\nEnter values in a matrix:\n";
	m1.fillMatrix();

	Matrices m2(r, c);
	cout << "\nEnter values in another matrix:\n";
	m2.fillMatrix();

	cout << "\nFirst matrix:\n";
	m1.printMatrix();

	cout << "\nSecond matrix:\n";
	m2.printMatrix();


	cout << "\nSum of the matrices:\n";
	Matrices sum = m1 + m2;
	sum.printMatrix();

	cout << "\nDifference of the matrices:\n";
	Matrices subt = m1 - m2;
	subt.printMatrix();

	cout << "\nMultiplication of the matrices:\n";
	Matrices mult = m1 * m2;
	mult.printMatrix();

	((m1 == m2) == 1) ? cout << "\nEqual Matrices\n" : cout << "\nDifferent Matrices\n";


	cout << "\n----------------------------------------------------------\nMultiplication of the matrices using different rows and columns\n\n";
	int r3, c3, r4, c4;

	cout << "Enter rows of a matrix: ";
	cin >> r3;
	cout << "Enter columns of a matrix: ";
	cin >> c3;

	cout << "\nEnter rows of another matrix: ";
	cin >> r4;
	cout << "Enter columns of another matrix: ";
	cin >> c4;

	Matrices m3(r3, c3);
	cout << "\nEnter values in the first matrix:\n";
	m3.fillMatrix();

	Matrices m4(r4, c4);
	cout << "\nEnter values in the second matrix:\n";
	m4.fillMatrix();

	cout << "\nFirst matrix:\n";
	m3.printMatrix();

	cout << "\nSecond matrix:\n";
	m4.printMatrix();

	cout << "\nMultiplication of the matrices:\n";
	Matrices mul(r3, c4);
	mul = m3 * m4;
	mul.printMatrix();

	((m3 == m4) == 1) ? cout << "\nEqual Matrices\n" : cout << "\nDifferent Matrices\n";

	return 0;
}
