# Russell Todd
# Lab 4 for UWYO COSC 2030
# Stacks and Queues
#
# You'll be checking parentheses and reversing strings just like you did in C++
# However, in Python the class you'll be using is a List

paren1 = "(()((((()()()((()(((()()()()(((()(()()()(())()())()()))))()()()))()))()())())())))";
paren2 = "()((((((()(((((()((()()()()()(()))))))))()))()(())(())(((((()()(())))(()()())(()))";
paren3 = "(()((()(()()(()(((((()()(()()()((((()()(()()))()))))()()())))))()()())()()))())())";
paren4 = "(()()(((()()(()(()()(()()()()()()(()(((((((((())())))))()))))()()))()())()()))()))";
paren5 = "((())";
paren6 = ")))(((";

rev1 = "sekopog";
rev2 = "racecar";
rev3 = "regnolsignirtssiht";
rev4 = "wonybnwodsihtevahyllufepohdluohssyuguoy";

parens = [paren1, paren2, paren3, paren4, paren5, paren6]
rever = [rev1, rev2, rev3, rev4]

# Finish this function
# You must complete it using a List in a similar manner as a Queue
def parenCheck(toCheck):
    pseudoQueue = []
    
    # Check string for open and closed parenthesis
    # If the queue is empty, it means all parenthesis have been matched.
    
    for letter in toCheck:
        # Open Parens
        if letter == "(":
            pseudoQueue.append(letter)
            
        # Closed Parens
        elif (letter == ")" and len(pseudoQueue) != 0):
            pseudoQueue.pop()
            
    # Check queue length
    if len(pseudoQueue) == 0:
        return True
    else:
        return False

# Finish this function
# You must complete it using a List in a similar manner as a Stack
def stringReverse(toReverse):
    pseudoStack = []
    newString = ""

    # Add letters to stack
    for letter in toReverse:
        pseudoStack.insert(0, letter)
        
    # Remove letters from stack
    for item in pseudoStack:
        newString = newString + item
        
    return newString

# Time to check some parentheses
for i in range(6):
    print("\nChecking string"+str(i+1))
    if parenCheck(parens[i]):
        print("Your code says that string"+str(i+1)+" is good. ")
        if i == 0 or i == 2 or i == 3:
            print("Correct!")
        else:
            print("Incorrect!")
    else:
        print("Your code says that string"+str(i+1)+" is bad. ")
        if i == 1 or i == 4 or i == 5:
            print("Correct!")
        else:
            print("Incorrect!")

# Time to reverse some strings
for j in range(4):
    print("\nReversing string"+str(j+1))
    print(stringReverse(rever[j]))
