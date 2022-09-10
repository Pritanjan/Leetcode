// #includeclass Solution {
// public:
//     int countDigitOne(int n) {
//         int c = 0;
//         for(int i=1; i<=n; i++){
//             string s = to_string(i);
//             c += count(s.begin(), s.end(), '1');
//         }
//         return c;
//     }
// };

// // T.C. --> O(n * log(n))
// // We iterate from 1 to n
// // In each iteration, we convert integer to string and count '1' in string which takes linear time in number of digits in i, which is log(n)

// // S.C. --> O(log(n))

#include <bits/stdc++.h>
using namespace std;

class Solution {
	int max(int a, int b){
		if(a>b)
			return a;
		else
			return b;
	}

	int min(int a, int b){
		if(a>b)
			return b;
		else
			return a;
	}

	public int countDigitOne(int n) {
		int c = 0;
		for(int i=1; i<=n; i*=10){
			int divider = i*10;
			c += (n/divider)*i + min(max((n%divider -i + 1), 0),i);
		}
		return c;
	}
}

int main (){
    int n = 13;
    cout<<countDigitOne(n) <<endl;
}