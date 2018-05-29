/*
2018Äê5ÔÂ23ÈÕ19:34:07
*/
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;



struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution_demo27 {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> >res;
		if(!root)
			return res;
		list<TreeNode *>l;
		l.push_back(root);
		vector<int>v_tmp;
		v_tmp.push_back(root->val);
		res.push_back(v_tmp);
		v_tmp.clear();
		int flag=0,count=0,nextcount=1;
		while(l.size()!=0)
		{
			TreeNode *top = l.front();
			l.pop_front();
			++count;
			if(top->left!=NULL)
				l.push_back(top->left);
			if(top->right!=NULL)
				l.push_back(top->right);
			if(count==nextcount)
			{
				++flag;
				count=0;
				nextcount=l.size();
				list<TreeNode *>::iterator it;
				for(it=l.begin();it!=l.end();++it)
				{
					v_tmp.push_back((*it)->val);
				}
				if(v_tmp.size())
				{
					if(flag%2!=0)
						reverse(v_tmp.begin(),v_tmp.end());
					res.push_back(v_tmp);
				}
				v_tmp.clear();
			}
		}
		return res;
        
    }
};
int main_demo27(int argc,char **argv)
{
	Solution_demo27 s1;
	TreeNode t1(1),t2(2),t3(3),t4(4),t5(5),t6(6),t7(7),t8(8),t9(9);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;
	t3.right = &t7;
	t4.left = &t8;
	t8.right = &t9;

	vector<vector<int> >res;
	res = s1.zigzagLevelOrder(&t1);
	vector<vector<int> >::iterator it_2;
	for(it_2=res.begin();it_2!=res.end();++it_2)
	{
		vector<int>::iterator it_1;
		for(it_1=(*it_2).begin();it_1!=(*it_2).end();++it_1)
			cout<<*it_1<<ends;
		cout<<endl;
	}
	system("pause");
	return 0;
}