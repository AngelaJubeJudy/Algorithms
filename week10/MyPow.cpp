class MyPow {
public:
    double myPow(double x, int n) {
        if(n == 1) return x;
        if (n < 0 && n >= INT_MIN) return 1 / myPow(x, -n);
        if(n == 0) return 1;
        
        // 方法二：快速幂
        double ans = 1;
        while(n > 0){
            if(n & 1) ans = ans * x;
            n = n >> 1;
            x = x*x;
        }
        return ans;
    }
};

