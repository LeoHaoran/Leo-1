#include<bits/stdc++.h>
using namespace std;
class Number{
	
private:
    int k;
public:
    Number(int n){
        k=n;
    }
    void show(){
        cout<<k<<endl;
    }
    int maxDivisor(Number no2){
        int a,b;
        a=max(k,no2.k);
		b=min(k,no2.k);
        while(b^=a^=b^=a%=b);
        return a;
    }
};
int main() {

    int n, n1, n2;

    std::cin >> n;
    
    for(int i = 0; i < n; ++i) {

        std::cin >> n1 >> n2;

        Number no1(n1), no2(n2);

        Number no3 = no1.maxDivisor(no2);  //最大公约数

        no3.show();

    }

}

