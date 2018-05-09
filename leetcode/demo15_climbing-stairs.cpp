/*
2018年4月27日20:15:00
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

#include "iostream"
using namespace std;


class Solution_demo15 {
public:
	/*
	递归解法  f(n) = f(n-1) + f(n-2)
	*/
    int climbStairs(int n) {
        if(n==1)
			return 1;
		if(n==2)
			return 2;
		return climbStairs(n-1)+climbStairs(n-2);
    }
	/*
	斐波那契数列
	*/
	int climbStairs_1(int n)
	{
		if(n<1)
			return 0;
		int count_1 = 1;
		int count_2 = 1;
		int count_3 = 0;
		while(--n)
		{
			count_3 = count_1+count_2;
			count_1 = count_2;
			count_2 = count_3;
		}
		return count_3;
	}
};
void main_demo15()
{
	Solution_demo15 s1;
	int res = 0;
	res = s1.climbStairs_1(5);
	cout<<"总共有:"<<res<<"种方法"<<endl;
	system("pause");
}