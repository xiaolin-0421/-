/*
*鸡尾酒排序
*/

#include<iostream>
#include<vector>


using namespace std;

void sort_cocktail(vector<int> &vec)
{
	int temp = 0;
	for (int i = 0; i < vec.size()/2; ++i)
	{
		bool is_sorted = true;//判断是否有元素交换
		for (int j = i; j < vec.size() - 1; j++) //奇数轮， 从左向右比较和交换
		{
			if (vec[j] > vec[j + 1])
			{
				temp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = temp;
				is_sorted = false;
			}
		}
		if (is_sorted)
			break;
		is_sorted = true;
		for (int j = vec.size() - i - 1; j > i; j--)//偶数轮，从右向左比较和交换
		{
			if (vec[j] < vec[j - 1])
			{
				temp = vec[j];
				vec[j] = vec[j - 1];
				vec[j - 1] = temp;
			}
		}
		if (is_sorted)
			break;
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
	sort_cocktail(vec);
	cout << "the result is :" << endl;
	for (vector<int>::iterator iter=vec.begin(); iter!=vec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	return 0;
}
