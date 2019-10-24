#include<iostream>
#include<cstdio>
#include<vector>
#include<omp.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;

int main()
{
	int num_threads_to_use = 4;
	omp_set_num_threads(2);
	int i,j,k;
	
	int n = 4;
	int sum=0;
	
	vector<vector<int>>arr1(n,vector<int>(n)),arr2(n,vector<int>(n)),result(n,vector<int>(n));
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			arr1[i][j]=j;
			arr2[i][j]=j;
		}
	}
	
#pragma omp parallel for
	for(i=0;i<n;i++)
	{
	#pragma omp parallel for
		for(j=0;j<n;j++)
		{	
			sum=0;
			#pragma omp parallel for reduction(+:sum)
			for(int k=0;k<n;k++)
			{
				sum+=arr1[i][k]*arr2[k][j];
			}
			result[i][j] = sum;	
		}
	}


for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		cout<<"\n"<<result[i][j];
	}	
}	
	return 0;
}
