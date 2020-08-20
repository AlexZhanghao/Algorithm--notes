#include<iostream>

using namespace std;

//线程安全的实现--懒汉模式
class singleThreadsafe{
public:
    static singleThreadsafe* getinstance();

private:
    singleThreadsafe(){}
    ~singleThreadsafe(){}
    static void lock();
    static void unlock();
    static singleThreadsafe* p;
};

void singleThreadsafe::lock(){}
void singleThreadsafe::unlock(){}
singleThreadsafe* singleThreadsafe::p=NULL;

singleThreadsafe* singleThreadsafe::getinstance(){
    if(p==NULL){
        lock();
        if(p==NULL){
            p=new singleThreadsafe;
        }
        unlock();
    }

    return p;
}

//懒汉--effective c++
class singleLazy{
private:
    singleLazy(){}
    ~singleLazy(){}

public:
    static singleLazy* getinstance();
};

singleLazy* singleLazy::getinstance(){
    static singleLazy obj;
    return &obj;
}

//饿汉
class singleHungry{
    private:
    singleHungry(){}
    ~singleHungry(){}
    static singleHungry* p;

public:
    static singleHungry* getinstance();
};

singleHungry* singleHungry::p=new singleHungry;

singleHungry* singleHungry::getinstance(){
    return p;
}