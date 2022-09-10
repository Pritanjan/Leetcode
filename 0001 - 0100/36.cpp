#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n,a[n];
        cin>>n;
        
        for(int i=0;i<n;i++){
        	cin>>a[i];
		}
		sort(a.begin(),a.end());
		for(int i=0;i<n;i++){
            if(a[i]!=a[i+1])
               cout<<a[i];
        }
        	
        
    }
	
	return 0;
}
