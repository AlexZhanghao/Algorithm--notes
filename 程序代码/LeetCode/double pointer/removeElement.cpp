#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int nsize = nums.size();
		if (nsize == 0) {
			return 0;
		}

		int fast = 0, slow = 0;
		while (fast < nsize) {
			if (nums[fast] == val) {
				Exchange(nums[fast], nums[slow]);
				++fast;
				++slow;
			}
			else {
				++fast;
			}
		}

		if (nums[0] == val) {
			for (int i = 0; i < slow; ++i) {
				nums.erase(nums.begin());
			}
		}


		return fast - slow;
	}

	void Exchange(int &a, int &b) {
		int c = a;
		a = b;
		b = c;
	}
};

class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow=0;
        for(int fast=0;fast<nums.size();++fast){
            if(nums[fast]!=val){
                nums[slow]=nums[fast];
                ++slow;
            }
        }

        return slow;
    }
};