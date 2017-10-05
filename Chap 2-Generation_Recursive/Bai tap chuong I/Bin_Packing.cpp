//bai toan co n thung hang cung voi dung luong thung chua b
// Tim so thung hang nho nhat de chua duoc so hang lon nhat

#include <iostream>

using namespace std;

int n;
int A[100],chuaxet[100],tong,b,OK = 1;
int i = 0,demThung = 0, demEnd=0;

void Init()
{
	cout<<"Nhap so luong thung hang: ";
	cin>>n;
	cout<<"Nhap dung luong thung chua: ";
	cin>>b; 
	tong = b;
	for(int i = 0;i<n;i++)
	{
		cout<<"Thung hang thu "<<i+1<<":";
		cin>>A[i];
		chuaxet[i] = 1;
	}
}

void Sort()
{
	for(int i = 0;i<n -1;i++)
	{
		for(int j = i+1;j<n;j++)
		{
			if(A[i] < A[j])
			{
				int t = A[i]; A[i] = A[j]; A[j] = t;
			}
		}
	}
}

void Greedy_Bin()
{
	while(b<A[i] || chuaxet[i] == 0) i++;
//	cout<<i<<endl;
	if(i < n )
	{
		b = b - A[i];
		chuaxet[i] = 0;
		demEnd++;
	}
	if(i == n - 1 || b==0 )
	{
		demThung++;
		b = tong;
		i = 0;
	}
	if(demEnd == n ) 
	{
		cout<<"So luong thung hang la: "<<demThung + 1<<endl;
		OK = 0;
	}
}
int main()
{
	Init();
	Sort();
	for(int i = 0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
	while(OK)
	{
		Greedy_Bin();
	}
}
