# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSubPath(self, head, root):
        """
        :type head: ListNode
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return False
        elif head.val == root.val:
            if self.check(head, root):
                return True
        return self.isSubPath(head, root.left) or self.isSubPath(head, root.right)
        
    def check(self, current_list, current_tree):
        if not current_tree or current_list.val != current_tree.val:
            return False
        if current_list.val == current_tree.val and not current_list.next:
            return True
        return self.check(current_list.next, current_tree.left) or self.check(current_list.next, current_tree.right)