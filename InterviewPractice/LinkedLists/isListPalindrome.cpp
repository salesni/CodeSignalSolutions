/*
Note: Try to solve this task in O(n) time using O(1) additional space, 
where n is the number of elements in l, since this is what you'll be asked to do during an interview.

Given a singly linked list of integers, determine whether or not it's a palindrome.

Note: in examples below and tests preview linked lists are presented as arrays just for simplicity of visualization:
in real data you will be given a head node l of the linked list

Example

For l = [0, 1, 0], the output should be
isListPalindrome(l) = true;

For l = [1, 2, 2, 3], the output should be
isListPalindrome(l) = false.

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] linkedlist.integer l

A singly linked list of integers.

Guaranteed constraints:
0 ≤ list size ≤ 5 · 105,
-109 ≤ element value ≤ 109.

[output] boolean

Return true if l is a palindrome, otherwise return false.


*/




// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//


//Find the middle node of the list
ListNode<int> * findMiddlePoint(ListNode<int> * l){
    ListNode<int> *head = l;
    ListNode<int> *prevItr= head;
    ListNode<int> *itr= head;
    ListNode<int> *fastItr= head;
    while(fastItr!=nullptr && fastItr->next!=nullptr){
        prevItr=itr;
        itr= itr->next;
        fastItr=fastItr->next->next;
    }
    
    return fastItr==nullptr? prevItr:itr;
    
}


//reverse a list 
void reverseList(ListNode<int> ** l){
    ListNode<int> * prev=nullptr;
    ListNode<int> * current=*l;
    ListNode<int> * next;
    while(current !=nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *l=prev;
}
//print function
void printList(ListNode<int> * ptr){
    while (ptr != nullptr) {
        printf("%i->", ptr->value);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

//compares two linked lists
bool checkLists(ListNode<int> * l1, ListNode<int> * l2){
    while(l1&&l2){
        if(l1->value!=l2->value){
            return false;
        }
        l1=l1->next;
        l2=l2->next;
    }
    return true;
}

bool isListPalindrome(ListNode<int> * l) {
    ListNode<int> *head = l;
    ListNode<int> *middlePointer = nullptr;
    ListNode<int> *secondHalb = nullptr;
    bool answer=true;
    if(head!=nullptr && head->next !=nullptr){
        middlePointer= findMiddlePoint(head);
        secondHalb=middlePointer->next;
        reverseList(&secondHalb);
        middlePointer->next=secondHalb;
        
        //printList(head);
        
        answer=checkLists(head, secondHalb);
        
        reverseList(&secondHalb);
        middlePointer->next=secondHalb;
        
        //printList(head);
    }
    
    
    return answer;
    

}
