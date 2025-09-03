#include<bits/stdc++.h>
#define For(i,n) for(int i=0;i<n;++i)
#define ForL(currNode,head) for(Node *currNode = head;currNode!=nullptr;currNode=currNode->next)
using namespace std;

//Structure of the Linked List Node Itself 
struct Node
{
	int Data;
	Node *next;
	
	Node(int Data) : Data(Data),next(nullptr){}                             
};
class solLList
{
    int nNodesSize;                                                        
    Node *linkedList = nullptr;                                                             
    Node *tailNode = nullptr;                                                              
    Node *headNode = nullptr;                                                                          
    
    public:
    	friend istream & operator>>(istream &In,solLList &S);              
    	friend ostream & operator<<(ostream &Out,solLList &S);          
    	
    	void operator+();                                                 
    	void operator-();                                                
    	
    	void operator++();                                               
		void operator--();                                                
		
		void addBegin();                                                  
		void remBegin();                                                   
		
		void clearLinkedList();                                          
		
		int getSize();                                                     
		bool isValidOprAdd(int);                                            
		bool isValidOprDel(int);                                          
				
		bool oprValidityCheck();                                           
        int prHead();                                                       //For printing they head the node data of the linked list 
        int prTail();                                                       //For Printing the Tail Node's Data of the linked ist 
        
        void addNodeMidLastLList(Node*,int); 
        void delMidLastNodeLList(Node*,int);
        
        int searchNodeLList(int);                                                               
		void printRevLList(Node*);                          
       
	    Node* getHeadLList();                               
};

int solLList::searchNodeLList(int dSr){
	int i=1;
	ForL(currNode,linkedList){
		if(currNode->Data==dSr) return i;                                                             
		i++;
	}
	return -1;                                                                                         
}

//Non tail Recursive Function for Printing Linked List in Reverse 
void solLList::printRevLList(Node *currNode){
	
	if(currNode!=nullptr){
		
		printRevLList(currNode->next);                                    
		cout<<" --> "<<currNode->Data;                                     
	}
}

//For Clearing Linked List , Like Take Out the Nodes and Also Deliting Them from Memory
void solLList::clearLinkedList(){
	
	for(Node *currNode = linkedList;currNode!=nullptr;){                                                              
		
		Node *delNode = currNode;                                  //Each Time store Pointer of Each currNode
		currNode = currNode->next;
		delete delNode;                                            //Stored Node Gonna Deleted 
	}
	linkedList = nullptr;                                         
    nNodesSize = 0;
    
    tailNode = nullptr;
    headNode = nullptr;
}
int solLList::getSize(){return nNodesSize;}

//Helper For + Customly Overloaded Operator Function for Adding Nodes in the Linked List 
void solLList::addNodeMidLastLList(Node *newNode,int idx){ 
	
	int i = 1;Node *prevNode = nullptr,*currNode = headNode;
	
		    for(;;currNode=currNode->next)
			{
				if(i==idx) break;
				
				prevNode = currNode;                         
				i++;
			}
			
			if(currNode==nullptr)                           
			{
				tailNode->next = newNode;
				tailNode = tailNode->next;
			}
			else{
			
			//Adjusting the Pointer Links After We Found index for Adding Mode 
			prevNode->next = newNode;
			newNode->next = currNode;
		
		}
		
}

//Helper Function for Removing or Deleting Nodes :  - Customly Overloaed Operator Function 
void solLList::delMidLastNodeLList(Node *delNode,int idx){
	
	Node *prevNode = nullptr,*currNode = nullptr;int i=1;
	
	      
		  for(currNode = headNode;currNode->next!=nullptr;currNode=currNode->next){                  
	      	  	
				if(i==idx) break;
				prevNode = currNode;
				i++;
		  }
		  
		
		if(currNode->next==nullptr) {                                                 
		            delNode = tailNode;
		            tailNode = prevNode;
		            
		            tailNode->next = nullptr;
		}
		else{
	   	delNode = currNode;                                                
	    prevNode->next = currNode->next;                                                
	  
	    delete delNode;  	
}
}
	
