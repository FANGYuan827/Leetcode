/*
2018年6月21日14:51:06
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list:1->2->3->4->5

For k = 2, you should return:2->1->4->3->5

For k = 3, you should return:3->2->1->4->5
*/
#include <iostream>
#include <stack>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

/*
自己的解题思路:
借助stack结构 以k个结点为一组 依次如栈 然后又依次出栈（借助栈先进后出的特点将链表进行反转）时间复杂度 O(n) 空间复杂度O(min(k,n))
*/
class Solution_demo58 {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
		if(!head||k<=1||!head->next)     //牛客网上一直不能AC的原因 一直提示段错误(很大的原因是访问了错误的地址 比如访问了0x00000000的地址空间)  因为没有加上||!head->next
			return head;
		stack<ListNode *>my_stack;
		ListNode *sublist = head;
		ListNode *res = NULL;
		ListNode *top = NULL;
		while(sublist)
		{
			my_stack.push(sublist);
			sublist = sublist->next;
			if(my_stack.size()==k)
			{
				if(!top) 
					top = my_stack.top();
				else
				{
					top->next = my_stack.top();
					top = top->next;
				}
				my_stack.pop();
				if(!res)
				{
					res = top;
				}
				while(!my_stack.empty())
				{
					ListNode *tmp = my_stack.top();
					my_stack.pop();
					top->next = tmp;
					top = tmp;
				}
			}
		}
		if(my_stack.size()>1)
		{
			while(my_stack.size()!=1)
			{
				my_stack.pop();
			}
			if(top)
				top->next = my_stack.top();
			else
				return head;                  //表示k的值大于链表的结点数
		}
		else
		{
			top->next = my_stack.size()==1?my_stack.top():NULL;
		}
		return res;
    }
};

int main_demo58(int argc,char **argv)
{
	Solution_demo58 s1;
	ListNode l1(1),l2(2),l3(3),l4(4),l5(5),l6(6),l7(7),l8(8),l9(9);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	l6.next = &l7;
	l7.next = &l8;
	l8.next = &l9;


	
	ListNode *res = NULL;
	res = &l1;
	while(res)
	{
		cout<<res->val<<"->";
		res = res->next;
	}
	cout<<endl;
	res= s1.reverseKGroup(&l1,2);
	while(res)
	{
		cout<<res->val<<"->";
		res = res->next;
	}
	cout<<endl;
	system("pause");
	return 0;
}