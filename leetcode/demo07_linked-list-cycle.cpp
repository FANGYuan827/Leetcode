/*
2018年4月24日09:58:33
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/
#include "iostream"
using namespace std;
/*
确定链表环中的结点数之后，快慢指针在重新指向头结点
快指针先走结点数的步数，
快慢指针在同时向后移动，当再次相遇时的结点即为环的入口地址;
*/

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


class Solution_demo07 {
public:
    bool hasCycle(ListNode *head) {
		if(head==NULL)
			return false;
		return (CountListNodeNum(head)>0?true:false);
        
    }
private:
	int CountListNodeNum(ListNode *pHead)    //统计链表环中的结点数目 
	{									    //定义两个指针，都从头结点出发，快指针每次移动两个结点 慢指针每次移动一个结点 当两个结点再次相遇 跳出循环
										   //跳出循环之后，再次移动慢指针,快指针不动（这时慢指针就会在环中移动），慢指针再次回到快慢指针相遇的结点时 即可统计出链表环中的结点数目
		int Node_total = 0;
		if(pHead == NULL)
			return 0;
		ListNode *tmp_1 = pHead,*tmp_2 = pHead;
		while(true)
		{
			tmp_1 = tmp_1->next;
			tmp_2 = tmp_2->next;
			if(tmp_1==NULL||tmp_2==NULL)
				return 0;
			tmp_2 = tmp_2->next;
			if(tmp_1==NULL||tmp_2==NULL)
				return 0;
			if(tmp_1==tmp_2)
                break;
		}
		tmp_1 = tmp_1->next;
		++Node_total;
		while(tmp_1!=tmp_2)
		{
			tmp_1 = tmp_1->next;
			++Node_total;
		}
		return Node_total;
	} 

};



void main_demo07()
{	
	Solution_demo07 s1;
	ListNode l1(1),l2(2),l3(3),l4(4),l5(5),l6(6);
	
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	l6.next = &l3;
	bool res = false;
	res = s1.hasCycle(&l1);
	if(res==true)
		cout<<"链表有环"<<endl;
	else
		cout<<"链表不存在环"<<endl;

	system("pause");
}


