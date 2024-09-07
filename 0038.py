class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        result = [1]
        if n <= 1:
            return "1"
        for _ in range(n-1):
            temp = []
            prev = result[0]
            count = 0
            for num in result:
                if num == prev:
                    count += 1
                else:
                    temp.append(count)
                    temp.append(prev)
                    prev = num
                    count = 1
            temp.append(count)
            temp.append(prev)
            result = temp
        return "".join(str(num) for num in result)

def main():
    s = Solution()
    print(s.countAndSay(4))
    print(s.countAndSay(1))
    print(s.countAndSay(30))

if __name__ == "__main__":
    main()