//Istream Customly Overloaed Opertaor Function : Creating and management of the linked list from scratch Again Each Time 	
istream & operator>>(istream &In,solLList &S)
{
	cout<<"\n\n\t   Please Enter the Size of the Linked List that you Wanna Create : ",In>>S.nNodesSize;
	if(S.linkedList!=nullptr)                                                                                     //Means Its ALready Exists , Firstly Clear It
	{
		S.clearLinkedList();                                                                           //If Linked List is Not Empty Then First need to Clear it 
		cout<<"\n\n\t\t\t      ~!~!~!~! (Already Exists) Linked List is Cleared : \n";
    }
    
	//Taking Input of N Nodes from the User in Linked List of Each and Every Ndoe 
	cout<<"\n\n        Please Enter the "<<S.nNodesSize<<" Nodes as Input in Linked List : \n\n";
	
	Node *currNode = nullptr;
	int tData;
	
	For(i,S.nNodesSize){
	
		cout<<"\n\t   Please Enter the Input of "<<i+1<<" Node's Data of Linked List => ",In>>tData;
		if(!S.linkedList){
			
			S.linkedList = new Node(tData);
			currNode = S.linkedList;
		}
		else
		{
			currNode->next = new Node(tData);                                            
			currNode = currNode->next;                                                     
		}	
	}
	
	//---------------------------------------------------------------------------
	 S.tailNode = currNode;                                                        
	 
	 S.headNode = S.linkedList;                                                     
	//----------------------------------------------------------------------------
	if(!currNode->next) currNode->next = nullptr;
	
	return In;
}

//For Adding the Nodes at Anywhere Inside the Linked List ~ Just Based on the Index 
void solLList::operator+(){                                                       
	int tData,idx;
	
	cout<<"\n\n\n\t            New Node Creation Request :::\n\n";
	cout<<"\n\t Enter the Index (1-Based) Where You Wanna Add the Node in Linked List => ",cin>>idx;
	
	if(isValidOprAdd(idx))
	{
		cout<<"\n\n\t            Please Enter the Data With Which You Wanna Create the New Node at Position "<<idx<<" in the Linked List : ";cin>>tData;
		Node *newNode = new Node(tData);
		
		if(idx==1){
			//----------------------------------------------------------------------------------------------------------------------------
			
			newNode->next = headNode;                                                           
			headNode = newNode;                                                                   
		   
		     
		    linkedList = headNode;                                                               
			//----------------------------------------------------------------------------------------------------------------------------
		}
		else{                                                                     //Handling Middle and Adding Node at Last of the Linked List
		       addNodeMidLastLList(newNode,idx);
		   }
	    
	    cout<<"\n\t                     !!!!   New Node with Data "<<tData<<" is Successfully Added in the Linked List ?";
	    nNodesSize++;
 } else cout<<"\n\n\t                        @#@#@#@#   INVALID OPERATION ::: Please Enter the Valid Index as Size of the Linked List is : "<<nNodesSize;

}


//Form Adding the Node in the Beggining of the linked list 
void solLList::addBegin(){
	
	int tData;
	cout<<"\n\n\t            New Node Creation Request in Beggining : Please Enter the Data With Which You Wanna Create the New Node at Beggining of the Linked List : ";cin>>tData;
	
	Node *newNode = new Node(tData);                                                                              
	
	//Adjusting the Pointers -------------------------------------------------------------------
	newNode->next = headNode;
	headNode = newNode;
    
    linkedList = headNode;
    //------------------------------------------------------------------------------------------
		
	cout<<"\n\n\t                    Success :: New Node is Added in the Beggining of the Linked List! ";
	nNodesSize++;
}

