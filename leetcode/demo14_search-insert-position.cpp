/*
2018年4月27日16:29:28
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/
#include "iostream"
using namespace std;

/*
有序数组 二分法查找
*/
class Solution_demo14 {
public:
    int searchInsert(int A[], int n, int target) {
		if(n<1)
			return 0;
		if(A[0]>=target)
			return 0;
		if(A[n-1]<target)
			return n;
		for(int i=0;i<n-1;++i)
		{
			if(A[i] == target)
				return i;
			else
				if(A[i]<target&&A[i+1]>target)
					return i+1;
		}
		return n-1;
    }
};

void main_demo14()
{
	Solution_demo14 s1;
	int input[10];
	
	for(int i=0;i<10;i++)
	{
		input[i] = i*2+1;
	}
	input[0] = 1;
	input[1] = 3;
	int res = 0;
	res = s1.searchInsert(input,2,3);
	cout<<"结果为:"<<res<<endl;
	system("pause");
}