#include <iostream>

using namespace std;

void merge(int *A,int l,int m,int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1],R[n2];
	for(int i = 0;i<n1;i++)
	{
		L[i] = A[l+i];
	}
	for(int i = 0;i<n2;i++)
	{
		R[i] = A[m+1+i];
	}
	int i = 0,j = 0,k = l;
	while(i<n1 && j<n2)
	{
		if(L[i] <= R[j]) A[k++] = L[i++];
		else
		A[k++] = R[j++];
	}
	while(i<n1)
	{
		A[k++] = L[i++];
	}
	while(j<n1)
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

void greedy(int Start[],int Finish[],int m)
{
	int Fopt = 1;
	int i = 0;
	for(int j = 1;j<m;j++)
	{
		if(Finish[i] <= Start[j])
		{
			Fopt++;
			i = j;
		}
	}
	cout<<"Fopt : "<<Fopt;
}

int main()
{
	int Start[] = {1,2,0,5,8,5};
	int Finish[] = {6,2,4,9,7,9};
	int m = sizeof(Finish)/sizeof(Finish[0]);
	int l = 0;
	mergeSort(Finish,l,m);
	for(int i = 0;i<m;i++)
	{
		cout<<Finish[i]<<" ";
	}
	greedy(Start,Finish,m);
}

