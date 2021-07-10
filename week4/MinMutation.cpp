 #include<queue>
class MinMutation {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, int> depth;
        unordered_set<string> bankSet;
        const char gene[4] = {'A', 'C', 'G', 'T'};

        // 初始化
        depth[start] = 0;
        queue<string> q;
        q.push(start);
        for(string& s: bank) bankSet.insert(s);
        // if(bankSet.size() == 0) return -1;

        // BFS
        while(!q.empty()){
            string s = q.front();
            q.pop();
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 4; j++){
                    if(s[i] == gene[j]) continue;
                    string nextS = s;

                    // s的某一种变化
                    nextS[i] = gene[j];
                    if(bankSet.find(nextS) == bankSet.end()) continue;
                    if(depth.find(nextS) == depth.end()){
                        depth[nextS] = depth[s] + 1;
                        q.push(nextS);

                        // 边界
                        if(nextS == end){
                            return depth[nextS];
                        }
                    }
                }
            }
        }
        return -1;
    }
};
