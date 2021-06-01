/*
 * Name: Annie Hayes
 * Date Submitted: 03/03/2021
 * Lab Section: 004
 * Assignment Name: Lab 5
 */
 #include "stringset.h"
 #include <iostream>
 #include <fstream>
 
 void testStringset(Stringset& words);
 void loadStringset(Stringset& words, string filename);
 vector<string> spellcheck(const Stringset& words, string word);
 
 int main()
 {
     Stringset wordlist;
     testStringset(wordlist);
     return 0;
 }
 
 void testStringset(Stringset& words)
 {
     string choice;
     string word;
     do
     {
         cout << "I: insert word" << endl;
         cout << "F: find word" << endl;
         cout << "R: remove word" << endl;
         cout << "P: print words in stringset" << endl;
         cout << "Q: quit" << endl;
         cin >> choice;
         switch (choice[0])
         {
             case 'I':
             case 'i':
                cout << "Enter word to insert: ";
                cin >> word;
                words.insert(word);
                break;
             case 'F':
             case 'f':
                cout << "Enter word to find: ";
                cin >> word;
                if (words.find(word))
                {
                    cout << word << " in stringset" << endl;
                }
                else
                {
                    cout << word << " not in stringset" << endl;
                }
                break;
             case 'R':
             case 'r':
                cout << "Enter word to remove: ";
                cin >> word;
                words.remove(word);
                break;
             case 'P':
             case 'p':
                vector<list<string>> t = words.getTable();
                int numWords = words.getNumElems();
                int tSize = words.getSize();
                for(int i=0; i<tSize; ++i)
                {
                    list<string>::iterator pos;
                    for (pos = t[i].begin(); pos != t[i].end(); ++pos)
                    {
                        cout << *pos << endl;
                    }
                }
                cout << "Words: " << numWords << endl;
         }
     } while (choice[0] != 'Q' && choice[0] != 'q');
 }
 
 void loadStringset(Stringset& words, string filename)
 {
     //open file
     std::ifstream infile(filename);
     std::string word;
     //put word in file
     while(std::getline(infile, word)) 
     {
        words.insert(word);
    }
     
 }
 
 vector<string> spellcheck(const Stringset& words, string word)
 {
     //make vecotr string
     vector<string> spellchecked; 
     //set new variable to word
     string replacedWord = word; 
     
     //go through word length
     for (int i = 0; i < word.length(); i++) 
     { 
         //go through alphabet
         for (char j = 'a'; j < 'z' + 1; j++) 
         { 
             //replace letters
             replacedWord.replace(i, 1, 1, j); 
             //if replaced letter word is an actual word
             if (replacedWord != word && words.find(replacedWord))
             {
                 //add replaced letter word to spellchecked
                spellchecked.push_back(replacedWord);
             }
             replacedWord = word; 
         }
     }
     return spellchecked; 
     
 }
 
 