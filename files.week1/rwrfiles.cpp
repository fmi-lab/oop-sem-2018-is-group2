#include<iostream>
#include<fstream>
using namespace std;
void readFromFile(const char* filename){
  //ifstream myIn(filename);
  ifstream myIn;
  ofstream myOut("output.txt");
  myIn.open(filename);
  char a[20];
/*  for(int i=0;i<6;i++){
    myIn>>a;
    cout<<a;
  }*/
/*  while(myIn>>a){
    cout<<a;
  }*/
  while(!myIn.eof()){
    if(myIn>>a){
            cout<<a;
            myOut<<a<<" ";
    }

  }
  //ВАЖНО!!!! Затваряме файловете, които сме отворили, след като сме приключили работа
  myIn.close();
  myOut.close();
}

int main(){
  readFromFile("testData.fmi");
  return 0;
}
