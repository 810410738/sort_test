// randomtest.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <random>
#include<cstdlib>
#include<ctime>
using namespace std;
void SelectSort(int *a, int n) {
	int i, j;
	for (i = 0; i<n; i++)
	{
		int index = i;
		for (j = i + 1; j<n; j++)
		{
			if (a[i]>a[j])
			{
				index = j;
			}
		}
		if (index != i)
		{
			//swap
			int temp = a[i];
			a[i] = a[index];
			a[index] = temp;
		}

	}
}

void show(int *a, int n) {

	for (int i = 0; i<n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void BubblingSort(int *a, int n) {
	int i, j;
	for (i = 1; i<n; i++)
	{
		for (j = 0; j<n - i; j++)
		{
			if (a[j]>a[j + 1])
			{
				//				swap
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void InsertSort(int *a, int n) {
	int i, j;
	for (i = 1; i<n; i++)
	{
		int temp = a[i];
		for (j = i - 1; j >= 0 && temp<a[j]; j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}
}

void quick_sort(int *s, int l, int r) {
	if (l < r)
	{
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) // 从右向左找第一个小于x的数  
				j--;
			if (i < j)
				s[i++] = s[j];

			while (i < j && s[i] < x) // 从左向右找第一个大于等于x的数  
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quick_sort(s, l, i - 1); // 递归调用   
		quick_sort(s, i + 1, r);
	}
}

void mergearray(int a[], int first, int mid, int last, int temp[]) {
	int i = first, j = mid + 1;
	int m = mid, n = last;
	int k = 0;

	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	while (i <= m)
		temp[k++] = a[i++];

	while (j <= n)
		temp[k++] = a[j++];

	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}
void mergesort(int a[], int first, int last, int temp[]) {
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergesort(a, first, mid, temp);    //左边有序  
		mergesort(a, mid + 1, last, temp); //右边有序  
		mergearray(a, first, mid, last, temp); //再将二个有序数列合并  
	}
}
void MergeSort(int a[], int n) {
	int *p = new int[n];
	mergesort(a, 0, n - 1, p);
	delete[] p;
}
	
void CheckRandom(int *a,int n) {
	int i;
	double sum=0;
	int half = n / 2;
	int count = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] > half)
		{
			count++;
		}
		sum += a[i];
	}
	double average = sum / n;
	double sum1 = 0;
	for (i = 0; i < n; i++) {
		sum1 += ((double)a[i] - average)*((double)a[i] - average);
	}
	double variance = sum1 / n;
	
	double trueVariance = (double)n*(double)n / 12;
	cout << "average is "<<average <<"\n" << "the number of bigger than half of n is "<<count << endl;
	cout << "variance is " << variance << endl;
	cout << "truevariance is " << trueVariance << endl;
}
int main()
{
	//	SelectSort(b,n);
	//	BubblingSort(b,n);
	//	MergeSort(b,n);
	//	quick_sort(b,0,n-1);
	//	InsertSort(b,n);
	
	time_t c_start,c_end;
	int n;
	cout << "Please input the n!\n";
	cin >> n;//输入n的规模
			 //创建数据 

	//随机产生20组测试样本
	random_device rd;
	uniform_int_distribution<int> dist(0, n);
	int i, j;
	int **a = new int*[20];
	for ( i = 0; i<20; i++) {
		a[i] = new int[n];
	}
	for (i = 0; i < 20; i++) {
		for (j = 0; j < n; j++) {
			a[i][j] = dist(rd);
		}
	}
	float Sumtime;
	/*
	//选择排序
	cout<<"The SelectSort:\n";
	Sumtime = 0;
	for (i = 0; i<20; i++) {
			//取一组样本
			int *b = new int[n];
			for (j = 0; j<n; j++) {
				b[j] = a[i][j];
			}
			
			//开始计时
				c_start = clock();
				SelectSort(b, n);
				c_end = clock();
			//结束计时
				float time =difftime(c_end, c_start);
				cout << time << "ms ";
				Sumtime += time;
			delete[] b;
		}	
	cout << "\nThe  average time is " << Sumtime / 20 << "ms\n";
	

	//冒泡排序
	cout << "The BubblingSort:\n";
	Sumtime = 0;
	for (i = 0; i<20; i++) {
		//取一组样本
		int *b = new int[n];
		for (j = 0; j<n; j++) {
			b[j] = a[i][j];
		}

		//开始计时
		c_start = clock();
		BubblingSort(b, n);
		c_end = clock();
		//结束计时
		float time = difftime(c_end, c_start);
		cout << time << "ms ";
		Sumtime += time;
		delete[] b;
	}
	cout << "\nThe average time is " << Sumtime / 20 << "ms\n";
	*/
	//归并排序
	cout << "The MergeSort:\n";
	Sumtime = 0;
	for (i = 0; i<20; i++) {
		//取一组样本
		int *b = new int[n];
		for (j = 0; j<n; j++) {
			b[j] = a[i][j];
		}

		//开始计时
		c_start = clock();
		MergeSort(b, n);
		c_end = clock();
		//结束计时
		float time = difftime(c_end, c_start);
		cout << time << "ms ";
		Sumtime += time;
		delete[] b;
	}
	cout << "\nThe average time is " << Sumtime / 20 << "ms\n";

	//快速排序
	cout << "The QuickSort:\n";
	Sumtime = 0;
	for (i = 0; i<20; i++) {
		//取一组样本
		int *b = new int[n];
		for (j = 0; j<n; j++) {
			b[j] = a[i][j];
		}

		//开始计时
		c_start = clock();
		quick_sort(b, 0, n - 1);
		c_end = clock();
		//结束计时
		float time = difftime(c_end, c_start);
		cout << time << "ms ";
		Sumtime += time;

		delete[] b;
	}
	cout << "\nThe average time is " << Sumtime / 20 << "ms\n";
	//插入排序
	cout << "The InsertSort:\n";
	Sumtime = 0;
	for (i = 0; i<20; i++) {
		//取一组样本
		int *b = new int[n];
		for (j = 0; j<n; j++) {
			b[j] = a[i][j];
		}

		//开始计时
		c_start = clock();
		InsertSort(b, n);
		c_end = clock();
		//结束计时
		float time = difftime(c_end, c_start);
		cout << time << "ms ";
		Sumtime += time;

		
		delete[] b;
	}
	cout << "\nThe average time is " << Sumtime / 20 << "ms\n";

	//释放20组数据
	for (i = 0; i < 20; i++) {
		delete[] a[i];
	}
	delete[] a;
	
	system("pause");
	return 0;
	
}

