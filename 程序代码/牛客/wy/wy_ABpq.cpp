#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n=0;
    cin>>n;
    for(int i=0;i<n;++i){
        int a[4];
        for(int j=0;j<4;++j){
            cin>>a[j];
        }
        int count=0;
        int aplus=0,pq=0;
        while(a[1]>a[0]+a[2]){
            //这里要考虑到超出int最大值的情况
            if(a[2]*a[3]>0){
                a[2]=a[2]*a[3];
                ++count;
            }
            else{
                a[0]+=a[2];
                ++count;
            }
        }
        ++count;
        printf("%d\n",count);
    }
    return 0;
}