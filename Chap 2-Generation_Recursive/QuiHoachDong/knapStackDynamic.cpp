
#include <iostream>

using namespace std;

int F[100][100], A[100], C[100],B,n;

void Init()
{
	cout<<"Nhap so luong hang: ";cin>>n;
	cout<<"Nhap khoi luong va gia tri: ";
	for(int i = 1;i<=n;i++)
	{
		cin>>A[i]>>C[i];
	}
	cout<<"Nhap gioi han khoi luong mat hang: ";cin>>B;
	//Gia tri khoi dau cua Fopt
	for(int i = 0;i<=B;i++)
	{
		F[0][i] = 0;
	}
}
//
// 2 Truong hop xay ra:
// TH1: Gia tri toi uu thu duoc boi i-1 mat hang. Tuc la khong chap nhan kha nang thu i;
// TH2: Gia tri toi uu thu duoc boi i mat hang. Chap nhan kha nang thu i;
void Optimize()
{
	for(int i = 1;i<=n;i++)
	{
		for(int j = 0;j<=B;j++)
		{
			F[i][j] = F[i-1][j];
			if(j>=A[i] && F[i][j]< F[i-1][j-A[i]] + C[i])
				F[i][j] = F[i-1][j - A[i]] + C[i];
		}
	}
}
int main()
{
	Init();
	Optimize();
	cout<<"gia tri lon nhat: "<<F[n][B];
}
