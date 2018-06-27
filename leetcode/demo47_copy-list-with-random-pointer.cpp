/*
2018年6月1日19:38:34

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/
#include <iostream>
using namespace std;


struct RandomListNode{
	int label;
	RandomListNode *next,*random;
	RandomListNode(int x):label(x),next(NULL),random(NULL){}


};


class Solution_demo47 {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
			return NULL;
		RandomListNode *Newhead = new RandomListNode(head->label);
		head = head->next;
		RandomListNode *tmp = Newhead;
		while(head)
		{
			RandomListNode *NewNode = new RandomListNode(head->label);    //新建一个结点
			tmp->next = NewNode;
			tmp = NewNode;
			head = head->next;
		}
		return Newhead;
    }
	RandomListNode *copyRandomList_1(RandomListNode *head) {
		if(!head)
			return NULL;
		RandomListNode *copy,*p;
		for(p=head;p;p=p->next)          //新建结点 并将新建的结点插入到原链表对应结点的后面
		{
			copy = new RandomListNode(p->label);
			copy->next = p->next;
			p->next = copy;
			p = p->next;
		}
		for(p=head;p;p=copy->next)      //复制random指针域
		{
			copy = p->next;
			copy->random = (p->random?p->random->next:NULL);
		}
		for(p=head,head=copy=p->next;p;)   //将新链表与旧链表分离
		{
			p = p->next = copy->next;
			copy = copy->next = p?p->next:NULL;
		}
		return head;
	}
};

template<typename T>
void Print_Randomlist(T *head)
{
	if(!head)
		return;
	while(head)
	{
		cout<<"head:("<<head<<")"<<ends<<head->label<<"->"<<endl;
		head = head->next;
	}
}

int main_demo47(int argc,char **argv)
{
	Solution_demo47 s1;
	RandomListNode l1(1),l2(2),l3(3),l4(4),l5(5),l6(6),l7(7),l8(8);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	l6.next = &l7;
	l7.next = &l8;
	Print_Randomlist(&l1);

	RandomListNode *res = NULL;
	res = s1.copyRandomList_1(&l1);
	Print_Randomlist(res);
	//Print_Randomlist(&l1);
	system("pause");
	return 0;
}