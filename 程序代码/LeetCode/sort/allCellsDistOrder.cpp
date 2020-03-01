#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        if(R==0||C==0){
            return {};
        }
        if(R==1&&C==1){
            return {{R,C}};
        }

        vector<vector<int>> cells;
        vector<int> a={0,0,0};
        
        for(int i=0;i<R;++i){
            for(int j=0;j<C;++j){
                a[0]=i;
                a[1]=j;
                a[2]=abs(i-r0)+abs(j-c0);
                cells.push_back(a);
            }
        }
        
        QuickSort(cells,0,cells.size()-1);
        for(int i=0;i<cells.size();++i){
            cells[i].pop_back();
        }

        return cells;
    }

    void QuickSort(vector<vector<int>> &A,int p,int r){
        if(p<r){
            int q=Partition(A,p,r);
            QuickSort(A,p,q-1);
            QuickSort(A,q+1,r);
        }
    }

    int Partition(vector<vector<int>> &A,int p,int r){
        int x=A[r][2];
        int i=p-1;
        for(int j=p;j<r;++j){
            if(A[j][2]<x){
                ++i;
                Exchange(A[i],A[j]);
            }
        }
        Exchange(A[i+1],A[r]);

        return i+1;
    }

    void Exchange(vector<int> &A,vector<int> &B){
        vector<int> C=A;
        A=B;
        B=C;
    }

};