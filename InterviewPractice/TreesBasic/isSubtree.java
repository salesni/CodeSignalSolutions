/*
Medium

Codewriting

3000

Given two binary trees t1 and t2, determine whether the second tree is a subtree of the first tree.
A subtree for vertex v in a binary tree t is a tree consisting of v and all its descendants in t. 
Determine whether or not there is a vertex v (possibly none) in tree t1 such that a subtree for vertex v (possibly empty) in t1 equals t2.

For

the output should be isSubtree(t1, t2) = true.

This is what these trees look like:

      t1:             t2:
       5              10
      / \            /  \
    10   7          4    6
   /  \            / \    \
  4    6          1   2   -1
 / \    \
1   2   -1
As you can see, t2 is a subtree of t1 (the vertex in t1 with value 10).

For
the output should be isSubtree(t1, t2) = false.

This is what these trees look like:

        t1:            t2:
         5             10
       /   \          /  \
     10     7        4    6
   /    \           / \    \
  4     6          1   2   -1
 / \   / 
1   2 -1
As you can see, there is no vertex v such that the subtree of t1 for vertex v equals t2.


*/

//
// Binary trees are already defined with this interface:
// class Tree<T> {
//   Tree(T x) {
//     value = x;
//   }
//   T value;
//   Tree<T> left;
//   Tree<T> right;
// }



boolean compareTrees(Tree<Integer> t1, Tree<Integer> t2){
    //if both are null is true
    if(t1 == null && t2 == null){
        return true;
    }
    //if one is and the other not is false
    if(t1 == null || t2 == null){
        return false;
    }
    //comare the hgead and its right and left side
    return  (t1.value.equals(t2.value) && 
    compareTrees(t1.left, t2.left) && 
    compareTrees(t1.right, t2.right));
}

boolean findRoot(Tree<Integer> t1, Tree<Integer> t2){
    // an emptu tree is always a subtree of any tree
    if(t2 == null){
        return true;
    }
    //if a tree is empty there cannot be any subtree
    if(t1 == null){
        return false;
    }
    //compare the trees from root,
    //the function compares roots fisrst before a recursive call
    if(compareTrees(t1, t2)){
        return true;
    }
    //if the root is not equal, search for the root on the left and right side
    return (findRoot(t1.left, t2) || findRoot(t1.right, t2));
}



boolean isSubtree(Tree<Integer> t1, Tree<Integer> t2) {
    return findRoot(t1, t2);
}

