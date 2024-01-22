#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <conio.h>
using namespace std;

class books{
    string id,title,auther,category,search,pass;
    public:
    void display_books();
    void sbyid();
    void sbytitle();
    void sbyauther();
    void sbycategory();
    void password();
    void admin();
    void add_book();
    void remove_book();
    void modify_book();
    string truncate(string str,int size);
    void sort();
}obj;

int main(){
    system("cls");
    system("color 0B");
    cout<<left;
    char op;
    cout<<"Choose an action: \n";
    cout<<"1-Show all books \n";
    cout<<"2-Search by ID \n";
    cout<<"3-Search by title \n";
    cout<<"4-Search by auther \n";
    cout<<"5-Choose category \n";
    cout<<"6-ADMIN control \n";
    cout<<"Esc-Exit program \n";
    op=getch();
    switch(op){
        case '1':{
            obj.display_books();
            break;
        }
        case '2':{
            obj.sbyid();
            break;
        }
        case '3':{
            obj.sbytitle();
            break;
        }
        case '4':{
            obj.sbyauther();
            break;
        }
        case '5':{
            obj.sbycategory();
            break;
        }
        case '6':{
            system("cls");
            obj.password();
            break;
        }
        case 27:{
            return 0;
        }

    }

    return 0;
}

void books :: password(){
    char op;
    cout<<"Enter password:\n\t";
    getline(cin,pass);
    if(pass=="1234"){
        obj.admin();
    }
    else{
        cout<<"Incorrect Password"<<endl;
        cout<<"Press Esc to return to main menu \nor any key to try again"<<endl;
        op=getch();
        if (op==27)
        {
            main();
        }
        else{
            password();
        }
        
    }
}

void books :: admin(){
    system("cls");
    system("color 0A");
    char op;
    cout<<"Choose an action: \n";
    cout<<"1-Show all books \n";
    cout<<"2-Search by ID \n";
    cout<<"3-Search by title \n";
    cout<<"4-Search by auther \n";
    cout<<"5-Choose category \n";
    cout<<"6-Add book data \n";
    cout<<"7-Remove book data \n";
    cout<<"8-Modify book data \n";
    cout<<"Esc-Back to main menu \n";
    op=getch();
    switch(op){
        case '1':{
            obj.display_books();
            break;
        }
        case '2':{
            obj.sbytitle();
            break;
        }
        case '3':{
            obj.sbytitle();
            break;
        }
        case '4':{
            obj.sbyauther();
            break;
        }
        case '5':{
            obj.sbycategory();
            break;
        }
        case '6':{
            obj.add_book();
            break;
        }
        case '7':{
            obj.remove_book();
            break;
        }
        case '8':{
            obj.modify_book();
            break;
        }
        case 27:{
            main();
            break;
        }
    }
}

void books :: display_books(){
    system("cls");
    ifstream book("book data.vsc");
    cout<<setw(10)<<"Book ID"<<setw(35)<<"Title"<<setw(20)<<"Auther"<<setw(15)<<"Category"<<endl;
    getline(book,id,'\t');
    getline(book,title,'\t');
    getline(book,auther,'\t');
    getline(book,category,'\n');
    while(!book.eof()){
        cout<<setw(10)<<id<<setw(35)<<truncate(title,34)<<setw(20)<<auther<<setw(15)<<category<<endl;
        getline(book,id,'\t');
        getline(book,title,'\t');
        getline(book,auther,'\t');
        getline(book,category,'\n');
    }
    book.close();
}

void books :: sbyid(){
    system("cls");
    cout<<"Enter book ID:\t";
    getline(cin,search);
    ifstream book("book data.vsc");
    cout<<setw(10)<<"Book ID"<<setw(35)<<"Title"<<setw(20)<<"Auther"<<setw(15)<<"Category"<<endl;
    do{
        getline(book,id,'\t');
        getline(book,title,'\t');
        getline(book,auther,'\t');
        getline(book,category,'\n');
        if(id==search){
            cout<<setw(10)<<id<<setw(35)<<truncate(title,34)<<setw(20)<<auther<<setw(15)<<category<<endl;
            break;
        }
    }while(!book.eof());
    book.close();
}

