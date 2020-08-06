// 一间屋子有许多桌子，许多人
// 如果3个人坐一桌多2个人，
// 如果5个人坐一桌多4个人，
// 如果7个人坐一桌多6个人，
// 如果9个人坐一桌多8个人，
// 如果11个人坐一桌刚好，请问屋子里有多少人？
//可以直接手算出来，见https://www.qianwa.com/archives/8420.html

#include<iostream>
#include<vector>

using namespace std;

int peoplenum(){
    int n=0;
    int valid=0;
    while(valid!=4){
        n+=11;
        int a=0;
        if(n%3==2) ++a;
        if(n%5==4) ++a;
        if(n%7==6) ++a;
        if(n%9==8) ++a;
        valid=a;
    }

    return n;
}

int main(){
    cout<<peoplenum()<<endl;
    return 0;
}