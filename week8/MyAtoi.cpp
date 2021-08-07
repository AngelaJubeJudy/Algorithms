class MyAtoi {
public:
    int myAtoi(string s) {
        // 丢弃签到空格
        int index = 0;
        while(index < s.length() && s[index] == ' '){  
            index++;
        }

        // 判断符号
        int sign = 1;
        if(index < s.length() && s[index] == '+' || s[index] == '-'){
            if(s[index] == '-') sign = -1;   
            index++;
        }

        // 处理数字
        int val = 0;
        while(index < s.length() && s[index] >= '0' && s[index] <= '9'){
            if(val > (2147483648 - (s[index] - '0'))/10) {
                if(sign == -1) return -2147483648;
                else return 2147483648;
            }
            val = val*10 + (s[index] - '0');
            index++;
        }
        return val*sign;
    }
};