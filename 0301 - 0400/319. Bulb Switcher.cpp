class Solution {
public:
    int bulbSwitch(int n) {
        int cnt = 0;
        for(int i=1; i*i<=n; i++) {
            cnt++;
        }
        return cnt;
    }
};





Since we only care about the bulbs that are on after n rounds, we can simply count the number of perfect squares less than or equal to n. This is because a bulb will be toggled once for every factor it has. For example, the first bulb will be toggled on the first round, but then it will only be toggled by itself (the first factor) on the second round, so it will end up off. However, the fourth bulb will be toggled on the first, second, and fourth rounds, so it will end up on.

Therefore, the number of bulbs that will be on after n rounds is simply the number of perfect squares less than or equal to n. This can be calculated by iterating from 1 to the square root of n and counting each iteration.
