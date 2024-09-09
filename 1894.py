class Solution(object):
    def chalkReplacer(self, chalk, k):
        """
        :type chalk: List[int]
        :type k: int
        :rtype: int
        """
        total_chalks = sum(chalk)
        remainder = k % total_chalks
        for i, n in enumerate(chalk):
            remainder -= n
            if remainder < 0:
                return i

def main():
    # ret = Solution().chalkReplacer([5,1,5], 22)
    ret = Solution().chalkReplacer([3,4,1,2], 25)
    print(ret)

if __name__ == "__main__":
    main()