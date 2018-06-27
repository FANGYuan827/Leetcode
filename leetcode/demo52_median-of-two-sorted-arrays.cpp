/*
2018��6��4��22:09:32
There are two sorted arrays A and B of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).


*/
#include <iostream>
#include <vector>
using namespace std;


class Solution_demo52 {
public:
	//ʱ�临�Ӷȣ�O(m+n) �ռ临�Ӷ�O(m+n)   �ϲ���m+n/2ʱ ���˳�
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		if(m==0&&n==0)
			return 0;
		vector<int>vec;
		int i = 0,j = 0;
		//for(;i<m&&j<n;)
		while(vec.size()<(m+n)/2+1)
		{
			if(i>=m||j>=n)
			{
				if(j<n)
				{
					vec.push_back(B[j]);
					++j;
				}
				if(i<m)
				{
					vec.push_back(A[i]);
					++i;
				}
			}
			else
			{
				if(A[i]>B[j])
				{
					vec.push_back(B[j]);
					++j;
				}
				else
				{
					vec.push_back(A[i]);
					++i;
				}
			}
			if(vec.size()>=(m+n)/2+1)
			{
				break;
			}
		}
		if((m+n)&0x1)
			return vec[vec.size()-1];
		else
			return (vec[vec.size()-1]+vec[vec.size()-2])/2.0;


		/*
		if(i==m)    //˵������A��������
		{
		for(;j<n;++j)
		vec.push_back(B[j]);
		}
		if(j==n)
		{
		for(;i<m;++i)
		vec.push_back(A[i]);
		}
		if(vec.size()%2!=0)
		{
		return vec[vec.size()/2];
		}
		else
		{
		return ((double)(vec[(vec.size()-1)/2]+vec[(vec.size()+1)/2]))/2.0;
		}
		*/
	}
	double findMedianSortedArrays_1(int A[],int m,int B[],int n);
private:
	double findKth(int A[],int m,int B[],int n,int k);
};

/*
����˼·��
���ǿ��Խ�ԭ����ת����һ��Ѱ�ҵ�kС�������⣨�������������������У�������λ����ʵ�����ǵڣ�m+n��/2С����
����ֻҪ����˵�kС������ԭ����Ҳ�͵õ�����ˡ�

���ȼ�������A������B��Ԫ�ظ���������k/2 ���ǱȽ�A[k/2-1]��B[k/2-1]����Ԫ�� ������Ԫ�طֱ��ʾA�ĵ�k/2С��B�ĵ�k/2С��Ԫ��
������Ԫ�صıȽϽ��������: > < =
��� A[k/2-1]<B[k/2-1] ���ʾA[0]��A[k/2-1]��Ԫ�ض���A��B�ϲ�֮ǰ��ǰkС��Ԫ���� ���仰˵ A[k/2-1]�����ܴ���������ϲ�֮��ĵ�kС��ֵ �������ǽ�������

��A[k/2-1] = B[k/2-1]ʱ �����Ѿ��ҵ���kС���� Ҳ�������ȵ�Ԫ�� ���ǽ����Ϊm 
������A��B�зֱ���k/2-1��Ԫ��С��m ����m���ǵ�kС����
�����kΪ���� ��m������λ����������������뻯���� ��ʵ�ʴ��������в�ͬ ������k/2 Ȼ������k-k/2�����һ����


ͨ������ķ��������Ǽȿ��Բ��õݹ�ķ�ʽʵ��Ѱ�ҵ�kС���� �������ǻ���Ҫ���Ǽ����߽�������
���A����BΪ�� ��ֱ�ӷ���B[k-1]����A[k-1]
���kΪ1 ����ֻ��Ҫ����A[0]��B[0]�еĽ�Сֵ
���A[k/2-1] = B[k/2-1] ��������һ��


*/
double Solution_demo52::findMedianSortedArrays_1(int A[],int m,int B[],int n)
{
	int total = m+n;
	if(total&0x1)
		return findKth(A,m,B,n,total/2+1);
	else
		return (findKth(A,m,B,n,total/2)+findKth(A,m,B,n,total/2+1))/2;
}
double Solution_demo52::findKth(int A[],int m,int B[],int n,int k)    //k��ʾ��kС
{
	if(m>n)
		return findKth(B,n,A,m,k);          //ʼ�ձ���Ԫ�ؽ��ٵ�����λ��ǰ���λ��
	if(m==0)
		return B[k-1];                    //���λ��ǰ�������Ϊ�� ��ֱ�ӷ��غ�������ĵ�k-1��Ԫ��
	if(k==1)
		return min(A[0],B[0]);          //���k=1 �򷵻���������ͷԪ�ص���Сֵ

	int pa = min(k/2,m),pb = k-pa;
	if(A[pa-1]<B[pb-1])
		return findKth(A+pa,m-pa,B,n,k-pa);
	else
		if(A[pa-1]>B[pb-1])
			return findKth(A,m,B+pb,n-pb,k-pb);
		else
			return A[pa-1];

}

int main_demo52(int argc,char **argv)
{
	Solution_demo52 *s1 = new Solution_demo52();
	int A[10] = {1,2,3,5,6,7,8,9,12,23};
	int B[15] = {2,3,5,6,7,8,9,13,14,16,17,19,20,45,100};
	double res = 0;
	res = s1->findMedianSortedArrays(A,0,B,2);
	cout<<"�����������λ��Ϊ:"<<res<<endl;
	if(s1)
		delete s1;
	s1 = NULL;
	system("pause");
	return 0;
}