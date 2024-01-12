#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;

class books{
    string id,title,auther,category;
    public:
    void display_books();
    void sbyid();
    void sbytitle();
    void sbyauther();
    void sbycategory();
    void admin();
    void add_book();
    void remove_book();
    void modify_book();
}obj;

int main(){
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
            obj.admin();
            break;
        }
        case 27:{
            return 0;
        }

    }

    return 0;
}

void books :: display_books(){
    string file;
    ifstream book("computer.vsc");
    while(getline(book,file)){
    cout<<file;

    }
    book.close();
}

void books :: sbyid(){
    string sid;
    cout<<"Enter book ID ";
    getline(cin,sid);
    ifstream book("computer.vsc");
    do{
        getline(book,id,"\t");
        getline(book,title,"\t");
        getline(book,auther,"\t");
        getline(book,category,"\n");
        if(id==sid){
            cout<<id<<"\t";
            cout<<title<<"\t";
            cout<<auther<<"\t";
            cout<<category<<endl;
            break;
        }
    }while(book.end!=true);
    book.close();
}

void books :: sbytitle(){
   string tit;
    cout<<"Please enter the title"<<endl;
    ifstream book("computer.vsc")
   while(getline(book.end!=true)){
    if(title==tit){
         cout<<id<<"\t";
        cout<<title<<"\t";
        cout<<auther<<"\t";
        cout<<category<<endl;
        break;
    }
   }
   book.close();
}

void books :: sbyauther(){
    string aut;
    cout<<"Please enter the auther name"<<endl;
    ifstream book("computer.vsc")
   while(getline(book.end!=true)){
    if(auther==aut){
         cout<<id<<"\t";
            cout<<title<<"\t";
            cout<<auther<<"\t";
            cout<<category<<endl;
            break;
    }
   }
   book.close();
}

void books :: sbycategory(){
    string scat;
    cout<<"Enter book ID ";
    getline(cin,scat);
    ifstream book("computer.vsc");
    do{
        getline(book,id,"\t");
        getline(book,title,"\t");
        getline(book,auther,"\t");
        getline(book,category,"\n");
        if(category==scat){
            cout<<id<<"\t";
            cout<<title<<"\t";
            cout<<auther<<"\t";
            cout<<category<<endl;
            break;
        }
    }while(book.end!=true);
    book.close();
}

void books :: admin(){
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

void books :: add_book(){
    getline(cin,id);
    getline(cin,title);
    getline(cin,auther);
    getline(cin,category);
    ofstream book (category+"computer.vsc", ios::app);
    book<<id<<"\t"<<title<<"\t"<<auther<<"\t"<<category<<endl;
    
}

void books :: remove_book(){
    
}
void books :: modify_book(){
    
}