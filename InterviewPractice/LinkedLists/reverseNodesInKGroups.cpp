/*
Note: Your solution should have O(n) time complexity, where n is the number of elements in l, and O(1) additional space complexity, 
since this is what you would be asked to accomplish in an interview.

Given a linked list l, reverse its nodes k at a time and return the modified list. 
k is a positive integer that is less than or equal to the length of l. If the number of nodes in the linked list is not a multiple of k,
then the nodes that are left out at the end should remain as-is.

You may not alter the values in the nodes - only the nodes themselves can be changed.

Example

For l = [1, 2, 3, 4, 5] and k = 2, the output should be
reverseNodesInKGroups(l, k) = [2, 1, 4, 3, 5];
For l = [1, 2, 3, 4, 5] and k = 1, the output should be
reverseNodesInKGroups(l, k) = [1, 2, 3, 4, 5];
For l = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11] and k = 3, the output should be
reverseNodesInKGroups(l, k) = [3, 2, 1, 6, 5, 4, 9, 8, 7, 10, 11].
Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] linkedlist.integer l

A singly linked list of integers.

Guaranteed constraints:
1 ≤ list size ≤ 104,
-109 ≤ element value ≤ 109.

[input] integer k

The size of the groups of nodes that need to be reversed.

Guaranteed constraints:
1 ≤ k ≤ l size.

[output] linkedlist.integer

The initial list, with reversed groups of k elements.

*/


// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
void printList(ListNode<int> * ptr){
    while (ptr != nullptr) {
        printf("%i->", ptr->value);
        ptr = ptr->next;
    }
    printf("NULL\n");
}


ListNode<int> *  reverseSegmentK(ListNode<int> *head,int k,ListNode<int> *curNext ){
    ListNode<int> * prev = curNext;
    ListNode<int> *current=head;
    ListNode<int> *next;
    while(current && k >0){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        k--;
    }
   
    return prev;
    
}

ListNode<int> * reverseNodesInKGroups(ListNode<int> * l, int k) {
    if(k==1 || l==nullptr || l->next ==nullptr){
        return l;
    }
    ListNode<int> *head=l;
    //helps to have the head even if it changes
    ListNode<int> *nullPointer= new ListNode<int>(0);
    nullPointer->next=head;
    //Current to go thorugh the list, tail to reverse it and prev to join the reverse
    ListNode<int> *current=head;
    ListNode<int> *prev=nullPointer;
    ListNode<int> *tail=nullptr;
    int kFinder=0;
    
    while(current){
        //Te begining will be the Tail of the reverse
        tail=current;
        //go throughh the list until a K index
        for(kFinder=0; kFinder<k && current;kFinder++)
            current=current->next;
        //reverse and join it
        if(kFinder==k){
            prev->next=reverseSegmentK(tail,k,current);
            prev=tail;
        }
    }

    //printList(nullPointer->next);
    return nullPointer->next;
}
