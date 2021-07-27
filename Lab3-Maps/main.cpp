#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <set>
#include <iterator>
#include <map>
#include <list>

using namespace std;

vector<string> readIntoVector(string name);
void printVector(vector<string> words, string name);
void printMap(map<string, vector<string>> mp, string name);

int main(int argc, char *argv[]){
    
    ifstream inputFile;
    ofstream outputFile;
    set<string> fileWords;
    vector<string> wordsVector;
    
    string fileName;
    string word;
    string outputFileName;
    
    word.clear();
    fileName.append(argv[1]);
    fileName.append(".txt");
    
    inputFile.open(fileName);
    
    while(inputFile >> word){
        for(int i = 0; i < word.size(); i++){
            if(isalpha(word[i]) == 0){
                word.erase(i);
                i--;
            }
        }
        fileWords.insert(word);
        word.clear();
    }
    
    outputFileName = fileName + "_set.txt";
    outputFile.open(outputFileName);
    
    set<string>::iterator itr;
    for(itr = fileWords.begin(); itr != fileWords.end(); itr++){
        outputFile << *itr << endl;
    }
    ///////////////end of Part 1
    
    int M=2;
    map<list<string>, vector<string>> wordmap;
    list<string> state;
    for (int i = 0; i < M; i++) {
        state.push_back("");
    }
    
    wordsVector = readIntoVector(fileName);
                        
    for (int i = 0; i < wordsVector.size(); i++) {
        wordmap[state].push_back(wordsVector.at(i));
        state.push_back(wordsVector.at(i));
        state.pop_front();
    }
    
    state.clear();
    for (int i = 0; i < M; i++) {
        state.push_back("");
    }
    for (int i = 0; i < 100; i++) {
        int ind = rand() % wordmap[state].size();
        cout << wordmap[state][ind]<<" ";
        state.push_back(wordmap[state][ind]);
        state.pop_front();
    }
    ///////////////end of Part 6
    
    
    //printVector(wordsVector, argv[1]);
    ///////////////end of Part 2
    
    /*map<string, string> wordmap;
    string last="";
    for (int i = 0; i < wordsVector.size(); i++) {
      wordmap[last] = wordsVector.at(i);
      last = wordsVector.at(i);
    }*/
    
    /*map<string, vector<string>> wordmap;
    string state = "";
    for(int i = 0; i < wordsVector.size(); i++) {
      wordmap[state].push_back(wordsVector.at(i));
      state = wordsVector.at(i);
    }*/
    
    //printMap(wordmap, argv[1]);
    ///////////////end of Part 3 and part of Part 5
    
    /*srand(time(NULL));
    
    state = "";
    for (int i = 0; i < 100; i++) {
      int ind = rand() % wordmap[state].size();
      cout << wordmap[state][ind] << " ";
      state = wordmap[state][ind];
    }
    cout << endl;*/
    ////////////////end of Part 5
    
    return 0;
}

//function
vector<string> readIntoVector(string name){
    vector<string> words;
    ifstream file;
    string newWord;
    
    file.open(name);
    
    while(file >> newWord){
        for(int i = 0; i < newWord.size(); i++){
            if(isalpha(newWord[i]) == 0){
                newWord.erase(i);
                i--;
            }
        }
        words.push_back(newWord);
        newWord.clear();
    }
    return words;
}

//function
void printVector(vector<string> words, string name){
    ofstream file;
    string outputName = name + "_vector.txt";
    
    file.open(outputName);
    
    for(int i = 0; i < words.size(); i++){
        file << words.at(i) << endl;
    }
}

//function
void printMap(map<string, vector<string>> mp, string name){
    ofstream file;
    string outputName = name + "_1_1.txt";
    
    file.open(outputName);
    
    for(map<string, vector<string>>::iterator itr = mp.begin(); itr != mp.end(); itr++){
        file << itr->first;
        for(int i = 0; i < itr->second.size(); i++){
            file << ", " << itr->second.at(i) << endl;
        }
    }
}