// APPROACH 1


class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
      int max = 0;
      vector<bool> ans;
      
      // finding the max
      for(int i=0; i<candies.size(); i++) {
         if(candies[i] > max)
            max = candies[i];
      }
      
      for(int i=0; i<candies.size(); i++) {
          if( (candies[i] + extraCandies) >= max)  ans.push_back(true);
          else  ans.push_back(false);
      }
      
      return ans;
    }
};








// APPROACH 2 [ STL ]


class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // Find the maximum number of candies among all kids
        int maxCandies = *max_element(candies.begin(), candies.end());
        
        // Check which kids can have the greatest number of candies after adding the extra candies
        vector<bool> res(candies.size());

        transform(candies.begin(), candies.end(), res.begin(), [extraCandies, maxCandies](int candy) {
            return candy + extraCandies >= maxCandies;
        });
        
        return res;
    }
};





