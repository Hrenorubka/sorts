#include "Sorts.h"
#include <ctime>
#include <iostream>

using namespace std;

void main()
{
	srand(time(NULL));
	int N = 10;
	vector <unsigned int> mas1(N);
	cout << "new mas:\n";
	for (int i = 0; i < N; i++)
	{
		mas1[i] = rand() % 15;
		cout << mas1[i] << ' ';
	}
	cout << "\nCountSort:" << "\n";
	CountSort(mas1, 14);
	for (int i = 0; i < N; i++)
	{
		cout << mas1[i] << ' ';
	}
	cout << "\n\nnew mas:\n";
	vector <int> mas2(N);
	for (int i = 0; i < N; i++)
	{
		mas2[i] = rand() % 68;
		cout << mas2[i] << ' ';
	}
	cout << "\nQSort:" << "\n";
	QSort(mas2, 0, 10);
	for (int i = 0; i < N; i++)
	{
		cout << mas2[i] << ' ';
	}
	cout << "\n\nnew mas:\n";
	vector <double> mas3(N);
	for (int i = 0; i < N; i++)
	{
		mas3[i] = rand() % 10 * 0.1;
		cout << mas3[i] << ' ';
	}
	cout << "\nBucketSort:" << "\n";
	BucketSort(mas3, 0, 1);
	for (int i = 0; i < N; i++)
	{
		cout << mas3[i] << ' ';
	}
}


