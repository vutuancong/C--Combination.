#include <iostream>

using namespace std;

int Vitri(int A[],int x,int i)
{
	if(x==A[i]) return i+1;
	return Vitri(A,x,i+1);		
}
int main()
{
	int x,A[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
	cout<<"Nhap x: ";cin>>x;
	cout<<"Vi tri cua x la: "<<Vitri(A,x,0);
	return 0;
	
}
