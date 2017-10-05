#include <iostream>

using namespace std;

int sumLeftRight(int arr[],int l,int m,int h)
{
	int sum_Left = INT_MIN,sum_Right = INT_MIN,sum = INT_MIN;
	for(int i = m ;i<= 0;i--)
	{
		sum = sum + arr[i];
		if(sum > sum_Left ) sum_Left = sum;
	}
	sum = 0;
	for(int i = m +1;i<=h;i++)
	{
		sum = sum + arr[i];
		if(sum> sum_Right) sum_Right = sum;
	}
	return sum_Left + sum_Right;
}
int maxSubArrSum(int arr[],int l,int h)
{
	if(l == h) return arr[l];
	int m = (l+h)/2;
	int max_ = INT_MIN;
	if(max_> sumLeftRight(arr,l,m,h)) max_ = sumLeftRight(arr,l,m,h); 
	return max_;
}
int main()
{
	int arr[] = {-2,-3,4,-1,-3,2,1,5,-3};
	int  h = sizeof(arr)/ sizeof(arr[0]);
	int max = maxSubArrSum(arr,0,h);
	cout<<"Day max cua mang can tim: "<<max<<endl;
}
