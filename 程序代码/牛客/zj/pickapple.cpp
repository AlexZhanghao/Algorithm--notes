// 牛牛有一个苹果园。又到了一年一度的收获季，牛牛现在要去采摘苹果买给市场的摊贩们。
// 牛牛的果园里面有n棵苹果树，第i棵苹果树上有ai个果子。
// 牛牛为了保证果子的新鲜程度，每天都会去苹果树上采摘果子。

// 牛牛特意安排一个计划表：
// 计划m天去采摘果子。
// 对于第i天，它会去所有果树上轮流采摘bi个果子。
// 如果对于第i天，某棵果树上没有bi个果子，那么它只会把当前果树上的果子采摘完。
// 牛牛想知道它每天能供应多少个苹果给市场的摊贩们。

// 输入:[10,20,10],[5,7,2]
// 输出:[15,17,2]
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> pick(vector<int> &a,vector<int> &b){
    vector<int> ret(b.size(),0);
    sort(a.begin(),a.end());
    
    //当前要摘的总苹果数
    int sum=0;
    //pos前的苹果树都已经被摘空
    int pos=0;
    for(int i=0;i<b.size();++i){
        sum+=b[i];
        while(pos<a.size()&&a[pos]<sum){
            //当前pos树上的苹果已经不够摘了，所以直接加上剩余的苹果数
            ret[i]+=a[pos]-(sum-b[i]);
            ++pos;
        }
        ret[i]+=(b.size()-pos)*b[i];
    }
    return ret;
}

int main() {
    vector<int> a={10,20,10};
    vector<int> b={5,7,2};
    vector<int> c=pick(a,b);
    for(int i=0;i<c.size();++i) cout<<c[i]<<" ";
    cout<<endl;
    return 0;
}