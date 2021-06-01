/*
 * Name: Annie Hayes
 * Date Submitted: 03/12/2021
 * Assignment Name: Anagram Finder
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> loadWordlist(string filename);

vector<string> anagram(string word, vector<string> wordlist);

int main()
{
    vector<string> words;
    vector<string> anagrams;
    string inputWord;
    words=loadWordlist("wordlist.txt");
    cout << "Find single-word anagrams for the following word: ";
    cin >> inputWord;
    anagrams = anagram(inputWord, words);
    for (int i=0; i<anagrams.size(); i++)
    {
        cout << anagrams[i] << endl;
    }
    return 0;
}

vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if(inFile.is_open())
    {
        while(getline(inFile,word))
        {
            if(word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}

 /*Implement the following function:
  anagram() takes a word (string) and a wordlist of all words (vector of strings)
  and builds a dictionary/map where the key is a specific number of times each
  letter occurs in a word and the associated value is a vector of strings
  containing all words using those letters (anagrams).
  The value returned is a vector of strings containing the corresponding
  set of anagrams
*/

//Implement this function
vector<string> anagram(string word, vector<string> wordlist)
{
    //initialize variables 
    int count = wordlist.size();
    string sortWord;
    
    //initialize map & output vector
    vector<string> sortedWords; 
    unordered_map<string, vector<string>> map;
    
    //for loop to sort chars & add them to list
    for(int i = 1; i <= count; i++) 
    {
        sortWord = wordlist[i];
		sort(sortWord.begin(), sortWord.end());
		map[sortWord].push_back(wordlist[i]);
    }
    
    //sort words & find anagrams 
    sort(word.begin(), word.end());
	sortedWords = (*(map.find(word))).second;
	return sortedWords;
}






