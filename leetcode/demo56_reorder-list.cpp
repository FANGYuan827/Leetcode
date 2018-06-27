/*
2018年6月20日21:15:59
*/
#include <iostream>
#include <vector>
using namespace std;


struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};


/*
自己的做法：时间复杂度O(n) 空间复杂度O(n) --->>>将所有链表节点都放入一个数组中 然后一个一个的连起来
*/
class Solution_demo56 {
public:
    void reorderList(ListNode *head) {
		if(!head||!(head->next))
			return;
		ListNode *current = head;
		vector<ListNode *>my_vector;
		while(current)
		{
			my_vector.push_back(current);
			current = current->next;
		}
		int length = my_vector.size();
		int i = 0;
		for(;i<length/2;++i)
		{
			my_vector[i]->next = my_vector[length-1-i];
			my_vector[length-1-i]->next = my_vector[i+1];
		}
		my_vector[i]->next = NULL;
    }
	//快慢指针找到中间节点 将后面的链表反转（前插法）合并链表   时间复杂度O(n) 空间复杂度O(1)
	void reorderList_1(ListNode *head)
	{
		if(!head||!(head->next))
			return;
		ListNode *phead = head;
		ListNode *fast = head,*slow = head;
		
		/*
		//这种求链表中间节点的方法太笨重了
		int length = 0;
		while(phead)   //求链表节点数  
		{
			++length;
			phead = phead->next;
		}
		for(int i=0;i<length/2;++i)
		{
			fast = fast->next;
		}
		while(fast&&fast->next)    //跳出循环之后 slow 指向新链表的尾节点
		{
			slow = slow->next;
			fast = fast->next;
		}
		*/
		//通过快慢指针直接找到链表的中间节点
		while(fast->next&&fast->next->next)       //这种方法比上面 那种先求链表节点数 在移动指针的方法好多了
		{ 
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode *sublist = slow->next;     //sublist为子链表的头结点
		slow->next = NULL;
		ListNode *reverse_sublist = reverselist(sublist);  //子链表进行翻转

		while(head&&reverse_sublist)     //merge两个链表
		{
			ListNode *tmp1 = reverse_sublist->next;
			ListNode *tmp2 = head->next;
			
			reverse_sublist->next = head->next;
			head->next = reverse_sublist;
			
			reverse_sublist = tmp1;
			head = tmp2;
		}
	}
private:
		ListNode *reverselist(ListNode *head)
		{
			if(!head||!(head->next))
				return head;
			ListNode *pre = NULL;
			ListNode *current = head;
			ListNode *after = head->next;
			pre = current;
			current = current->next;
			pre->next = NULL;
			while(current)
			{
				after = current->next;
				current->next = pre;     //current->next = pre：一开始报错
				pre = current;
				current = after;
			}
			return pre;
		}
};
/*
 网上大神的做法：
public class Solution {
    public void reorderList(ListNode head) {
        if(head==null)
            return;
        ListNode slow=head;
        ListNode fast=head;
        while(fast.next!=null&&fast.next.next!=null)          //通过快慢指针找到中间节点
		{
            fast=fast.next.next;
            slow=slow.next;
        }
        ListNode pre=slow.next;
        if(pre!=null&&pre.next!=null){
            ListNode nex=pre.next;
            while(nex!=null)         //反转链表
			{
            	pre.next=nex.next;
            	nex.next=slow.next;
            	slow.next=nex;
            	nex=pre.next;
           }        
        }     
        merge(head,slow);
    }
    public void merge(ListNode head,ListNode slow){
        ListNode p=head;
        ListNode q=slow.next;
        while(q!=null&&p!=null){
            slow.next=q.next;
            q.next=p.next;
            p.next=q;
            q=slow.next;
            p=p.next.next;
        }
    }
}
*/

int main_demo56(int argc,char *argv)
{
	Solution_demo56 *s1 = new Solution_demo56();
	ListNode l1(1),l2(2),l3(3),l4(4),l5(5),l6(6),l7(7);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	l6.next = &l7;

	ListNode *res = NULL;
	res = &l1;
	cout<<"排序之前的结果:"<<endl;
	while(res)
	{
		cout<<res->val<<"->";
		res = res->next;
	}
	cout<<endl;
	s1->reorderList_1(&l1);
	res = &l1;
	cout<<"排序之后的结果为:"<<endl;
	while(res)
	{
		cout<<res->val<<"->";
		res = res->next;
	}
	cout<<endl;
	system("pause");
	return 0;
}