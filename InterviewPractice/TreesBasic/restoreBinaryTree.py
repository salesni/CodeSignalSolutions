"""
Note: Your solution should have O(inorder.length) time complexity, 
since this is what you will be asked to accomplish in an interview.

Let's define inorder and preorder traversals of a binary tree as follows:

Inorder traversal first visits the left subtree, then the root, then its right subtree;
Preorder traversal first visits the root, then its left subtree, then its right subtree.
For example, if tree looks like this:

    1
   / \
  2   3
 /   / \
4   5   6
then the traversals will be as follows:

Inorder traversal: [4, 2, 1, 5, 3, 6]
Preorder traversal: [1, 2, 4, 3, 5, 6]
Given the inorder and preorder traversals of a binary tree t, but not t itself, restore t and return it.
Input/Output

[execution time limit] 4 seconds (py)

[input] array.integer inorder

An inorder traversal of the tree. It is guaranteed that all numbers in the tree are pairwise distinct.

Guaranteed constraints:
1 ≤ inorder.length ≤ 2 · 103,
-105 ≤ inorder[i] ≤ 105.

[input] array.integer preorder

A preorder traversal of the tree.

Guaranteed constraints:
preorder.length = inorder.length,
-105 ≤ preorder[i] ≤ 105.

[output] tree.integer

The restored binary tree.

"""


#
# Binary trees are already defined with this interface:
# class Tree(object):
#   def __init__(self, x):
#     self.value = x
#     self.left = None
#     self.right = None



def buildTree(preStart,inStart,inEnd,inorder,preorder,mp):
    #If the root is a leaf it should return each child as Null
    if(preStart>len(preorder)-1 or inStart>inEnd):
        return None
        
    #Put the value for the root that will always be found
    #at the begining of the preorder array
    root = Tree(preorder[preStart])
    
    #Check for the index of the root on the inorder array
    inRootIdx=mp[root.value]
    
    #The left is built adding the prestart 1, because the second
    #value of a preorder traversal is the left child of the root
    #the range to search for all the noodes for the left side 
    #are from the inStart to the index of the root -1 
    root.left = buildTree(preStart+1,inStart,inRootIdx-1,inorder,preorder,mp)

    #The right is built adding the prestart the value of the root index
    #minus the start of the inorder +1, in order to find the right root
    #the range to search for all the noodes for the right side 
    #are from the index of the root +1 tothe in order end
    root.right = buildTree( preStart + inRootIdx - inStart + 1 ,inRootIdx+1,inEnd,inorder,preorder,mp)
    
    
    return root
    
    
    
    
def restoreBinaryTree(inorder, preorder):
    #Build a Dictionary  to store the index of 
    #all in order elements to use them in the algortihm
    inOrderMap={}
    for i in  range(len(inorder)):
        inOrderMap[inorder[i]]=i
    
    return buildTree(0,0,len(inorder)-1,inorder,preorder,inOrderMap)
