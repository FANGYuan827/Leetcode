/*
2018年6月20日19:13:58
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given1->2->3->4->5->NULL, m = 2 and n = 4,

return1->4->3->2->5->NULL.

Note: 
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/
#include <iostream>
#include <stack>
using namespace std;


struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

/*常规做法：利用stack先入后出的性质 将需要reverse的节点都入栈 然后在依次出栈 即可;*/
class Solution_demo55 {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(!head)
			return head;
		stack<ListNode *>my_stack;
		ListNode *current = head;
		ListNode *before = NULL;
		int count = 0;
		while(count<n)
		{
			++count;
			if(count==m-1)
			{
				before = current;
			}
			if(count>=m)
			{
				my_stack.push(current);
			}
			current = current->next;
		}
		if(!before)      //链表的第一个节点也要reverse
		{
			ListNode *res = my_stack.top();
			ListNode *tmp = res;
			my_stack.pop();
			while(!my_stack.empty())
			{
				tmp->next = my_stack.top();
				my_stack.pop();
				tmp = tmp->next;
			}
			tmp->next = current;
			return res;
		}
		while(!my_stack.empty())
		{
			before->next = my_stack.top();
			my_stack.pop();
			before = before->next;
		}
		before->next = current;
		return head;
    }
};

int main_demo55(int argc,char **argv)
{
	ListNode l1(1),l2(2),l3(3),l4(4),l5(5),l6(6);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	Solution_demo55 s1;
	ListNode *res = s1.reverseBetween(&l1,2,6);
	while(res)
	{
		cout<<res->val<<"->";
		res = res->next;
	}
	cout<<endl;
	system("pause");
	return 0;
}