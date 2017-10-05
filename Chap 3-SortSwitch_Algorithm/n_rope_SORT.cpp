#include <iostream>

using namespace std;

void merge(int *A,int l,int m,int r)
{
	int n1 = m - l +1;
	int n2 = r - m;
	int L[n1],R[n2];
	for(int i = 0;i<n1;i++)
	{
		L[i] = A[i+l];
	}
	for(int j = 0;j<n2;j++)
	{
		R[j] = A[m+1+j];
	}
	int i = 0,j = 0,k = l;
	while(i<n1 && j<n2)
	{
		if(L[i]<= R[j]) A[k++] = L[i++];
		else
		A[k++] = R[j++];
	}
	while(i<n1)
	{
		A[k++] = L[i++];
	}
	while(j<n2)
	{
		A[k++] = R[j++];
	}
}

void mergeSort(int *A,int l,int r)
{
	if(l<r)
	{
		int m = l + (r-l)/2;
		mergeSort(A,l,m);
		mergeSort(A,m+1,r);
		merge(A,l,m,r);
	}
}

int main()
{
	int chiphi = 0;
	int D[] = {9,7,12,8,6,5,14,4},l = 0;//2 3 4 6
	int m  = sizeof(D)/sizeof(D[0]);
//	mergeSort(D,l,m-1);
//	for(int i = 0;i<m;i++)
//	{
//		cout<<D[i]<<" ";
//	}
	while(m>1)
	{
//		for(int i = 0;i<m;i++)
//		{
//			cout<<D[i]<<" ";
//		}
		mergeSort(D,0,m-1);
		cout<<endl;
		int mot =D[0];
		int hai =D[1];
		chiphi = chiphi + mot + hai;
		D[1] = mot+hai;
		for(int i = 1;i<m;i++)
		{
			D[i-1] = D[i]; 
		}
		m--;
	}
	cout<<"Chi phi noi day la: "<<chiphi<<endl;
}
