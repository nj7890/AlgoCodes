# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        head=None
        tail=None
        flag=0
        temp=0
        while l1 and l2:
            temp=l1.val+l2.val+flag
            if temp//10==0:
                flag=0
            else:
                flag=temp//10
                temp=temp%10
            new_node=ListNode(temp)
            if head is None:
                head=new_node
                tail=new_node
            else:
                tail.next=new_node
                tail=new_node
            l1=l1.next
            l2=l2.next
        while l1 :
            temp=l1.val+flag
            if temp//10==0:
                flag=0
            else:
                flag=temp//10
                temp=temp%10
            new_node=ListNode(temp)
            if head is None:
                head=new_node
                tail=new_node
            else:
                tail.next=new_node
                tail=new_node
            l1=l1.next
        
        while l2:
            temp=l2.val+flag
            if temp//10==0:
                flag=0
            else:
                flag=temp//10
                temp=temp%10
            new_node=ListNode(temp)
            if head is None:
                head=new_node
                tail=new_node
            else:
                tail.next=new_node
                tail=new_node
            l2=l2.next
        if flag !=0:
            new_node=ListNode(flag)
            if head is None:
                head=new_node
                tail=new_node
            else:
                tail.next=new_node
                tail=new_node

        return head