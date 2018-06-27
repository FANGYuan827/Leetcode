/*
2018年6月1日15:49:10
Given a linked list, swap every two adjacent nodes and return its head.
For example,
Given1->2->3->4, you should return the list as2->1->4->3.
Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.    //不能改变链表节点中的值 只能改变链表自身 
*/
#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

/*
解题思路：
定义三个辅助指针变量 tmp1指向头结点 tmp2指向下一个结点 tmp3指向在下一个结点（用于保存下一次交换两个结点的起始地址）
每次处理两个结点 （主要是改变结点next指针的指向）
关键点：前后两次处理 结点的连接；（最后一个结点next指针如果处理不好就会出现循环链表了）

*/
class Solution_demo46 {
public:
    ListNode *swapPairs(ListNode *head) {
        if(!head)
			return NULL;
		if(head->next==NULL)
			return head;
		ListNode *phead = NULL;
		phead = head->next;//==NULL?head:head->next;
		ListNode *tmp1 = head;
		ListNode *tmp2 = tmp1->next;
		ListNode *tmp3 = tmp2->next;
		while(tmp1&&tmp2)
		{
			tmp1->next = tmp3;
			tmp2->next = tmp1;

			ListNode *tmp = tmp1;
			tmp1 = tmp3;
			if(tmp1)
				tmp2 = tmp1->next;
			if(tmp2)
				tmp3 = tmp2->next;
			if(tmp2&&tmp->next)       //前后两次处理结点的连接
				tmp->next = tmp2;
		}
		return phead;
    }
};

void Print_list(ListNode *head)
{
	if(!head)
		return ;
	while(head)
	{
		cout<<head->val<<"->"<<ends;
		head = head->next;
	}
	cout<<endl;
}

int main_demo46(int argc,char **argv)
{
	Solution_demo46 s1;
	ListNode l1(1),l2(2),l3(3),l4(4),l5(5),l6(6),l7(7),l8(8);
	l1.next = &l2;
	//l2.next = &l3;
	//l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	l6.next = &l7;
	l7.next = &l8;
	cout<<"Before:"<<endl;
	Print_list(&l1);
	ListNode *res = s1.swapPairs(&l1);
	cout<<"After:"<<endl;
	Print_list(res);
	system("pause");
	return 0;
}