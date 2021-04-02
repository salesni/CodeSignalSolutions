
/*

*/

//
// Binary trees are already defined with this interface:
// function Tree(x) {
//   this.value = x;
//   this.left = null;
//   this.right = null;
// }

let findSum=(root,sum,acum)=>{
    if(root){
        if(isLeaf(root)){
            return sum==acum+root.value;
        }
        else{
            return findSum(root.right,sum,acum+root.value) ||
                    findSum(root.left,sum,acum+root.value) 
        }
    }
    return false;
}

let isLeaf=(node)=> node.right==null && node.left==null;

function hasPathWithGivenSum(t, s) {
    return findSum(t,s,0);

}
