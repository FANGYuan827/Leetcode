/*
2018��5��14��18:53:41
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


//�Ƚ�ԭʼ�ķ��� ʱ�临�Ӷ�O(n);
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
���ϴ����˼��:
���������������ֱ��������ǰ��zeroindex ��ǰ������λ�� �����twoindex
1����A[i]=0ʱ ��Ȼ��������ǰ�� �򽻻�A[i]��A[zeroindex]
2����A[i]=1ʱ��ֻ��Ҫi++���� ��ΪֻҪ�ź���0��2 1��Ȼ���ܹ����м䣻
3����A[i]=2ʱ����Ȼ��������󲿣��򽻻�A[i]��A[twoindex] ����twoindex--
��ʱ�Ͳ���i++����Ϊ������ȥ��A[i]�п�����0����2 ������Ҫ����һ��ѭ�����ж� ��������λ�ò��ܹ���ȷ
*/

//��һ���ڴ������������� ��ʱ�临�Ӷ�<O(n)��
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

//0  --->>>��ɫ
//1  --->>>��ɫ
//2  --->>>��ɫ
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