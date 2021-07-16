class Permutation:

    def permute(self, nums: List[int]) -> List[List[int]]:
        # 初始化
        self.nums = nums
        self.ans = []
        self.permutation = []
        self.n = len(nums)
        self.used = [False] * self.n

        self.find(0)
        return self.ans

    def find(self, index):
        if index == self.n:
            self.ans.append(self.permutation[:])
            return

        for i in range(self.n):
            if not self.used[i]:
                self.used[i] = True
                self.permutation.append(self.nums[i])
                self.find(index + 1)
                self.permutation.pop()
                self.used[i] = False