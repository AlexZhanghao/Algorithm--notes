#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        vector<int> v;
        for(int i=0;i<n;++i){
            int j;
            cin>>j;
            v.push_back(j);
        }
        vector<int> out(n,0);
        int start,end;
        // if(n>1){
        //     start=1;
        //     end=n-1;
        // }
        int ostart=0,oend=0;
        for(int i=0;i<n-3;++i){
            if(v[i+i]<v[0]||v[i+i]<v[i+2]){
                ++ostart;                
            }
            if(v[n-1-i]<v[n-1]||v[n-i-1]<v[n-i-2]){
                ++oend;
            }
        }
        out[0]=ostart;
        out[n-1]=oend;
        for(int i=1;i<n-1;++i){
            int left=i-1;
            int right=i+1;
            int lnum=1,rnum=1;
            while(left>0){
                if(v[left]<v[i]||v[left]<v[left-1]){
                    ++lnum;
                    --left;
                }
            }
            while(right<n-1){
                if(v[right]<v[i]||v[right]<v[right+1]){
                    ++rnum;
                    ++right;
                }
            }
            out[i]=lnum+rnum+1;
        }
        for(int i=0;i<n;++i){
            cout<<out[i]<<" "<<endl;
        }
    }
}

//题解中发现可以用单调栈解决，这老哥写代码的水平很高
#include <stack>
#include <algorithm>
using namespace std;
vector<int> a, b;
stack<int> st1, st2;
  
int main() {
    int n, x[100001];
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) cin >> x[i];
      
    for (int i = 0, j = n - 1; i < n, j >= 0; i++, j--) {
        //他这里a存左侧能看到的楼数，b存右侧能看到的楼数。
        //这里要注意顺序，必须先push到vector中在更新stack，因为这里保存的是左右侧能看到的楼数，自然不能包括自己。
        a.push_back(st1.size());
        b.push_back(st2.size());
          
        //这里是在构造单调递减栈
        while (!st1.empty() && st1.top() <= x[i]) st1.pop();
        while (!st2.empty() && st2.top() <= x[j]) st2.pop();
        st1.push(x[i]);
        st2.push(x[j]);
    }
    reverse(b.begin(), b.end());
    for (int i = 0; i < n; i++) cout << b[i] + a[i] + 1<< " ";
    return 0;
}