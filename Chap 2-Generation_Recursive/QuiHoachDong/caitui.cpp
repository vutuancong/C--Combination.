#include <iostream>

using namespace std;

int X[100], A[100], C[100], F[100][100],n,B;

void Init()
{
	cout<<"Nhap khoi luong tui: ";cin>>B;
	cout<<"Nhap so luong do vat: ";cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cout<<"Nhap do vat thu: "<<i<<":";
		cin>>A[i];
		cout<<"Gia tri su dung cua do vat thu: "<<i<<":";
		cin>>C[i];
	}
	for(int i = 0 ;i<= B;i++)
	{
		F[0][i] = 0;
	}
}
void Result()
{
	cout<<"Bang phan bo gia tri toi da trong tung buoc: "<<endl;
	for(int i = 1;i<= n;i++)
	{
		for(int j = 0;j<=B;j++)
		{
			cout<<F[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void Optimize()
{
	for(int i = 1;i<=n;i++)
	{
		for(int j = 0;j<=B;j++)
		{
			//Khong chap nhan gia tri i hien tai
			//Thi lay gia tri toi uu thu i - 1
			F[i][j] = F[i-1][j];
			//Neu khoi luong j lon chua duoc gia tri A[i]
			//Va gia tri toi uu hien tai nho hon gia tri truoc do cong voi gia tri C[i] hien tai thi
			//Chap nhan gia tri toi uu  =  Gia tri toi uu truoc do + gia tri..
			if(j >= A[i] && F[i][j] < F[i-1][j - A[i]] + C[i])
				F[i][j] = F[i-1][j - A[j]] + C[i];
		}
	}
}
void Trace()
{
	cout<<"Gia tri toi uu: "<<F[n][B]<<endl;
	cout<<"Cac do vat dem theo: ";
	while(n!=0)
	{
		if(F[n][B] != F[n - 1][B])
		{
			cout<<n<<" ";
			B = B - A[n];
		}
		n--;
	}
}
int main()
{
	Init();Optimize();Trace();
}
