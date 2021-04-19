"""
You have two arrays of strings, words and parts.
 Return an array that contains the strings from words, 
 modified so that any occurrences of the substrings from parts are surrounded by square brackets [], 
 following these guidelines:

If several parts substrings occur in one string in words, choose the longest one. 
If there is still more than one such part, 
then choose the one that appears first in the string.

Example

For words = ["Apple", "Melon", "Orange", "Watermelon"] 
and parts = ["a", "mel", "lon", "el", "An"], the output should be

findSubstrings(words, parts) = ["Apple", "Me[lon]", "Or[a]nge", "Water[mel]on"].

While "Watermelon" contains three substrings from the parts array, "a", "mel", and "lon", "mel" 
is the longest substring that appears first in the string.


"""

"""
Refrencing the Code From 
    Damien Martin
    
https://medium.com/codefight-on/codefights-solves-it-findsubstrings-5d6284d314e0
Thank you
"""

#data structure to be used is Trie, makes the program more efficient
class TrieNode:
    def __init__(self, letter):
        self.letter = letter
        self.terminal = False
        self.children = {}


#Function in charge of creating a path in the trie
def addFragmentToTrie(root, fragment):
    currentNode = root
    for letter in fragment:
        if letter not in currentNode.children:
            # create a new node
            currentNode.children[letter] = TrieNode(letter)
        currentNode = currentNode.children[letter]
    currentNode.terminal = True



def buildTrieFromArray(root,parts):
    for p in parts:
        addFragmentToTrie(root, p)




def findSubstringInWord(w, root):
    
    longSubStringLen =0
    subStartPos = 0

    for start_pos in range(len(w)):
        # reset to the beginning of the trie
        currNode = root

        for position in range(start_pos, len(w)):
            letter = w[position]
            #if the letter is not in the first  children
            #go for another starting index
            if letter not in currNode.children:
                break
            #if leter is on the children go to the children and then save position and length
            currNode = currNode.children[letter]
            length = position - start_pos + 1
            #if its terminal and the new route found on the tree is bigger than the previous
            #save the new route
            if currNode.terminal and length > longSubStringLen:
                longSubStringLen = length
                subStartPos   = start_pos
                
    #If no substring is found return the string  without change 
    if longSubStringLen == 0:
        return w
        
    #end index used to save the sub string   
    end = subStartPos + longSubStringLen
    return w[:subStartPos] + "[" + w[subStartPos: end] + "]" + w[end:]




def findSubstrings(words, parts):
    # build the trie
    root = TrieNode('')
    buildTrieFromArray(root,parts)
    return [findSubstringInWord(w, root) for w in words]