//For removing or deliting the node from the Beggingning of the Linked List by default  
void solLList::remBegin()
{
	
	
		if(nNodesSize==1){                                                                           //To Check if there is one Node in Linked List 
		linkedList = nullptr;
		headNode = nullptr;
		tailNode = nullptr;
		nNodesSize = 0;
		
		cout<<"\n\n\t                -------------   [{Node is Successfully Deleted form the Beggining of the Linked List }]\n\n\n";

		return;
	}
	
	else{
		
	//Adjusting the Pointers -------------------------------------------------------------------
	Node *delNode = headNode;
	
	headNode = headNode->next;
	linkedList = headNode;                                                 
    //------------------------------------------------------------------------------------------------
    
    delete delNode;                                                        //Also delete the node from the memory 
   }
     
    cout<<"\n\n\t                -------------   [{Node is Successfully Deleted form the Beggining of the Linked List }]\n\n\n";
    nNodesSize--;
}

//For Adding the Node By Default At the End or at the Last of the Linked list 
void solLList::operator++()
{
	
	int tData;
	cout<<"\n\n\t            New Node Creation Request At the End ::: Please Enter the Data With Which You Wanna Create the New Node at Last/End in the Linked List : ";cin>>tData;
	
	Node *newNode = new Node(tData);

    //Adjusing the Links     
	
	tailNode->next = newNode;
	tailNode = tailNode->next;                                 
    
	nNodesSize++;
}
//For Deliting or Removing the Node from the Last or from the End of the Linked List by Default  
void solLList::operator--()
{
	
	
	if(nNodesSize==1){
		linkedList = nullptr;
		headNode = nullptr;
		tailNode = nullptr;
		nNodesSize = 0;
		
		cout<<"\n\n\t                -------------   [{Node is Successfully Deleted form the End/Last of the Linked List }]\n\n\n";

		return;
	}
	
	
	//Traverse till till the Second Last Node 
    Node *currNode = nullptr;
    for(currNode = headNode;currNode->next!=tailNode;currNode=currNode->next){}                
    
    Node *delNode = tailNode;    
	                                                                
	tailNode = currNode;                                                                        
	tailNode->next = nullptr;                                                                   
	
	delete delNode;                                                                              // Tail Node is also Deleted form Memory 
    
	//-----------------------------------------------------------------------------------------------------------------------------------
	nNodesSize--;
	    cout<<"\n\n\t                -------------   [{Node is Successfully Deleted from the End/Last of the Linked List }]\n\n\n";

	
}

//For Removing or deliting of the Node from Anywhere from the Linked List based on the Index , From Any Index Node will be deleted 
void solLList::operator-(){	
    int idx;
    cout<<"\n\n\n\t            Node Delition Request From Linked List :::\n\n";
	cout<<"\n\t Enter the Index (1-Based) Where From You Wanna Delete the Node in Linked List => ",cin>>idx;
    
	if(isValidOprDel(idx)){
    	
    Node *delNode = nullptr;
    
    
    	if(nNodesSize==1){
		linkedList = nullptr;
		headNode = nullptr;
		tailNode = nullptr;
	    nNodesSize = 0;
		
		cout<<"\n\n\t                -------------   [{Node is Successfully Deleted from the Index "<<idx<<" of the Linked List  }]\n\n\n";
	
		return;
	}
    
    if(idx==1){                             
	    delNode = headNode;                                                                                
	    headNode = headNode->next;                                                                      
	    
 	    linkedList = headNode;                                                                          
	    delete delNode;                                                                                 //Also delete the node from the memory
	}
	else{
	      delMidLastNodeLList(delNode,idx);
       }
    cout<<"\n\n\t              [{Node is Successfully Deleted form the "<<idx<<" Position/Index of the Linked List }]";
   
    nNodesSize--;
  }
  
  else cout<<"\n\n\t                    @#@#@#@#@#@#   INVALID OPERATION :::: Please Enter the Valid Index or Position : As Size of the Linked List is => "<<nNodesSize;  
}

//For Printing the Linked List Each Time Updated 
ostream & operator<<(ostream &Out,solLList &S){
	Out<<"\n\n\n\t                    ---------------------- Linked List ------------------- \n\n\t\t\t";
	ForL(currNode,S.linkedList) cout<<currNode->Data<<" --> ";cout<<" NULL ";
    
    return Out;
}

