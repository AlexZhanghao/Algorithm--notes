#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(){
    string input,output;
    while(cin>>input>>output){
        string put;
        int isize=input.size();
        if(isize!=output.size()){
            cout<<-1<<endl;
            continue;
        }
        stack<char> s;
        int count=0;
        for(int i=isize-1;i>=0;--i){           
            if(input[i]==output[count]){
                put+="ED";
                ++count;
            }
            else if(!s.empty()&&s.top()==output[count]){
                s.pop();
                put+="D";
                ++count;
                ++i;
            }
            else{
                s.push(input[i]);
                put+="E";
            }
        }
        if(count<isize) put="-1";
        cout<<put<<endl;
    }
}