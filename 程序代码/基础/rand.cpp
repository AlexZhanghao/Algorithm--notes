#include<iostream>

using namespace std;

int Rand5()
{
    int m = rand() % 5 + 1;
    return m;
}

int Rand7()
{
    int x = 22;
    while (x > 21)
        //Rand5产生1到5的数，减1就产生0到4的数，乘以5后可以产生的数是：0,5,10,15,20。 
        //再加上第二个Rand5()产生的1,2,3,4,5。我们可以得到1到25， 而且每个数都只由一种组合得到，
        //故以下代码可以等概率地生成1到25。
        x = Rand5() + (Rand5() - 1) * 5;
    return x % 7 + 1;
}

int main(){
    int n=7;
    while(n--)
    cout<<Rand7()<<" ";
    cout<<endl;

    return 0;
}