//Valid Check :: For While Adding the Node in the Linked List 
bool solLList::isValidOprAdd(int i){
	return (((i<=nNodesSize) && (i>0)) || i==(nNodesSize+1));
}

//valid Check :: For While Remving or Deliting the Nodes from the Linked List 
bool solLList::isValidOprDel(int i){
	return ((i>0 && i<=nNodesSize));
}

//Empty Check :: Ensures Linked List Must Not Empty While Request been made for perfornming Any Operation on Linked list 
bool solLList::oprValidityCheck(){
	return (linkedList!=nullptr);
}


int solLList::prHead(){return headNode->Data;}                    //Return Data of Head
int solLList::prTail(){return tailNode->Data;}                    //Return Data of Tail Node
Node *solLList::getHeadLList(){return headNode;}                  //Return the Head Node Itself 



void printLinkedListRules() {
    cout << "\n\n";
    cout << "\t===========================================================\n";
    cout << "\t       LinkedListInfinityEngine_CPP - RULES & USAGE\n";
    cout << "\t===========================================================\n\n";

    cout << "\tAvailable Menu Operations:\n";
    cout << "\t-----------------------------------------------------------\n";
    cout << "\t [1]   >>   Create Linked List From Scratch\n";
    cout << "\t [2]   <<   Display the Linked List\n";
    cout << "\t [3]   ++   Add Node at the End (Tail)\n";
    cout << "\t [4]   --   Remove Node from the End (Tail)\n";
    cout << "\t [5]   +    Insert Node at a Specific Index\n";
    cout << "\t [6]   -    Delete Node from a Specific Index\n";
    cout << "\t [7]   addBegin()     - Insert at the Beginning\n";
    cout << "\t [8]   remBegin()     - Remove from the Beginning\n";
    cout << "\t [9]   printRevLList() - Reverse Print (Recursive)\n";
    cout << "\t[10]   searchNodeLList() - Search Node by Data\n";
    cout << "\t[11]   prHead()        - Print Head Node Data\n";
    cout << "\t[12]   prTail()        - Print Tail Node Data\n";
    cout << "\t[13]   getSize()       - Show Size of the List\n";
    cout << "\t[14]   clearLinkedList() - Fully Clear List\n";
    cout << "\t[15]   #     Shortcut to Clear List\n";
    cout << "\t[16]   !     Exit the Program\n";

    cout << "\n\tOperator Overloading Rules:\n";
    cout << "\t-----------------------------------------------------------\n";
    cout << "\t [+ ] : Add Node at User-Defined Index\n";
    cout << "\t [- ] : Remove Node from a Specified Index\n";
    cout << "\t [++ ]: Add Node at the End of the List (Tail)\n";
    cout << "\t [-- ]: Remove Node from the Last (Tail)\n";
    cout << "\t [>> ]: Input the Entire Linked List\n";
    cout << "\t [<< ]: Print the Entire Linked List\n";

    cout << "\n\tValidation Rules & Edge Case Handling:\n";
    cout << "\t-----------------------------------------------------------\n";
    cout << "\t - List must not be empty for any operation.\n";
    cout << "\t - Insertion index must be in [1, Size+1].\n";
    cout << "\t - Deletion index must be in [1, Size].\n";
    cout << "\t - Deleting from empty list is safely blocked.\n";
    cout << "\t - Single-node list operations are handled correctly.\n";

    cout << "\n\tObject-Oriented Design Features Applied:\n";
    cout << "\t-----------------------------------------------------------\n";
    cout << "\t - All data members are private.\n";
    cout << "\t - Only public member functions allow manipulation.\n";
    cout << "\t - Operator overloading for intuitive usage.\n";
    cout << "\t - Helper functions maintain modularity.\n";

    cout << "\n\tTracked Internals:\n";
    cout << "\t-----------------------------------------------------------\n";
    cout << "\t - headNode     : Points to the first node.\n";
    cout << "\t - tailNode     : Points to the last node.\n";
    cout << "\t - linkedList   : Complete list referenced by this.\n";
    cout << "\t - nNodesSize   : Size of the current linked list.\n";

    cout << "\n\tNote:\n";
    cout << "\t-----------------------------------------------------------\n";
    cout << "\t Every update to the list reflects immediately.\n";
    cout << "\t Designed to safely guide and simulate linked list usage.\n";

    cout << "\n\t===========================================================\n";
    cout << "\t       Built by the Tycoonic Problem Solver - KING LEVEL\n";
    cout << "\t===========================================================\n\n";
}

