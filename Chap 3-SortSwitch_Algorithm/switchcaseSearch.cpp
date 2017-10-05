#include <iostream>

using namespace std;

int sequentialSearch(int *A,int n,int x)
{
	for(int i = 0;i<n;i++)
	{
		if(A[i] == x) return i;
	}
	return -1;
}

int binarySearch(int *A,int n,int x)
{
	int high = n - 1,low = 0,mid;
	mid = (high + low)/2;
	while(low<high)
	{
		if(x > A[mid])
		low = mid+1;
		else if(x < A[mid])
		high = mid -1;
		else
		return mid;
		mid = (low+high)/2;
	}
}

int interpolationSearch(int *A,int n,int x)
{
	int low = 0 ,high = n-1,mid;
	if(A[low] > x || x > A[high] ) return -1;
	while(low <= high)
	{
		mid = low + ((x - A[low])*(high - low))/(A[high] - A[low]);
		if(A[mid] == x) return mid;
		if(x >A[mid]) low = mid + 1;
		if(x< A[mid]) high = mid -1;
	}
	return -1;
}

//int jumpingSearch(int *A,int n,int x)
//{
//	int step = int(sqrt(n));
//	int prev = 0;
//	int r = step - 1;
//	while(A[r]<x)
//	{
//		prev = step;
//		step += int(sqrt(n));
//		if(prev >= n) return -1;
//		r = step -1;
//	}
//	while(A[prev] < x)
//	{
//		prev++;
//		if(prev == )
//	}
//}
int main()
{
	int n,x,m;
	int A[] = {10,11,12,13,15,16,19};
	m = sizeof(A)/sizeof(A[0]);
	cout<<"---Tim kiem cac loai---"<<endl;
	cout<<"1.Tim kiem tuyen tinh(Sequential Search)"<<endl;
	cout<<"2.Tim kiem nhi phan(Binary Search)"<<endl;
	cout<<"3.Tim kiem noi suy(Interpolation Search)"<<endl;
	cout<<"4.Tim kiem Jumping"<<endl;
	cin>>n;
	switch(n)
	{
		case 1:
			cout<<"Phan tu tim kiem: ";cin>>x;
			if(sequentialSearch(A,m,x)>=0) cout<<"O vi tri thu "<<sequentialSearch(A,m,x)<<endl;
			else cout<<"Khong co trong danh sach"<<endl;break;
		case 2:
			cout<<"Phan tu tim kiem: ";cin>>x;
			if(binarySearch(A,m,x)>=0) cout<<"O vi tri thu "<<binarySearch(A,m,x)<<endl;
			else cout<<"Khong co trong danh sach"<<endl;break;
		case 3:
			cout<<"Phan tu tim kiem: ";cin>>x;
			if(interpolationSearch(A,m,x)>=0) cout<<"O vi tri thu "<<interpolationSearch(A,m,x)<<endl;
			else cout<<"Khong co trong danh sach"<<endl;break;
//		case 4:
//			cout<<"Phan tu tim kiem: ";cin>>x;
//			if(jumpingSearch(A,m,x)>=0) cout<<"O vi tri thu "<<jumpingSearch(A,m,x)<<endl;
//			else cout<<"Khong co trong danh sach"<<endl;break;		
	}
}
