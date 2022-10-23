/*This program will take input for a coeffecient matrix, and solve for the variables, or provide a general solution.*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	vector<vector<double>> matrix1;
	vector<vector<double>> matrixX;
	vector<vector<double>> matrixY;

	double row, column;

	cout << "Please enter matrix dimensions (rows and columns)\n"; // for now will start with a 2x3 matrix.
	cout << "Enter your row count\n";
	cin >> row;
	cout << "Enter your column count\n";
	cin >> column;

	matrix1.resize(row, vector<double>(column));
	matrixX.resize(row, vector<double>(column - 1));
	matrixY.resize(row, vector<double>(column - 1));

	// entering matrix data
	cout << "Enter your augmented coefficent matrix. 2x3 for now." << endl;
	for (int i = 0; i < row; i++)
	{
		for (int q = 0; q < column; q++)
		{
			cout << "Enter row " << i + 1 << " column " << q + 1 << " value\n";
			cin >> matrix1[i][q];
		}
	}

	cout << "\n";
	for (int i = 0; i < row; i++)
	{
		for (int q = 0; q < column; q++)
		{
			cout << matrix1[i][q] << " ";
		}
		cout << "\n";
	}

	int z = column - 1; // getting x matrix from matrix 1.
	for (int i = 0; i < row; i++)
	{
		for (int q = 0; q < column - 1; q++)
		{
			if (z == 0)
			{
				z = column - 1;
			}
			matrixX[i][q] = matrix1[i][z];
			z--;
		}
	}

	cout << "\nX matrix\n"; // outputting x matrix
	for (int i = 0; i < row; i++)
	{
		for (int q = 0; q < column - 1; q++)
		{
			cout << matrixX[i][q] << " ";
		}
		cout << "\n";
	}

	int u = column; // getting y matrix
	for (int i = 0; i < row; i++)
	{
		for (int q = 0; q < column - 1; q++)
		{
			if (q == 0 || q == 2)
			{
				u = 0;
			}
			if (q == 1 || q == 3)
			{
				u = 2;
			}
			matrixY[i][q] = matrix1[i][u];
		}
	}

	cout << "\nY matrix\n"; // outputting y matrix
	for (int i = 0; i < row; i++)
	{
		for (int q = 0; q < column - 1; q++)
		{
			cout << matrixY[i][q] << " ";
		}
		cout << "\n";
	}

	// using cramer's rule to solve for variables
	double D[2][2], Dx[2][2], Dy[2][2]; //[row][column]
	double Determ1, DetermX, DetermY, a, b, c, d, a1, b1, c1, d1, a2, b2, c2, d2, x, y;
	a = D[0][0] = matrix1[0][0];
	b = D[0][1] = matrix1[0][1];
	c = D[1][0] = matrix1[1][0];
	d = D[1][1] = matrix1[1][1];
	Determ1 = (a * d) - (b * c);

	a1 = Dx[0][0] = matrix1[0][2];
	b1 = Dx[0][1] = matrix1[0][1];
	c1 = Dx[1][0] = matrix1[1][2];
	d1 = Dx[1][1] = matrix1[1][1];
	DetermX = (a1 * d1) - (b1 * c1);

	a2 = Dy[0][0] = matrix1[0][0];
	b2 = Dy[0][1] = matrix1[0][2];
	c2 = Dy[1][0] = matrix1[1][0];
	d2 = Dy[1][1] = matrix1[1][2];
	DetermY = (a2 * d2) - (b2 * c2);

	x = DetermX / Determ1;
	y = DetermY / Determ1;

	cout << "The answer for the first variable is " << x << "\nThe answer for the second variable is " << y << endl;

	return 0;
}