void action(string tIn,solLList &S){
	
	if(tIn[0]=='1'){
		cin>>S;
	}
	else if(tIn[0]=='2') {
				if(S.oprValidityCheck()) S.addBegin();
				else cout<<"\n\n\t                Invalid Operation ::: Linked List Not Exists (Please Create the Linked List First) <<Menu Option 1.>> \n\n";}	
	
	else if(tIn[0]=='3'){
		if(S.oprValidityCheck()) ++S;
		else cout<<"\n\n\t                Invalid Operation ::: Linked List Not Exists (Please Create the Linked List First) <<Menu Option 1.>> \n\n";}	
	
	else if(tIn[0]=='4'){
	    if(S.oprValidityCheck()) S.operator+();
 		else cout<<"\n\n\t                Invalid Operation ::: Linked List Not Exists (Please Create the Linked List First) <<Menu Option 1.>> \n\n";}	

	else if(tIn[0]=='5') {
		if(S.oprValidityCheck()) S.remBegin();
		else cout<<"\n\n\t   !!!!!             Invalid Operation ::: Linked List Not Exists (Please Create the Linked List First) <<Menu Option 1.>> \n\n";}	
	
	else if(tIn[0]=='6'){
		if(S.oprValidityCheck()) --S;
		else cout<<"\n\n\t                Invalid Operation ::: Linked List Not Exists (Please Create the Linked List First) <<Menu Option 1.>> \n\n";}	

	else if(tIn[0]=='7') {
		if(S.oprValidityCheck()) S.operator-();
		else cout<<"\n\n\t                Invalid Operation ::: Linked List Not Exists (Please Create the Linked List First) <<Menu Option 1.>> \n\n";}	

	else if(tIn[0]=='8') {
		if(S.oprValidityCheck()) cout<<S;
		else cout<<"\n\n\t                Invalid Operation ::: Linked List Not Exists (Please Create the Linked List First) <<Menu Option 1.>> \n\n";}	

	else if(tIn[0]=='9') {
	   if(S.oprValidityCheck()) cout<<"\n\n\t                             ~~~~~~~~~ Size of Linked List is : "<<S.getSize();
	   else cout<<"\n\n\t                Invalid Operation ::: Linked List Not Exists (Please Create the Linked List First) <<Menu Option 1.>> \n\n";}	

	else if(tIn[0]=='#') {
		if(S.oprValidityCheck()) {S.clearLinkedList(); cout<<"\n\n\n\t      ///////////////////////// Linked List is Cleared Successfully";}
		else cout<<"\n\n\t                Invalid Operation ::: Linked List Not Exists (Please Create the Linked List First) <<Menu Option 1.>> \n\n";}	

	else if((tIn[0]=='h') || (tIn[0]=='H')){
		if(S.oprValidityCheck()) cout<<"\n\n\t               ----------   Head Node is ------------ :     |"<<S.prHead()<<" |";
		else cout<<"\n\n\t                Invalid Operation ::: Linked List Not Exists (Please Create the Linked List First) <<Menu Option 1.>> \n\n";}	

	else if((tIn[0]=='t') ||(tIn[0]=='T')){
		if(S.oprValidityCheck()) cout<<"\n\n\t               ----------   Tail Node is ------------ :     |"<<S.prTail()<<" |";
		else cout<<"\n\n\t                Invalid Operation ::: Linked List Not Exists (Please Create the Linked List First) <<Menu Option 1.>> \n\n";}	
	
	else if(tIn[0]=='r' || tIn[0]=='R'){
		if(S.oprValidityCheck()) {cout<<"\n\n\t                 Printing the Linked List in Reverse : \n"<<"  NULL ";
		                          S.printRevLList(S.getHeadLList());}
		else cout<<"\n\n\t                Invalid Operation ::: Linked List Not Exists (Please Create the Linked List First) <<Menu Option 1.>> \n\n";}	
	
	else if(tIn[0]=='s' || tIn[0]=='S'){ 
	     
	     if(S.oprValidityCheck())
		 {
			 int tD;
		     cout<<"\n\n\t           Please Enter the Data of the Node , Which You Want to (First Existense) Find/Search in the Linked List => ",cin>>tD;
		     
		     tD = S.searchNodeLList(tD);
		     
		     if(tD!=-1) cout<<"\n\n\t             {{{{ ----------   Search Successfull : The Node (First Exist) Present at "<<tD<<" Index (1-Based) in the Linked List !!!   ----------- }}}}}";
		     else cout<<"\n\n\t                  {{{{ -----------    SEARCH UNSUCCESSFULL ðŸ‘Ž : The Node Which You Wanna Find is Not present Inside Linked List : \n\n";
	     }
	   else cout<<"\n\n\t                Invalid Operation ::: Linked List Not Exists (Please Create the Linked List First) <<Menu Option 1.>> \n\n";}	
    
	else if(tIn[0]=='?')  printLinkedListRules();
    
	else if(tIn[0]=='!') return;
	
	else {cout<<"\n\n\t                       !@!@!@!@!@!@!@ Please Enter the Correct Input From Menu  !@!@!@!@!@!@!@ ";}	
}
void startLList(){
	
    cout<<"\t    __________________________________________________________________________________";
    cout<<"\n\n\t                             Linked List Implementation \n\n";
    cout<<"\t    __________________________________________________________________________________\n";
     
	cout<<"\n\n\n\t     *-*-*-*-*-*-*-*-*-*-*-*- Operations Menu *-*-*-*-*-*-*-*-*-*-*-*-\n\n";
	cout<<"\n\t     [1] Creation of Linked List From Scratch \n\t     [2] Adding Node in the Beggining of Linked List \n\t     [3] Adding Node by Default at the End or Last of the Linked List \n\t     [4] Adding Node at Any Where in the Linked List \n\t     [5] Delition of Node from the Beggining of Linked List \n\t     [6] Delition of Node from the Last or End of the Linked List By Default \n\t     [7] Delition of Node from Anywhere in the Linked List \n\t     [8] Printing Linked List \n\t     [9] Getting Size of the Linked List \n\t     [h] Printing the Head Node (Data) of the Linked List \n\t     [t] Printing the Tail Node of the Linked List \n\t     [r] Printing the Linked List in Reverse \n\t     [s] Searching the Node inside the Linked List \n\t     [#] Clearing the Linked List \n\t     [?] LinkedListInfinityEngine_CPP - RULES & USAGE \n\t     [!]  Exit / Stop ";
}
 
