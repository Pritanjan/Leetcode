class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(), p.end(), compare);
        int mx = INT_MIN;
        int cnt = 0;
        int n = p.size();
        
        for(int i=n-1; i>=0; i--){
            if(p[i][1] < mx)
                cnt++;
            
            mx = max(mx, p[i][1]);
        }
        return cnt;
    }
};


// we need both attack and defence of the player should be less than the other player then only we can say the later person is weaker
// so we need to see two parameter(defence and attack) to give our answer
// we can do a thing lets sort the array on one parameter and then we will see how will we handle the other one
// if the array is sorted on one parameter we only need to check other. As the array is sorted the greater index cant be weaker than then smaller index i.e if i > j i cant be weaker than j (as the array is sorted)
// so lets iterate from back and store the maximum element we encounter(as if we found a larger element(value of second parameter) on right it will be weaker as the second element is less and first one was already less because of sorting so both strenght and defence is weak)



    
