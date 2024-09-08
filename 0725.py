# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def splitListToParts(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: List[ListNode]
        """
        current_node = head
        list_size = 0
        while current_node:
            list_size += 1
            if not current_node.next:
                break
            current_node = current_node.next
        element_size = list_size // k
        exception_count = list_size % k
        result = []
        target = 0
        current_node = head
        current_index = 0
        prev_node = None
        while current_node:
            if current_index == target:
                result.append(current_node)
                if prev_node:
                    prev_node.next = None
                target += (element_size + (1 if exception_count > 0 else 0))
                exception_count -= 1
            prev_node = current_node
            current_node = current_node.next
            current_index += 1
        for _ in range(k-len(result)):
            result.append(None)
        return result
    
def main():
    ret = Solution().splitListToParts(None, 3)
    print(ret)

if __name__ == "__main__":
    main()