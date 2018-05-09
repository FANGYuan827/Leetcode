/*
2018年4月24日15:04:39
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/

/*
LeetCode中 负数不是回文数
*/
#include "iostream"
using namespace std;

class Solution_demo09 {
public:
    bool isPalindrome(int x) {
        if(x<0)
			return false;
		int abs_x = abs(x);    //取绝对值
		int tmp = 1;
		//将tmp位数变得与x一致
		while(abs_x/tmp>=10)      //防止tmp溢出  
		{
			tmp *= 10;
		}
		while(abs_x!=0)     //abs_x==0表示所有位都比较完
		{
			if(abs_x/tmp != abs_x%10)      //最高位不等于最低位 直接返回false
				return false;
			
			abs_x = (abs_x%tmp)/10;    //最高位等于最低位 (abs_x%tmp)-->>>去掉最高位 /10--->>>去掉最低位 之后继续比较
			tmp /= 100;
		}
		return true;
    }
};



void main_demo09()
{
	Solution_demo09 s1;
	bool res = s1.isPalindrome(125521);
	if(res)
		cout<<"该数是回文数"<<endl;
	else
		cout<<"该数不是回文数"<<endl;
	system("pause");
}