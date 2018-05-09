/*
2018年4月20日21:51:19
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. 
You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times).
However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

#include "iostream"
#include <vector>
#include <algorithm>
using namespace std;


/*
判断相邻是否递增，因为连续递增可以合起来看为一次买入卖出操作，所以统计所有递增量即可
*/

class Solution_demo04 {
public:
    int maxProfit(vector<int> &prices) {
		if(prices.size()<1)
			return 0;
		int maxProfit = 0 ;
		for(int i=1;i<prices.size();++i)
		{
			if(prices[i]>prices[i-1])
				maxProfit+=(prices[i]-prices[i-1]);

		}
		return maxProfit;
    }
};

void main_demo04()
{



	system("pause");
}