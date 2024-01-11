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
            break;
        }
        case 2:{
            obj.sbytitle();
            break;
        }
        case 3:{
            obj.sbytitle();
            break;
        }
        case 4:{
        obj.sbyauther();
            break;
        }
        case 5:{
            obj.sbycategory();
            break;
        }
        case 6:{
            obj.add_book();
            break;
        }
        case 7:{
            obj.remove_book();
            break;
        }
        case 8:{
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
    
}
void books :: remove_book(){
    
}
void books :: modify_book(){
    
}