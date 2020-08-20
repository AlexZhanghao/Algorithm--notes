#include<iostream>

using namespace std;

#define MAXSIZE 10000

/* QElemType类型根据实际情况而定，这里假设为int */
typedef int QElemType;

class myQueue{
public:
    myQueue(int x):len(x){
        front=0;
        rear=0;
        data=new QElemType[len];
    }
    ~myQueue(){
        delete [] data;
    }

    int getQueueLength(){
        return (rear-front+len)%len;
    }

    bool EnQueue(QElemType x){
        // 队列满的判断 
        if ((rear + 1) % len == front) return false;
        data[rear]=x;
        rear=(rear+1)%len;
        return true;
    }

    bool DeQueue(QElemType& ret){
        if(front==rear) return false;
        ret=data[front];
        front=(front+1)%len;
        return true;
    }

private:
    QElemType* data;
    int front;
    int rear;
    int len;
};