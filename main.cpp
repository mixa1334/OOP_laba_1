#include "matrix.h"
#include <cstdlib>

int main()
{
	system("chcp 1251>null");
	bool exit = false;
	int func;
	double x;
	int X;
	Matrix A;
	Matrix B;
	Matrix C;
	while (!exit)
	{
		cout << "\n\n\t===  1 - Изменить матрицу A                ===\n";
		cout << "\t===  2 - Показать матрицу А                ===\n";
		cout << "\t===  3 - Изменить матрицу B                ===\n";
		cout << "\t===  4 - Показать матрицу В                ===\n";
		cout << "\t===  5 - Cложить матрицу A и B             ===\n";
		cout << "\t===  6 - Сложить матрицу А с числом        ===\n";
		cout << "\t===  7 - Сложить матрицу В с числом        ===\n";
		cout << "\t===  8 - Вычесть из матрицы А матрицу В    ===\n";
		cout << "\t===  9 - Вычесть из матрицы В матрицу А    ===\n";
		cout << "\t=== 10 - Вычесть из матрицы А число        ===\n";
		cout << "\t=== 11 - Вычесть из матрицы В число        ===\n";
		cout << "\t=== 12 - Произведение матрицы А и матрицы В ===\n";
		cout << "\t=== 13 - Произведение матрицы А на число   ===\n";
		cout << "\t=== 14 - Произведение матрицы В на число   ===\n";
		cout << "\t=== 15 - Деление матрицы А на число        ===\n";
		cout << "\t=== 16 - Деление матрицы В на число        ===\n";
		cout << "\t=== 17 - Возведение матрицы А в степень    ===\n";
		cout << "\t=== 18 - Возведение матрицы В в степень    ===\n";
		cout << "\t=== 19 - Вычислить детерминант матрицы А   ===\n";
		cout << "\t=== 20 - Вычислить детерминант матрицы В   ===\n";
		cout << "\t=== 21 - Вычислить норму матрицы А         ===\n";
		cout << "\t=== 22 - Вычислить норму матрицы В         ===\n";
		cout << "\t===  0 - Выход                             ===\n";
		cout << "\t=== 99 - Очистка экрана                    ===\n";
		cout << "\n\tВыберите действие - ";
		cin >> func;
		cout << endl;
		switch (func)
		{
		case 0:
			exit = true;
			break;
		case 99:
			system("cls");
			break;
		case 1:
			cout << "Введите размер, а затем матрицу А:\n";
			cin >> A;
			break;
		case 2:
			cout << "Матрица А:\n";
			cout << A;
			break;
		case 3:
			cout << "Введите размер, а затем матрицу B\n";
			cin >> B;
			break;
		case 4:
			cout << "Матрица B:\n";
			cout << B;
			break;
		case 5:
			if (A.matrixСompatibilityCheck(B))
			{
				cout << "Результат суммы матирцы А и матрицы В:\n";
				cout << A + B;
			}
			else
			{
				cout << "Матрицы А и В нельзя сложить\n";
			}
			break;
		case 6:
			cout << "Введите число которое необходимо прибавить к матрице А:\n";
			cin >> x;
			cout << "Результат сложения матрицы А и числа " << x << endl;
			cout << A + x;
			break;
		case 7:
			cout << "Введите число которое необходимо прибавить к матрице B:\n";
			cin >> x;
			cout << "Результат сложения матрицы B и числа " << x << endl;
			cout << B + x;
			break;
		case 8:
			if (A.matrixСompatibilityCheck(B))
			{
				cout << "Результат разности матирцы А и матрицы В:\n";
				cout << A - B;
			}
			else
			{
				cout << "От матрицы А нельзя отнять матрицу В\n";
			}
			break;
		case 9:
			if (B.matrixСompatibilityCheck(A))
			{
				cout << "Результат разности матирцы B и матрицы A:\n";
				cout << B - A;
			}
			else
			{
				cout << "От матрицы B нельзя отнять матрицу A\n";
			}
			break;
		case 10:
			cout << "Введите число которое необходимо отнять от матрицы А:\n";
			cin >> x;
			cout << "Результат разности матрицы А и числа " << x << endl;
			cout << A - x;
			break;
		case 11:
			cout << "Введите число которое необходимо отнять от матрицы B:\n";
			cin >> x;
			cout << "Результат разности матрицы B и числа " << x << endl;
			cout << B - x;
			break;
		case 12:
			if (A.matrixMaltiplicationCheck(B))
			{
				cout << "Произведение матрицы А и В:\n";
				cout << A * B;
			}
			else
			{
				cout << "Матрицы А и В нельзя перемножить\n";
			}
			break;
		case 13:
			cout << "Введите число которое на которое необходимо умножить матрицу А:\n";
			cin >> x;
			cout << "Результат произведения матрицы А и числа " << x << endl;
			cout << A * x;
			break;
		case 14:
			cout << "Введите число на которое необходимо умножить матрицу B:\n";
			cin >> x;
			cout << "Результат умножения матрицы B и числа " << x << endl;
			cout << B * x;
			break;
		case 15:
			x = 0;
			while (x == 0)
			{
				cout << "Введите число на которое необходимо разделить матрицу А:\n";
				cin >> x;
			}
			cout << "Результат деления матрицы А на число " << x << endl;
			cout << A / x;
			break;
		case 16:
			x = 0;
			while (x == 0)
			{
				cout << "Введите число на которое необходимо разделить матрицу B:\n";
				cin >> x;
			}
			cout << "Результат деления матрицы А на число " << x << endl;
			cout << B / x;
			break;
		case 17:
			X = 0;
			while (X == 0)
			{
				cout << "Введите степень в которую будет возведена матрица A:\n";
				cin >> X;
			}
			if (A.squareMatrixCheck())
			{
				cout << "Матрица A возведенная в степень " << X << endl;
				C = A ^ X;
				cout << C;
			}
			else
			{
				cout << "Матрица A имеет не квадратный вид\n";
			}
			break;
		case 18:
			X = 0;
			while (X == 0)
			{
				cout << "Введите степень в которую будет возведена матрица B:\n";
				cin >> X;
			}
			if (B.squareMatrixCheck())
			{
				cout << "Матрица B возведенная в степень " << X << endl;
				C = B ^ X;
				cout << C;
			}
			else
			{
				cout << "Матрица B имеет не квадратный вид\n";
			}
			break;
		case 19:
			if (A.squareMatrixCheck())
			{
				cout << "Детерминант матрицы А:\n";
				cout << A.getDeterminantOfMatrix();
			}
			else
			{
				cout << "Матрица имеет не квадратный вид\n";
			}
			break;
		case 20:
			if (B.squareMatrixCheck())
			{
				cout << "Детерминант матрицы B:\n";
				cout << B.getDeterminantOfMatrix();
			}
			else
			{
				cout << "Матрица имеет не квадратный вид\n";
			}
			break;
		case 21:
			cout << "Норма матрицы А:\n";
			cout << "A1: " << A.getNormOneOfMatrix() << "\tA2: " << A.getNormTwoOfMatrix() << "\tA3: " << A.getNormThreeOfMatrix() << endl;
			break;
		case 22:
			cout << "Норма матрицы B:\n";
			cout << "B1: " << B.getNormOneOfMatrix() << "\tB2: " << B.getNormTwoOfMatrix() << "\tB3: " << A.getNormThreeOfMatrix() << endl;
			break;
		}
	}
}