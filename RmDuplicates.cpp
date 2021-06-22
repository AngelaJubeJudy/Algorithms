class RemoveDuplicates {
public:
    int removeDuplicates(vector<int>& nums) {
        // vector<int> result;
        // for (int i = 0; i < nums.size(); i++){
        //     if (i == 0 || nums[i] != nums[i-1]) result.push_back(nums[i]);
        // }
        // return result.size();
        int n = 0;
        for (int i = 0; i < nums.size(); i++){
            if(i == 0 || nums[i] != nums[i-1]){
                nums[n] = nums[i];
                n++;
            }
        }
        return n;
    }
};