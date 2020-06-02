#include<iostream>
#include<numeric>

template<class Item>
class vecIter{
    Item *ptr;
public:
    typedef std::forward_iterator_tag iterator_category;
    typedef Item value_type;
    typedef Item* pointer;
    typedef Item& reference;
    typedef std::ptrdiff_t difference_type;
public:
    vecIter(Item *p = 0) :ptr(p){}
    Item& operator*()const{
        return *ptr;
    }
    Item* operator->()const{
        return ptr;
    }
    //++i
    vecIter& operator++(){
        ++ptr;
        return *this;
    }
    //i++
    vecIter operator++(int){
        vecIter tmp = *this;
        ++*this;
        return tmp;
    }

    bool operator==(const vecIter &iter){
        return ptr == iter.ptr;
    }
    bool operator!=(const vecIter &iter){
        return !(*this == iter);
    }

};

int main(){
    int a[] = { 1, 2, 3, 4 };
    std::cout << std::accumulate(vecIter<int>(a), vecIter<int>(a + 4), 0);//输出 10
    getchar();
    return 0;
}