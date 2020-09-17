#include "matrix.h"

Matrix::Matrix()
{
	
}

Matrix::Matrix(const int& sizeX, const int& sizeY)
{
	arr.resize(sizeX);
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i].resize(sizeY);
		for (int k = 0; k < arr[i].size(); k++)
		{
			arr[i][k] = 0;
		}
	}
}

Matrix::Matrix(const Matrix& other)
{
	arr.resize(other.arr.size());
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i].resize(other.arr[i].size());
		for (int k = 0; k < arr[i].size(); k++)
		{
			arr[i][k] = other.arr[i][k];
		}
	}
}

Matrix::Matrix(const vector<vector<double>>& other)
{
	arr.resize(other.size());
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i].resize(other[i].size());
		for (int k = 0; k < arr[i].size(); k++)
		{
			arr[i][k] = other[i][k];
		}
	}
}

Matrix& Matrix::operator=(const Matrix& other) {
	arr.clear();
	arr.resize(other.arr.size());
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i].resize(other.arr[i].size());
		for (int k = 0; k < arr[i].size(); k++)
		{
			arr[i][k] = other.arr[i][k];
		}
	}
	return *this;
}

Matrix Matrix::operator+(const double& other)
{
	Matrix temp(this->arr.size(), this->arr[arr.size() - 1].size());
	for (int i = 0; i < temp.arr.size(); i++)
	{
		for (int k = 0; k < temp.arr[i].size(); k++)
		{
			temp.arr[i][k] = this->arr[i][k] + other;
		}
	}
	return temp;
}

Matrix& Matrix::operator+=(const double& other)
{
	return *this = *this + other;
}

Matrix Matrix::operator+(const Matrix& other)
{
	Matrix temp(this->arr.size(), this->arr[this->arr.size() - 1].size());
	for (int i = 0; i < temp.arr.size(); i++)
	{
		for (int k = 0; k < temp.arr[i].size(); k++)
		{
			temp.arr[i][k] = this->arr[i][k] + other.arr[i][k];
		}
	}
	return temp;
}

Matrix& Matrix::operator+=(const Matrix& other)
{
	return *this = *this + other;
}

Matrix Matrix::operator-(const double& other)
{
	Matrix temp(this->arr.size(), this->arr[this->arr.size() - 1].size());
	for (int i = 0; i < temp.arr.size(); i++)
	{
		for (int k = 0; k < temp.arr[i].size(); k++)
		{
			temp.arr[i][k] = this->arr[i][k] - other;
		}
	}
	return temp;
}

Matrix& Matrix::operator-=(const double& other)
{
	return *this = *this - other;
}

Matrix Matrix::operator-(const Matrix& other)
{
	Matrix temp(this->arr.size(), this->arr[this->arr.size() - 1].size());
	for (int i = 0; i < temp.arr.size(); i++)
	{
		for (int k = 0; k < temp.arr[i].size(); k++)
		{
			temp.arr[i][k] = this->arr[i][k] - other.arr[i][k];
		}
	}
	return temp;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
	return *this = *this - other;
}

Matrix Matrix::operator*(const double& other)
{
	Matrix temp(this->arr.size(), this->arr[this->arr.size() - 1].size());
	for (int i = 0; i < temp.arr.size(); i++)
	{
		for (int k = 0; k < temp.arr[i].size(); k++)
		{
			temp.arr[i][k] = this->arr[i][k] * other;
		}
	}
	return temp;
}

Matrix& Matrix::operator*=(const double& other)
{
	return *this = *this * other;
}

Matrix Matrix::operator*(const Matrix& other)
{
	Matrix temp(this->arr.size(), other.arr[other.arr.size() - 1].size());
	for (int i = 0; i < temp.arr.size(); i++)
	{
		for (int k = 0; k < temp.arr[i].size(); k++)
		{
			for (int j = 0; j < other.arr.size(); j++)
			{
				temp.arr[i][k] = temp.arr[i][k] + (this->arr[i][j] * other.arr[j][k]);
			}
		}
	}
	return temp;
}

Matrix Matrix::operator/(const double& other)
{
	Matrix temp(this->arr.size(), this->arr[this->arr.size() - 1].size());
	for (int i = 0; i < temp.arr.size(); i++)
	{
		for (int k = 0; k < temp.arr[i].size(); k++)
		{
			temp.arr[i][k] = this->arr[i][k] / other;
		}
	}
	return temp;
}

