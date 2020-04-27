#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size()==0) return true;
        return verifybintree(postorder);      
    }

    private:
    bool verifybintree(vector<int> &postorder){
        int psize=postorder.size();
        if(psize==1) return true;
        int root=postorder.back();        
        int rstart=0;
        for(int i=0;i<psize;++i){
            if(postorder[i]>=root){
                rstart=i;
                break;
            } 
        }
        vector<int> right;
        //这里要注意为毛上面的i<psize，而这里是j<psize-1。
        //首先这里是psize-1是因为，这里是统计的右子树，所以不能把根节点也给算上了。
        //而上面的是psize则是因为如果出现无右子树的情况时rstart就会是0，这样下面就会错误的把左子树给放进right中。
        for(int j=rstart;j<psize-1;++j){
            if(postorder[j]>root){
                right.push_back(postorder[j]);
            }
            else{
                return false;
            }
        }
        if(right.size()>0&&!verifybintree(right)) return false;
        vector<int> left;
        for(int k=0;k<rstart;++k){
            left.push_back(postorder[k]);
        }
        if(left.size()>0&&!verifybintree(left)) return false;
        return true;
    }
};