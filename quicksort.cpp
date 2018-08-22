
/*
*快速排序
*/

#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int> &arr, int low, int high)
{
	int pivot = arr[low];
	while (low < high)
	{
		while (low < high&&arr[high]>=pivot)
			high--;
		arr[low] = arr[high];
		while (low < high&&arr[low] <= pivot)
			low++;
		arr[high] = arr[low];
	}
	arr[low] = pivot;
	return low;
}
void quickSort(vector<int> &arr, int low, int high)
{
	if (low >= high)
		return;
	int pivot = partition(arr, low, high);
	quickSort(arr, low, pivot - 1);
	quickSort(arr, pivot + 1, high);
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
	quickSort(vec, 0, vec.size() - 1);
	cout << "the result is :" << endl;
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	return 0;
}
