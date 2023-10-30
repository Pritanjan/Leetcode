// A 1

class Solution {
public:
    static bool compare(int a, int b){
        bitset<32> c0(a);
        bitset<32> c1(b);
        if(c0.count() != c1.count()) return c0.count() < c1.count();
        else return a < b;
    }    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};






// A 2








// A 3

class Solution {
public:
    static bool compare(const int& a, const int& b){
        int c0 = __builtin_popcount(a); // Count the number of one
        int c1 = __builtin_popcount(b); // Count the number of zero
        // cout<<a<<" "<<b;
        return c0 == c1 ? a<b : c0<c1 ;
    }    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};


// OR


class Solution {
public: 
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](const int& a, const int& b){
            int c0 = __builtin_popcount(a); // Count the number of one
            int c1 = __builtin_popcount(b); // Count the number of zero
            return c0 == c1 ? a<b : c0<c1 ;
        });
        return arr;
    }
};


// OR


class Solution {
public:
    static int cntOnes(int num) {
        int cnt = 0;
        while(num > 0) {
            if(num & 1) cnt++;
            num >>= 1;
        }
        return cnt;
    }
    static bool compare(int a, int b){
        int c0 = cntOnes(a); // Count the number of one
        int c1 = cntOnes(b); // Count the number of zero
        // cout<<a<<" "<<b;
        return c0 == c1 ? a<b : c0<c1 ;
    }    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};






// A 4



