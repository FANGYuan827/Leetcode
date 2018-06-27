/*
2018年6月5日20:00:55 
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

/*
自己的解题思路：
先确定lists中的非空链表的位置 然后将这些非空链表都串起来形成一个大的链表
最后对这个大链表排序 并返回拍完序之后新链表的头结点
*/

class Solution_demo54 {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
		if(lists.empty())   //空
			return NULL;
		int length = lists.size();
		vector<int>position;
		for(int i=0;i<length;++i)
		{
			if(lists[i]!=NULL)
			{
				position.push_back(i);
			}
		}
		if(position.empty())
			return NULL;
		ListNode *res = new ListNode(-1);
		res->next = lists[position[0]];
		ListNode *tmp = NULL;
		int count = position.size();
		vector<int>::iterator it = position.begin();
		for(int i=0;i<count-1;++i)
		{
			tmp = findlastNode(lists,position[i]);
			tmp->next = lists[position[i+1]];
		}
		return sortList(res->next);
    }
private:
	ListNode *findlastNode(vector<ListNode *>&lists,int position)
	{
		int length = lists.size();
		if(position>=length)
			return NULL;
		if(!lists[position])    //空节点来 空节点回去
		{
			return NULL;
		}
		while(lists[position]->next)
		{
			lists[position] = lists[position]->next;
		}
		return lists[position];
	}

//链表排序
	ListNode *sortList(ListNode *head) {
		if(!head||!(head->next))
            return head;
		Quicksortlist(head,NULL);
		return head; 
    }
	void Quicksortlist(ListNode *head,ListNode *tail)       //链表范围是[low,high)
	{
		if(head!=tail&&head->next!=tail)
		{
			ListNode *mid = partitionlist(head,tail);
			Quicksortlist(head,mid);
			Quicksortlist(mid->next,tail);
		}
	}
	ListNode *partitionlist(ListNode *low,ListNode *high)			//链表范围是[low,high)
	{
		int key = low->val;
		ListNode *loc = low;
		for(ListNode *i = low->next;i!=high;i=i->next)
		{
			if(i->val<key)
			{
				loc = loc->next;
				swap(i->val,loc->val);
			}
		}
		swap(loc->val,low->val);
		return loc;
	}
};

/*
网上的做法：
使用优先队列来求解问题 
每次从队列中找到最小的数取出来 然后把该数的下一个结点添加到优先队列中（如果没有后继结点则无需添加） 直到优先队列为空
此时 所有的链表都合并结束了
*/

//题目没看清 是已经排完序的k个链表 
class Solution_demo54_1{
public:
	struct compare
	{
		bool operator()(ListNode *input1,ListNode *input2)
		{
			return input1->val>input2->val;     //保证定义的堆为:小顶堆
		}
	};
public:
	ListNode *mergeKLists(vector<ListNode *>&lists)
	{
		if(lists.empty())
			return NULL;
		priority_queue<ListNode *,vector<ListNode *>,compare>q;      //类型---容器---比较方法
		ListNode *res = new ListNode(-1);
		ListNode *f_res = res;
		for(int i=0;i<lists.size();++i)
		{
			if(lists[i])
				q.push(lists[i]);
		}
		while(!q.empty())
		{
			ListNode *tmp = q.top();
			q.pop();
			if(tmp&&tmp->next)
				q.push(tmp->next);
			res->next = tmp;
			res = tmp;
		}
		return f_res->next;
		//return sortList(f_res->next);
	}
private:
	//链表排序
	ListNode *sortList(ListNode *head) {
		if(!head||!(head->next))
            return head;
		Quicksortlist(head,NULL);
		return head; 
    }
	void Quicksortlist(ListNode *head,ListNode *tail)       //链表范围是[low,high)
	{
		if(head!=tail&&head->next!=tail)
		{
			ListNode *mid = partitionlist(head,tail);
			Quicksortlist(head,mid);
			Quicksortlist(mid->next,tail);
		}
	}
	ListNode *partitionlist(ListNode *low,ListNode *high)			//链表范围是[low,high)
	{
		int key = low->val;
		ListNode *loc = low;
		for(ListNode *i = low->next;i!=high;i=i->next)
		{
			if(i->val<key)
			{
				loc = loc->next;
				swap(i->val,loc->val);
			}
		}
		swap(loc->val,low->val);
		return loc;
	}
};
/*
static bool compareLess(ListNode* l1,ListNode* l2)
   {
       return l1->val > l2->val;
   }
   ListNode* mergeKLists(vector<ListNode*> &lists)
   {
      ListNode fake(0);
      ListNode *cur = &fake;
      vector<ListNode *> vec;
       
      int listSize = lists.size();
      for(int i=0;i<listSize;i++)
      {
          if(lists[i])
               vec.push_back(lists[i]);
      }
      make_heap(vec.begin(),vec.end(),compareLess);      // 建堆
      while(vec.size())
      {
          cur->next = vec.front();                       // 堆第一个节点first为最小值节点
          pop_heap(vec.begin(),vec.end(),compareLess);   // 它把first和last-1交换，然后重新生成一个堆
          vec.pop_back();                                // 容器弹出最后一个节点
          cur = cur->next;
          if(cur->next)                                  // 添加弹出的最小值的节点所在链表节点 last-1位置
          {
              vec.push_back(cur->next);                
              push_heap(vec.begin(),vec.end(),compareLess);  // first到last-1是一个有效堆，新加入元素重新生成堆
          }
      }
      return fake.next;
    }
*/

int main_demo54(int argc,char **argv)
{
	Solution_demo54_1 s1;
	ListNode l1(1),l2(2),l3(3),l4(40);
	l1.next = &l4;
	l4.next = &l3;
	l3.next = &l2; 
	vector<ListNode *>input;     //l1->l4->l3->l2
    input.push_back(&l1);
	//input.push_back(NULL);

	ListNode l5(-8),l6(21),l7(31),l8(88),l9(100); //l5->l6->l7->l8->l9
	l5.next = &l6;
	l6.next = &l7;
	l7.next = &l8;
	l8.next = &l9;
	input.push_back(&l5);
	input.push_back(NULL);

	ListNode l10(10),l11(111),l12(222);    //l10->l11->l12
	l10.next = &l11;
	l11.next = &l12;
	input.push_back(&l10);
	input.push_back(NULL);

	ListNode *res = NULL;
	res = s1.mergeKLists(input);
	cout<<"最终排序的结果为:"<<endl;
	while(res)
	{
		cout<<res->val<<"->";
		res = res->next;
	}
	cout<<endl;
	system("pause");
	return 0;
}


/*
#include<iostream>    
using namespace std;    
int main()    
{    
	cout.operator<<("Hello,World!");
	cout.operator<<(endl);    
	system("pause");
	return 0;    
}
*/