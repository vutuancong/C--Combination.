#include <iostream>

using namespace std;

int merge(int *A,int l,int m,int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1],R[n2];
	for(int i = 0;i<n1;i++)
	{
		L[i] = A[l+i];
	}
	for(int j = 0;j<n2;j++)
	{
		R[j] = A[m+1+j];
	}
	int i = 0,j = 0, k = l;
	while(i<n1&& j<n2)
	{
		if(L[i] <= R[j])
		{
			A[k++] = L[i++];
		}
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
		int m = l+ (r-l)/2;
		mergeSort(A,l,m);
		mergeSort(A,m+1,r);
		merge(A,l,m,r);
	}
}
int main()
{
	int A[] = {5,3,4,1,6,7};
	int l = 0,m = sizeof(A)/sizeof(A[0]);
	mergeSort(A,l,m-1);
	for(int i = 0;i<m;i++)
	{
		cout<<A[i]<<" ";
	}
}
