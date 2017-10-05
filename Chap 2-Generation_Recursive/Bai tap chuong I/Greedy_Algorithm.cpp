#include <iostream>

using namespace std;

int N,S[100],F[100],FO[100];
int k=0;

void Init()
{
	cout<<"nhap so luong cong viec: ";
	cin>>N;
	for(int i = 0;i<N;i++)
	{
		cout<<"thoi gian bat dau cong viec thu "<<i+1<<": ";
		cin>>S[i];
	}
	cout<<endl;
	for(int i = 0;i<N;i++)
	{
		cout<<"thoi gian ket thuc cong viec thu "<<i+1<<":";
		cin>>F[i];
	}
}

void SapXep()
{
	for(int i = 0;i<N-1;i++)
	{
		for(int j =i+1;j<N;j++)
		{
			if(F[i]>F[j])
			{
				int temp = F[i];F[j] = F[i];F[j] = temp;
			}
		}
	}
}

void HanhDong()
{
	FO[0] = 0;
	k = 1;
	int i = 0;
	for(int j = 1;j<N;j++)
	{
		if(S[j] >= F[i])
		{
			FO[k] = j;
			k++;
			i = j; 
		}
	}
}
void Result()
{
	for(int i  =0 ;i<k;i++)
	{
		cout<<FO[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	Init();
	SapXep();
	HanhDong();
	Result();
}
