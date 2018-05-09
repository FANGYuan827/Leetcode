/*
2018年4月24日21:07:56
Say you have an array for which the i th element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/
#include "iostream"
#include <vector>
#include <algorithm>
using namespace std;

class Solution_demo12 {
public:
    int maxProfit(vector<int> &prices) {
		if(prices.size()<2)
			return 0;
		int length = prices.size();
		vector<int>delta_profit;
		for(int i=0;i<length;++i)
		{
			for(int j=i+1;j<length;++j)
				if(prices[j]>prices[i])
					delta_profit.push_back(prices[j]-prices[i]);
		}
		sort(delta_profit.begin(),delta_profit.end());
		if(!delta_profit.empty())
			return delta_profit[delta_profit.size()-1];
		return 0;
    }
	//保存每个最小值点 更新维护该值后面较大值和最小值的差值即可
	 int maxProfit_1(vector<int> &prices) {
		 if(prices.size()<1)
			 return 0;
		 int res = 0;
		 int min = prices[0];
		 for(int i=1;i<prices.size();++i)
		 {
			 if(prices[i]<min)
				 min = prices[i];
			 else
				 res = (res>prices[i]-min)?res:prices[i]-min;
		 }
		 return res;
	 }
};


void main_demo12()
{
	Solution_demo12 s1;
	vector<int>prices;
	prices.push_back(1);
	prices.push_back(2);
	prices.push_back(4);
	int res = 0;
	res = s1.maxProfit_1(prices);
	cout<<"最大利润为:"<<res<<endl;
	system("pause");
}