class Solution(object):
    def xorQueries(self, arr, queries):
        """
        :type arr: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        cache = []
        cache.append(arr[0])
        index = 1
        result = []
        for query in queries:
            if index <= query[1]:
                while index <= query[1]:
                    cache.append(cache[-1] ^ arr[index])
                    index += 1
            if query[0]:
                result.append(cache[query[0]-1] ^ cache[query[1]])
            else:
                result.append(cache[query[1]])
        return result

def main():
    ret = Solution().xorQueries([1,3,4,8], [[0,1],[1,2],[0,3],[3,3]])
    # ret = Solution().xorQueries([4,8,2,10], [[2,3],[1,3],[0,0],[0,3]])
    print(ret)

if __name__ == "__main__":
    main()
