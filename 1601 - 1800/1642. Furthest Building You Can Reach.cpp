// A 1 

class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        priority_queue<int> pq;
        for(int i=0; i<h.size()-1; i++){
            if(h[i] < h[i+1]){
                pq.push(h[i] - h[i+1]);
            }
            if(pq.size() > l){
                b += pq.top();
                pq.pop();
            }
            
            if(b<0)
                return i;
        }
        return h.size()-1;
    }
};

// h[i] > h[i+1] --> l += 0; b += 0;
// h[i] < h[i+1] --> l += 1; b += (h[i+1] - h[i]);






// A 2 

