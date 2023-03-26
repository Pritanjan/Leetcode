// APPROACH 1

class Solution {
public:
    int countSubstrings(string s, string t) {
        int m = s.size(), n = t.size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int diff = 0;
                for (int k = 0; i + k < m && j + k < n; k++) {
                    diff += s[i + k] == t[j + k] ? 0 : 1;
                    if (diff > 1) {
                        break;
                    } else if (diff == 1) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};







// APPROACH 20

// https://space.bilibili.com/206214
class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans = 0, n = s.length(), m = t.length();
        for (int d = 1 - m; d < n; ++d) { // d=i-j, j=i-d
            int i = max(d, 0);
            for (int k0 = i - 1, k1 = k0; i < n && i - d < m; ++i) {
                if (s[i] != t[i - d]) {
                    k0 = k1; // 上上一个不同
                    k1 = i;  // 上一个不同
                }
                ans += k1 - k0;
            }
        }
        return ans;
    }
};
