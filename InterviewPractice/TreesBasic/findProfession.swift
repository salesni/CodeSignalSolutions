/*
Consider a special family of Engineers and Doctors. This family has the following rules:

Everybody has two children.
The first child of an Engineer is an Engineer and the second child is a Doctor.
The first child of a Doctor is a Doctor and the second child is an Engineer.
All generations of Doctors and Engineers start with an Engineer.
We can represent the situation using this diagram:

                E
           /         \
          E           D
        /   \        /  \
       E     D      D    E
      / \   / \    / \   / \
     E   D D   E  D   E E   D
Given the level and position of a person in the ancestor tree above, find the profession of the person.
Note: in this tree first child is considered as left child, second - as right.

Example

For level = 3 and pos = 3, the output should be
findProfession(level, pos) = "Doctor".

Input/Output

[execution time limit] 20 seconds (swift)

[input] integer level

The level of a person in the ancestor tree, 1-based.

Guaranteed constraints:
1 ≤ level ≤ 30.

[input] integer pos

The position of a person in the given level of ancestor tree, 1-based, counting from left to right.

Guaranteed constraints:
1 ≤ pos ≤ 2(level - 1).

[output] string

Return Engineer or Doctor.
*/




func findProfession(level: Int, pos: Int) -> String {
    if(level==1){
        return "Engineer"
    }
    //find if the father is an engineer
    if(findProfession(level:level-1, pos:(pos+1)/2 ) == "Engineer"){
        //if so if the position is an odd number is an Engineer else a doctor
        if(pos % 2 == 0){
            return "Doctor"
        }
        else{
            return "Engineer"
        }
    }else{
        if(pos % 2 == 0){
            return "Engineer"
        }
        else{
            return "Doctor"
        } 
    }
}
