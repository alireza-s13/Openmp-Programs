#include<iostream>
#include<omp.h>
using namespace std;


void merge(int arr[], int l, int mid, int mid1, int h)
{
	int buff[ h+1 ]; // or use buff[ (mid-l+1) + (h-mid1+1) ]
	int i = l,j = mid1, k = 0;
	while(i<=mid && j<=h)
	{
		if (arr[i] < arr[j])
		{
			buff[k++] = arr[i++];
		}
		else
		{
			buff[k++] = arr[j++];
		}
	}
	while(i<=mid)
	{
		buff[k++] = arr[i++];
	}
	while(j<=h)
	{
		buff[k++] = arr[j++];
	}
	for(i = l, j = 0 ; i<=h ; i++,j++)
		arr[i] = buff[j];

}

void merge_sort(int *arr, int l, int h)
{
	if (l<h)
	{
		int mid = (l+h)/2;
		#pragma omp parallel sections
		{
			#pragma omp section
			{
				merge_sort(arr,l,mid);
			}
			#pragma omp section
			{
				merge_sort(arr,mid+1,h);
			}
		}
		merge(arr,l,mid,mid+1,h);
	}
}

int main()
{
	int arr[] = {5,4,3,2,1};
	merge_sort(arr,0,4);

	cout<<endl;
	for (int i = 0; i < 5; ++i)
	{
		/* code */
		cout<<"\t"<<arr[i];
	}
	cout<<endl;

	return 0;
}