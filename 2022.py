class Solution(object):
    def construct2DArray(self, original, m, n):
        """
        :type original: List[int]
        :type m: int
        :type n: int
        :rtype: List[List[int]]
        """
        result = []
        if len(original) != m * n:
            return result
        index = 0
        temp = []
        for num in original:
            temp.append(num)
            if index == n-1:
                result.append(temp)
                temp = []
                index = 0
                continue
            index += 1
        return result

def main():
    # ret = Solution().construct2DArray([1,2,3,4], 2, 2)
    # ret = Solution().construct2DArray([1,2,3], 1, 3)
    # ret = Solution().construct2DArray([1,2], 1, 1)
    ret = Solution().construct2DArray([5], 3, 1)
    print(ret)

if __name__ == "__main__":
    main()