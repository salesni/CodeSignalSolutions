/*.
Given a binary tree t, determine whether it is symmetric around its center, i.e. each side mirrors the other.
For

the output should be isTreeSymmetric(t) = true.

Here's what the tree in this example looks like:

    1
   / \
  2   2
 / \ / \
3  4 4  3
As you can see, it is symmetric.

For
the output should be isTreeSymmetric(t) = false.

Here's what the tree in this example looks like:

    1
   / \
  2   2
   \   \
   3    3
   
   nput/Output

[execution time limit] 4 seconds (js)

[input] tree.integer t

A binary tree of integers.

Guaranteed constraints:
0 ≤ tree size < 5 · 104,
-1000 ≤ node value ≤ 1000.

[output] boolean

Return true if t is symmetric and false otherwise.
*/


//
// Binary trees are already defined with this interface:
// function Tree(x) {
//   this.value = x;
//   this.left = null;
//   this.right = null;
// }

let isMirror=(t1,t2)=>{
    if(t1==null && t2==null)
        return true;
    if (t1!=null && t2!=null && t1.value==t2.value){
        return isMirror(t1.left,t2.right) && 
                isMirror(t1.right,t2.left);
    }
    return false;
}
function isTreeSymmetric(t) {
    return isMirror(t,t);

}
