/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//Ileana Bocage 
//Hangman Game

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool is_hung(int);

int main()
{
    ifstream reader;
    reader.open("infile.txt");
    string lines=""; 
    int numErrors=0;
    string answer="";
    bool continuecode=true;
    string line="";
    string correct="";
    //1
    while (continuecode == true)
    {
        for(int i=5; i>0;i--) //run this code 5 times
        {
            getline(reader,lines); //read line from file
            cout << lines << endl; //printing line from the file
        }
        cin >> answer;
        getline(reader,line); //read line from file
        int word_length = 0;
        word_length = line.find(" ");
        for (int j=5;j>0;j--)
        {
            correct = line.substr(word_length+1,line.size());
            word_length = correct.find(" ");
        }
        string answer1 = correct.substr(word_length+1,line.size());
        if (answer == answer1)
        {
            cout << line << endl;
        }
        else
        {
            numErrors++;
            continuecode=is_hung(numErrors);
            cout << line << endl;
        }
        
    }    

    return 0;
}

bool is_hung(int num_errors)
{
    if (num_errors == 1)
    {
        cout << "\t \t \t" << " O " << endl;
        return true;
    }
    else if (num_errors == 2)
    {
        cout << "\t \t \t" << " O " << endl;
        cout << "\t \t \t" << "/   " << endl;
        return true; 
    }
    else if (num_errors == 3)
    {
        cout << "\t \t \t" << " O " << endl;
        cout << "\t \t \t" << "/ \\" << endl;
        return true;
    }
    else if (num_errors == 4)
    {
        cout << "\t \t \t" << " O " << endl;
        cout << "\t \t \t" << "/|\\" << endl;
        return true;
    }
    else if (num_errors == 5)
    {
        cout << "\t \t \t" << " O " << endl;
        cout << "\t \t \t" << "/|\\" << endl;
        cout << "\t \t \t" << " | " << endl;
        return true;
    }
    else if (num_errors == 6)
    {
        cout << "\t \t \t" << " O " << endl;
        cout << "\t \t \t" << "/|\\" << endl;
        cout << "\t \t \t" << " | " << endl;
        cout << "\t \t \t" << "/   " << endl;
        return true;
    }
    else if (num_errors == 7)
    {
        cout << "\t \t \t" << " O " << endl;
        cout << "\t \t \t" << "/|\\" << endl;
        cout << "\t \t \t" << " | " << endl;
        cout << "\t \t \t" << "/ \\" << endl;
        cout << " YOU ARE HUNG" << endl;
        return false;
    }
    else
    {
        return true;
    }
}

