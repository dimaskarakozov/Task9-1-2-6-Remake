// Task9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
void zadanie1() {
	{
		int i, j, n, m, ** mas;

		printf("Введите 2 числа:\n");
		scanf("%d %d", &m, &n);

		mas = (int**)malloc(m * sizeof(int*));

		for (i = 0; i < m; i++)
		{
			mas[i] = (int*)malloc(n * sizeof(int));
		}

		printf("Введите элементы массива\n");

		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				scanf("%d", &mas[i][j]);
			}
		}
		printf("Начальный массив:\n");

		for (i = 0; i < m; i++ ) {
			printf("\n");
			for (j = 0; j < n; j++) {
				printf("%d ", mas[i][j]);
			}
		}
		int *b;
		b = (int*)malloc((m * n) * sizeof(int));
		

		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++)
			{
				b[i * n + j] = mas[i][j];

			}
		}

		printf("\nОтвет туда:\n");

		for (i = 0; i < m * n; i++) {
			printf("%d ", b[i]);
		}
		printf("\n");

		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				mas[i][j] = 0;
				
			}
		}
		printf("Ответ обратно :\n");
		for (i = 0; i < m * n; i++){
			mas[i / n][i % n] = b[i];

		}

		for (i = 0; i < m; i++) {
			printf("\n");
				for (j = 0; j < n; j++) {
					printf("%d ", mas[i][j]);
				}
		}
	}

}
void zadanie2() {
	int n, m;
	printf("Введите размер через пробел");
	scanf("%d %d", &n, &m);

	int** mas;
	mas = (int**)malloc(n * sizeof(int*));
	for (int q = 0; q < n; q++) {
		mas[q] = (int*)malloc(m * sizeof(int));
	}
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			mas[i][j] = j + 1 - i;
			if (mas[i][j] <= 0) {
				mas[i][j] = 2 - mas[i][j];
			}
		}
	}


	for (int i = 0; i < n; i++) {  //вывод
		printf("\n");
		for (int j = 0; j < m; j++) {
			printf("\t%d", mas[i][j]);
			mas[i][j] = 0;
		}
	}
	printf("\n\n");
	*/

	int sum = 1;

	if (n % 2 == 1 && m % 2 == 1) {
		mas[n / 2][m / 2] = n * m;

	}

	int krugov;
	if (n > m) {
		krugov = m / 2 + m % 2;
	}
	else{
		krugov = n / 2 + m % 2;
	}
	
		for (int i = 0; i < krugov; i++) {
			if ( (krugov == i + 1 && n % 2 == 1) || (n % 2 == 0 )|| (krugov != i + 1 && n % 2 == 1)) {
			for (int j = i; j < (m - i); j++) {
				mas[i][j] = sum;
				sum++;
			} 
		}
			if ((krugov == i + 1 && m % 2 == 1) || (m % 2 == 0) || (krugov != i + 1 && m % 2 == 1)) {
				for (int j = 1; j < (n - i - i); j++) {
					mas[(j + i)][m - i - 1] = sum;
					sum++;
				}
			}
		if (krugov != i + 1 && (m % 2 == 1 || n % 2 == 1)) {
			for (int j = m - 2 - i; j >= i; j--) {
				mas[n - i - 1][(j)] = sum;
				sum++;
			}
			for (int j = ((n - i) - 2); j > i; j--) {
				mas[j][i] = sum;
				sum++;
			}
		}
	}


	for (int i = 0; i < n; i++) {  //вывод
		printf("\n");
		for (int j = 0; j < m; j++) {
			printf("\t%d", mas[i][j]);
		}
	}



}

void gauss(double** mas1, double** mas2, int n)
{
	int k = 0, ind;
	while (k < n)
	{
		double t = mas1[k][k];
		if (t == 0)
		{
			for (int i = 0; i < n; i++)
				if (mas1[i][k] != 0)
				{
					ind = i;
					break;
				}
			for (int i = 0; i < n; i++)
			{
				double t = mas1[k][i], t1 = mas2[k][i];
				mas1[k][i] = mas1[ind][i], mas2[k][i] = mas2[ind][i];
				mas1[ind][i] = t, mas2[ind][i] = t1;
			}
			t = mas1[k][k];
		}
		for (int i = 0; i < n; i++)
		{
			mas1[k][i] /= t;
			mas2[k][i] /= t;
		}
		for (int i = k + 1; i < n; i++)
		{
			double t = mas1[i][k];
			for (int j = 0; j < n; j++)
			{
				mas1[i][j] -= mas1[k][j] * t;
				mas2[i][j] -= mas2[k][j] * t;
			}
		}
		k++;
	}
	for (k = n - 1; k > 0; k--)
	{
		for (int j = k - 1; j >= 0; j--)
		{
			double t = mas1[j][k];
			mas1[j][k] -= mas1[k][k] * t;
			for (int i = n - 1; i >= 0; i--)
			{
				mas2[j][i] -= mas2[k][i] * t;
			}
		}
	}
}


void zadanie6() {
	int n;
	double** mas1, ** mas2, ** mas3;

	printf("Введите размер: ");
	scanf("%d", &n);

	mas1 = (double**)malloc(n * sizeof(double*));
	mas2 = (double**)malloc(n * sizeof(double*));
	mas3 = (double**)malloc(n * sizeof(double*));


	for (int i = 0; i < n; ++i) {
		mas1[i] = (double*)malloc(n * sizeof(double));
		mas2[i] = (double*)malloc(n * sizeof(double));
		mas3[i] = (double*)malloc(n * sizeof(double));
	}
	printf("Матрица: \n");

	for (int i = 0; i < n; i++)

		for (int j = 0; j < n; j++)

		{
			if (i == j)
				mas2[i][j] = 1;
			else mas2[i][j] = 0;

			scanf("%lf", &mas1[i][j]);
			mas3[i][j] = mas1[i][j];
		}

	gauss(mas1, mas2, n);
	printf("\nОтвет: \n");

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%lf ", mas2[i][j]);
		printf("\n");
	}

	double** mas4;
	mas4 = (double**)malloc(n * sizeof(double*));
	for (int i = 0; i < n; i++)
	{
		mas4[i] = (double*)malloc(n * sizeof(double));

		for (int j = 0; j < n; j++)

		{
			mas4[i][j] = 0;

			for (int k = 0; k < n; k++)
				mas4[i][j] += mas3[i][k] * mas2[k][j];

			if (fabs(mas4[i][j]) < 0.000001)
				mas4[i][j] = 0;
		}

	}

}

int main()
{


	int q = -1;
	setlocale(LC_ALL, "Russian");

	//Task6

	printf("\n\n1) (1)  Считаем, что двумерный массив размера m на n преобразуется в одномерный массив размера m* n путем последовательной записи строк. (m и n заданы) Реализовать такое преобразование «туда» и «обратно».  ");
	printf("\n\n2) (2) Заполнить двумерный массив размером n x m так, как представлено в таблице для 5х5");
	printf("\n\n6) (2) Найти обратную матрицу методом Гаусса (сделать проверку)");
	printf("\n\n0)Выйти");
	while (q != 0) {
		printf("\n\nВведите номер нужного задания : ");
		scanf_s("%d", &q);
		switch (q) {
		case 1: {
			zadanie1();//Задание 1
			break;
		}
		case 2: {
			zadanie2();//Задание 2
			break;
		}
		case 6: {
			zadanie6();//Задание 6
			break;
		}

		}
	}
	return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