/*
Linked list is basically implemented and to end fully in detailed manner : 


The main purpose is to basically fully understand the concept of the structure behind the link list Proper easy way to understand
 it by performing various operations over the linked list and view the link list properly how the nodes go to how things happening 
 everything is basically implemented even if it is removing the node from the last we're adding the node at the last or removing the 
 node from the beginning or adding the node at the beginning is fully managed also take care of the proper edge cases like Must not 
 have the link list empty and also uh correct indexing based addition or the insertion of nodes in the linked list or the correct removal 
 or the deleting of the notes from the linked list which is based upon the valid indexes
  
Operators overloaded for end to end the implementation of the linked list also take care of every possible case which can be possible and 
which makes the linked list to be  it is also take care of that accordingly ,
Various operators are overloaded customly to customly provide the implementation of the operators  Even if it is an + operator using for adding 
notes anywhere in the linked list or subtraction operator is for removal of the node from the linked list by index from anywhere and basically 
taking the input of the linked list from the scratch and to and after asking the size and creating it from the scratch and by using the input
stream overloaded operator function implementation customly and each and every point when we try to be create the linked list from scratch its 
gonna used 
incrementation and the decrement operator which are the unary operators are also used for adding the nodes by default at the last or removing 
the nodes by default from the last or the end of the linked list 

Also even if it is clearing the linked list  People just direct forward clearing the linked list deleting and removing the notes and also delete t
he notes from the memory as well or even if it is  , Clearing the link released when we try to be create the linked list from scratch 
Searching notes by the data in the linked list is also addex And reverse printing of the linked list is also implemented , 
Each time updated linked list is printed on the console by using the output stream overloaded operator customly which is 
implemented 

Tracking size of the linked list tracking the head of the linked list tracking the tail node of the linked list Also tracking the end to end linked list
itself which represents the whole linked list through a pointer from the beginning to end 
 
 
Fully implementation of the linked list is basically happened with the object orientation nature proper moduletic with proper following the object orientation principles properly:

by overloading of the operators 
having getters 
encapsulated stuff private data   
Customly overloading of the operators    
Data hiding direct changes in the linked list is not allowed :: Data hiding ensures that  User not have direct access to playing with the data members like which directly avoid the data members to be used The main purpose is to avoid the mishandling of the data members that's why data hiding is using  
Automated menu driven functionality for playing with the linked list 
Every change is referencily happen in place 
Member function properly encapsulate the stuff in the class only Nothing but we can say that a blueprint or the prototype to implement the linked list  
Always data is private and functions are public as data members are private and facilitators are public 

 
Overloading Operators and Implemented Operations:

+     Adding the node at anywhere in Linked list through index 
-     Removing or deleting the node from anywhere in the linked list 
++    Adding the node by default at the end of the last of the linked list 
--    Removing or deleting the node by default from the end or last of the linked list 
>>    Fully end to end creation of the linked list from scratch Each Time the custom size linked list creation 
<<    Each time printing the updated linked list 

addBegin()  Adding the node by default at the beginning of the linked list or at the head of the linked list 
remBegin()  Removing the node by default from the beginning or the start of the linked list 

isValidOprAdd()    For checking  Insertion operation over linked list like adding node at the valid index in the linked list   
isValidOprDel()    For checking the deletion or the removal of the node from the valid index of the linked list 

oprCheckValidity()   It always checks linked list not to empty before every operation means while performing any operation 

getSize()     :: return the Size of The Linked List Updated
prHead()      :: For Displaying the head node of the linked list 
prTail()      :: For displaying the tail node of the linked list 

serachNodeLList()  :: Searching the node inside linked list buy their data if the node exists return index otherwise return minus 1 
printRevLList()    :: Printing of the linked list in reverse using the non  tail or the normal recursive function 

clearLinkedList() : For Clearing the Linked List fully like Deleteing the Nodes and also from Memory Nulls each Node 
					    

Tracking Properly the :
Size of the Linked List Updated
Head or First Node of the linked list 
Tail or last Node of the Linked List 
Actual linkedList , Fom Beggining to End as Whole by a Pointer
 
 
Handling:
     Properly handling of the Edge Cases and valid 
	  
	     => If Linked List is Empty
		 => If Linked List is Not Empty
		  
         => Insertion:
           If the index is invalid while insertin
		   
		   For Adding Node At Head
		   For Adding Node At Tail or End of linked List
		   
		   For Adding Node at Any Index of Linked List 
		   
		 => Delition: 
		   if there is One Node in Linked List 
		   
		   If the index is invalid while Delition

		   For Delition Node from Head
		   For Delition Node from Tail or End of linked List
		   
		   For Delition Node from Anywhere from linked List
		   
*/