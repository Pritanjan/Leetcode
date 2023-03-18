class Solution {
    public int distMoney(int m, int c) {
        if(c > m)
            return -1;

        if(m < 8) return 0;

        int d = m / 8;
        int modulus = m % 8;

        if(d == c && modulus == 0) return c;
        if(d >= c) return c - 1;

        if(modulus == 4 && (c - d) == 1) return c - 2;

        if(modulus >= (c-d)) return d;

        int rem = c-d;

        while(modulus < rem){
            rem++;
            modulus += 8;
            d--;
        }
        return d;
    }
}



