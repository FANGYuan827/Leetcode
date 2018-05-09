/*
2018年4月20日19:04:38
Sort a linked list in O(n log n) time using constant space complexity.
时间复杂度：O(nlogn) 空间复杂度: O(1)
*/
#include "iostream"
using namespace std;



 struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution_demo01 {
public:
    ListNode *sortList(ListNode *head) {
		if(head==NULL)
			return NULL;
		for(ListNode *first = head;first!=NULL;first=first->next)
		{
			for(ListNode *second = first->next;second!=NULL;second = second->next)
			{
				if(first->val>second->val)
				{
					ListNode *tmp = first;
					first = second;
					second = tmp;
				}
			}
		}
		return head;
        
    }
};

void main_demo01()
{
	Solution_demo01 s1;
	ListNode l1(1),l2(3),l3(6),l4(4),l5(2),l6(12),l7(0);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next =&l5;
	l5.next = &l6;
	l6.next = &l7;
	ListNode *res = NULL;
	res = s1.sortList(&l1);

	while(res!=NULL)
	{
		cout<<res->val<<ends;
		res = res->next;
	}
	cout<<endl;
	system("pause");
}