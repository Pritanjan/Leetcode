// A 1 - Using PQ

class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    SeatManager(int n) {
        for(int i=1; i<=n; i++) {
            pq.push(i);
        }
    }
    
    int reserve() {
        int tmp = pq.top();
        pq.pop();
        return tmp;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};






// A 2 - Min Heap (without pre-initialization)

class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int seat;
public:
    SeatManager(int n) {
        seat = 1;
    }
    
    int reserve() {
        if(!pq.empty()) {
            int tmp = pq.top();
            pq.pop();
            return tmp;
        }
        int tmp = seat;
        seat++;
        return tmp;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};






// A 3 

// JAVA
public class SeatManager {
    private boolean[] seats;
    private int first = 0;
    private int total = 0;

    public SeatManager(int n) {
        seats = new boolean[n];
        total = n;
        Arrays.fill(seats, false);
    }

    public int reserve() {
        seats[first] = true;
        int reserved = first + 1;
        while(first < total && seats[first]) first++;
        return reserved;
    }

    public void unreserve(int seatNumber) {
        if(first > seatNumber - 1) {
            first = seatNumber - 1;
        }
        seats[seatNumber - 1] = false;
    }
}



// C++ - TLE
class SeatManager {
private:
    vector<bool> seats;
    int first = 0;
    int total = 0;
public:
    SeatManager(int n) {
        total = n;
        seats.resize(n, false);
    }
    
    int reserve() {
        seats[first] = true;
        int reserved = first + 1;
        while(first < total && seats[first]) first++;
        return reserved;
    }
    
    void unreserve(int seatNumber) {
        if(first > seatNumber - 1) {
            first = seatNumber - 1;
        }
        seats[seatNumber - 1] = false;
    }
};
