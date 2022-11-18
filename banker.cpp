#include <iostream>
#include <fstream>

using std::ifstream;
int main(){
  //input stream
  ifstream fin;
  //index for initializing table variables
  int index = 0;
  int t=0;
  
  //length of variables
  const int processes = 5;
  const int resources = 3;
  
  //initializing arrays of table variables
  int allocated[processes][resources];
  int max[processes][resources];
  int available[resources];
  
  //opening text file
  fin.open("banker.txt");
  
  //testing if opening failed
  if (fin.fail()){
  std::cout << "input file opening failed";
  exit(1);
  }
  std::cout << "Opening is successful, continue" << std::endl;
  
    //initializing variable to take as input from text file
    char ch;
    while (fin >> ch){
      //quitting if it hits a semicolon, end of data for that variable
      if (ch == ';'){
        break;
      }
      else{
        //taking in the value for that index
        allocated[index][t] = ch - '0';
        t++;
        //resetting the variables
        if (t == resources){
          t = 0;
          index++;
        }
      }
    }
    
    index = 0;
    t = 0;
  
    while (fin >> ch){
      //quitting if it hits a semicolon, end of data for that variable
      if (ch == ';'){
        break;
      }
      else{
        //taking in the value for that index
        max[index][t] = ch - '0';
        t++;
        //resetting the variables
        if (t == resources){
          t = 0;
          index++;
        }
      }
    }
  
    index = 0;
    t = 0;
  
    while (fin >> ch){
      //quitting if it hits a semicolon, end of data for that variable
      if (ch == ';'){
        break;
      }
      else{
        //taking in the value for that index
        available[t] = ch - '0';
        t++;
      }
    }
  //1 means that process at that index has not been used yet
  int table[processes] = {1,1,1,1,1};
  //calculating the amount needed for each resource
  int need[processes][resources];
  // array to show the order of each process
  int order[processes];
  
  //determing the mean for each resource
  for(int i = 0; i<processes; i++){
    for(int j = 0; j < resources; j++){
      need[i][j] = max[i][j]-allocated[i][j];
    }
  }
  
  //f will determine if the resources in a given process are able to be consumes
  int f = 0;
  //s will be the index for the order array
  int s = 0;
  
  for(int k=0;k<5;k++){ 
    //loop through the table array
    for(int i = 0; i<processes;i++){
      //if that process is available
      if (table[i] == 1){
        f = 0;
        //check to see if the need is < available, break if not
        for(int j =0; j<resources;j++){
          if (available[j] < need[i][j]){
            f = 1;
            break;
          }
        }
        //if all the resources are less than, save the process that has been used and change the amount available
        if (f==0){
          table[i] = 0;
          order[s] = i;
          s++;
          for(int z = 0;z<resources;z++){
            available[z] += allocated[i][z];
          }
        }
      }
    }
  }
  int c = 0;
  //check to see if each process was used
  for(int i = 0;i<processes;i++){
    if (table[i] !=0){
      c=1;
    }
  }
  //if yes then print out the safe sequence
  if (c == 0){
    std::cout << "The system is a safe state." << std::endl << "The safe sequence is: ";
    for(int i =0; i < processes; i++){
      std::cout << "P" << order[i] << ", ";
    }
  }
  else{
    std::cout << "The system is not a safe state.";
  }
  
  //close the in file
  fin.close();
}