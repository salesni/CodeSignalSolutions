public int count;
public int answer;

void inorder(Tree<Integer> root, int k){
    if(root==null){
        return;
    }
    
    inorder(root.left, k);
    count++;
    if(k==count){
        answer=root.value;
        return;
    }
    inorder(root.right,k);
}
int kthSmallestInBST(Tree<Integer> t, int k) {
    //Start searching  using an inorder transversal
    count=0;
    answer=0;
    inorder(t, k);
    return answer;
}
