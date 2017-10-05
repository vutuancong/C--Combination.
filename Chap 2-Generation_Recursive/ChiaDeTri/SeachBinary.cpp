#include <iostream>

using namespace std;

int binarySearch(int arr[],int l,int r, int x)
{
	if(r>=l)
	{
		int mid = l + (r - l )/2;
		if(arr[mid] == x)
			return mid;
		if(arr[mid] > x)
			return binarySearch(arr,l,mid-1,x);
		return binarySearch(arr,mid+1,r,x);
	}
	return -1;
}
int main()
{
	int x;
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int n  = sizeof(arr)/sizeof(arr[0]);
	cout<<"Nhap so can tim kiem: ";cin>>x;
	cout<<"Ket qua "<<x<<" o vi tri: "<<binarySearch(arr,0,n,x);
}
