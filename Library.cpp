#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <conio.h>
using namespace std;

class books{
    string id,title,auther,category,search,pass;
    vector<string>idv,titlev,autherv,categoryv;
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
    void get_data();
}obj;

    int mode;
int main(){
    mode=1;
    system("cls");
    system("color 0B");
    cout<<left;
    cout<<"\t\t================================================================"<<endl;
    cout<<"\t\t                            LIBRARY                             "<<endl;
    cout<<"\t\t================================================================"<<endl;
    char op;
    cout<<"\t\t\t\t\t"<<"Choose an action \n";
    cout<<"\t\t\t"<<setw(30)<<"1-Show all books"<<"2-Search by ID \n";
    cout<<"\t\t\t"<<setw(30)<<"3-Search by title"<<"4-Search by auther \n";
    cout<<"\t\t\t"<<setw(30)<<"5-Choose category"<<"6-ADMIN control \n";
    cout<<"\t\t\t"<<"Esc-Exit program \n";
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
    if(pass=="123"){
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
    mode=2;
    system("cls");
    system("color 0A");
    cout<<"\t\t================================================================"<<endl;
    cout<<"\t\t                            LIBRARY                             "<<endl;
    cout<<"\t\t================================================================"<<endl;
    char op;
    cout<<"\t\t\t\t\t"<<"Choose an action \n";
    cout<<"\t\t\t"<<setw(30)<<"1-Show all books"<<"2-Search by ID \n";
    cout<<"\t\t\t"<<setw(30)<<"3-Search by title"<<"4-Search by auther \n";
    cout<<"\t\t\t"<<setw(30)<<"5-Choose category"<<"6-Add book data \n";
    cout<<"\t\t\t"<<setw(30)<<"7-Remove book data"<<"8-Modify book data \n";
    cout<<"\t\t\t"<<setw(30)<<"Esc-Back to main menu \n";
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
    cout<<setw(10)<<"Book ID"<<setw(40)<<"Title"<<setw(20)<<"Auther"<<setw(15)<<"Category"<<endl;
    getline(book,id,'\t');
    getline(book,title,'\t');
    getline(book,auther,'\t');
    getline(book,category,'\n');
    while(!book.eof()){
        cout<<setw(10)<<id<<setw(40)<<truncate(title,38)<<setw(20)<<auther<<setw(15)<<category<<endl;
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
    cout<<setw(10)<<"Book ID"<<setw(40)<<"Title"<<setw(20)<<"Auther"<<setw(15)<<"Category"<<endl;
    do{
        getline(book,id,'\t');
        getline(book,title,'\t');
        getline(book,auther,'\t');
        getline(book,category,'\n');
        if(id==search){
            cout<<setw(10)<<id<<setw(40)<<truncate(title,38)<<setw(20)<<auther<<setw(15)<<category<<endl;
            break;
        }
    }while(!book.eof());
    book.close();
    cout<<endl;
    cout<<"press Esc to return to main menu \nor any button to search for another book..."<<endl;
        if(getch()==27){
            if (mode=1){
                main();
            }
            else{
                admin();
            }
        }
        else{
            sbyid();
        }
}

void books :: sbytitle(){
   system("cls");
    cout<<"Enter title:\t";
    getline(cin,search);
    ifstream book("book data.vsc");
    cout<<setw(10)<<"Book ID"<<setw(40)<<"Title"<<setw(20)<<"Auther"<<setw(15)<<"Category"<<endl;
    do{
        getline(book,id,'\t');
        getline(book,title,'\t');
        getline(book,auther,'\t');
        getline(book,category,'\n');
        if(title==search){
            cout<<setw(10)<<id<<setw(40)<<truncate(title,38)<<setw(20)<<auther<<setw(15)<<category<<endl;
        }
    }while(!book.eof());
    book.close();
    cout<<endl;
    cout<<"press Esc to return to main menu \nor any button to search for another book..."<<endl;
        if(getch()==27){
            if (mode=1){
                main();
            }
            else{
                admin();
            }
        }
        else{
            sbytitle();
        }
}

void books :: sbyauther(){
    system("cls");
    cout<<"Enter auther name:\t";
    getline(cin,search);
    ifstream book("book data.vsc");
    cout<<setw(10)<<"Book ID"<<setw(40)<<"Title"<<setw(20)<<"Auther"<<setw(15)<<"Category"<<endl;
    do{
        getline(book,id,'\t');
        getline(book,title,'\t');
        getline(book,auther,'\t');
        getline(book,category,'\n');
        if(auther==search){
            cout<<setw(10)<<id<<setw(40)<<truncate(title,38)<<setw(20)<<auther<<setw(15)<<category<<endl;
        }
    }while(!book.eof());
    book.close();
    cout<<endl;
    cout<<"press Esc to return to main menu \nor any button to search for another book..."<<endl;
        if(getch()==27){
            if (mode=1){
                main();
            }
            else{
                admin();
            }
        }
        else{
            sbyauther();
        }
}

void books :: sbycategory(){
    system("cls");
    cout<<"Enter category:\t";
    getline(cin,search);
    ifstream book("book data.vsc");
    cout<<setw(10)<<"Book ID"<<setw(40)<<"Title"<<setw(20)<<"Auther"<<setw(15)<<"Category"<<endl;
    do{
        getline(book,id,'\t');
        getline(book,title,'\t');
        getline(book,auther,'\t');
        getline(book,category,'\n');
        if(category==search){
            cout<<setw(10)<<id<<setw(40)<<truncate(title,38)<<setw(20)<<auther<<setw(15)<<category<<endl;
        }
    }while(!book.eof());
    book.close();
    cout<<endl;
    cout<<"press Esc to return to main menu \nor any button to search for another book..."<<endl;
        if(getch()==27){
            if (mode=1){
                main();
            }
            else{
                admin();
            }
        }
        else{
            sbycategory();
        }
}

void books :: add_book(){
    system("cls");
    ofstream book ("book data.vsc", ios::app);
        cout<<"Enter book ID: ";
        getline(cin,id);
        cout<<"Enter book title: ";
        getline(cin,title);
        title[0]=toupper(title[0]);
        cout<<"Enter book auther: ";
        getline(cin,auther);
        cout<<"Enter book category: ";
        getline(cin,category);
        book<<id<<"\t"<<title<<"\t"<<auther<<"\t"<<category<<endl;
        cout<<"Book added "<<endl;
        book.close();
        sort();
        cout<<"press Esc to return to main menu \nor any button to continue adding books..."<<endl;
        if(getch()==27){
            obj.admin();
        }
        else{
            obj.add_book();
        }

}

void books :: remove_book(){
    get_data();

    cout<<"Enter ID of book to be removed: ";
    cin>>search;
    ofstream book2("book data.vsc");
    for(int i = 0; i<idv.size() ; i++)
    {
        if (idv[i]!=search)
        {
            book2<<idv[i]<<"\t"<<titlev[i]<<"\t"<<autherv[i]<<"\t"<<categoryv[i]<<endl;
        }
        else{
            continue;
        }
    }
    book2.close();
    cout<<"Books removed"<<endl;
    cout<<"press Esc to return to main menu \nor any button to continue removing books..."<<endl;
        if(getch()==27){
            obj.admin();
        }
        else{
            obj.remove_book();
        }
}
void books :: modify_book(){
    get_data();

    cout<<"Enter ID of book to be modified: ";
    cin>>search;
    for (int i = 0; i < idv.size(); i++)
    {
        if (idv[i]==search)
        {
            cout<<"Enter book ID: ";
            getline(cin,idv[i]);
            cout<<"Enter book title: ";
            getline(cin,titlev[i]);
            titlev[0]=toupper(titlev[0]);
            cout<<"Enter book auther: ";
            getline(cin,autherv[i]);
            cout<<"Enter book category: ";
            getline(cin,categoryv[i]);
        }
        
    }
    
    ofstream book2("book data.vsc");
    for(int i = 0; i<idv.size() ; i++)
    {
        book2<<idv[i]<<"\t"<<titlev[i]<<"\t"<<autherv[i]<<"\t"<<categoryv[i]<<endl;
    }
    book2.close();
    
    cout<<"Books modified"<<endl;
    cout<<"press Esc to return to main menu \nor any button to modify another book..."<<endl;
        if(getch()==27){
            obj.admin();
        }
        else{
            obj.modify_book();
        }
}

string books :: truncate(string str,int size){
    if(str.length()>size){
       return str.substr(0,size-3)+"...";
    }
    else{
       return str;
    }
}

void books :: sort(){
    get_data();

    int n= titlev.size();
    string temp;
   for (int i = 0; i < n; i++){
      for (int j = i+1; j < n; j++)
      {
         if (titlev[i]>titlev[j])
         {
            swap(idv[i],idv[j]);
            swap(titlev[i],titlev[j]);
            swap(autherv[i],autherv[j]);
            swap(categoryv[i],categoryv[j]);
         }  
      }
   }

   ofstream book2("book data.vsc");
    for(int i = 0; i<idv.size() ; i++)
    {
        book2<<idv[i]<<"\t"<<titlev[i]<<"\t"<<autherv[i]<<"\t"<<categoryv[i]<<endl;
    }
    book2.close();
}

void books :: get_data(){
    idv.clear();
    titlev.clear();
    autherv.clear();
    categoryv.clear();
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
    idv.pop_back();
    titlev.pop_back();
    autherv.pop_back();
    categoryv.pop_back();
}