#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Matrix
{
public:
	Matrix();

	Matrix(const int& sizeX, const int& sizeY);

	Matrix(const Matrix& other);

	Matrix(const vector<vector<double>>& other);

	Matrix& operator=(const Matrix& other);

	Matrix operator+(const double& other);

	Matrix& operator+=(const double& other);

	Matrix operator+(const Matrix& other);

	Matrix& operator+=(const Matrix& other);

	Matrix operator-(const double& other);

	Matrix& operator-=(const double& other);

	Matrix operator-(const Matrix& other);

	Matrix& operator-=(const Matrix& other);

	Matrix operator*(const double& other);

	Matrix& operator*=(const double& other);

	Matrix operator*(const Matrix& other);

	Matrix operator/(const double& other);

	Matrix& operator/=(const double& other);

	Matrix operator^(const int& other);

	Matrix& operator^=(const int& other);

	double getDeterminantOfMatrix();

	double getNormOneOfMatrix();

	double getNormTwoOfMatrix();

	double getNormThreeOfMatrix();

	bool matrixAdditionCheck(const Matrix& other);

	bool matrixMaltiplicationCheck(const Matrix& other);

	bool squareMatrixCheck();

	friend ostream& operator<<(ostream& os, const Matrix& matrix);

	friend istream& operator>>(istream& stream, Matrix& matrix);

private:
	vector<vector<double>> arr;

	Matrix  minor(Matrix matrix, const int& i, const int& j);

	double determinant(const Matrix& matrix);

	double normOne();

	double normTwo();

	double normThree();

};