void books :: sbytitle(){
   system("cls");
    cout<<"Enter title:\t";
    getline(cin,search);
    ifstream book("book data.vsc");
    cout<<setw(10)<<"Book ID"<<setw(35)<<"Title"<<setw(20)<<"Auther"<<setw(15)<<"Category"<<endl;
    do{
        getline(book,id,'\t');
        getline(book,title,'\t');
        getline(book,auther,'\t');
        getline(book,category,'\n');
        if(title==search){
            cout<<setw(10)<<id<<setw(35)<<truncate(title,34)<<setw(20)<<auther<<setw(15)<<category<<endl;
        }
    }while(!book.eof());
    book.close();
}

void books :: sbyauther(){
    system("cls");
    cout<<"Enter auther name:\t";
    getline(cin,search);
    ifstream book("book data.vsc");
    cout<<setw(10)<<"Book ID"<<setw(35)<<"Title"<<setw(20)<<"Auther"<<setw(15)<<"Category"<<endl;
    do{
        getline(book,id,'\t');
        getline(book,title,'\t');
        getline(book,auther,'\t');
        getline(book,category,'\n');
        if(auther==search){
            cout<<setw(10)<<id<<setw(35)<<truncate(title,34)<<setw(20)<<auther<<setw(15)<<category<<endl;
        }
    }while(!book.eof());
    book.close();
}

void books :: sbycategory(){
    system("cls");
    cout<<"Enter category:\t";
    getline(cin,search);
    ifstream book("book data.vsc");
    cout<<setw(10)<<"Book ID"<<setw(35)<<"Title"<<setw(20)<<"Auther"<<setw(15)<<"Category"<<endl;
    do{
        getline(book,id,'\t');
        getline(book,title,'\t');
        getline(book,auther,'\t');
        getline(book,category,'\n');
        if(category==search){
            cout<<setw(10)<<id<<setw(35)<<truncate(title,34)<<setw(20)<<auther<<setw(15)<<category<<endl;
        }
    }while(!book.eof());
    book.close();
}

void books :: add_book(){
    system("cls");
    ofstream book ("book data.vsc", ios::app);
        cout<<"Enter book ID: ";
        getline(cin,id);
        cout<<"Enter book title: ";
        getline(cin,title);
        cout<<"Enter book auther: ";
        getline(cin,auther);
        cout<<"Enter book category: ";
        getline(cin,category);
        book<<id<<"\t"<<title<<"\t"<<auther<<"\t"<<category<<endl;
        cout<<"Book added "<<endl;
        cout<<"press Esc to return to main menu \nor any button to continue adding books..."<<endl;
        if(getch()==27){
            obj.admin();
        }
        else{
            obj.add_book();
        }
    book.close();
}

void books :: remove_book(){
    vector<string>idv,titlev,autherv,categoryv;
    ifstream book("book data.vsc");
    for(int i=0;!book.eof();i++){
        getline(book,id,'\t');
        getline(book,title,'\t');
        getline(book,auther,'\t');
        getline(book,category,'\n');
        idv.push_back(id);
        titlev.push_back(title);
        autherv.push_back(auther);
        categoryv.push_back(category);
    }
    book.close();

    cout<<"Enter ID of book to be removed: ";
    cin>>search;
    ofstream book2("book data.vsc");
    for(int i = 0; i<idv.size() ; i++)
    {
        if (idv[i]!=search)
        {
            if (book2.tellp()==0)
            {
            book2<<idv[i]<<"\t"<<titlev[i]<<"\t"<<autherv[i]<<"\t"<<categoryv[i]<<endl;
            }else{
            book2<<endl<<idv[i]<<"\t"<<titlev[i]<<"\t"<<autherv[i]<<"\t"<<categoryv[i];
            }
        }
        else{
            continue;
        }
    }
    book2.close();
    cout<<"Books removed"<<endl;
}
void books :: modify_book(){
    
}

string books :: truncate(string str,int size){
    if(str.length()>size){
       return str.substr(0,31)+"...";
    }
    else{
       return str;
    }
}

void books :: sort(){

}