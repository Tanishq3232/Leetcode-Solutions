# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry=0
        flag=l1.val+l2.val
        if(flag>=10):
            carry=flag//10
            flag=flag%10
        l3=ListNode()
        l3.val=flag
        head=l3
        if(l1.next==None and l2.next==None):
            if(carry>0):
                head.next=ListNode(carry)
        else:
            while(l1.next!=None and l2.next!=None):
                #print(l1.val)
                #print(l2.val)
                temp=l1.next.val+l2.next.val+carry
                carry=0
                if(temp>=10):
                    carry=temp//10
                    temp=temp%10
                flag=ListNode(temp)
                head.next=flag
                head=head.next
                l1=l1.next
                l2=l2.next
            #print(l1.val)
            #print(l2.val)
            if(l1.next!=None):
                while(l1.next!=None):
                    temp=l1.next.val+carry
                    carry=0
                    if(temp>=10):
                        carry=temp//10
                        temp=temp%10
                    flag=ListNode(temp)
                    head.next=flag
                    head=head.next
                    l1=l1.next
            elif(l2.next!=None):
                while(l2.next!=None):
                    temp=l2.next.val+carry
                    carry=0
                    if(temp>=10):
                        carry=temp//10
                        temp=temp%10
                    flag=ListNode(temp)
                    head.next=flag
                    head=head.next
                    l2=l2.next
            if(l1.next==None and l2.next==None):
                if(carry>0):
                    head.next=ListNode(carry)
                
        return l3