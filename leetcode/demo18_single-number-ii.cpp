/*
2018年5月9日13:55:20
Given an array of integers, every element appears three times except for one. Find that single one.

Note: 
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
#include "iostream"
#include <map>
using namespace std;


class Solution_demo18 {
public:
	/*自己的思路：运用map 键值对来求解这个题目*/
    int singleNumber(int A[], int n) {
		if(A==NULL||n<1)
			return 0;
		if(n==1)
			return A[0];
		map<int,int>my_map;
		int res = -1;
		for(int i=0;i<n;++i)
		{
			++my_map[A[i]];
		}
		for(int i=0;i<n;++i)
		{
			if(my_map[A[i]]==1)
			{
				res = A[i];
				break;
			}
		}
		return res;
    }
	int singleNumber_1(int A[],int n);
};
/*
Single Number的本质就是用一个数记录每个bit出现的次数 如果一个bit出现两次就归零，这种运算采用二进制下的位操作^（按位异或）是很自然的。
Single Number II中，如果定义三进制底下的某种位操作，也可以达到相同的效果，
Single Number II中如果想记录每个bit出现的次数，一个数搞不定就加两个数：用 ones来记录只出现过一次的bits 用twos来记录只出现过两次的bits，
ones&twos实际上就记录了出现过三次的bits 
这时候我们来模拟进行 出现3次就抵消为0的操作 抹去ones和twos中都为1的bits
*/

//把一个数表示成二进制数的形式 一起统计每个位上的1出现的次数
int Solution_demo18::singleNumber_1(int A[],int n)
{
	int ones = 0;         //记录只出现1次的bits
	int twos = 0;		 //记录只出现2次的bits
	int threes = 0;
	for(int i=0;i<n;++i)
	{
		int t = A[i];
		twos |= ones&t;			//要在更新ones之前更新twos
		ones ^=t;
		
		threes = ones&twos;   //ones和twos中都为1即出现了3次
		
		ones &= ~threes;      //抹去出现了3次的bits
		twos &= ~threes;
	}
	return ones;
}
/*
解释一下，个人理解：one用来存储只出现一次1（用异或很简单，出现1次就是1，出现2次就是0，出现3次也是1，只有出现三次的时候要update），
two用来存储出现两次1（两次1的前提是之前的one必须为1，所以要&one而且必须在one之前更新，同时还要加上本身，因为只要one不同时为1，就是一直只有两个1，这时候明显one异或了2次是0，所以three是0
当one和two都是1，也就是三个1了，相与one和two得到1，然后更新one和two都为0，&~three，同时也保证不是1和1的位置与上的是0的非（也就是1，不变）
*/
/*
argc 是外部命令参数的个数，argv[] 存放各参数的内容,
*/
int main_demo18(int argc,char **argv)
{
	Solution_demo18 s1;
	int Array[10] = {11,11,12,12,13,13,13,12,11,19};
	int res = s1.singleNumber_1(Array,sizeof(Array)/sizeof(int));
	cout<<"仅出现一次的数字为："<<res<<endl;
	cout<<"argv:"<<argv<<endl;
	system("pause");
	return 0;
}