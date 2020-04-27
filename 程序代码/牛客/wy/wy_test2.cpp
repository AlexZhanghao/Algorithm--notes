#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
	int n, m, s;
	int count = 0;
	while (cin >> n >> m >> s) {
        bool is_haved=true;
        --s;
        unordered_set<int> us;
		for(int i=0;i<n;++i){
            us.insert(i);
        }
        us.erase(s);

        int count=0;
		for (int i = 0; i < m; ++i) {
			int x, y;
			cin >> x >> y;
            ++count;
            --y;

            if(x==0){
                if(y==s){
                    is_haved=false;
                    break;
                }
                else{
                    us.erase(y);
                }
            }
            else{
                --x;
                if(x==s) us.erase(y);
                if(y==s) us.erase(x);
            }

            if(us.size()==0){
                is_haved=false;
                break;
            }
		}

		
		if(is_haved) count=0;
        printf("%d\n", count);
	}
	return 0;
}