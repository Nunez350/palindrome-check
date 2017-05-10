/*Author: Roy Nunez

This program prompts user for input and checksand reports if input string is a Pallindrome RECURSIVELY
*/

#include <iostream>
#include <string> //library for substr function
using namespace std;

bool pal(string finalUserInputP); //for Task1 and Task2

int main() {
string userInput, finalUserInput="";

/*userInput = contains the raw input from user (with any non alphabetical letters)
    //only contains lower case letters
    //precondition: Assume the pallindrome is case-sensitive.
    //assume we are ONLY dealing with letters
    //I did not decide to upcase everthing.
    //USER CANNOT ENTER A BLANK SPACE*/
cout<<"Enter string"<<endl;
getline(cin, userInput);

//cast into ascii code to remove punctuations
 for(int i=0;i<userInput.length();i++) {
   
   //ascii numbers for upper and lower case letters.
   if ( (int(userInput[i])>=65 and int(userInput[i])<=90) or (int(userInput[i])>=97 and int(userInput[i])<=122) )
     finalUserInput = finalUserInput + userInput[i];
 }
 
if (finalUserInput.length()%2==0)
  cout<<"Your input is of even Length"<<endl;
 else 
   cout<<"Your input is of odd Length"<<endl;
if (pal(finalUserInput))
  cout<<"This is a pallindrome"<<endl;
 else 
   cout<<"This is not a pallindrome"<<endl;

//string printoutuser= finalUserInput ;
// cout<< printoutuser<<endl; 

return 0;
}

//functions below:
bool pal(string finalUserInputP) {
  //  cout<<finalUserInputP<<endl;
  string newString;
if (finalUserInputP=="" or finalUserInputP.length()==1)
  return true;
int lastIndex = finalUserInputP.length()-1;
 if(finalUserInputP[0]==finalUserInputP[lastIndex]) { 
   newString = finalUserInputP.substr(1,lastIndex-1);
   return pal(newString); 
 }
 else 
   return false;
}

bool pal2(string userInputP) {  
  int lastIndex = userInputP.length()-1;
  string newString; //brand new string created at the end of each function. 
                  //this output will be the input for the new recursive function
  
if (userInputP=="" or userInputP.length()==1)
  return true;
 
//removing nonetters from LEFT side of input
if  ( 
     (int(userInputP[0])<65 and int(userInputP[0])>=0)  or 
      (int(userInputP[0])<97 and int(userInputP[0])>=91) or  
     (int(userInputP[0])<127 and int(userInputP[0])>=123)  or 
     (userInputP[lastIndex]==' ')
      )
  
    {
      newString = userInputP.substr(1,lastIndex);
      return pal2(newString);
    }

 
//removing non letters from RIGHT side
if  ( (int(userInputP[lastIndex])<65 and int(userInputP[lastIndex])>=0)  or 
     (int(userInputP[lastIndex])<97 and int(userInputP[lastIndex])>=91) or  
     (int(userInputP[lastIndex])<127 and int(userInputP[lastIndex])>=123) or 
     (userInputP[lastIndex]==' ') )
  
  {newString = userInputP.substr(0,lastIndex);//Hi Professor, may you know why this index works but NOT lastIndex-1 , 
    return pal2(newString);
  }
 //actual checking of pallindrome one non-alpha symbols removed.
 if(userInputP[0]==userInputP[lastIndex]) { 
     newString = userInputP.substr(1,lastIndex-1);
     return pal2(newString); 
   }
 else 
   return false;
}