Matrix& Matrix::operator/=(const double& other)
{
	return *this = *this / other;
}

Matrix Matrix::operator^(const int& other)
{
	Matrix temp(*this);
	for (int i = 1; i < other; i++)
	{
		temp = temp * *this;
	}
	return temp;
}

Matrix& Matrix::operator^=(const int& other)
{
	Matrix temp(*this);
	for (int i = 1; i < other; i++)
	{
		*this = temp * *this;
	}
	return *this;
}

double Matrix::getDeterminantOfMatrix()
{
	if (squareMatrixCheck())
	{
		return determinant(*this);
	}
	else
	{
		return 0;
	}
}

double Matrix::getNormOneOfMatrix()
{
	return (this->normOne());
}

double Matrix::getNormTwoOfMatrix()
{
	return (this->normTwo());
}

double Matrix::getNormThreeOfMatrix()
{
	return (this->normThree());
}

bool Matrix::matrixAdditionCheck(const Matrix& other)
{
	if (this->arr.size() == other.arr.size() && this->arr[this->arr.size() - 1].size() == other.arr[other.arr.size() - 1].size())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Matrix::matrixMaltiplicationCheck(const Matrix& other)
{
	if (this->arr[this->arr.size() - 1].size() == other.arr.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Matrix::squareMatrixCheck()
{
	if (this->arr.size() == this->arr[this->arr.size() - 1].size())
	{
		return true;
	}
	else
	{
		return false;
	}
}

Matrix Matrix::minor(Matrix matrix, const int& i, const int& j)
{
	matrix.arr.erase(matrix.arr.begin() + i);
	for (auto& matrix_ : matrix.arr)
	{
		matrix_.erase(matrix_.begin() + j);
	}
	return matrix;
}

double Matrix::determinant(const Matrix& matrix)
{
	int  Y = matrix.arr[0].size();
	if (Y == 1)
	{
		return matrix.arr[0][0];
	}
	int  signum = 1;
	int  summ = 0;
	int  j = 0;
	for (auto& matrix_ : matrix.arr[0])
	{
		summ += matrix_ * signum * determinant(minor(matrix, 0, j));
		signum *= -1;
		j++;
	}
	return summ;
}

double Matrix::normOne()
{
	double max = 0, num = 0;
	for (int i = 0; i < this->arr.size(); i++)
	{
		for (int k = 0; k < this->arr[i].size(); k++)
		{
			num += abs(this->arr[i][k]);
		}
		if (num > max)
		{
			max = num;
			num = 0;
		}
		else
		{
			num = 0;
		}
	}
	return max;
}

double Matrix::normTwo()
{
	double max = 0, num = 0;
	for (int i = 0; i < this->arr[this->arr.size() - 1].size(); i++)
	{
		for (int k = 0; k < this->arr.size(); k++)
		{
			num += abs(this->arr[k][i]);
		}
		if (num > max)
		{
			max = num;
			num = 0;
		}
		else
		{
			num = 0;
		}
	}
	return max;
}

double Matrix::normThree()
{
	double temp = 0;
	for (int i = 0; i < this->arr.size(); i++)
	{
		for (int k = 0; k < this->arr[i].size(); k++)
		{
			temp += this->arr[i][k] * this->arr[i][k];
		}
	}
	return sqrt(temp);
}



ostream& operator<<(ostream& stream, const Matrix& matrix)
{
	for (int i = 0; i < matrix.arr.size(); i++)
	{
		for (int k = 0; k < matrix.arr[i].size(); k++)
		{
			stream << matrix.arr[i][k] << " ";
		}
		stream << endl;
	}
	stream << "\n\n";
	return stream;
}

istream& operator>>(istream& stream, Matrix& matrix)
{
	int size;
	stream >> size;
	matrix.arr.resize(size);
	stream >> size;
	for (int i = 0; i < matrix.arr.size(); i++)
	{
		matrix.arr[i].resize(size);
		for (int k = 0; k < matrix.arr[i].size(); k++)
		{
			stream >> matrix.arr[i][k];
		}
	}
	return stream;
}