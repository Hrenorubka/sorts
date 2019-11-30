#pragma once
#ifndef __Sort_H__
#define __Sort_H__
#include <vector>

using std::vector;

template <class ValType>
void Upg_Buble_Sort(vector <ValType> &mas)
{
	bool flag = false;
	if (mas.size() > 0)
		flag = true;
	int i = 0;
	while (flag)
	{
		flag = false;
		for (int j = 0; j < mas.size() - i - 1; j++)
		{
			if (mas[j] > mas[j + 1])
			{
				flag = true;
				ValType obl = mas[j + 1];
				mas[j + 1] = mas[j];
				mas[j] = obl;
			}
		}
		i++;
	}
}


void BucketSort(vector <double> &mas, double min, double max)
{
	vector <vector <double>> buckets(mas.size());
	for (int i = 0; i < mas.size(); i++)
	{
		buckets[(int)((mas[i] - min) / (max - min)*mas.size())].push_back(mas[i]);
	}
	int k = 0;
	for (int i = 0; i < mas.size(); i++)
	{
		Upg_Buble_Sort(buckets[i]);
		for (int j = 0; j < buckets[i].size(); j++)
		{
			mas[k] = buckets[i][j];
			k++;
		}
	}
}

void CountSort(vector <unsigned int> &mas, const unsigned int MAX)
{
	const unsigned int N = MAX + 1;
	vector <unsigned int> obl(N);
	for (int i = 0; i < N; i++)
		obl[i] = 0;
	for (int i = 0; i < mas.size(); i++)
		obl[mas[i]]++;
	unsigned int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum = obl[i] + sum;
		obl[i] = sum;
	}
	vector <unsigned int> res(mas.size());
	for (int i = mas.size() - 1; i >= 0; i--)
	{
		res[obl[mas[i]] - 1] = mas[i];
		obl[mas[i]]--;
	}
	mas = res;
}


template <class ValType>
void QSort(vector <ValType> &mas, int beg, int end)
{

	int mid = beg + (end - beg) / 2;
	int i = beg;
	int j = end - 1;
	ValType mid_elem = mas[mid];
	while (i <= j)
	{
		while (mas[j] > mid_elem)
			j--;
		while (mas[i] < mid_elem)
			i++;
		if (i <= j)
		{
			ValType obl = mas[i];
			mas[i] = mas[j];
			mas[j] = obl;
			i++;
			j--;
		}

	}
	if (beg < j)
		QSort(mas, beg, j + 1);
	if (end > i)
		QSort(mas, i, end);
}


#endif