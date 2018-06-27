/*
2018��5��31��21:29:13
Sort a linked list in O(n log n) time using constant space complexity.
*/
#include <iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

/*
�㷨ֻ�����ڵ��valֵ��ʱ�临�Ӷ�O(nlogn)  �ռ临�Ӷ�O(1)

*/
class Solution_demo44 {
public:
	//�����������
    ListNode *sortList(ListNode *head) {
		if(!head||!(head->next))
            return head;
		Quicksortlist(head,NULL);
		return head; 
    }
private:
	void Quicksortlist(ListNode *head,ListNode *tail)       //����Χ��[low,high)
	{
		if(head!=tail&&head->next!=tail)
		{
			ListNode *mid = partitionlist(head,tail);
			Quicksortlist(head,mid);
			Quicksortlist(mid->next,tail);
		}
	}
	ListNode *partitionlist(ListNode *low,ListNode *high)			//����Χ��[low,high)
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


int main_demo44(int argc,char **argv)
{
	Solution_demo44 s1;
	ListNode l1(10),l2(2),l3(4),l4(11),l5(3),l6(88),l7(30);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	l6.next = &l7;
	ListNode *res = NULL;
	res = &l1;
	cout<<"����֮ǰ�Ľ��:"<<endl;
	while(res)
	{
		cout<<res->val<<"->";
		res = res->next;
	}
	cout<<endl;
	res = s1.sortList(&l1);
	cout<<"����֮��Ľ��Ϊ:"<<endl;
	while(res)
	{
		cout<<res->val<<"->";
		res = res->next;
	}
	system("pause");
	return 0;
}



/*
void main()
{
	//cout<<'A'+4*25.0-'b';
	printf("%x",100);
	int x =3,y=5;
	printf("%f",(x=3,y=5,x>y?1:1.5));
	int m=48;
	char ch = 'a';
	int n = 0;
	cout<<(m>=n&&ch<'b'&&!n)<<endl;
	cout<<endl;
	int print;
	x=y=1;
	int z = 0;
	z = x++,y++,++y;
	printf("x=%d,y=%d,z=%d",x,y,z);
	system("pause");
}
int fac(int n)
{
	if(n<1)
		return 1;
	else
		return n*fac(n-1);
}
*/