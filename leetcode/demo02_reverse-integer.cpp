/*
2018年4月20日20:19:09
Reverse digits of an integer.
Example1: x = 123, return 321
Example2: x = -123, return -321
*/


#include "iostream"
#include <queue>
#include <string>
using namespace std;

class Solution_demo02 {
public:
    int reverse(int x) {
        queue<int>my_queue;
        if(abs(x)<10)
            return x;
		long tmp = x;
        GetBit(abs(tmp),my_queue);
		long sum = 0;
		while(!my_queue.empty())
		{
			sum = sum*10+my_queue.front();
			my_queue.pop();
		}
		return (x>0?sum:-sum);
    }
private:
	void GetBit(long num,queue<int>&input)
	{
		while(num>0)
		{
			int tmp = num%10;
			input.push(tmp);
			num = num/10;
		}
	}

};

//要考虑溢出
class Solution_demo02_2{
public:
	int reverse(int x) {
		int res = 0;
		while(x>0)
		{
			int tail = x%10;
			int newres = res *10 + tail;
			if((newres-tail)/10!=res)         // (newres-tail)/10!=res 表明newres溢出了
				return 0;
			res = newres;
			x/=10;
		}
		return res;
	}
};

void main_demo02()
{
	Solution_demo02_2 s1;
	int res = s1.reverse(1000000003);
	cout<<res<<endl;
	system("pause");
}