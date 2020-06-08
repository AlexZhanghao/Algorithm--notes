#include<iostream>
#include<cstring>

using namespace std;

class myString{
public:
    myString(const char* str=0);
    //拷贝构造函数
    myString(const myString& str);
    ~myString();

    //赋值操作符
    myString& operator=(const myString &str);
    bool operator==(const myString &str)const;
    myString operator+(const myString &str)const;
    myString& operator+=(const myString &str);
    char& operator[](int i)const;

    char* get_c_str() const{return m_data;};//函数后加const表示在函数内部不会改变数据
    size_t get_size() const{return len;};

    friend istream& operator>>(istream &is,myString &str);
    friend ostream& operator<<(ostream &os,myString &str);
private:
    char *m_data;
    size_t len;
};

inline myString::myString(const char* str){
    if(str){
        len=strlen(str);
        m_data=new char[len+1];
        strcpy(m_data,str);
    }
    else{
        len=0;
        m_data=new char[1];
        m_data[0]='\0';        
    }
}

inline myString::~myString(){
    delete []m_data;
}

inline myString::myString(const myString& str){
    len=strlen(str.m_data);
    m_data=new char[len+1];
    strcpy(m_data,str.m_data);
}

//赋值运算符因为考虑可能需要连续赋值，所以设了返回值，这里要返回它自己。
inline myString& myString::operator=(const myString &str){
    //证同测试，如果是自赋值就什么也不做，直接返回
    if(this==&str) return *this;

    //因为“=”左值一开始就存在，所以先将其删除
    delete []m_data;
    len=strlen(str.m_data);
    m_data=new char[len+1];
    strcpy(m_data,str.m_data);
    return *this;
}

inline bool myString::operator==(const myString &str)const{
    if(len!=str.get_size()) return false;
    return strcmp(m_data,str.get_c_str())?true:false;
}

inline myString myString::operator+(const myString &str) const{
    myString newstring;
    newstring.len=len+str.len;
    newstring.m_data=new char[newstring.len+1];
    strcpy(newstring.m_data,m_data);
    strcat(newstring.m_data,str.m_data);
    return newstring;
}

inline myString& myString::operator+=(const myString &str){
    len+=str.len;
    char *newchar=new char[len+1];
    strcpy(newchar,m_data);
    strcat(newchar,str.m_data);
    delete []m_data;
    m_data=newchar;
    return *this;
}

inline char& myString::operator[](int i) const{
    if(i>=len) return m_data[len-1];
    return m_data[i];
}

//这里直接将输入先存在一个足够大的数组tem中，然后再将它赋值给str。
//直接is>>str.data的方法是错误的，因为不能确定str.data的大小和即将输入的字符串的大小关系。
istream& operator>>(istream &is,myString &str){
    char tem[1000];
    is>>tem;
    str.len=strlen(tem);
    str.m_data=new char[str.len+1];
    strcpy(str.m_data,tem);
    return is;
}

ostream& operator<<(ostream &os,myString &str){
    os<<str.m_data;
    return os;
}

int main(){
    myString str("zhangaho");
    cout<<"str:"<<str<<endl;
    myString cpy(str);
    cout<<"cpy:"<<cpy<<endl;
    myString cpyp("++");
    cpyp+=cpy;
    cout<<"cpy+:"<<cpyp<<endl;
    str=str;
    cout<<"self:"<<str<<endl;
    myString in;
    cin>>in;
    cout<<"in:"<<in<<endl;
    myString ass;
    ass=str=in;
    cout<<"assign:"<<ass<<endl;
    return 0;
}