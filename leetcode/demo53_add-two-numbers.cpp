/*
 2018年6月5日16:25:37

 You are given two linked lists representing two non-negative numbers. 
 The digits are stored in reverse order and each of their nodes contain a single digit.
 Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};
/*
题目意思：
这就是普通的加法 只不过低位在左边 高位在右边 
与普通的加法不一样 进位是往右边进位
*/

class Solution_demo53{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		if(!l1)
			return l2;
		if(!l2)
			return l1;
		ListNode *head = new ListNode(0);
		ListNode *tmp = head;
		int up = 0;                     //进位 位
		while(l1&&l2)
		{
			int sum = l1->val+l2->val+up;
			up = sum/10;
			sum = sum%10;
			ListNode *node = new ListNode(sum);
			tmp->next = node;
			tmp = node;
			l1 = l1->next;
			l2 = l2->next;
		}

		/*
		if(up&&!l1&&!l2)          //此时的进位位放到下一次遍历中处理
		{
			ListNode *node = new ListNode(up);
			tmp->next = node;
			tmp = node;
			up = 0;
		}
		*/

		if(!l1)           //l1==NULL
		{
			while(l2)
			{
				int sum = l2->val+up;
				up = sum/10;
				sum = sum%10;
				ListNode *node = new ListNode(sum);
				tmp->next = node;
				tmp = node;
				l2 = l2->next;
			}
		}
		else
			if(!l2)
			{
				while(l1)
				{
					int sum = l1->val+up;
					up = sum/10;
					sum = sum%10;
					ListNode *node = new ListNode(sum);
					tmp->next = node;
					tmp = node;
					l1 = l1->next;
				}
			}
		if(up)      //l1与l2都遍历完成了 如果还有进位位 那么就必须在加一个链表结点
		{
			ListNode *node = new ListNode(up);
			tmp->next = node;
			tmp = node;
			up = 0;
		}
		return head->next;
	}
}; 

template<typename T>
void Print_list(T *head)
{
	if(!head)
		return;
	while(head)
	{
		cout<<head->val<<"->"<<ends;
		head = head->next;
	}
	cout<<endl;
}


int main_demo53(int argc,char **argv)
{
	Solution_demo53 s1;
	ListNode l1(1),l2(9),l3(3),l4(9),l5(9),l6(4);
	//l1.next = &l2;
	//l2.next = &l3;

	l4.next = &l5;
	//l5.next = &l6;

	ListNode *res = s1.addTwoNumbers(&l1,&l4);
	
	cout<<"计算结果为:"<<endl;
	Print_list(res);
	system("pause");
	return 0;
}