// tim xau ngan nhat chua tat ca xau con lai cua no.
#include <iostream>
#include <string>

using namespace std;

int min(int a, int b)
{
	return (a < b ) ? a : b;
}
int maxCompare(string str1, string str2, string &str)
{
	int max = INT_MIN;
	int len1 = str1.length();
	int len2 = str2.length();
	//Kiem tra cuoi str1 trung voi dau cua str2 ?
	for(int i = 1; i<= min(len1,len2);i++)
	{
		if(str1.compare(len1 - i,i,str2,0,i) == 0)
		{
			if(max < i)
			{
				max = i;
				str = str1 + str2.substr(i);
			}
		}
	}
	//Kiem tra dau cua str1 co trung voi cuoi cua str2 ?
	for(int i = 1;i<=min(len1,len2);i++)
	{
		if(str1.compare(0, i, str2, len2 - i, i) == 0)
		{
			if(max < i)
			{
				max = i;
				str = str2 + str1.substr(i);
			}
		}
	}
	return max;
}
string shortest_string(string arr[],int len)
{
	while(len!=1)
	{
		int max = INT_MIN;
		int l, r;
		string resStr;
		
		for(int i = 0;i<len;i++)
		{
			for(int j = i+1;j<len;j++)
			{
				string str;
				int res = maxCompare(arr[i],arr[j], str);
				if(max < res)
				{
					max = res;
					resStr.assign(str);
					l = i;r = j;
				}
			}
		}
		len--;
		
		if(max == INT_MIN)
			arr[0] += arr[len];
		else
		{
			arr[l] = resStr;
			arr[r] = arr[len];
		}
	}
	return arr[0];
}
int main()
{
	int n ;
	string arr[100];
	cout<<"Nhap so cac string: ";
	cin>>n;
	for(int i = 0 ;i<n;i++)
	{
		cout<<"Nhap string thu "<<i+1<<":";
		cin>>arr[i];
	}
	cout<<"The Shortest Superstring is "<<shortest_string(arr, n);
	return 0;
}
