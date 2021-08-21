class HammingWeight {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        // 方法一
        // for(int i = 0; i < 32; i++){
        //     if((n >> i) & 1 == 1) count++;
        // }

        // 方法二
        while(n > 0){
            count++;
            n -= n & -n;
        }
        return count;
    }

    
};