#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int NguyenTo(int n)
{
	for(int i = 2; i<= sqrt(n); i++)
	{
		if(n%i == 0 ) return 0;
	}
	return 1;
}
int Tong1(int n)
{
	int tong = 0;
	while(n>0)
	{
		tong = tong + n%10;
		n = n/10;
	}
	return tong;
}
int A[100000], B[5][5] = {{0,0,0,0,0},
						 {0,0,0,0,0},
						 {0,0,0,0,0},
						 {0,0,0,0,0},
						 {0,0,0,0,0}},
						  k=0,S[4];
static int dem=0;
void Init()
{
	for(int i = 0 ;i<=4;i++)
	{
		for(int j = 0; j<=4;j++)
		{
			B[i][j] = 0;
		}
	}
}
void TachSo(int n)
{
	int i=4;
	while(n>0)
	{
		S[i--] = n%10;
		n=n/10; 
	}
}
void MangSo()
{
	int Tong=0;
	cout<<"Nhap tong: ";cin>>Tong;
	for(int i = 10001; i<=99999; i++)
	{
		if(NguyenTo(i) && Tong ==Tong1(i))
		A[k++] = i;
	}
}
void Result()
{
	cout<<"Ma tran thu "<<dem++<<":"<<endl;
	for(int i = 0 ;i<5;i++)
	{
		for(int j= 0;j<5 ;j++)
		{
			cout<<B[i][j]<<"  ";
		}
		cout<<endl;
	}
	cout<<endl;
}
// vet mang
void VetMang()
{
	for(int i = 0; i < k; i++)
	{
		TachSo(A[i]);
		for(int j= 0; j<=4; j++)
			B[0][j] = S[j];
		for(int i1 = 0; i1 < k;i1++)
		{
			TachSo(A[i1]);
			if(B[0][0] == S[0])
			{
				for(int j = 0; j <= 4; j++)
				B[j][0] = S[j];
				for(int i2 = 0; i2 <k;i2++)
				{
					TachSo(A[i2]);
					if(B[4][0] == S[0] && B[0][4] == S[4])
					{
						for(int j = 0,j1=4;j<=4,j1>=0;j++,j1--)
							B[j1][j] = S[j];
						for(int i3 = 0;i3 <k;i3++)
						{
							TachSo(A[i3]);
							if(B[1][0]==S[0] && B[1][3] == S[3])
							{
								for(int j = 0; j<=4; j++)
									B[1][j] = S[j];
								for(int i4 = 0;i4< k;i4++)
								{
									TachSo(A[i4]);
									if(B[0][1]==S[0] && B[1][1]==S[1] && B[4][1]==S[3])
									{
										for(int j= 0;j<=4;j++)
											B[j][1] = S[j];
										for(int i5 = 0 ;i5< k;i5++)
										{
											TachSo(A[i5]);
											if(B[2][0]==S[0]&& B[2][1]==S[1] &&B[2][2]==S[2])
											{
												for(int j = 0 ;j<=4;j++)
													B[2][j]= S[j];
												for(int i6 = 0;i6<k;i6++)
												{
													TachSo(A[i6]);
													if(B[0][2]== S[0] && B[1][2]==S[1] && B[2][2]==S[2])
													{
														for(int j = 0;j<=4;j++)
															B[j][2]= S[j];
														for(int i7 = 0;i7<k;i7++)
														{
															TachSo(A[i7]);
															if(B[3][0]==S[0] && B[3][1] == S[1] && B[3][2] == S[2])
															{
																for(int j = 0;j<=4;j++)
																	B[3][j]= S[j];
																for(int i8 = 0;i8<k;i8++)
																{
																	TachSo(A[i8]);
																	if(B[4][0]==S[0] && B[4][1]== S[1] && B[4][2]==S[2])
																	{
																		for(int j = 0;j<=4;j++)
																			B[4][j]=S[j];
																		Result();
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}	
				}
			}	
		}
	}
}
int main()
{
	MangSo();
	VetMang();
//	Result();	
}
