
"""
You're given 2 huge integers represented by linked lists. 
Each linked list element is a number from 0 to 9999 that represents a number with exactly 4 digits. 
The represented number might have leading zeros. Your task is to add up these huge integers and return the result in the same format.

Example

For a = [9876, 5432, 1999] and b = [1, 8001], the output should be
addTwoHugeNumbers(a, b) = [9876, 5434, 0].

Explanation: 987654321999 + 18001 = 987654340000.

For a = [123, 4, 5] and b = [100, 100, 100], the output should be
addTwoHugeNumbers(a, b) = [223, 104, 105].

Explanation: 12300040005 + 10001000100 = 22301040105.

Input/Output

[execution time limit] 4 seconds (py3)

[input] linkedlist.integer a

The first number, without its leading zeros.

Guaranteed constraints:
0 ≤ a size ≤ 104,
0 ≤ element value ≤ 9999.

[input] linkedlist.integer b

The second number, without its leading zeros.

Guaranteed constraints:
0 ≤ b size ≤ 104,
0 ≤ element value ≤ 9999.

[output] linkedlist.integer

The result of adding a and b together, returned without leading zeros in the same format.



"""




# Singly-linked lists are already defined with this interface:
# class ListNode(object):
#   def __init__(self, x):
#     self.value = x
#     self.next = None
#

def addTwoHugeNumbers(a, b):
    acumA=""
    acumB=""
    maxA=0
    maxB=0
    while(a!= None):
        acumA+=str(a.value).zfill(4)
        a=a.next
        maxA+=1
        
    print(acumA)
    
    while(b!=None):
        acumB+=str(b.value).zfill(4)
        b=b.next
        maxB+=1
        
    print(acumB)
    
    maxInx=4*max(maxA,maxB)
    cString=str(int(acumA)+int(acumB));
    
    if(len(cString)>maxInx):
        maxInx+=4
    
    cString=str(int(acumA)+int(acumB)).zfill(maxInx)
    
    
    c=[]
    maxInx=int(maxInx/4)
    
    for i in range(maxInx):
        c.append(int(cString[i*4:4+i*4]))
    return c

