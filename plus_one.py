class PlusOne:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits)
        flag = False

        if 9 not in digits:
            digits[n - 1] += 1
            return digits

        for i in range(n-1, -1, -1):
            if digits[i] == 9:
                flag = True
                digits[i] = 0
            else:
                if flag:
                    digits[i] += 1
                    flag = False
                    break
                else:
                    digits[i] += 1
                    break

        if flag:
            digits.insert(0, 1)
        return digits