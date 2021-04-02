/*
Given a string str and array of pairs that indicates which indices in the string can be swapped, 
return the lexicographically largest string that results from doing the allowed swaps. 
You can swap indices any number of times.

Example

For str = "abdc" and pairs = [[1, 4], [3, 4]], 
the output should be
swapLexOrder(str, pairs) = "dbca".

By swapping the given indices, you get the strings: "cbda", "cbad", "dbac", "dbca". 
The lexicographically largest string in this list is "dbca".

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] string str

A string consisting only of lowercase English letters.

Guaranteed constraints:
1 ≤ str.length ≤ 104.

[input] array.array.integer pairs

An array containing pairs of indices that can be swapped in str (1-based). 
This means that for each pairs[i], you can swap elements in str that have 
the indices pairs[i][0] and pairs[i][1].

Guaranteed constraints:
0 ≤ pairs.length ≤ 5000,
pairs[i].length = 2.

[output] string


*/



//function to fill the map with its init values
void buildInitPermutation(map<int,set<int>> &map,vector<vector<int>> pairs){
    int len=pairs.size();
    for(int i=0; i<len;i++){
        map[pairs[i][0]].insert(pairs[i][1]);
        map[pairs[i][1]].insert(pairs[i][0]);
    }
    
}
//recursion function to build All permutations using a modified DFS
void buildPermutations(set<int>& visited, map<int,set<int>>  &map, int visiting, int root){
    for(auto index : map[visiting]) {
        if(visited.find(index)==visited.end()){
            visited.insert(index);
            buildPermutations(visited, map, index, root);
        }
    }
    if(visiting== root) return;
    map[visiting].insert(root); 
    
}


//function to print map, used to see how the map was filled
void printMap(map<int,set<int>>  map){
    cout <<  "--------------"<<endl;
    for (auto i = map.begin(); i != map.end(); i++){
        cout << i->first << " : ";
            for (auto elem : i->second){
                cout << elem << " , ";
            }
        cout<<endl;
    }
}

string swapLexOrder(string str, vector<vector<int>> pairs) {
    map<int,set<int>> permutations;
    //build the initial map for the posible position for an specific index
    buildInitPermutation(permutations, pairs);
    //Use a DFS to fill  the hash map with all posible nodes that 
    //an index can reach 
    for (auto i = permutations.begin(); i != permutations.end(); i++){
        set<int> visited= set<int>();
        visited.insert(i->first);
        buildPermutations(visited, permutations,i->first, i->first);
    }
    
    //build the new string
    int len=str.length();
    for(int i=0;i<len;i++){
        if (permutations.find(i+1) != permutations.end()) {
            //for all posible positions for an specific index
            for(auto pos:permutations[i+1]){
                //when the position is higher than the index
                //in order to not repeat it and the string has a  bigger
                //lexical value, swap indexes.
                if(pos-1>i && str[pos-1]>str[i]){
                    char temp=str[pos-1];
                    str[pos-1]=str[i];
                    str[i]=temp;
                }
            }
        }
    }
    
    //printMap(permutations);
    
    return str;
}
