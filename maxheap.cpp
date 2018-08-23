/*
*大顶堆排序
*/

#include<iostream>
#include<vector>

using namespace std;

void maxHeapDown(vector<int> &arr, int start, int end)
{
	int c = start;
	int temp = arr[c];
	for (int l = 2 * c + 1; l <= end; c = l, l = 2 * l + 1)
	{
		if (l  < end&&arr[l] < arr[l + 1])
			l++;
		if (temp >= arr[l])
			break;
		else
		{
			arr[c] = arr[l];
			arr[l] = temp;
		}
	}
}
void heapSort(vector<int> &arr)
{
	int n = arr.size();
	int i, temp;
	for (i = n / 2 - 1; i >= 0; i--)
		maxHeapDown(arr, i, n - 1);
	for (i = n - 1; i > 0; i--)
	{
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		maxHeapDown(arr, 0, i - 1);
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
	maxHeapDown(vec, 0, vec.size() - 1);
	cout << "the result is :" << endl;
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	return 0;
}
