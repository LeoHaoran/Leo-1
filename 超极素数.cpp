#include<bits/stdc++.h> 
#include<algorithm> 
#include<cstdio>
#include<cstring>
using namespace std;


int judge(int n) //�ж�����
{
    for(int i =2; i<=sqrt(n); i++)
   
       if(n % i == 0)return 0;
    return 1;
}
int superSu(int m)
{
    int last;   //���һ������
    int x = pow(10,m-1); //��������
    int y = pow(10,m);
    int sum = 0; //ͳ������
    int p;
    for(int i = x; i<y; i++)
    {
        p = i;
        int flag = 1; 
        while(p) //���һ�����м���0�Ļ�����ôһ�������ǳ�������
        {
            int t = p % 10;
            p /=10;
            if(t == 0)
            {
                flag = 0;  
                break;
            }
        }

        if(!flag)continue; //�����0��������

        p = i;
        int u = m-1;
        while(u > 0)
        {
            if(judge(p))
            {
                p = p % (int)pow(10,u--);  
            }
            else
            {
                flag = 0;  //����ֻҪ��һ������������ų�
                break;
            }
        }
        if((p == 3 || p == 7 )&& flag == 1) //������ĩβһ����3 or 7�������9����ôһ������һλ������ͬ��
        {
            sum++;         //ͳ�Ƹ���
            last = i;   //��¼���һλ
        }
    }
    return last;
}
int main(){
	int a;
	cin>>a;
	superSu(a);
}
