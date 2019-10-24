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
	int sum = 0;
	vector<vector<int>>arr1(1,vector<int>(n)),arr2(n,vector<int>(n)),result(1,vector<int>(n));
	
	for(i=0;i<n;i++)
	{
		arr1[0][i] = i;
		for(j=0;j<n;j++)
		{
			arr2[i][j] = j;
		}
	}
	
#pragma omp parallel for	
	for(i=0;i<n;i++)
	{
		#pragma omp parallel for		
		for(j=0;j<n;j++)
		{
			sum = 0;
			#pragma omp parallel for reduction(+:sum)		
			for(k=0;k<n;k++)
			{
				sum+= arr1[0][k]*arr2[k][j];
			}

			result[0][j] = sum;
		}
	}
	
	for(i=0;i<n;i++)
	{
		cout<<result[0][i]<<endl;
	}
	return 0;
}
