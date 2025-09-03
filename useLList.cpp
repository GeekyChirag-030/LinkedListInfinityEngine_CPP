#include<bits/stdc++.h>
#include<iostream>
#include "LinkedList.h"
#include <cstdlib> // Required for system()

using namespace std;
int main(){

    system("Color 0B");

   // printLinkedListRules();
    
	solLList S;     //Object Creation over the stack of the Solution Class for being Further Start the Linked List Process
    string tIn ="C";

	startLList();
	 
	while(tIn[0]!='!'){
	cout<<"\n\n\t   Please Enter Your Input From Menu Each Time for Any Operation (To Stop Press !) => ",cin>>tIn;
	action(tIn,S);
  }


  return 0; 
}

