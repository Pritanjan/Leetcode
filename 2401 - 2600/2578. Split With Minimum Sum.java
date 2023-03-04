import java.util.PriorityQueue;

class Solution {
    public int splitNum(int num) {
        String s = String.valueOf(num);
        int n = s.length();
        int[] a = new int[n];
        
        for (int i=0; i<n; i++) {
            a[i] = s.charAt(i) - '0';
        }
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        StringBuilder n1 = new StringBuilder();
        StringBuilder n2 = new StringBuilder();
        
        for (int i : a) {
            pq.add(i);
        }
        
        while (!pq.isEmpty()) {
            n1.append(pq.poll());
            if (!pq.isEmpty()) {
                n2.append(pq.poll());
            }
        }
        
        return Integer.parseInt(n1.toString()) + Integer.parseInt(n2.toString());
    }
}
