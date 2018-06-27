/*
2018��6��4��19:53:55
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given1->4->3->2->5->2and x = 3,
return1->2->2->4->3->5.
*/
#include <iostream>
using namespace std;



struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

/*
ʱ�临�Ӷȣ�O(n)
�ռ临�Ӷȣ�O(1)
����˼·��
�½����������� small��big
����������x���ֵ�ҵ�big������ȥ
��xС��ֵ�ҵ�small������ȥ��
�������������кϲ�
*/
class Solution_demo51 {
public:
    ListNode *partition(ListNode *head, int x) {
        if(!head)
			return NULL;
		ListNode *small = new ListNode(-1);
		ListNode *big = new ListNode(-1);
		ListNode *tmp_s = small;
		ListNode *tmp_b = big;
		while(head)
		{
			if(head->val>=x)
			{
				big->next = head;
				big = big->next;
			}
			else
			{
				small->next = head;
				small = small->next;
			}
			head = head->next;
		}
		big->next = NULL;
		small->next = tmp_b->next;
		return tmp_s->next;
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

int main_demo51(int argc,char **argv)
{
	Solution_demo51 s1;
	Solution_demo51 *s2 = new Solution_demo51();
	ListNode l1(1),l2(4),l3(3),l4(2),l5(5),l6(2);//,l7(7),l8(8),l9(9);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	Print_list(&l1);
	ListNode *res = s1.partition(&l1,4);
	Print_list(res);
	system("pause");
	return 0;
}