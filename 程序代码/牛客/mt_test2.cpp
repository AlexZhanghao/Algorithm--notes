#include<iostream>

using namespace std;

int main(){
    int n,k;
    cin>>n;
    cin>>k;
    int min_num=n;    
    for(int i=0;i<n;++i){
        int cnt=n-i;
        int sn=n;
        int sk=k;
        while((cnt/sk)!=0){
            sn-=cnt/sk;
            if(sn<=0) break;
            sk=sk*sk;
        }
        if((cnt/sk)==0&&sn>0){
            min_num=cnt;
            break;
        }
    }
    printf("%d\n",min_num+1);
    return 0;
}