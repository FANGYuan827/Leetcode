/*
2018年5月14日16:35:04
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
*/

#include <iostream>
using namespace std;



struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

//不借助额外的内存空间 通过移动指针的方式解决问题

/*
解题思路：新建一个链表头节点指针（初始值为空），首先根据传入参数，确定头结点，
然后不断对比两个链表结点值的大大小，不断将较小的值挂到这个新的链表中去（通过修改next域的方式实现）
退出循环之后，将剩余的结点直接挂到新链表上，最后将这个头结点返回；
其实这个方法改变的是两个链表结点之间的相互关系
*/
class Solution_demo20 {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==NULL)
			return l2;
		if(l2==NULL)
			return l1;
		if(l1==NULL&&l2==NULL)
			return NULL;
		ListNode *head = NULL;
		head = (l1->val<=l2->val)?l1:l2;
		ListNode *res = head;
		while(l1!=NULL&&l2!=NULL)
		{
			if(l1->val<=l2->val)
			{
				if(head!=l1)
				{
					head->next = l1;
					head = head->next;
				}
				l1 = l1->next;
			}
			else
			{
				if(head!=l2)
					{
						head->next = l2;
						head = head->next;
					}
				l2 = l2->next;
			}
		}
		if(l1==NULL)
			head->next = l2;
		if(l2==NULL)
			head->next = l1;
		return res;
    }
	//递归的思想：
	ListNode *Merge(ListNode *l1,ListNode *l2);
};

ListNode *Solution_demo20::Merge(ListNode *l1,ListNode *l2)
{
	if(l1==NULL)
		return l2;
	if(l2==NULL)
		return l1;
	if(l1->val<=l2->val)
	{
		l1->next = Merge(l1->next,l2);
		return l1;
	}
	else
	{
		l2->next = Merge(l1,l2->next);
		return l2;
	}
}
int main_demo20(int argc,char **argv)
{
	Solution_demo20 s1;
	ListNode l1(1),l2(2),l3(7),l4(4),l5(7),l6(6),l7(7);
	l1.next = &l3;
	l3.next = &l5;
	l5.next = &l7;

	l2.next = &l4;
	l4.next = &l6;

	ListNode *res = NULL;
	//res  = s1.mergeTwoLists(&l1,&l2);
	res = s1.Merge(&l1,&l2);
	while(res!=NULL)
	{
		cout<<res->val<<"->";
		res = res->next;
	}
	cout<<endl;
	system("pause");
	return 0;
	
}