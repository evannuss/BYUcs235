#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include "Pathfinder.h"

using namespace std;

//CONSTRUCTOR
Pathfinder::Pathfinder(){
    for(int i = 0; i < MAZE_DIM; i++){
        for(int j = 0; j < MAZE_DIM; j++){
            for(int k = 0; k < MAZE_DIM; k++){
                maze[i][j][k] = 1;
            }
        }
    }
    srand(time(NULL));
}

//TO STRING
string Pathfinder::toString()const{
    stringstream mazeString;
    
    for(int i = 0; i < MAZE_DIM; i++){
        for(int j = 0; j < MAZE_DIM; j++){
            for(int k = 0; k < MAZE_DIM; k++){
                if(k < MAZE_DIM - 1){
                    mazeString << maze[k][j][i] << " ";
                }
                else{
                    mazeString << maze[k][j][i];
                }
                if(k == (MAZE_DIM - 1)){
                    mazeString << endl;
                }
            }
            if(j == (MAZE_DIM - 1) && i != (MAZE_DIM - 1)){
                mazeString << endl;
            }
        }
    }
    return mazeString.str();
}

//CREATE RANDOM MAZE
void Pathfinder::createRandomMaze(){
    for(int i = 0; i < MAZE_DIM; i++){
        for(int j = 0; j < MAZE_DIM; j++){
            for(int k = 0; k < MAZE_DIM; k++){
                maze[i][j][k] = rand() % 2;
            }
        }
    }
    maze[0][0][0] = 1;
    maze[4][4][4] = 1;
}

//IMPORT MAZE
bool Pathfinder::importMaze(string file_name){
    ifstream inputFile;
    vector<int> fileMaze;
    int counter = 0;
    string entry;
    
    inputFile.open(file_name);
    if(!inputFile.is_open()){
        return false;   
    }
    
    while(inputFile >> entry){
        if(entry == "0" || entry == "1"){
            fileMaze.push_back(stoi(entry));
        }
        else if(entry == ""){
            
        }
        else{
            cout << "This is not a valid maze" << endl;
            return false;
        }
        entry.clear();
    }
    
    inputFile.close();
    
    if(fileMaze.size() != 125){
        return false;
    }
    
    for(int i = 0; i < MAZE_DIM; i++){
        for(int j = 0; j < MAZE_DIM; j++){
            for(int k = 0; k < MAZE_DIM; k++){
                maze[k][j][i] = fileMaze.at(counter);
                counter++;
            }
        }
    }
    
    if(maze[0][0][0] != 1 || maze[4][4][4] != 1){
        return false;
    }
    
    return true;
}

//FIND PATH
bool Pathfinder::findPath(int x, int y, int z){
    stringstream ss;
    ss << "(" << x << ", " << y << ", " << z << ")";
    string coordinates  = ss.str();
    path.push_back(coordinates);
    
    if(x >= MAZE_DIM || x< 0 || y >= MAZE_DIM || y < 0 || z >= MAZE_DIM || z < 0){
        path.pop_back();
        return false;
    }
    if(maze[x][y][z] == 0 || maze[x][y][z] == 2){
        path.pop_back();
        return false;
    }
    if(x == MAZE_DIM - 1 && y == MAZE_DIM - 1 && z == MAZE_DIM - 1){
        return true;
    }
    
    maze[x][y][z] = 2;
    
    if(findPath(x, y-1, z)){
        return true;
    }
    else if(findPath(x, y+1, z)){
        return true;
    }
    else if(findPath(x-1, y, z)){
        return true;
    }
    else if(findPath(x+1, y, z)){
        return true;
    }
    else if(findPath(x, y, z-1)){
        return true;
    }
    else if(findPath(x, y, z+1)){
        return true;
    }
    else{
        path.pop_back();
        return false;
    }
}

//SOLVE MAZE
vector<string> Pathfinder::solveMaze(){
    path.clear();
    
    findPath(0, 0, 0);
    
    for(int i = 0; i < MAZE_DIM; i++){
        for(int j = 0; j < MAZE_DIM; j++){
            for(int k = 0; k < MAZE_DIM; k++){
                if(maze[i][j][k] == 2){
                    maze[i][j][k] = 1;
                }
            }
        }
    }
    return path;
}
