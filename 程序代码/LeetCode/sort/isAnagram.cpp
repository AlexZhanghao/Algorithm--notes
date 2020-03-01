#include<iostream>
#include<string>
#include<vector>

using namespace std;
    
bool isAnagram(string s, string t) {
    int m=s.size();
    int n=s.size();

    if(m!=n){
        return false;
    }

    InsertSort(s,m);
    InsertSort(t,n);
    
    return s==t;
}

//插入排序
void InsertSort(string &s,int n){ 
    int j=0;
    for(int i=1;i<n;++i){
        char key=s[i];
        j=i-1;
        while(j>-1&&s[j]>key){
            s[j+1]=s[j];
            --j;
        }
        s[j+1]=key;
    }
}

//堆排序
void HeapSort(string &s,int n){
    vector<char> a;
    vector<char> b;
    for(int i=0;i<n;++i){
        a.push_back(s[i]);
    }

    BuildMaxHeap(a);
    int heap_size=n;
    for(int i=0;i<n;++i){
        b.push_back(a[0]);
        Exchange(a[0],a[n-i-1]);
        a.pop_back();
        --heap_size;
        MaxHeapify(a,0,heap_size);
    }

    for(int i=0;i<n;++i){
        s[i]=b[i];
    }
}

void BuildMaxHeap(vector<char>& a){
    int heap_size=a.size();
    for(int i=a.size()/2-1;i>-1;--i){
        MaxHeapify(a,i,heap_size);
    }
}

void MaxHeapify(vector<char>& a,int i,int heap_size){
    int l=Left(i);
    int r=Right(i);

    int largest=i;
    if (l<heap_size&&a[l]>a[i]){
        largest=l;
    }
    if(r<heap_size&&a[r]>largest){
        largest=r;
    }

    if(largest!=i){
        Exchange(a[largest],a[i]);
        MaxHeapify(a,largest,heap_size);
    } 


}

int Left(int i){
    return 2*i;
}

int Right(int i){
    return 2*i+1;
}

void Exchange(char &a,char &b){
    char m=a;
    a=b;
    b=m;
}