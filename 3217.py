# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def modifiedList(self, nums, head):
        """
        :type nums: List[int]
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        nums_set = set(nums)
        current_node = head
        prev_node = None
        while current_node:
            if current_node.val in nums_set:
                if prev_node:
                    prev_node.next = current_node.next
                else:
                    head = head.next
            else:
                prev_node = current_node
            current_node = current_node.next
        return head
