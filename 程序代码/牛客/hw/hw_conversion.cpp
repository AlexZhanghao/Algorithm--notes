#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main() {
	string sixteen;
	while (cin >> sixteen ) {
		int sixsize = sixteen.size();
		double decimalism = 0;
		for (int i = 0; i < sixsize; ++i) {
			switch (sixteen[i]) {
			case 'A':
				decimalism += pow(16, sixsize - i - 1) * 10;
				break;
			case 'B':
				decimalism += pow(16, sixsize - i - 1) * 11;
				break;
			case 'C':
				decimalism += pow(16, sixsize - i - 1) * 12;
				break;
			case 'D':
				decimalism += pow(16, sixsize - i - 1) * 13;
				break;
			case 'E':
				decimalism += pow(16, sixsize - i - 1) * 14;
				break;
			case 'F':
				decimalism += pow(16, sixsize - i - 1) * 15;
				break;
            case 'x':
                break;
			default:
			    //ASCII中0~9的char从48开始，而A~F的char从65开始（大小写不同，小写从97开始）
			    decimalism += pow(16, sixsize - i - 1) * (sixteen[i]-48);		
			}
		}
		cout << decimalism << endl;
	}

	return 0;
}