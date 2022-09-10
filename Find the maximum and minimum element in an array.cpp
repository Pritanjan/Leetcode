// https://practice.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1

// APPROACH 1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long
pair<long long, long long> getMinMax(long long a[], int n) ;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}

// } Driver Code Ends
pair<long long, long long> getMinMax(long long a[], int n) {
    ll ma = a[0];
    ll mi = a[0];
    // pair<ll,ll> p;
    
    for(int i=0; i<n; i++){
        if(a[i] < mi)
            mi = a[i];
    }
    
    for(int i=0; i<n; i++){
        if(a[i] > ma) 
            ma = a[i];
    }
    return {mi,ma} ;
}


// APPROACH 2

pair<long long, long long> getMinMax(long long a[], int n) {
    ll ma = a[0];
    ll mi = a[0];
    pair<ll,ll> p;
    
    for(int i=0; i<n; i++){
        ma = max(ma, a[i]);
        mi = min(mi, a[i]);
    }
    
    p.first = mi, p.second = ma;
    return p;
    
    // return {mi,ma} ;
}
