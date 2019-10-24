#include<iostream>
#include<stdlib.h>
#include<vector>
#include<omp.h>
#include<bits/stdc++.h>

using namespace std;

template<typename T, typename S>
bool binary_search(T arr, int l , int h,S K)
{
	int m = 0;
	while(l<=h)
	{
		m = (l+h)/2;
		if (K==arr[m])
		{
			cout<<"\n\t Key found ! index : "<<m;
		}
		if (K>arr[m])
		{
			l = m+1;
		}
		else
		{
			h = m-1;
		}
	}
	return false;
}

int main()
{
	int threads = 0;
	cout<<"\n\t Enter threads : ";
	cin>>threads;	
	omp_set_num_threads(threads);

	int n = 0 ;
	cout<<"\n\t Enter array size : ";
	cin>>n;
	std::vector<int> arr(n);
	for(int i = 0 ; i < n ; i++ )
		arr[i] = i+1;

	sort(begin(arr), end(arr));

	cout<<"\n\t Sorted Array "<<endl<<endl;
	for(int i = 0 ; i < n ; i++ )
	{
		if(i!=0 && i%10 == 0)
			cout<<endl;
		cout<<"\t"<<arr[i];
	}

	int key = 0;
	cout<<"\n\n\t====================================================";
	cout<<"\n\n\t Key : ";
	cin>>key;

	int k = n/threads;

	#pragma omp parallel for
	for(int i = 0 ; i <threads ; i++)
		binary_search(arr, i*k, min( n , i * k + k ), key);
	cout<<"\n\n\t===================================================="<<endl<<endl;

	return 0;
}