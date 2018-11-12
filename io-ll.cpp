#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class Protein{ 
  private:
    int id;
    string gi;
    string ref;
    string keyword;
    string AAcode;
    
  public:
    Protein* next;
    Protein();
    

    void input_all(int a, string b, string c, string d, string e);
    /*void input_id(int a);
    void input_gi(string b);
    void input_ref(string c);
    void input_keyword(string d);
    void input_AAcode(string e);*/

    ~Protein();

    int get_id();
    string get_gi();
    string get_ref();
    string get_keyword();
    string get_AAcode();

    void display();
};

class Count{
  public:
	Protein* head;
	int data;
	

	Count();
	~Count();
	void add_all(int a, string b, string c, string d, string e);
	void print();

};
Count::Count(){
  this->data=0;
  this->head=NULL;
}
Count::~Count(){
  cout<<"List Deleted"<<endl;
}
void Count::add_all(int a, string b, string c, string d, string e){
  Protein* node = new Protein();
  node->input_all(a,b,c,d,e);
  node->next=this->head;
  this->head=node;
  this->data++;
}

void Count::print(){
  Protein* h=this->head; /*h points to last element*/
  int i=1;
  while(h){
    h->display();
    h=h->next;
    i++;
  }
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
  cout<<"List Deleted"<<endl;
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
  cout<<"ID: "<<id<<endl;
    cout<<"GI: "<<gi<<endl;
    cout<<"Ref: "<<ref<<endl;
    cout<<"Keywords: "<<keyword<<endl;
    cout<<"Sequence: "<<AAcode<<endl;
}
void Input();

int main(){
  Input();
  return 0;
}

void Input(){
  Count* list= new Count();
  fstream myfile("protein_c.fa");
  string gi, ref;
  string data, data2;
  char space;
  string keyword;
  string AAcode;
  char third[50];
  //Protein protein;
  int i=0;
  while(!myfile.eof()){
    int id = i+1;
    getline(myfile,data,'|');
    getline(myfile,gi,'|');
    getline(myfile,data2,'|');
    getline(myfile,ref,'|');
    myfile.get(space);
    getline(myfile,keyword,'\n'); 
    getline(myfile,AAcode,'>');
    list->add_all(id,gi,ref,keyword,AAcode);

    
    /*protein[i].input_all(id,gi,ref,keyword,AAcode);
    protein[i].display();  */  
    i++;
  }
  list->print();
  cout<<"List lenght: "<<list->data<<endl;
  delete list;
}