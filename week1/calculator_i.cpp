class calculator {
public:
    int calculate(string s) {
        stack<char> op;
        vector<string> tokens;
        bool num_srtart = false;
        bool comp_zero = true;
        long long val = 0;
        for(char ch: s){
            // 思路：中缀表达式转成后缀表达式，然后用逆波兰式求解

            // 字符转成数值
            if(ch >= '0' && ch <= '9'){
                val = val*10 + ch - '0';
                num_srtart = true;
                continue;
            }else if (num_srtart){
                tokens.push_back(to_string(val));
                num_srtart = false;
                comp_zero = false;
                val = 0;
            }
            
            // 处理运算符：括号用栈来存
            if(ch == ' ') continue;
            if(ch == '('){
                op.push(ch);
                comp_zero = true;
                continue;
            }
            if(ch == ')'){
                while(!op.empty() && op.top() != '('){
                    tokens.push_back(string(1, op.top()));
                    op.pop();
                }
                comp_zero = false;
                op.pop();
                continue;
            }

            if(comp_zero) tokens.push_back("0");

            while(!op.empty() && getRank(op.top()) >= getRank(ch)){
                tokens.push_back(string(1, op.top()));
                op.pop();
            }
            op.push(ch);
            comp_zero = true;
        }

        // 最后处理：如果数字没结束
        if (num_srtart) tokens.push_back(to_string(val));
        // 最后处理：如果栈不为空
        while(!op.empty()){
            tokens.push_back(string(1, op.top()));
            op.pop();
        }
        return evalRPN(tokens);
    }

    int getRank(char ch){
        if (ch == '+' || ch == '-') return 1;
        if (ch == '*' || ch == '/') return 2;
        return 0;   
    }

    int evalRPN(vector<string>& tokens) {
        stack<long long> s;
        for (string& token : tokens) {
            // 是运算符，取出栈顶两个操作数，运算结果入栈
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                long long b = s.top();
                s.pop();
                long long a = s.top();
                s.pop();
                s.push(calc(a, b, token)); 
            } else {
                // 操作数入栈
                s.push(stoi(token));
            }
        }
        return s.top();
    }

    long long calc(long long a, long long b, string op) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/") return a / b;
        return 0;
    }
};