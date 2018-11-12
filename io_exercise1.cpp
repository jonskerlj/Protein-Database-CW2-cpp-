#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Protein{ 
  private:
    int id;
    string gi;
    string ref;
    string keyword;
    string AAcode;
  public:
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
  fstream myfile("protein_a.fa");
  string gi, ref;
  string data, data2;
  char space;
  string keyword;
  string AAcode;
  char third[50];
  Protein protein[12];
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

    protein[i].input_all(id,gi,ref,keyword,AAcode);
    protein[i].display();    
    i++;
  }
}