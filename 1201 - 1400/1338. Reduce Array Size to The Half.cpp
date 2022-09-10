//https://leetcode.com/problems/reduce-array-size-to-the-half/

Solution 1: HashMap & Sorting
Using HashMap to count the frequency of each numbers.
Get array of the frequency, let name it frequencies.
Sort frequencies in increasing order.
We prioritize removing the numbers with the largest frequency first, until we've eliminated at least half of the arr.
Return the number of numbers removed.

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> ump;
        for(int i=0; i<arr.size(); i++){
            ump[arr[i]]++;
        }
        
        vector<int> v;
        for(auto i : ump)
            v.push_back(i.second);
        
        sort(v.begin(),v.end());
        
        int ans = 0;
        int removed = 0;
        int i = v.size()-1;
        
        while(removed < arr.size()/2){
            ans += 1;
            removed += v[i--];
        }
        return ans;
    }
};



class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> ump;
        for(int i=0; i<arr.size(); i++){
            ump[arr[i]]++;
            if(ump[arr[i]] >= arr.size()/2)
            	return 1;
        }
        
        priority_queue<int> pq;
        for(auto it : ump){
        	pq.push(it.second);
		}
                   
        int ans = 0;
        int removed = 0;
        while(pq.empty()==0){
            ans++;
            removed += pq.top();
            if(removed >= arr.size()/2)
            	break;
            pq.pop();;
        }
        return ans;
    }
};
