#include <iostream>
#include <algorithm>
#include <vector>
 
int main()
{
    using namespace std;
 
    vector<int> vec;
 
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
 
    vector<int>::iterator it = find(vec.begin(), vec.end(), 6);
 
    if (it != vec.end())
        cout<<*it<<endl;
    else
        cout<<"can not find"<<endl;
 
    return 0;
}