/*
2018��4��20��21:03:06
Given an array of integers, every element appears twice except for one. Find that single one.
*/
#include "iostream"
#include <vector>
#include <algorithm>
using namespace std;

//���ߣ�����set ����һ�� ���ھ�ɾ�� �����ھͲ��� ��󷵻�set����ֻ����һ�ε�������

class Solution_demo03 {
public:
    int singleNumber(int A[], int n) {
		if(n==1)
			return A[0];
		if(n==3)
		{
			if(A[0]==A[1])
				return A[2];
			if(A[0]==A[2])
				return A[1];
			if(A[1]==A[2])
				return A[0];
		}
		vector<int>my_vec;
		int res = 0;
		for(int i=0;i<n;++i)
		{
			my_vec.push_back(A[i]);
		}
		sort(my_vec.begin(),my_vec.end());
		for(int i=1;i<my_vec.size()-2;++i)
		{
			if(my_vec[i]!=my_vec[i-1]&&my_vec[i]!=my_vec[i+1])
			{
				res = my_vec[i];
				return res;
			}
		}
		if(my_vec[0]==my_vec[1])
			return my_vec[my_vec.size()-1];
        return my_vec[0];
    }
};


/*
���ϴ���Ľⷨ��
�������������ص㣺
������ͬ�������Ľ��Ϊ0;
*/
class Solution_demo03_2 {
public:
	int singleNumber(int A[], int n) {
		int num = 0;
		for(int i=0;i<n;++i)
			num ^=A[i];
		return num;
	}
};

void main_demo03()
{
	Solution_demo03_2 s1;
	int numArray[] = {2,2,5,3,3};
	int res = s1.singleNumber(numArray,sizeof(numArray)/sizeof(int));
	cout<<res<<endl;
	system("pause");
}
