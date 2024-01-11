#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
using namespace std;

class books{
    string id,title,auther;
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
        case 1:{
            obj.display_books();
        }
        case 2:{
            obj.sbyid();
        }
        case 3:{
            obj.sbytitle();
        }
        case 4:{
        obj.sbyauther();
        }
        case 5:{
            obj.sbycategory();
        }
        case 6:{
            obj.admin();
        }
        case 27:{
            return 0;
        }
    }

    return 0;
}

void books :: display_books(){

}

void books :: sbyid(){
    
}

void books :: sbytitle(){
    
}

void books :: sbyauther(){
    
}

void books :: sbycategory(){
    
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
        case 1:{
            obj.display_books();
        }
        case 2:{
            obj.sbytitle();
        }
        case 3:{
            obj.sbytitle();
        }
        case 4:{
        obj.sbyauther();
        }
        case 5:{
            obj.sbycategory();
        }
        case 6:{
            obj.add_book();
        }
        case 7:{
            obj.remove_book();
        }
        case 8:{
            obj.modify_book();
        }
        case 27:{
            main();
        }
    }
}

void books :: add_book(){
    
}
void books :: remove_book(){
    
}
void books :: modify_book(){
    
}