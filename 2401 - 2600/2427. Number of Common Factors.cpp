// APPROACH 1

class Solution {
public:
    int commonFactors(int a, int b) {
        int cnt = 0;
        for(int i=1; i<=a and i<=b; i++){
            if(a % i == 0 and b % i == 0)
                cnt++;
        }
        return cnt;
    }
};


// T.C. --> O(min(a, b)), since we loop through all possible factors from 1 to the minimum of a and b.
// S.C. --> O(1), since we are only using a constant amount of extra space to
// store the count of common factors.






// APPROACH 2

class Solution {
public:
    int commonFactors(int a, int b) {
        map<int, bool> mp;
        
        if(a==0 || b==0) return 0;
        if(a==1 && b==1) return 1;

        int count = 1;
        mp[1] = 1;
        mp[a] = 1;
        
        for(int i=2; i*i<=a; i++) {
            if(a % i == 0) {
                mp[i] = 1;
                mp[a/i] = 1;
            }
        }

        for(int i=2; i*i<=b; i++) {
            if(b % i == 0) {
                if(mp.find(i) != mp.end()) count++;
                if(mp.find(b/i) != mp.end()) count++;
            }
        }

        if(mp.find(b) != mp.end()) count++;

        return count;
    }
};


// T.C. --> O(sqrt(a) + sqrt(b) + k*log(k)), where k is the number of common factors of a and b.
// Because we first loop through all the factors of a and store them in a map, which takes 
// O(sqrt(a)) time. 
// Then, we loop through all the factors of b and check if they are common factors with a 
// using the map. This takes O(sqrt(b)) time. 
// Finally, we count the number of common factors and return the result. 
// Counting the number of common factors requires iterating through the map, which has size k. 
// In the worst case, the map could contain all the factors of a, so k would be O(sqrt(a)),
// and the total time complexity would be O(sqrt(a) + sqrt(b) + sqrt(a)*log(sqrt(a))) =
// O(sqrt(a)*log(sqrt(a))).


// S.C. --> O(sqrt(a)), since we are using a map to store the factors of a. 
// In the worst case, the map could contain all the factors of a, which is O(sqrt(a)).







