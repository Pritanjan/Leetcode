#include<bits/stdc++.h>
using namespace std;

int main(){
	string s,digit;
	cin>>s>>digit;
	
	for(int i=0; i<s.size(); i++){
		if(s[i] == digit)
			break;
		else
		continue;
	}
	
	cout<<s;
}

