#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;
// writing into file.
void writefile(){
   string fileName;
   ofstream fout;
   cout<<"Enter the name of text file.(Ex- example.txt ) : ";
   cin>>fileName;
    fout.open(fileName);
   cin.ignore();
    string s;
    cout<<"Enter the text.(Type END to Stop) : ";
    while(true){
    getline(cin,s);
    if(s=="END"){
     break;
    }
    else{
        fout<<s+"\n";
    }
}
}
// Reading for Number of lines,words,and letters.
void readLine(){
   string fileName;
   cout<<"Enter the name of text file.(Ex- example.txt ) : ";
    cin>>fileName;
   ifstream myfile(fileName);
    if(!myfile){
      cout<<"Error : Can't open file."<<endl;
    }
 string s;
 int countchar=0;
 int countword=0;
 bool inword=false;
 int line=0;
 bool lastwasspace=false;
 while(getline(myfile,s)){
    line++;
 for(char ch:s){
    if(isalpha(ch)){
        countchar++;
        inword=true;
        lastwasspace=false;
    }
    if(isspace(ch)){
        if(inword){
            countword++;
        }
        inword=false;
        lastwasspace=true;
    } 
 }
 if(inword){
    countword++;
 }
  lastwasspace=false;
 }
 myfile.close();
 if(countchar==0){
    cout<<"File has only white spaces."<<endl;
 }
 else{
 cout<<"No. of lines = "<<line<<endl;
 cout<<"No. of words = "<<countword<<endl;
 cout<<"No of characters = "<<countchar<<endl;
}
}
// printing the file.
void printFile(){
   ifstream fout;
 cout<<"Enter the name of text file.(Ex- example.txt ) : ";
 string s;
 cin>>s;
 fout.open(s);
 string line;
 while(getline(fout,line)){
   cout<<line<<endl;
 }
}
int main(){
cout<<"Enter 1 To print the Number of Line,Words,Letters. "<<endl;
cout<<"Enter 2 To write in to the file.(you can write multiple lines)"<<endl;
cout<<"Enter 3 To print the content of file."<<endl;
cout<<"Enter 4 To Exit."<<endl;
int choice=0;
while(choice!=4){
   cout<<"Enter your choice. : ";
   cin>>choice;
   switch(choice){
      case 1:
      readLine();
      break;
      case 2:
       writefile();
      break;
      case 3:
      printFile();
      break;
      case 4:
      cout<<"Exiting from program.";
      break;
      default :
       cout<<"Invalid choice."<<endl;
   }
}

 
}
