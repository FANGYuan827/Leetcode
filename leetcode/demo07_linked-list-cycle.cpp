/*
2018��4��24��09:58:33
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/
#include "iostream"
using namespace std;
/*
ȷ�������еĽ����֮�󣬿���ָ��������ָ��ͷ���
��ָ�����߽�����Ĳ�����
����ָ����ͬʱ����ƶ������ٴ�����ʱ�Ľ�㼴Ϊ������ڵ�ַ;
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
	int CountListNodeNum(ListNode *pHead)    //ͳ�������еĽ����Ŀ 
	{									    //��������ָ�룬����ͷ����������ָ��ÿ���ƶ�������� ��ָ��ÿ���ƶ�һ����� ����������ٴ����� ����ѭ��
										   //����ѭ��֮���ٴ��ƶ���ָ��,��ָ�벻������ʱ��ָ��ͻ��ڻ����ƶ�������ָ���ٴλص�����ָ�������Ľ��ʱ ����ͳ�Ƴ������еĽ����Ŀ
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
		cout<<"�����л�"<<endl;
	else
		cout<<"�������ڻ�"<<endl;

	system("pause");
}


