/*Protein Database - Coursework 2(c++)*/
/*Author: Jon Skerlj*/
/*Use of linked list to store all the elements into a class*/
/*Last modification: 23/11/2018*/


#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int f; //global variable

/*Class that stores all the data form the protein file. It also has a pointer that can point to the objects of the same class*/
/*The pointer is going to be used to create the link list(linking the objects together)*/
class Protein{ 
  private: //All the data from the protein file is going to be stored in these variables
    int id;
    string gi;
    string ref;
    string keyword;
    string AAcode;
    
  public:
    Protein* next; //Pointer that links objects of the same class together
    Protein(); //Constructor*
    

    void input_all(int a, string b, string c, string d, string e); //Class function that inputs the data for 1 protein form the protein file into an object
    ~Protein(); //Destructor

    int get_id(); //Member function that returns the id of a protein
    string get_gi(); //Member function that returns the gi of a protein
    string get_ref(); //Member function that returns the ref of a protein
    string get_keyword(); //Member function that returns the keyword(aka name) of a protein
    string get_AAcode(); //Member function that returns the Protein code of a protein

    void display(); //Member function that displays one protein(id, gi, ref, name). Doesn't display protein code
	void Multiple_display(); //Member function that displays when multiple choices of protein is called
	void Pro_seq(); //Member function that displays protein code
	void Pro_statistics(Protein* selected); //Member function that displays statistics of protein code
	void Record_2_file(Protein* selected); //Member function that records protein to a file
};
/*Class that is going to navigate across the linked list (of class Protein) with the pointer(named head)*/
class Count{
  public:
	Protein* head;
	int data; //value that is going to count the number of objects in the linked list
	

	Count(); //Constructor
	~Count(); //Destructor
	void add_all(int a, string b, string c, string d, string e); //Member function that inputs the data in the Protein object
	Protein* Search_id(int id); //Member function that searches by the id and returns the pointer of the correct object of Protein class
	Protein* Search_str(string str); //Member function that searches(from back to the front) by the gi and returns the pointer of the correct object of Protein class
	Protein* Search_ref(string str); //Member function that searches(from back to the front) by the ref and returns the pointer of the correct object of Protein class
	void Search_keyword(string str); //Member function that searches(from back to the front) by the keyword and displays all correct objects(aka Proteins)
	Protein* Selected_protein(string str, int x); //Member function that selects the correct protein form the options displayed by member function Search_keyword
};
Count::Count(){ //Constructor
  this->data=0;
  this->head=NULL; //First head pointer = null. This way i know where the linked list started
}
Count::~Count(){ //Destructor
}

/*Count member function that imports all the data in the new Protein object and points back to previous object(Creating linked list) */
void Count::add_all(int a, string b, string c, string d, string e){ 
  Protein* node = new Protein(); //Creating a pointer that points to the new object of class Protein
  node->input_all(a,b,c,d,e); //Inputing the data in the Protein object
  node->next=this->head; //Assigning the pointer named next(in protein class) to the pointer named head of class count(First one = NULL)
  this->head=node; //Asigning the pointer named head(in count class) to the pointer named node(of the class Protein)
  this->data++; //Increment the variable data by one each time you go through loop - counting the number of the objects created
}

