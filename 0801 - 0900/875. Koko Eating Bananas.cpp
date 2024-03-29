// A 1 - Binary Search

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int L = 1;
        int R = *max_element(piles.begin(), piles.end());         
        while(L < R){
            int mid = (L+R)/2;
            int hrs = 0;            

            // for(int i : piles) hrs += (i + mid - 1)/mid;
            for(int i : piles) hrs += i/mid + (i % mid != 0);
            if(hrs <= h) R = mid;
            else L = mid + 1;
        }
        return R;
    }
};

// T.C. --> O(n log m)
// The initial search space is from 1 to m, it takes logm comparisons to reduce the search space to 1.
// For each eating speed middle, we traverse the array and calculate the overall time Koko spends, which takes O(n) for each traversal.
// To sum up, the time complexity is O(n·logm)

// S.C. --> O(1)   
// For each eating speed middlemiddle, we iterate over the array and calculate the total hours Koko spends, which costs constant space.
// Therefore, the overall space complexity is O(1).






// A 2

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int L = 1;
        int R = *max_element(piles.begin(), piles.end());
        while(L < R) {
            int mid = L + (R - L) / 2;
            if(canEatAll(piles, mid, h)) R = mid;
            else L = mid + 1;
        }        
        return L;
    }

    bool canEatAll(vector<int>& piles, int speed, int h) {
        int hrs = 0;
        for(int pile : piles) {
            hrs += (pile + speed - 1) / speed;
        }        
        return hrs <= h;
    }
};








// A 3

class Solution {
public:
    unordered_map<int, int> ump;
    int minEatingSpeed(vector<int>& piles, int h) {
        int L = 1;
        int R = *max_element(piles.begin(), piles.end());
        while(L < R) {
            int mid = L + (R - L) / 2;
            if(ump.find(mid) == ump.end()) {
                int hrs = 0;
                for(int pile : piles) hrs += (pile + mid - 1) / mid;
                ump[mid] = hrs;
            }
            if(ump[mid] > h) L = mid + 1;
            else R = mid;
        }
        return L;
    }
};






// A 4 - Randomized Algorithm

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());
        int miK = 1, mxK = maxPile;
        
        while(miK < mxK) {
            int midK = miK + rand() % (mxK - miK + 1);
            long long int hrs = 0;
            for(auto pile : piles) hrs += (pile + midK - 1) / midK;
            if(hrs <= h) mxK = midK;
            else miK = midK + 1;
        }
        return miK;
    }
};






// A 5


