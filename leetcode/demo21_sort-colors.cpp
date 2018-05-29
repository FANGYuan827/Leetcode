/*
2018年5月14日18:53:41
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: 
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up: 
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/
#include <iostream>
using namespace std;


//比较原始的方法 时间复杂度O(n);
class Solution_demo21 {
public:
    void sortColors(int A[], int n) {
		if(A==NULL||n<1)
			return;
        int zero_count = 0;
		int one_count = 0;
		int two_count = 0;
		for(int i=0;i<n;++i)
		{
			switch(A[i])
			{
			case 0:
				{
					++zero_count;
					break;
				}
			case 1:
				{
					++one_count;
					break;
				}
			case 2:
				{
					++two_count;
					break;
				}
			default:
				break;
			}
		}
		for(int i=0;i<n;++i)
		{
			if(i<zero_count)
				A[i] = 0;
			if(i>=zero_count&&i<zero_count+one_count)
				A[i] = 1;
			if(i>=zero_count+one_count)
				A[i] = 2;
		}
    }
	void QuickSort(int A[],int n);
};
/*
网上大神的思想:
设置三个变量，分别代表数组前部zeroindex 当前遍历的位置 数组后部twoindex
1）当A[i]=0时 必然属于数组前部 则交换A[i]和A[zeroindex]
2）当A[i]=1时，只需要i++即可 因为只要排好了0和2 1自然就能够在中间；
3）当A[i]=2时，必然属于数组后部，则交换A[i]和A[twoindex] 接着twoindex--
此时就不能i++，因为交换过去的A[i]有可能是0或者2 所以需要在下一个循环里判断 这样他的位置才能够正确
*/

//在一块内存区间上做排序 （时间复杂度<O(n)）
void Solution_demo21::QuickSort(int A[],int n)
{
	if(A==NULL||n<1)
			return;
	int zeroindex = 0, i = 0,twoindex  = n -1;
	while(i < twoindex+1)
	{
		if(A[i]==0)
		{
			swap(A[i],A[zeroindex]);
			++zeroindex;
			++i;
		}
		else
			if(A[i]==2)
			{
				swap(A[i],A[twoindex]);
				--twoindex;
			}
			else
				++i;
	}

}

//0  --->>>红色
//1  --->>>白色
//2  --->>>蓝色
int main_demo21(int argc,char **argv)
{
	Solution_demo21 s1;
	int A[20] ={0,1,1,1,1,1,2,2,2,2,2,0,0,0,1,2,0,0,1,1};
	s1.QuickSort(A,sizeof(A)/sizeof(int));
	for(int i=0;i<sizeof(A)/sizeof(int);++i)
	{
		cout<<A[i]<<endl;
	}
	system("pause");
	return 0;
}