/*Count member function that searches the data with respect to id. From back of the linked list to the front*/
Protein* Count::Search_id(int n){
	Protein* h = this->head;
	while(h){
		if(h->get_id()==n) break;
		h=h->next;
	}
	return h;
}
Protein* Count::Search_str(string str){
	Protein* h= this->head;
	while(h){
		if(h->get_gi()==str) break;
		h=h->next;
	}
	return h;
}
Protein* Count::Search_ref(string str){
	Protein* h= this->head;
	while(h){
		if(h->get_ref()==str) break;
		h=h->next;
	}
	return h;
}
void Count::Search_keyword(string str){
	Protein* h= this->head;
	Protein* pt=this->head;
	int count=0;
	while(h){ //checking all the protein objects - from the back to the front(first object has pointer equal to NULL)
		int ref_length=h->get_keyword().length(); //Lenght of the name of the protein
		int str_length=str.length(); //Lenght of the entered string
		for(int i=0;i<(ref_length-str_length+1);i++){ //loop that goes throug the name of the protein one by one 
			if(str[0]==(h->get_keyword()[i])){ //Check if the character of the name is the same as the first character of the entered string 
				string a = h->get_keyword().substr(i,str_length); //Assign string a to a string from a name of a protein that starts with the same letter as entered string and has the same lenght as the entered string
				if(str==a) count++;	 //If the strings are the same increment count
			}
		}
		h=h->next; //Going to the next object
	}
	cout<<"\nNumber of matches found: "<<count<<endl;
	count=0;
	/*Same thing as above, but it also prints all the possible options*/
	while(pt){
		int ref_length=pt->get_keyword().length();
		int str_length=str.length();
		for(int i=0;i<(ref_length-str_length+1);i++){
			if(str[0]==(pt->get_keyword()[i])){
				string a = pt->get_keyword().substr(i,str_length);
				if(str==a) {
					count++;	
					cout<<count<<") ";
					pt->Multiple_display();
				}
			}
		}
	pt=pt->next;
	}
}
Protein* Count::Selected_protein(string str, int x){
	Protein* h=this->head;
	int count=0;
	while(h){
		int ref_length=h->get_keyword().length();
		int str_length=str.length();
		for(int i=0;i<(ref_length-str_length+1);i++){
			if(str[0]==(h->get_keyword()[i])){
				string a = h->get_keyword().substr(i,str_length);
				if(str==a) count++;
				if(count==x) return h;
			}
		}
		h=h->next;
	}
	return NULL;
}


	
Protein::Protein(){
  id=0;
  gi="";
  ref="";
  keyword="";
  AAcode="";
}
void Protein::input_all(int a, string b, string c, string d, string e){
  id = a;
  gi = b;
  ref = c;
  keyword = d;
  AAcode = e;
}
Protein::~Protein(){
}

int Protein::get_id(){
 return id;
}
string Protein::get_gi(){
  return gi;
}
string Protein::get_ref(){
  return ref;
}
string Protein::get_keyword(){
  return keyword;
}
string Protein::get_AAcode(){
  return AAcode;
}

void Protein::display(){
	cout<<"Description of the protein:"<<endl;
	cout<<"Item id: "<<id<<endl;
    cout<<"Gi id: "<<gi<<endl;
    cout<<"Ref id:: "<<ref<<endl;
    cout<<"Name: "<<keyword<<"\n"<<endl;
}
void Protein::Multiple_display(){
	cout<<"item id: "<<id<<", gi id: "<<gi<<", ref id: "<<ref<<endl;
	cout<<"    "<<keyword<<endl;
}
void Protein::Pro_seq(){
	cout<<"Protein sequence:"<<endl;
	cout<<AAcode<<endl;
}
void Protein::Pro_statistics(Protein* selected){
	int count2=0;
	cout<<"\nReport on the protein statistics:\n"<<endl;
	for(char letter='A';letter<'[';letter++){
		int count=0;
		if(letter!='J'&&letter!='O'){
			for(int i=0;i<selected->AAcode.length();i++){
				if(letter==selected->AAcode[i]) {
					count++;
					count2++;
				}
			}
			cout<<letter<<" "<<count<<endl;
		}
	}
	int c=0;
	for(int i=0;i<selected->AAcode.length();i++){
		if('*'==selected->AAcode[i]) c++;
	}
	cout<<"* "<<c<<endl;
	c=0;
	for(int i=0;i<selected->AAcode.length();i++){
		if('-'==selected->AAcode[i]) c++;
	}
	cout<<"- "<<c<<endl;
	cout<<"Total number of amino acids: "<<count2<<endl;
}
void Protein::Record_2_file(Protein* selected){
	ofstream create_File;
	create_File.open("Selected_proteins.txt",  create_File.app);
	create_File<<"Item id: "<<selected->get_id()<<endl;
	create_File<<"Gi id: "<<selected->get_gi()<<endl;
	create_File<<"Ref id: "<<selected->get_ref()<<endl;
	create_File<<"Name: "<<selected->get_keyword()<<endl;
	create_File<<"Protein sequence: "<<selected->get_AAcode()<<endl;
	create_File.close();
	cout<<"\nThe protein was written to a file"<<endl;
}

