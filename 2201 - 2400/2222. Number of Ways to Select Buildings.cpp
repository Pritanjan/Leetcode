//https://leetcode.com/problems/number-of-ways-to-select-buildings/

//If the current building is '0', then the number of sequences of pattern "101" will be the product of the number of occurances of building '1' before the current building to the number of occurances of building '1' after the current building and viceversa.

#define ll long long int

class Solution {
public:
    long long numberOfWays(string s) {
        // a, b -: no. of occurence of '1' and '0' after the current building.
        ll ans = 0, a = 0, b = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '1' )
                a++;
            else
                b++;
        }
        // c, d -: no. of occurence of '1' and '0' before the current building.
        ll c = 0, d = 0;
        for(int i=0; i<s.size(); i++){
            // counting pattern '010'
            if(s[i] == '1'){
                ans += (d*b);
                c++;
                a--;
            }
            // counting pattern '101'
            else {
                ans += (a*c);
                d++;
                b--;
            }
        }
        return ans;
    }
};
