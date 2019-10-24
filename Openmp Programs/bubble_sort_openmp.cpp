#include<iostream>
#include<omp.h>
#include<stdlib.h>
#include<vector>

using namespace std;

template<typename T>
void bubble_sort(vector<T> &arr)
{
	int t = 0;
	int sv = 1;
	for (int i = 0; i < arr.size() - 1 ; ++i)
	{
		/* code */
		#pragma omp parallel for
		for (int j = sv; j < arr.size(); j+=2)
		{
			/* code */
			if (arr[j]>arr[j-1])
			{
				t = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = t;
			}
		}
		sv+=1;	
		sv-=(sv == 3 ? 2 : 0);
	}
}

int main()
{
	vector<int> arr(5);
	for(int i = 0 ; i<5; i++)
		arr[i] = 5-i;

	// 	for (int i = 0; i < 5; ++i)
	// {
	// 	cout<<arr[i];
	// }
	omp_set_num_threads(4);
	bubble_sort(arr);

	for (int i = 0; i < 5; ++i)
	{
		cout<<"\n"<<arr[i]<<"\n";
	}

	return 0;
}
