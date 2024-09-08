class Solution(object):
    def missingRolls(self, rolls, mean, n):
        """
        :type rolls: List[int]
        :type mean: int
        :type n: int
        :rtype: List[int]
        """
        sum_n = mean * (len(rolls) + n) - sum(rolls)
        if sum_n < n or sum_n > 6*n:
            return []
        quotient = sum_n // n
        remainder = sum_n % n
        return [quotient+1]*remainder + [quotient]*(n-remainder)