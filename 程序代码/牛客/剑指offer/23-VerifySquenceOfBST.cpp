#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int ssize=sequence.size();
        VerifyBST(sequence,0,ssize-1);
    }

    bool VerifyBST(vector<int> seq,int left,int right){        
        if(seq.empty()||left>right) return false;
        int root=seq[right];
        int i;
        for(i=left;i<right;++i){
            if(seq[i]>root) break;
        }

        for(int j=i;j<right;++j){
            if(seq[j]<root) return false;
        }
        if(i>left){
            if(!VerifyBST(seq,left,i-1)) return false;
        }
        if(i<right-1){
            if(!VerifyBST(seq,i,right-1)) return false;
        }
        return true;
    }
};