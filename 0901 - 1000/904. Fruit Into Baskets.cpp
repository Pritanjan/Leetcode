class Solution {
public:
    int totalFruit(vector<int>& f) {
        unordered_map<int, int> cnt;
        int L = 0, R = 0;
        
        while(R < f.size()){              //iterate over the array
            cnt[f[R]]++;                  //increase frequency at current index

            if(cnt.size() > 2){          //if size of map > (2)
                cnt[f[L]]--;              //decrease left index frequency

                if(cnt[f[L]] == 0) cnt.erase(f[L]);  //if freq==0
                L++;                      //left index ++(removing from window)
            }
            R++;                          //right index at each iteration ++
        }
        return R - L;                      //final window size
    }
};


// Same

class Solution {
public:
  int totalFruit(vector<int>& tree) {
    int ans = 0;
    unordered_map<int, int> count;

    for (int l = 0, r = 0; r < tree.size(); ++r) {
      ++count[tree[r]];
      while (count.size() > 2) {
        if (--count[tree[l]] == 0)
          count.erase(tree[l]);
        ++l;
      }
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};







