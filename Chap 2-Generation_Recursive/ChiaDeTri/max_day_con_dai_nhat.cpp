#include <iostream>

using namespace std;

int maxSup(int arr[],int n)
{
	int max_so_far = 0, max_ending_here = 0;
	for(int i = 0;i<n;i++)
	{
		max_ending_here = max_ending_here + arr[i];
		if(max_ending_here < 0)
			max_ending_here = 0;
		if(max_so_far < max_ending_here)
			max_so_far = max_ending_here;
	}
	return max_so_far;
}
int main()
{
	int arr[] = {-2,-3,4,-1,-3,2,1,5,-3};
	int n  = sizeof(arr)/sizeof(arr[0]);
	int max_sum = maxSup(arr,n);
	cout<<"Day con co tong lon nhat la: "<<max_sum;	
}
