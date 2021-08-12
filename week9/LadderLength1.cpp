class LadderLength1 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 初始化
        unordered_map<string, int> dist;
        for(string& s: wordList) dist[s] = 1e9;
        dist[beginWord] = 1;

        // bfs
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            string s = q.front();
            q.pop();
            int depth = dist[s];
            
            for(int i = 0; i < s.length(); i++){
                for(char ch = 'a'; ch <= 'z'; ch++){
                    char backup = s[i];
                    s[i] = ch;
                    if(dist.find(s) != dist.end()){
                        if(dist[s] > depth + 1){
                            dist[s] = depth + 1;
                            q.push(s);
                            if(s == endWord) return dist[s];
                        }
                    }

                    // 还原
                    s[i] = backup;
                }
            }
        }
        return 0;
    }
};