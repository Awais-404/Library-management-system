#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class books{
    string id,title,auther;
    public:
    void display_books();
    void sbytitle();
    void sbyauther();
    void sbycategory();
    void admin();
}obj;

int main(){
    char op;
    cout<<"Choose an action: \n";
    cout<<"1-Show all books \n";
    cout<<"2-Search by title \n";
    cout<<"3-Search by auther \n";
    cout<<"4-Choose category \n";
    cout<<"5-ADMIN control \n";
    cout<<"Esc-Exit program \n";
    cin>>op;
    switch(op){
        case 1:{
            obj.display_books();
        }
        case 2:{
            obj.sbytitle();
        }
        case 3:{
        obj.sbyauther();
        }
        case 4:{
            obj.sbycategory();
        }
        case 5:{
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

void books :: sbytitle(){
    
}

void books :: sbyauther(){
    
}

void books :: sbycategory(){
    
}

void books :: admin(){
    
}