/*Function that displays start menu which returns first user input*/
int Starting_menu(){ 
	int n;
	cout<<"Welcome to the Protein Database"<<endl;
	cout<<"\nSelect an option from the menu below:"<<endl;
	cout<<"1) Load the abridged protein data"<<endl;
	cout<<"2) Load the complete protein data"<<endl;
	cout<<"3) Quit database"<<endl;
	do{ //Do-while loop that checks if the user inputted a correct value
		cin>>n;
		if(n>3||n<1) cout<<"Error, your number is invalid. Try again(1-3): "<<endl;
	} while(n>3||n<1);
	return n;
}
void Protein_menu(){ 
		cout<<"\nSelect and option from the menu below:"<<endl;
		cout<<"1) Description of the protein"<<endl;
		cout<<"2) Protein sequence"<<endl;
		cout<<"3) Protein statistics"<<endl;
		cout<<"4) Record protein to file"<<endl;
		cout<<"5) Return to main menu"<<endl;
}

bool Main_menu(Count* list); //I need the delcaration here because I am using the function in the Functions below
/*Function that prints the overview the of database*/
void Overview(Count* list){
	cout<<"The proteins in the database are from GenBank(R)"<<endl;
	if(f==2)cout<<"Total number of proteins in the database: 110386"<<endl;
	else cout<<"Total number of proteins in the database: 11"<<endl;
	cout<<"Amino acids are represented by the following characters:"<<endl;
	cout<<"A  alanine				P  proline"<<endl;
	cout<<"B aspartate/asparagine			Q glutamine"<<endl;
	cout<<"C cystine				R arginine"<<endl;
	cout<<"D aspartate				S serine"<<endl;
	cout<<"E glutamate				T threonine"<<endl;
	cout<<"F phenylalanine 			U selenocysteine"<<endl;
	cout<<"G glycine				V valine"<<endl;
	cout<<"H histidine				W tryptophan"<<endl;
	cout<<"I isoleucine				Y tyrosine"<<endl;
	cout<<"K lysine 				Z glutamate/glutamine"<<endl;
	cout<<"L leucine				X any"<<endl;
	cout<<"M methionine				* translation stop"<<endl;
	cout<<"N asparagine				- gap of indeterminate length"<<endl;
	Main_menu(list);
}

/*Function that gets the addres of the correct protein and then calls the right function according to the user input*/
void Protein_display(Protein* selected){
	int n=0;
	if (selected==NULL) cout<<"You id is out of range"<<endl;
	else Protein_menu();
	while(n!=5){ 
		cin>>n;
		switch(n){
			case 1:
				selected->display();
				break;
			case 2:
				selected->Pro_seq();
				break;
			case 3:
				selected->Pro_statistics(selected);
				break;
			case 4:
				selected->Record_2_file(selected);
		}
		if(n>5||n<1) cout<<"Error, your number is invalid. Try again(1-5)"<<endl; //Statement that displays an error if the user inputted incorrect value
		Protein_menu();
	}
}

/*Function that finds the correct protein by id*/
void Id_display(Count* list){ 
	int id, n;
	Protein* selected;
	cout<<"Enter an item id:"<<endl;
	cin>>id;
	selected = list->Search_id(id); //Getting an address of the correct object in the class Protein searching by the id number of the protein
	Protein_display(selected); //Displaying the next menu with new options
	Main_menu(list);	
}

/*Function that finds the correct protein by gi*/
void Gi_display(Count* list){ 
	int n=0;
	string gi;
	Protein* selected;
	cout<<"Enter an item gi:"<<endl;
	cin>>gi;
	selected = list->Search_str(gi); //Getting an address of the correct object in the class Protein searching by the gi number of the protein
	Protein_display(selected); //Displaying the next menu with new options
	Main_menu(list);
}

