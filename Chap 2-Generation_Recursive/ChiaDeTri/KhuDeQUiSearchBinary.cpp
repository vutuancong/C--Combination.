#include <iostream>

using namespace std;

int binarySearch(int arr[],int l,int r,int x)
{
	while(l<=r)
	{
		int mid = l + (r-l)/2;
		if(arr[mid] == x) return mid;
		if(arr[mid] < x)  l = mid + 1;
		else
			r = mid - 1;
	}
	return -1;
}
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8};
	int n = sizeof(arr)/sizeof(arr[0]);
	int x;
	cout<<"Nhap x: ";cin>>x;
	cout<<"Gia tri vi tri tai x: "<<binarySearch(arr,0,n,x);
}
