/*
2018Äê5ÔÂ24ÈÕ08:29:38
*/
#include <iostream>
#include <list>
using namespace std;


struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


class Solution_demo32 {
public:
    void connect(TreeLinkNode *root) {
		if(!root)
			return;
		list<TreeLinkNode *>l;
		l.push_back(root);
		int count=0,nextcount=1;
		while(l.size()!=0)
		{
			TreeLinkNode *top = l.front();
			l.pop_front();
			++count;
			if(top->left!=NULL)
				l.push_back(top->left);
			if(top->right!=NULL)
				l.push_back(top->right);
			if(count==nextcount)
			{
				count=0;
				nextcount=l.size();
				list<TreeLinkNode *>::iterator it,it_tmp;
				it_tmp = l.begin();
				for(it=l.begin();it!=l.end();++it)
				{
					it_tmp++;
					if(it_tmp!=l.end())
						(*it)->next = *it_tmp;
				}
			}
		}
    }
};

int main_demo32(int argc,char **argv)
{
	Solution_demo32 s1;
	TreeLinkNode t1(1),t2(2),t3(3),t4(4),t5(5),t6(6),t7(7),t8(8),t9(9);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;
	t3.right = &t7;
	t5.left = &t8;
	t8.right = &t9;
	s1.connect(&t1);
	system("pause");
	return 0;
}