/*Function that finds the correct protein by ref*/
void Ref_display(Count* list){ 
	int n=0;
	string ref;
	Protein* selected;
	cout<<"Enter an item ref:"<<endl;
	cin>>ref;
	selected = list->Search_ref(ref); //Getting an address of the correct object in the class Protein searching by the ref number of the protein
	Protein_display(selected);
	Main_menu(list);
}
/*Function that finds the correct protein by keyword*/
void Keyword_search(Count* list){
	int n=0,x;
	string id;
	Protein* selected;
	cout<<"Enter a keyword: "<<endl;
	cin>>id;
	list->Search_keyword(id);
	cout<<"\nSelect one of the matches:"<<endl;
	cin>>x;
	selected = list->Selected_protein(id, x);
	Protein_display(selected);
	Main_menu(list);	
}

/*Function that displays Main menu of the program and then calls appropriate functions based on user input*/
/*Returns false if user selects quit data base option, otherwise it return a positive value*/
bool Main_menu(Count* list){
	int n=1;
	cout<<"\nSelect an option from the menu below:"<<endl;
	cout<<"1) Overview by protein"<<endl;
	cout<<"2) Search by protein #"<<endl;
	cout<<"3) Search by gi #"<<endl;
	cout<<"4) Search by ref #"<<endl;
	cout<<"5) Search by keyword"<<endl;
	cout<<"6) Quit database"<<endl;
	do{ //Do-while loop that checks if the user inputted a correct value
		cin>>n;
		if(n>6||n<1) cout<<"Error, your number is invalid. Try again(1-6)"<<endl;
		switch(n){
			case 1:
				Overview(list);			/*Function that displays overview*/
				break;
			case 2:
				Id_display(list); /*Function that finds the protein and displays next step*/
				break;
			case 3:
				Gi_display(list); /*Function that finds protein with the same gi and displays next step*/
				break;
			case 4:
				Ref_display(list); /*Function that finds protein with the same ref and displays next step*/
				break;
			case 5:
				Keyword_search(list); /*Function that searches for the keyword*/
				break;
			case 6:
				return false;
		}
	}while(n>6||n<1);
	
	return true;
}


/*Function that stores values for one protein in each loop and inputs them in the newly created object*/
void Input(int a, Count* list, ifstream& myfile){
  if(a==1) myfile.open("protein_a.fa"); //Loading abridged version
  else myfile.open("protein_c.fa"); //loading complete version
  string gi, ref;
  string data, data2;
  char space;
  string keyword;
  string AAcode;
  int id=1;
  cout<<"Loading database..."<<endl;
  while(!myfile.eof()){
	
    getline(myfile,data,'|');
    getline(myfile,gi,'|');
    getline(myfile,data2,'|');
    getline(myfile,ref,'|');
    myfile.get(space);
    getline(myfile,keyword,'\n'); 
    getline(myfile,AAcode,'>');
    list->add_all(id,gi,ref,keyword,AAcode); 
    id++;
  }
  cout<<"Database loaded"<<endl;
  cout<<"List lenght: "<<list->data<<endl;
}
int main(){
	int n;
	bool m;
	ifstream myfile;
	Count* list=new Count();  //Pointer type Count
	n = Starting_menu();
	int id=1;
	//loading of the database
	if(n==1||n==2) {
		Input(n, list, myfile); //Depending on the first user input it selects abridged protein database, complete protein database or quits the program(else-if statement)
		f = n;
	}
	else if(n==3){
		delete list;
		cout<<"\nExiting the database"<<endl;
		return 0;
	}
	//Main menu
	m = Main_menu(list); //return false if users wants to quit the program(when they enter 6)
	if(m==false){
		delete list; //Deleting the dynamically alocated memory 
		cout<<"\nExiting the database"<<endl;
		return 0;
	}
	/*Main menu*/
	delete list; 
	return 0;
}