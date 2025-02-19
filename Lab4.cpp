//UWYO COSC 2030
//Lab 4
//Written by Danny Radosevich
//8-4-19

#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;


//function declarations
string stringReverse(string toReverse);
bool parenCheck(string toCheck);

/*DO NOT CHANGE MAIN OR THE FUNCTION DECLARATIONS*/
int main()
{
  //paren strings
  string paren1 = "(()((((()()()((()(((()()()()(((()(()()()(())()())()()))))()()()))()))()())())())))";
  string paren2 = "()((((((()(((((()((()()()()()(()))))))))()))()(())(())(((((()()(())))(()()())(()))";
  string paren3 = "(()((()(()()(()(((((()()(()()()((((()()(()()))()))))()()())))))()()())()()))())())";
  string paren4 = "(()()(((()()(()(()()(()()()()()()(()(((((((((())())))))()))))()()))()())()()))()))";
  string paren5 = "((())";
  string paren6 = ")))(((";

  string rev1 = "sekopog";
  string rev2 = "racecar";
  string rev3 = "regnolsignirtssiht";
  string rev4 = "wonybnwodsihtevahyllufepohdluohssyuguoy";

  //Ignore this for now, these vectors are just part of the program
  vector<string> parens;
  parens.push_back(paren1);
  parens.push_back(paren2);
  parens.push_back(paren3);
  parens.push_back(paren4);
  parens.push_back(paren5);
  parens.push_back(paren6);

  vector<string> rever;
  rever.push_back(rev1);
  rever.push_back(rev2);
  rever.push_back(rev3);
  rever.push_back(rev4);
  
  //call the parenCheck
  for(int i=0; i<6; i++)
  {
    cout<<"Checking string"<<i+1<<endl;
    if(parenCheck(parens.at(i)))
    {
      cout<<"Your code says that string"<<i+1<<" is good.";
      if(i == 0 || i == 2 || i==3)
      {
        cout<<" Correct!"<<endl<<endl;
      }
      else
      {
        cout<<" Incorrect!"<<endl<<endl;
      }
    }
    else
    {
      cout<<"Your code says that string"<<i+1<<" is bad.";
      if(i == 1 || i == 4 || i==5)
      {
        cout<<" Correct!"<<endl<<endl;
      }
      else
      {
        cout<<" Incorrect!"<<endl<<endl;
      }
    }
  }

  //now to reverse some strings
  for(int i =0; i<4; i++)
  {
    cout<<"Reversing string"<<i+1<<endl;
    cout<<stringReverse(rever.at(i))<<endl<<endl;
  }
}

//This function takes a string and reverses it using a stack
//it returns the reversed string
string stringReverse(string toReverse)
{
  stack<char> reverse; //declare the stack
  string newString = "";

  // Put every letter into a stack, so it may be read in reverse
  for (char letter : newString)
  {
    reverse.push(letter);
  }

  // Move trhough stack to create string
  while (!reverse.empty())
  {
    // Pull item from stack
    char letter = reverse.top();
    reverse.pop();

    // Add to string
    newString = (newString + letter);
  }

  return newString;
}

//this function uses a queue to check if a string of parens is properly matched
bool parenCheck(string toCheck)
{
  queue<char> checker; //declare my queue

  // We can check if each parenthesis is matched by adding a token to the queue once finding an open parenthesis,
  // and removing a token when meeting a closed parenthesis
  for (char letter : toCheck)
  {
    if (letter == '(')
    {
        // Open a Parenthesis
        checker.push(letter);
    }
    else if (letter == ')' && !checker.empty())
    {
        // Close a parenthesis
        checker.pop();
    }
  }

  // Now we check if the queue has successfully been cleared
  if (checker.empty())
  {
    return true;
  }

  return false; //need a return statement to compile
}
