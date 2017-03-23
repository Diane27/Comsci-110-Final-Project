#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//value- returning function checking if the character is a valid email character or not
bool isValidEmailCharacter(char c)
{
   if (c >= 'A' && c <= 'Z')  
     return true;
   else if (c >= 'a' && c <= 'z')
     return true;
   else if (c >= '0'  && c <= '9')
     return true;
   else if (c == '.' || c == '-' || c == '+')
     return true;
   else
     return false;
}//isValidEmailCharacter



int main()
{
   string userInputFile;
   string inputFile;
   string defaultIn = "fileContainingEmails.txt"; //setting the default variable for the input file

   //getting the input file from the user and storing it in a variable
   cout << "Enter input filename [default: " << defaultIn << "]: ";
   getline(cin, userInputFile);

   string userOutputFile;
   string outputFile;
   string defaultOut = "copyPasteMyEmails.txt";//setting the default variable for the output file

   //getting the output file from the the user and storing it in a variable
   cout << "Enter output filename [default: " << defaultOut << "]: ";
   getline(cin, userOutputFile);
   
   //comparing the values of each variables and storing the valid value in another variable and outputting it
   if (userInputFile == "" && userOutputFile == "")
   {
    inputFile = defaultIn;
    outputFile = defaultOut;
   }//if

   else if (userOutputFile == "" && userInputFile != "")
   {
    inputFile = userInputFile;
    outputFile = userInputFile;
   }//else if

   else if (userInputFile== "" && userOutputFile != "")
   {
    inputFile = defaultIn;
    outputFile = userOutputFile;
   }//else if

   else 
   {
    inputFile = userInputFile;
    outputFile = userOutputFile; 
   }//else
    
   //opening the valid file entered by the user as the input file
   ifstream fin; 
   fin.open(inputFile.c_str()); 
   if (!fin.good()) throw "I/O error";

   //searching in each line inside the file(looping)
   string textLine;
   while (!fin.eof())
    { 
     getline(fin, textLine);
    
     for (int i =0; i < textLine.length(); i++)
     {
      if (textLine[i] == '@')//searching for the @ character into the line
      {
       int s = i - 1;// creating a new variable to help loop backward from the @.
       while(isValidEmailCharacter(textLine[s])) //checking each character to see if it's a valid email character
       {
         s--;
       }//while
       bool hasDot = false;
       int e = i + 1; //creating a new variable to help loop forward from the @.
       while(isValidEmailCharacter(textLine[e])) //checking each character until it gets an invalid email character
       {
         e++;
         if (textLine[e] == '.')//checking for at list one dot in the part after the @
           hasDot = true;
       }//while
       if (hasDot)
       {
         cout << textLine.substr(s, e - s) << endl; // outputting the substring containing the valid email adresses
       }//if
      }//if
     }//for
    }//while
    fin.close();

}//main