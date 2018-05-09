/*
2018年4月24日16:03:30
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
#include "iostream"
using namespace std;

/*
二叉搜索树
有个性质， 就是左边的数都比根小 右边的数都比根大
如果二叉树的结点是从1到n，所以我们就可以确定：

如果根是k 则根左边的数是1到k-1 右边的数是k+1到n
对于一个根来说，唯一二叉树的数量是其左子树的数量乘以右子树的数量，这是简单的乘法原理。

并且 左右子树的形态数量跟具体的数无关 只跟这个树里有多少结点有关。

而根可以选择从1到n的任意数，唯一二叉树的总数就是根从1到n的树相加。
所以该问题化简为以k为根，其唯一左子树和右子树各有多少，这就是个动态规划的问题了。
我们建立一个数组dp[i]，代表节点数为i的唯一子树有多少个。显然dp[0]=dp[1]=1。

思路：
    考虑根节点，设对于任意根节点k，有f(k)种树的可能。
    比k小的k-1个元素构成k的左子树。则左子树有f(k-1)种情况。
    比k大的n-k个元素构成k的右子树。则右子树有f(n-k)种情况。
    易知，左右子树相互独立，所以f(k)=f(k-1)*f(n-k)。
    综上，对于n，结果为k取1,2,3,...,n时，所有f(k)的和。
代码思路：
    根据上述思路可以用简单的递归方法快速解决。
    现在考虑非递归解法，用数组记录每个f(i)的值，记f(0)=1,f(1)=1。
    根据公式：f(k)=f(k-1)*f(n-k)，访问数组中的元素。
    循环求和，结果更新到数组中。
(PS:此题可用Catalan number快速求解：对于n，答案为1/(n+1)*nC2n。)
*/
class Solution_demo10 {
public:
    int numTrees(int n) {             //非递归
		if(n==0)
			return 1;
		int *res = new int[n+1];
		res[0] = 1;
		res[1] = 1;
		for(int i=2;i<=n;++i)
		{
			res[i] = 0;
			for(int j=1;j<=i;++j)
				res[i] += res[j-1]*res[i-j];
		}
		return res[n];
    }
	int numTrees_1(int n)           //递归
	{
		if(n==0||n==1)
			return 1;
		int res = 0;
		for(int i=1;i<=n;++i)
			res +=numTrees_1(i-1)*numTrees_1(n-i);
		return res;
	}
};

void main_demo10()
{
	Solution_demo10 s1;
	int res = s1.numTrees_1(3);
	cout<<"构成二叉搜索树的情况总共有:"<<res<<endl;
	system("pause");
}