// A 1 

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for (auto &i : piles)
            pq.push(i);
        
        while (k--){
            int temp = pq.top() - floor(pq.top() / 2);
            pq.pop();
            pq.push(temp);
        }

        int sum = 0;
        while (!pq.empty()){
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};






// A 2 

class Solution {
public:
    string makeFancyString(string s) {
        if (s.size() < 3) return s;
        int j = 2;
        for (int i = 2; i < s.size(); i++) {
            if (s[i] != s[j - 1] || s[i] != s[j - 2])
                s[j++] = s[i];
        }
        s.resize(j);
        return s;
    }
};

