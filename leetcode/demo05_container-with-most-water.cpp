/*
2018��4��21��20:05:24
Given n non-negative integers a1 , a2 , ..., an , 
where each represents a point at coordinate (i, ai ). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai ) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/

#include "iostream"
#include <vector>
#include <algorithm>
using namespace std;


/*
 һ��ʼ��Ŀ��˼��û����⣬ľ��ЧӦ ��װ����ˮȡ��������ǿ�ľ��
����˼·��
����Ĺؼ������㣺
1�����������м���
2��ÿ�η�����̵İ�
ԭ�򣺴������յ㿪ʼ�ң���������ʱÿ�ƶ�һ���� ��Ȼ��ȱ�С
����һ�� ������� ֻ�и߶��������п������� ȥ�����ơ����̰壬�������߶Ƚ�С�ĵ�
*/
class Solution_demo05 {
public:
    int maxArea(vector<int> &height) {
		if(height.size()<=1)
			return 0;
        int res = 0;
		for(int i=0;i<height.size();++i)
		{
			for(int j=i+1;j<height.size();++j)
				if(res<((min(height[i],height[j]))*(j-i)))
                    res = (min(height[i],height[j]))*(j-i);
		}
		return res;
    }
	int maxArea_2(vector<int> &height) {
		if(height.size()<=1)
			return 0;
		int l,r,Max = -999;
		for(l=0,r=height.size()-1;l<r;)
		{
			Max = max(Max,(r-l)*min(height[l],height[r]));
			height[l]<height[r]?++l:--r;
		}
		return Max;
	}
};


void main_demo05()
{
	Solution_demo05 s1;
	vector<int>input;
	input.push_back(1);
	input.push_back(2);
	input.push_back(1);
	input.push_back(3);
	input.push_back(4);
	input.push_back(7);
	input.push_back(0);
	int res = 0;
	res = s1.maxArea(input);
	cout<<res<<endl;
	system("pause");
}