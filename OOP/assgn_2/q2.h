#include <iostream>
using namespace std;

class Matrices
{
private:
	int** matrix;
	int rows;
	int cols;

public:
	Matrices(int, int);
	void fillMatrix();
	void printMatrix();
	~Matrices();

	Matrices(Matrices&);
	Matrices& operator = (Matrices&);

	Matrices& operator + (Matrices&);
	Matrices& operator - (Matrices&);
	Matrices& operator * (Matrices&);
	bool operator == (Matrices&);
};
