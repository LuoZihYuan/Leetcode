class Solution(object):
    def getLucky(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        str_sum = ""
        for l in s:
            str_sum += str(ord(l)-96)
        for _ in range(k):
            su = 0
            for digit_sum in str_sum:
                su += int(digit_sum)
            str_sum = str(su)
        return int(str_sum)

def main():
    # ret = Solution().getLucky("iiii", 1)
    # ret = Solution().getLucky("leetcode", 2)
    ret = Solution().getLucky("zbax", 2)
    print(ret)

if __name__ == "__main__":
    main()