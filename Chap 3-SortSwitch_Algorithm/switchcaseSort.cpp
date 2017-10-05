#include <iostream>

using namespace std;
void swap(int *a,int *b)
{
	int temp = *a;*a = *b;*b = temp;
}

void selectionSort(int *A,int m)
{
	for(int i = 0;i<m - 1;i++)
	{
		int index_min = i ;
		for(int j = i +1;j<m;j++)
		{
			if(A[i] >A[j])
			{
				index_min = j;
				swap(&A[i],&A[index_min]);
			}
		}
	}
}
void insertionSort(int *A,int m)
{
	for(int i = 0 ;i<m;i++)
	{
		int key = A[i];
		int j = i - 1;
		while(j>=0 && A[j]>key)
		{
			A[j+1] = A[j];
			j--;
		} 
		A[j+1] = key;
	}
}

void bubbleSort(int *A,int m)
{
	for(int i = 0;i<m;i++)
	{
		for(int j = 0;j<m-i-1;j++)
		{
			if(A[j]>A[j+1])
			swap(&A[j],&A[j+1]);
		}
	}
}
//------------------------------------
int partition(int *A,int l,int h)
{
	int x = A[h];
	int i = (l-1);
	for(int j = l;j <= h-1;j++)
	{
		if(A[j]<=x)
		{
			i++;
			swap(&A[i],&A[j]);
		}
	}
	swap(&A[i+1],&A[h]);
	return i+1;
}

void quickSort(int *A,int l ,int m)
{
	if(l<m)
	{
		int p = partition(A,l,m);
		quickSort(A,l,p-1);
		quickSort(A,p+1,m);
	}
}
//----------------------------------
void merge(int *A,int l,int m,int r)
{
	int i,j,k;
	int n1 = m - l + 1;
	int n2  = r - m;
	int L[n1],R[n2];
	for(i = 0;i<n1;i++)
	{
		L[i] = A[l+i];
	}
	for(j = 0;j<n2;j++)
	{
		R[j] = A[m+j+1];
	}
	i = 0;j=0;k = l;
	while(i <n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			A[k] = L[i];i++;
		}
		else
		{
			A[k] = R[j];j++;
		}
		k++;
	}
	while(i<n1)
	{
		A[k] = L[i];i++;k++;
	}
	while(j<n2)
	{
		A[k] = R[j];j++;k++;
	}
}
void mergeSort(int *A,int l,int r)
{
	if(l<r)
	{
		int m = l + (r - l)/2;
		mergeSort(A,l,m);
		mergeSort(A,m+1,r);
		merge(A,l,m,r);
	}
}
//-----------------------------------
void heapify(int *A,int n,int i)
{
	int largest = i;
	int l = 2*i+1;
	int r = 2*i+2;
	if(l<n && A[largest]<A[l]) largest = l;
	if(r<n && A[largest]<A[r]) largest = r;
	if(largest != i)
	{
		swap(&A[i],&A[largest]);
		heapify(A,n,largest);
	}
}
void heapSort(int *A,int n)
{
	for(int i = n/2 - 1;i>=0;i--)
		heapify(A,n,i);
	for(int i = n - 1;i>=0;i--)
	{
		swap(&A[0],&A[i]);
		heapify(A,i,0);
	}
}
//--------------------------
void Result(int *A,int m)
{
	for(int i = 0;i<m;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int n;
	int m=0;
	int A[] = {65,50,29,19,48};
	m = sizeof(A)/sizeof(A[0]);
	cout<<"---Thuat toan sap xep----"<<endl;
	cout<<"1.Selection-Sort"<<endl;
	cout<<"2.Insertion-Sort"<<endl;
	cout<<"3.Bubble-Sort"<<endl;
	cout<<"4.Quick-Sort"<<endl;
	cout<<"5.Merge-Sort"<<endl;
	cout<<"6.Heap-Sort"<<endl;
	cout<<"Lua chon thuat toan sap xep"<<endl;
	cin>>n;
	switch(n)
	{
		case 1:
			selectionSort(A,m);Result(A,m);break;
		case 2:
			insertionSort(A,m);Result(A,m);break;
		case 3:
			bubbleSort(A,m);Result(A,m);break;
		case 4:
			quickSort(A,0,m-1);Result(A,m);break;
		case 5:
			mergeSort(A,0,m-1);Result(A,m);break;
		case 6:
			heapSort(A,m);Result(A,m);break;
	}
}
