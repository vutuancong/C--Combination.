#include <iostream>

using namespace std;

int swap(int *a,int *b)
{
	int temp = *a;*a=*b;*b=temp;
}
int partition(int *A,int l,int h)
{
	int i = l-1;
	int x = A[h];
	for(int j = l;j<h-1;j++)
	{
		if(A[j] <= x )
		{
			i++;
			swap(&A[i],&A[j]);
		}
	}
	swap(&A[i+1],&A[h]);
	return i+1;
}

void quickSort(int *A,int l,int m)
{
	if(l<m)
	{
		int p = partition(A,l,m);
		quickSort(A,l,p-1);
		quickSort(A,p+1,m);
	}
}

int main()
{
	int A[] = {5,3,4,1,6,7};
	int l = 0,m = sizeof(A)/sizeof(A[0]);
	quickSort(A,l,m-1);
	for(int i = 0;i<m;i++)
	{
		cout<<A[i]<<" ";
	}
}
