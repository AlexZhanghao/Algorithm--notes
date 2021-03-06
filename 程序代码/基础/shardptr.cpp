#include<iostream>

using namespace std;

class Point
{
private:
    int x, y;
public:
    Point(int xVal = 0, int yVal = 0) :x(xVal), y(yVal) {}
    int getX() const { return x; }
    int getY() const { return y; }
    void setX(int xVal) { x = xVal; }
    void setY(int yVal) { y = yVal; }
};

class RefPtr
{
private:
    friend class SmartPtr;      
    RefPtr(Point *ptr):p(ptr),count(1){ }
    ~RefPtr(){delete p;}
    
    int count;   
    Point *p;                                                      
};

class SmartPtr
{
public:
	
	//构造函数
	SmartPtr() { rp = nullptr; }
	SmartPtr(Point *ptr):rp(new RefPtr(ptr)) {}
	SmartPtr(const SmartPtr &sp):rp(sp.rp)
	{ 
		++rp->count;
		cout << "in copy constructor" <<endl;
	}
	
	//重载赋值运算符
	SmartPtr& operator=(const SmartPtr& rhs)
	{
		//但事实上这里不做证同测试也可以，因为没有牵扯数组释放在里面
		if(this==&rhs) return *this;
		 
		++rhs.rp->count;
		if (rp != nullptr && --rp->count == 0)
		{
			delete rp;
		}
		rp = rhs.rp;
		cout << "in assignment operator" << endl;
		return *this;
	}
	
	//重载->操作符
	Point* operator->()
	{
		return rp->p;
	}
	
	//重载*操作符
	Point& operator*()
	{
		return *(rp->p);
	}

	~SmartPtr()
	{
		if (--rp->count == 0)
			delete rp;
		else
			cout << "还有" << rp->count << "个指针指向基础对象" << endl;
	}

private:
	RefPtr* rp;
};

int main()
{
    //定义一个基础对象类指针
    Point *pa = new Point(10, 20);

    //定义三个智能指针类对象，对象都指向基础类对象 pa
    //使用花括号控制三个智能指针的生命周期，观察计数的变化
    {
        SmartPtr sptr1(pa);//此时计数 count=1
        cout <<"sptr1:"<<sptr1->getX()<<","<<sptr1->getY()<<endl;
        {
            SmartPtr sptr2(sptr1); //调用拷贝构造函数，此时计数为 count=2
            cout<<"sptr2:" <<sptr2->getX()<<","<<sptr2->getY()<<endl;
            {
            	SmartPtr sptr3;
                sptr3=sptr1; //调用赋值操作符，此时计数为 conut=3
                cout<<"sptr3:"<<(*sptr3).getX()<<","<<(*sptr3).getY()<<endl;
            }
            //此时count=2
        }
        //此时count=1；
    }
    //此时count=0；对象 pa 被 delete 掉
    cout << pa->getX() << endl;
    return 0;
}