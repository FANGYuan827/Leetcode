/*
2018年6月4日22:09:32
There are two sorted arrays A and B of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).


*/
#include <iostream>
#include <vector>
using namespace std;


class Solution_demo52 {
public:
	//时间复杂度：O(m+n) 空间复杂度O(m+n)   合并到m+n/2时 就退出
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		if(m==0&&n==0)
			return 0;
		vector<int>vec;
		int i = 0,j = 0;
		//for(;i<m&&j<n;)
		while(vec.size()<(m+n)/2+1)
		{
			if(i>=m||j>=n)
			{
				if(j<n)
				{
					vec.push_back(B[j]);
					++j;
				}
				if(i<m)
				{
					vec.push_back(A[i]);
					++i;
				}
			}
			else
			{
				if(A[i]>B[j])
				{
					vec.push_back(B[j]);
					++j;
				}
				else
				{
					vec.push_back(A[i]);
					++i;
				}
			}
			if(vec.size()>=(m+n)/2+1)
			{
				break;
			}
		}
		if((m+n)&0x1)
			return vec[vec.size()-1];
		else
			return (vec[vec.size()-1]+vec[vec.size()-2])/2.0;


		/*
		if(i==m)    //说明数组A遍历完了
		{
		for(;j<n;++j)
		vec.push_back(B[j]);
		}
		if(j==n)
		{
		for(;i<m;++i)
		vec.push_back(A[i]);
		}
		if(vec.size()%2!=0)
		{
		return vec[vec.size()/2];
		}
		else
		{
		return ((double)(vec[(vec.size()-1)/2]+vec[(vec.size()+1)/2]))/2.0;
		}
		*/
	}
	double findMedianSortedArrays_1(int A[],int m,int B[],int n);
private:
	double findKth(int A[],int m,int B[],int n,int k);
};

/*
解题思路：
我们可以将原问题转换成一个寻找第k小数的问题（假设两个序列升序排列）这样中位数数实际上是第（m+n）/2小的数
所以只要解决了第k小的数，原问题也就得到解决了。

首先假设数组A和数组B的元素个数都大于k/2 我们比较A[k/2-1]和B[k/2-1]两个元素 这两个元素分别表示A的第k/2小和B的第k/2小的元素
这两个元素的比较结果有三种: > < =
如果 A[k/2-1]<B[k/2-1] 这表示A[0]到A[k/2-1]的元素都在A和B合并之前的前k小的元素中 换句话说 A[k/2-1]不可能大于两数组合并之后的第k小的值 所以我们将其抛弃

当A[k/2-1] = B[k/2-1]时 我们已经找到第k小的数 也即这个相等的元素 我们将其记为m 
由于在A和B中分别有k/2-1个元素小于m 所以m即是第k小的数
（如果k为奇数 则m不是中位数）这里进行了理想化考虑 在实际代码中略有不同 是先求k/2 然后利用k-k/2获得另一个数


通过上面的分析，我们既可以采用递归的方式实现寻找第k小的数 此外我们还需要考虑几个边界条件：
如果A或者B为空 则直接返回B[k-1]或者A[k-1]
如果k为1 我们只需要返回A[0]和B[0]中的较小值
如果A[k/2-1] = B[k/2-1] 返回其中一个


*/
double Solution_demo52::findMedianSortedArrays_1(int A[],int m,int B[],int n)
{
	int total = m+n;
	if(total&0x1)
		return findKth(A,m,B,n,total/2+1);
	else
		return (findKth(A,m,B,n,total/2)+findKth(A,m,B,n,total/2+1))/2;
}
double Solution_demo52::findKth(int A[],int m,int B[],int n,int k)    //k表示第k小
{
	if(m>n)
		return findKth(B,n,A,m,k);          //始终保持元素较少的数组位于前面的位置
	if(m==0)
		return B[k-1];                    //如果位于前面的数组为空 则直接返回后面数组的第k-1个元素
	if(k==1)
		return min(A[0],B[0]);          //如果k=1 则返回两个数组头元素的最小值

	int pa = min(k/2,m),pb = k-pa;
	if(A[pa-1]<B[pb-1])
		return findKth(A+pa,m-pa,B,n,k-pa);
	else
		if(A[pa-1]>B[pb-1])
			return findKth(A,m,B+pb,n-pb,k-pb);
		else
			return A[pa-1];

}

int main_demo52(int argc,char **argv)
{
	Solution_demo52 *s1 = new Solution_demo52();
	int A[10] = {1,2,3,5,6,7,8,9,12,23};
	int B[15] = {2,3,5,6,7,8,9,13,14,16,17,19,20,45,100};
	double res = 0;
	res = s1->findMedianSortedArrays(A,0,B,2);
	cout<<"两个数组的中位数为:"<<res<<endl;
	if(s1)
		delete s1;
	s1 = NULL;
	system("pause");
	return 0;
}