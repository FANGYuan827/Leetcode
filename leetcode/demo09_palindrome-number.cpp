/*
2018��4��24��15:04:39
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/

/*
LeetCode�� �������ǻ�����
*/
#include "iostream"
using namespace std;

class Solution_demo09 {
public:
    bool isPalindrome(int x) {
        if(x<0)
			return false;
		int abs_x = abs(x);    //ȡ����ֵ
		int tmp = 1;
		//��tmpλ�������xһ��
		while(abs_x/tmp>=10)      //��ֹtmp���  
		{
			tmp *= 10;
		}
		while(abs_x!=0)     //abs_x==0��ʾ����λ���Ƚ���
		{
			if(abs_x/tmp != abs_x%10)      //���λ���������λ ֱ�ӷ���false
				return false;
			
			abs_x = (abs_x%tmp)/10;    //���λ�������λ (abs_x%tmp)-->>>ȥ�����λ /10--->>>ȥ�����λ ֮������Ƚ�
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
		cout<<"�����ǻ�����"<<endl;
	else
		cout<<"�������ǻ�����"<<endl;
	system("pause");
}