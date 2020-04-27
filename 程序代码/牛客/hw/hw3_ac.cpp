/*
一个序列，切k份，要求和最小的尽量大。
这道题题目有问题的。

题目上说尽量使S[0]大，但这样会卡80%
后来我灵机一动，让S[0]尽量小，AC.

 题目样例 1 2 3 2 5 4
 答案 1 2 3 / 2 5 / 4
 但s[0]尽量大应该是 1 2 3 2 / 5 / 4
 ………………
 …………
 ……
 难顶~

 解法:
 这个要猜答案，用二分得到最大解。
 再从头到尾贪心构造。
 （如果按题目所说，其实应该从尾到头构造的……）

*/
//#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=505;
ll m,k;
ll a[maxn];
ll ans;

//这里是将x作为为上限，找出a数组中小于x的最少组合数
bool check(ll x)
{
    ll now=0;
    int t=0;
    //似乎是在记录a[i]中和值小于x的组数
    for(int i=0;i<m;i++)
    {
        if(now>=x)
        {
            t++;
            now=0;
            i--;
        }
        else
        {
            now+=a[i];
        }
    }
    //也许加上最后一个数后它就>=x了
    if(now>=x)
    {
        t++;
    }
    if(t>=k)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    cin>>m>>k;
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
        ans+=a[i];
    }
    if(k==1)
    {
        for(int i=0;i<m;i++)
        {
            cout<<a[i]<<' ';
        }
        cout<<endl;
        return 0;
    }


    ll l=0,r=ans;

    while(l<r)
    {
        ll mid=(l+r)/2;
        if(check(mid))
        {
            l=mid+1;
        }
        else
        {
            r=mid;
        }
    }
    ll d=l-1;
    ll now=0;
    vector<ll> v;
    int num=1;
    for(int i=0;i<m;i++)
    {
        now+=a[i];
        if(now>=d)
        {
            v.push_back(i);
            now=0;
            num++;
        }
        if(num>=k)
        {
            break;
        }
    }
    int cnt=0;
    for(int i=0;i<m;i++)
    {

        cout<<a[i]<<" ";
        if(i==v[cnt])
        {
            cnt++;
            cout<<"/ ";
        }
    }
    cout<<endl;

}

//他在这里的做法，就是先求出输入的和，然后以和的平均值为标准将输入分段，每段的和刚好小于这个平均值
//这里就会有两种情况：
//1、分段的数目大于k，这时就需要将分段标准增大，所以令l=mid+1
//2、小于k，则反之，令r=mid
//懂了，这里在t>=k时选择增大值，而t<k时减小值，则最后值会刚好停在k或者最接近k的值
//取出最后得到的分段值，以它为标准进行分段，即可得到解！！！