/*
2018��5��9��13:55:20
Given an array of integers, every element appears three times except for one. Find that single one.

Note: 
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
#include "iostream"
#include <map>
using namespace std;


class Solution_demo18 {
public:
	/*�Լ���˼·������map ��ֵ������������Ŀ*/
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
Single Number�ı��ʾ�����һ������¼ÿ��bit���ֵĴ��� ���һ��bit�������ξ͹��㣬����������ö������µ�λ����^����λ����Ǻ���Ȼ�ġ�
Single Number II�У�������������Ƶ��µ�ĳ��λ������Ҳ���Դﵽ��ͬ��Ч����
Single Number II��������¼ÿ��bit���ֵĴ�����һ�����㲻���ͼ����������� ones����¼ֻ���ֹ�һ�ε�bits ��twos����¼ֻ���ֹ����ε�bits��
ones&twosʵ���Ͼͼ�¼�˳��ֹ����ε�bits 
��ʱ��������ģ����� ����3�ξ͵���Ϊ0�Ĳ��� Ĩȥones��twos�ж�Ϊ1��bits
*/

//��һ������ʾ�ɶ�����������ʽ һ��ͳ��ÿ��λ�ϵ�1���ֵĴ���
int Solution_demo18::singleNumber_1(int A[],int n)
{
	int ones = 0;         //��¼ֻ����1�ε�bits
	int twos = 0;		 //��¼ֻ����2�ε�bits
	int threes = 0;
	for(int i=0;i<n;++i)
	{
		int t = A[i];
		twos |= ones&t;			//Ҫ�ڸ���ones֮ǰ����twos
		ones ^=t;
		
		threes = ones&twos;   //ones��twos�ж�Ϊ1��������3��
		
		ones &= ~threes;      //Ĩȥ������3�ε�bits
		twos &= ~threes;
	}
	return ones;
}
/*
����һ�£�������⣺one�����洢ֻ����һ��1�������ܼ򵥣�����1�ξ���1������2�ξ���0������3��Ҳ��1��ֻ�г������ε�ʱ��Ҫupdate����
two�����洢��������1������1��ǰ����֮ǰ��one����Ϊ1������Ҫ&one���ұ�����one֮ǰ���£�ͬʱ��Ҫ���ϱ�����ΪֻҪone��ͬʱΪ1������һֱֻ������1����ʱ������one�����2����0������three��0
��one��two����1��Ҳ��������1�ˣ�����one��two�õ�1��Ȼ�����one��two��Ϊ0��&~three��ͬʱҲ��֤����1��1��λ�����ϵ���0�ķǣ�Ҳ����1�����䣩
*/
/*
argc ���ⲿ��������ĸ�����argv[] ��Ÿ�����������,
*/
int main_demo18(int argc,char **argv)
{
	Solution_demo18 s1;
	int Array[10] = {11,11,12,12,13,13,13,12,11,19};
	int res = s1.singleNumber_1(Array,sizeof(Array)/sizeof(int));
	cout<<"������һ�ε�����Ϊ��"<<res<<endl;
	cout<<"argv:"<<argv<<endl;
	system("pause");
	return 0;
}