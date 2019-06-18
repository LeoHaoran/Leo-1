#include<bits/stdc++.h> 
#include<algorithm> 
#include<cstdio>
#include<cstring>
using namespace std;


int judge(int n) //判断素数
{
    for(int i =2; i<=sqrt(n); i++)
   
       if(n % i == 0)return 0;
    return 1;
}
int superSu(int m)
{
    int last;   //最后一个素数
    int x = pow(10,m-1); //计算区间
    int y = pow(10,m);
    int sum = 0; //统计素数
    int p;
    for(int i = x; i<y; i++)
    {
        p = i;
        int flag = 1; 
        while(p) //如果一个数中间有0的话，那么一定不会是超级素数
        {
            int t = p % 10;
            p /=10;
            if(t == 0)
            {
                flag = 0;  
                break;
            }
        }

        if(!flag)continue; //如果有0，则跳过

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
                flag = 0;  //其中只要有一项不是素数，就排除
                break;
            }
        }
        if((p == 3 || p == 7 )&& flag == 1) //素数最末尾一定是3 or 7，如果是9，那么一定不是一位素数，同理。
        {
            sum++;         //统计个数
            last = i;   //记录最后一位
        }
    }
    return last;
}
int main(){
	int a;
	cin>>a;
	superSu(a);
}
