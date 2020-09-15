#include <iostream>
#include <vector>
using namespace std;

class Matrix
{
public:
	Matrix(const int& sizeX, const int& sizeY)
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

	Matrix(const Matrix& other)
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

	Matrix(const vector<vector<double>>& other)
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

	Matrix& operator=(const Matrix& other)
	{
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

	Matrix operator+(const double& other)
	{
		Matrix temp(this->arr.size(), this->arr[arr.size()-1].size());
		for (int i = 0; i < temp.arr.size(); i++)
		{
			for (int k = 0; k < temp.arr[i].size(); k++)
			{
				temp.arr[i][k] = this->arr[i][k] + other;
			}
		}
		return temp;
	}

	Matrix& operator+=(const double& other)
	{
		return *this = *this + other;
	}

	Matrix operator+(const Matrix& other)
	{
		Matrix temp(this->arr.size(), this->arr[this->arr.size()-1].size());
		for (int i = 0; i < temp.arr.size(); i++)
		{
			for (int k = 0; k < temp.arr[i].size(); k++)
			{
				temp.arr[i][k] = this->arr[i][k] + other.arr[i][k];
			}
		}
		return temp;
	}

	Matrix& operator+=(const Matrix& other)
	{
		return *this = *this + other;
	}

	Matrix operator-(const double& other)
	{
		Matrix temp(this->arr.size(), this->arr[this->arr.size()-1].size());
		for (int i = 0; i < temp.arr.size(); i++)
		{
			for (int k = 0; k < temp.arr[i].size(); k++)
			{
				temp.arr[i][k] = this->arr[i][k] - other;
			}
		}
		return temp;
	}

	Matrix& operator-=(const double& other)
	{
		return *this = *this - other;
	}

	Matrix operator-(const Matrix& other)
	{
		Matrix temp(this->arr.size(), this->arr[this->arr.size()-1].size());
		for (int i = 0; i < temp.arr.size(); i++)
		{
			for (int k = 0; k < temp.arr[i].size(); k++)
			{
				temp.arr[i][k] = this->arr[i][k] - other.arr[i][k];
			}
		}
		return temp;
	}

	Matrix& operator-=(const Matrix& other)
	{
		return *this = *this - other;
	}

	Matrix operator*(const double& other)
	{
		Matrix temp(this->arr.size(), this->arr[this->arr.size()-1].size());
		for (int i = 0; i < temp.arr.size(); i++)
		{
			for (int k = 0; k < temp.arr[i].size(); k++)
			{
				temp.arr[i][k] = this->arr[i][k] * other;
			}
		}
		return temp;
	}

	Matrix& operator*=(const double& other)
	{
		return *this = *this * other;
	}

	Matrix operator*(const Matrix& other)
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

	Matrix operator/(const double& other)
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

	Matrix& operator/=(const double& other)
	{
		return *this = *this / other;
	}

	Matrix operator^(const int& other)
	{
		Matrix temp(*this);
		for (int i = 1; i < other; i++)
		{
			temp = temp * *this;
		}
		return temp;
	}

	Matrix& operator^=(const int& other)
	{
		Matrix temp(*this);
		for (int i = 1; i < other; i++)
		{
			*this = temp * *this;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& os, const Matrix& matrix);

private:
	vector<vector<double>> arr;
};

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

int main()
{
	vector<vector<double>> GG = { {1,9},{-5,6} };
	vector<vector<double>> WP = { {8},{-4} };
	Matrix A(GG);
	Matrix B(WP);
	Matrix C = A * B;
	cout << C;

}