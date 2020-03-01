#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        //INT_MIN=-INT_MAX-1，所以它不能取绝对值，这里要单独拿出来
        if(x==INT_MIN){
            return 0;
        }

        bool is_negative=x<0?1:0;
        int remainder=0;
        int alrever=0;
        int abs_x=abs(x);
        
        while(abs_x>=10){
            remainder=abs_x%10;
            abs_x/=10;
            alrever=alrever*10+remainder;
        }

        if(alrever>INT_MAX/10){
                return 0;
        }else if(alrever<INT_MAX/10){
            if(is_negative){
                return -(alrever*10+abs_x);
            }
            else{
                return alrever*10+abs_x;
            }
        }else{
        if(is_negative){
            if(abs_x>8){
                return 0;
            }
            else{
                return -(alrever*10+abs_x);
            }
        }
        else{
            if(abs_x>7){
                return 0;
            }
            else{
                return alrever*10+abs_x;
            }
        }
        }
        
    }
};

//写法2，比我的好太多，注释的部分可以好好品味，这里pop>7和pop<-8的情况是不可能出现的
class Solution2 {
public:
	int reverse(int x) {
		int rev = 0;
		while (x != 0)
		{
			int pop = x % 10; // 取末位
			x /= 10;
			if (rev > INT_MAX / 10 
				/*|| (rev == INT_MAX / 10 && pop > 7)*/)// 情况2,排除
			{
				return 0;
			}
			if (rev < INT_MIN / 10
				/*|| (rev == INT_MIN / 10 && pop < -8)*/)// 情况2,排除
			{
				return 0;
			}
			rev = rev * 10 + pop;
		}

		return rev;
	}
};