#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k==0||k>input.size()) return {};
        vector<int> output;
        for(int i=0;i<k;++i) output.push_back(input[i]);
        MakeHeap(output);
        for(int j=k;j<input.size();++j){
            if(input[j]<output[0]){
                output[0]=input[j];
                ShiftDown(output,0);
            }
        }
        sort(output.begin(),output.end());
        return output;
    }

    void MakeHeap(vector<int> &v){
        int n=v.size()-1;
        for(int i=n/2;i>=0;--i) ShiftDown(v,i);
        return;
    };

    void ShiftDown(vector<int> &v,int i){
        int n=v.size();
        int flag=0,t=0;
        while((i*2)+1<n&&flag==0){
            if(v[i]<v[(i*2)+1]) t=(i*2)+1;
            else t=i;

            if((i*2)+2<n){
                if(v[t]<v[(i*2)+2]) t=(i*2)+2;
            }

            if(t!=i){
                swap(v[t],v[i]);
                i=t;
            }
            else flag=1;
        }

        return;
    }
};