/*
2018年4月24日20:19:44
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array[−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray[4,−1,2,1]has the largest sum =6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
#include "iostream"
using namespace std;

/*
解题思路：
直接从头开始累加并统计此时是否为最大值  
累加直到和为负，舍弃前面这段（因为所加和不能为后面的累加值带来正的影响） sum清零 继续累加
*/
class Solution_demo11 {
public:
    int maxSubArray(int A[], int n) {
       if(n==0)
		   return 0;
	   int max = A[0],sum = 0;
	   for(int i=0;i<n;++i)
	   {
		   sum+=A[i];
		   if(max<sum)
			   max = sum;
		   if(sum<0)
			   sum = 0;
	   }
	   return max;
    }
};

void main_demo11()
{
	Solution_demo11 s1;
	int input[9] = {-2,-1,-3,-4,-1,-2,-1,-5,-4};
	int maxSubArray = 0;
	maxSubArray = s1.maxSubArray(input,9);
	cout<<"最大连续子数组的和为:"<<maxSubArray<<endl;
	system("pause");
}