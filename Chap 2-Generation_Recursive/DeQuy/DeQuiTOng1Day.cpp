#include <iostream>

using namespace std;

int Tong(int A[],int i)
{
	if(i==0) return(A[i]);
	return(A[i]+Tong(A,i-1));
}
int main()
{
	int n,A[100];
	cout<<"Nhap so luong phan tu cua day: ";cin>>n;
	for(int i = 0 ;i<n;i++)
	{
		cout<<"Phan tu "<<i+1<<": ";
		cin>>A[i];
	}
	cout<<"Tong cua cac so trong day la: "<<Tong(A,n-1);
	return 0;
}
