class LadderLength2 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 初始化
        unordered_map<string, int> distBegin, distEnd;
        for(string& s: wordList) distBegin[s] = distEnd[s] = 1e9;
        if(distBegin.find(endWord) == distBegin.end()) return 0;
        distBegin[beginWord] = 1;
        distEnd[endWord] = 1;
        queue<string> qBegin, qEnd;
        qBegin.push(beginWord);
        qEnd.push(endWord);

        // 双向 BFS
        while(!qBegin.empty() || !qEnd.empty()){
            int res = expand(qBegin, distBegin, distEnd);
            if(res != -1) return res;
            res = expand(qEnd, distEnd, distBegin);
            if(res != -1) return res;
        }
        return 0;
    }

    int expand(queue<string>& q, unordered_map<string, int>& dist, unordered_map<string, int>& distOther){
        if(!q.empty()){  // 只扩展一步
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
                            if(distOther[s] != 1e9){
                                return depth + distOther[s];
                            }
                        }
                    }

                    // 还原
                    s[i] = backup;
                }
            }
        }
        return -1;
    }
};