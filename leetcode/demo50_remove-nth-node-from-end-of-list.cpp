/*
2018年6月4日16:06:05 
Given a linked list, remove the n th node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note: 
Given n will always be valid.
Try to do this in one pass.
*/
#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution_demo50 {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(n<0)
		{
			return head;
		}
		vector<ListNode *>v;
		ListNode *tmp = head;
		ListNode *top =NULL;
		while(tmp)
		{
			v.push_back(tmp);
			tmp = tmp->next;
		}
		if(n>v.size())
		{
			return head;
		}
		if(n==v.size())
		{
			v[0]->next = NULL;
			if(v.size()==1)
				return NULL;
			else
				return v[1];
		}
		else
		{
			if(n==1)
				v[v.size()-n-1]->next = NULL;
			else
			{
				v[v.size()-n-1]->next = v[v.size()-n+1];
			}
			return head;
		}
    } 
	ListNode *removeNthFromEnd_1(ListNode *head, int n);                //不能带花括号 函数体
};


/*
本题的关键是找到倒数第n个节点
定义两个指针pre、after同时指向head
先将pre指针向后移动n步
然后pre、after同时向后移动 当pre==NULL时 此时after所指结点的下一个结点 就是倒数第n个结点
*/
ListNode * Solution_demo50::removeNthFromEnd_1(ListNode *head,int n)
{
	if(n<0)
		return head;
	ListNode *pre = head,*after = head;
	while(n&&pre)
	{
		pre = pre->next;
		n--;
	}
	if(!pre&&n==0)                 //表示删除是链表的头结点
		return head->next;
	
	/*
	if(!pre)					//
	{
		return head;
	}
	*/
	while(pre->next)
	{
		after = after->next;
		pre = pre->next;
	}
	after->next = after->next?after->next->next:NULL;    //删除after所指向结点的下一个结点（这个结点就是需要删除的结点）
	return head;
}

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

int main_demo50(int argc,char **argv)
{
	Solution_demo50 s1;
	ListNode l1(1),l2(2),l3(3),l4(4),l5(5),l6(6),l7(7),l8(8),l9(9);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	l6.next = &l7;
	l7.next = &l8;
	l8.next = &l9;
	Print_list(&l1);
	ListNode *phead = s1.removeNthFromEnd_1(&l1,9);
	Print_list(phead);
	system("pause");
	return 0;
}