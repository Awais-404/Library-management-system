#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <conio.h>
using namespace std;

class books{
    string id,title,auther,category,search;
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
    string truncate(string str,int size);
    void sort();
}obj;

int main(){
    system("cls");
    system("color 0A");
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
            obj.admin();
            break;
        }
        case 27:{
            return 0;
        }

    }

    return 0;
}

void books :: admin(){
    system("cls");
    system("color 09");
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
    ifstream book("computer.vsc");
    cout<<setw(8)<<"Book ID"<<setw(30)<<"Title"<<setw(20)<<"Auther"<<setw(15)<<"Category"<<endl;
    do{
        getline(book,id,'\t');
        getline(book,title,'\t');
        getline(book,auther,'\t');
        getline(book,category,'\n');
        cout<<setw(8)<<id<<setw(30)<<truncate(title,29)<<setw(20)<<auther<<setw(15)<<category<<endl;
    }while(!book.eof());
    book.close();
}

void books :: sbyid(){
    system("cls");
    cout<<"Enter book ID ";
    getline(cin,search);
    ifstream book("computer.vsc");
    cout<<setw(8)<<"Book ID"<<setw(30)<<"Title"<<setw(20)<<"Auther"<<setw(15)<<"Category"<<endl;
    do{
        getline(book,id,'\t');
        getline(book,title,'\t');
        getline(book,auther,'\t');
        getline(book,category,'\n');
        if(id==search){
            cout<<setw(8)<<id<<setw(30)<<truncate(title,29)<<setw(20)<<auther<<setw(15)<<category<<endl;
            break;
        }
    }while(!book.eof());
    book.close();
}

void books :: sbytitle(){
   string tit;
    cout<<"Please enter the title"<<endl;
//     ifstream book("computer.vsc");
//    while(getline(book.end!=true)){
//     if(title==tit){
//          cout<<id<<"\t";
//         cout<<title<<"\t";
//         cout<<auther<<"\t";
//         cout<<category<<endl;
//         break;
//     }
//    }
//    book.close();
}

void books :: sbyauther(){
    string aut;
    cout<<"Please enter the auther name"<<endl;
//     ifstream book("computer.vsc");
//    while(getline(book.end!=true)){
//     if(auther==aut){
//          cout<<id<<"\t";
//             cout<<title<<"\t";
//             cout<<auther<<"\t";
//             cout<<category<<endl;
//             break;
//     }
//    }
//    book.close();
}

void books :: sbycategory(){
    system("cls");
    cout<<"Enter category ";
    getline(cin,search);
    ifstream book("computer.vsc");
    cout<<setw(8)<<"Book ID"<<setw(30)<<"Title"<<setw(20)<<"Auther"<<setw(15)<<"Category"<<endl;
    do{
        getline(book,id,'\t');
        getline(book,title,'\t');
        getline(book,auther,'\t');
        getline(book,category,'\n');
        if(category==search){
            cout<<setw(8)<<id<<setw(30)<<title<<setw(20)<<auther<<setw(15)<<category<<endl;
        }
    }while(!book.eof());
    book.close();
}

void books :: add_book(){
    system("cls");
    ofstream book ("computer.vsc", ios::app);
    while(true){
        cout<<"Enter book ID: ";
        getline(cin,id);
        cout<<"Enter book title: ";
        getline(cin,title);
        cout<<"Enter book auther: ";
        getline(cin,auther);
        cout<<"Enter book category: ";
        getline(cin,category);
        book<<"\n"<<id<<"\t"<<title<<"\t"<<auther<<"\t"<<category;
        cout<<"Book added "<<endl;
        cout<<"press Esc to return to main menu \nor any button to continue adding books...";
        if(getch()==27){
            obj.admin();
        }
        else{
        }
    }
    book.close();
}

void books :: remove_book(){
    
}
void books :: modify_book(){
    
}

string books :: truncate(string str,int size){
    if(str.length()>size){
       return str.substr(0,36)+"...";
    }
    else{
       return str;
    }
}

void books :: sort(){

}