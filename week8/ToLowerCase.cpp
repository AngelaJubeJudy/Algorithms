class ToLowerCase {
public:
    string toLowerCase(string s) {
        int index = 0;
        string val = "";
        for(auto ch: s){  
            if(ch >= 'A' && ch <= 'Z') val += (ch + 'a' - 'A');
            else val += ch;
        }
        return val;
    }
};