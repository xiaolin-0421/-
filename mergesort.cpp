/*
*归并排序
*/
#include "stdafx.h"
#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int> &arr, int leftPos, int rightPos, int rightEnd)
{
	vector<int>temp;
	int leftEnd = rightPos - 1;
	int numElements = rightEnd - leftPos + 1;
	while (leftPos <= leftEnd&&rightPos <= rightEnd)
	{
		if (arr[leftPos] <= arr[rightPos])
			temp.push_back(arr[leftPos++]);
		else
			temp.push_back(arr[rightPos++]);
	}
	while (leftPos <= leftEnd)
		temp.push_back(arr[leftPos++]);
	while (rightPos <= rightEnd)
		temp.push_back(arr[rightPos++]);
	for (int i = numElements-1; i>=0; i--, rightEnd--)
		arr[rightEnd] = temp[i];
}
void mergeSort(vector<int> &arr, int left, int right)
{
	if (left < right)
	{
		int center = (left + right) / 2;
		mergeSort(arr, left, center);
		mergeSort(arr, center + 1, right);
		merge(arr, left, center + 1, right);
	}
}

int main()
{
	vector<int> vec;
	int n, each;
	cout << "please input the number of array :" << endl;
	cin >> n;
	cout << "please input each number :" << endl;
	for (int i = 0; i < n; ++i)
	{
		cin >> each;
		vec.push_back(each);
	}
	mergeSort(vec, 0, vec.size() - 1);
	cout << "the result is :" << endl;
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	return 0;
}
