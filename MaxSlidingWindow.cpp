class MaxSlidingWindow {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        // 大根堆：堆顶值最大
        priority_queue<pair<int, int>> q;

        // 二元组：（值，下标）
        for(int i=0; i<k-1; i++) q.push(make_pair(nums[i], i));

        // 窗口开始滑动
        for(int i=k-1; i<nums.size(); i++){
            q.push(make_pair(nums[i], i));

            // 懒惰删除：延迟到未删答案会影响结果（=堆顶）时
            while(q.top().second <= i-k) q.pop();
            ans.push_back(q.top().first);
        }
        return ans;
    }
};