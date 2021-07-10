class MySqrt {
public:
    int mySqrt(int x) {
        long long start = 0;
        long long end = x;  

        while(start < end){
            long long mid = (end+start+1) >> 1;
            if(mid * mid <= x) start = mid;
            else end = mid - 1;
        }
        return end;
    }
};