#include <iostream>
#include <string.h>

using namespace std;

typedef struct SoLan
{
	char a;
	int so_lan;
};

void Init(char S[100],int &d)
{
	cout<<"Nhap xau : ";
	cin>>S;
	cout<<"Nhap khoang cach giua cac ki tu: ";
	cin>>d;
}

int Dem(SoLan X[100],int &n,char a)
{
	for(int i = 0; i <=n; i++)
	{
		if(X[i].a == a)
		{
			return i;
		}
	}
	return n+1;
}

int Tach_Kytu(SoLan X[100],char S[],int &n)
{
	for(int i = 0;i<strlen(S);i++)
	{
		int m = Dem(X,n,S[i]);
		if(m <= n) X[m].so_lan++;
		else 
		{
			n = m;
			X[m].a = S[i]; X[m].so_lan = 1;
		} 
	}
	return n;
}

void Sort(SoLan X[],int &n)
{
	SoLan t;
	for(int i = 0;i< n- 1;i++)
	{
		for(int j = i+1; j < n;j++)
		{
			if(X[i].so_lan < X[j].so_lan)
			{
				t = X[i]; X[i] = X[j]; X[j] = t;
			}
		}
	}
}
void Result(SoLan X[],int n)
{
	for(int i =0; i<=n ;i++)
	{
		cout<<X[i].a<<" "<<X[i].so_lan;
		cout<<endl;
	}
}

void Greedy_Arr_String()
{
	char S[100],STR[100];
	int d,m = -1,chuaxet[100];
	SoLan X[255];
	Init(S,d);
	m = Tach_Kytu(X,S,m);
	Sort(X,m);
	Result(X,m);
	for(int i = 0;i<strlen(S);i++)
	{
		chuaxet[i] = 1;
	}
	for(int i = 0;i<=m;i++)
	{
		int t = 0;
		int k = X[i].so_lan;
		while(!chuaxet[t]) t++;
		for(int j = 0;j<k;j++)
		{
			if((t+j*d) >= strlen(S))
			{
				cout<<"Khong co ket qua"<<endl;
				return;
			}
			STR[t+j*d] = X[i].a;
			chuaxet[t+j*d]  = 0;
		}
	}
	
	STR[strlen(S)] = '\0';
	cout<<STR;
}
int main()
{
	Greedy_Arr_String();
}

