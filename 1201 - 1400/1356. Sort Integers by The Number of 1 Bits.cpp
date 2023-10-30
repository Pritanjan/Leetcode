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

// Custom Comparator and Sorting with Lambda Function
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


// Lambda Function for Custom Sorting
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

// Custom Comparator and Counting Ones with Bit Shifting
class Solution {
public:
    // Function to count the number of 1's in the binary representation of an integer
    static int cntOnes(int num) {
        int cnt = 0;
        while(num > 0) {
            if(num & 1) cnt++;
            num >>= 1;
        }
        return cnt;
    }
    
    // Custom comparator function for sort
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



