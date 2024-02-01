#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <conio.h>
using namespace std;

class books{
    string id,title,auther,category,search,pass;
    vector<string>idv,titlev,autherv,categoryv;
    bool found;
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
    string truncate(string str, int size);
    string set_case(string, string);
    void sort();
    void get_data();
    void get_data(string);
    bool checkID(string);

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
            obj.get_data();
            obj.sbyid();
            break;
        }
        case '3':{
             obj.get_data();
            obj.sbytitle();
            break;
        }
        case '4':{
             obj.get_data();
            obj.sbyauther();
            break;
        }
        case '5':{
             obj.get_data();
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
        default:{
            main();
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
    cout<<"\t\t\t"<<setw(30)<<"Esc-To exit ADMIN menu \n";
    op=getch();
    switch(op){
        case '1':{
            obj.display_books();
            break;
        }
        case '2':{
            get_data();
            obj.sbyid();
            break;
        }
        case '3':{
             obj.get_data();
            obj.sbytitle();
            break;
        }
        case '4':{
             obj.get_data();
            obj.sbyauther();
            break;
        }
        case '5':{
             obj.get_data();
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
        default:{
            admin();
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
    cout<<endl;
    cout<<"\t"<<setw(30)<<"1-Search by ID"<<"2-Search by title \n";
    cout<<"\t"<<setw(30)<<"3-Search by auther"<<"4-Choose category \n";
    cout<<"\t"<<setw(30)<<"Esc-Return to main menu \n";
    char op;
    op=getch();
    switch(op){
        case '1':{
            get_data();
            sbyid();
            break;
        }
        case '2':{
            get_data();
            sbytitle();
            break;
        }
        case '3':{
            get_data();
            sbyauther();
            break;
        }
        case '4':{
            get_data();
            sbycategory();
            break;
        }
        case 27:{
            if (mode==1){
                main();
            }
            else{
                admin();
            }
            break;
        }
        default:{
            display_books();
        }

    }
}

void books :: sbyid(){
    system("cls");
    cout<<"Enter book ID:\n\t";
    getline(cin,search);
    cout<<setw(10)<<"Book ID"<<setw(40)<<"Title"<<setw(20)<<"Auther"<<setw(15)<<"Category"<<endl;
    for (int i = 0; i < idv.size(); i++)
    {
        if (idv[i]==search){
            cout<<setw(10)<<idv[i]<<setw(40)<<truncate(titlev[i],38)<<setw(20)<<autherv[i]<<setw(15)<<categoryv[i]<<endl;
            found=true;
            break;
        }
        else{
            continue;
        }
        
    }
    cout<<endl;
    if (!found)
    {
        cout<<"This ID does not exist"<<endl;
    }
    
    cout<<"press Esc to return to main menu \nor any button to search for another book..."<<endl;
        if(getch()==27){
            if (mode==1){
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
    cout<<"Enter title:\n\t";
    getline(cin,search);
    search=set_case(search,"first");
    cout<<setw(10)<<"Book ID"<<setw(40)<<"Title"<<setw(20)<<"Auther"<<setw(15)<<"Category"<<endl;
    for (int i = 0; i < idv.size(); i++)
    {
        if (titlev[i]==search){
            cout<<setw(10)<<idv[i]<<setw(40)<<truncate(titlev[i],38)<<setw(20)<<autherv[i]<<setw(15)<<categoryv[i]<<endl;
            found=true;
            break;
        }
        else{
            continue;
        }
        
    }
    cout<<endl;
    if (!found)
    {
        cout<<"This title does not exist"<<endl;
    }
    cout<<"press Esc to return to main menu \nor any button to search for another book..."<<endl;
        if(getch()==27){
            if (mode==1){
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
    cout<<"Enter auther name:\n\t";
    getline(cin,search);
    search=set_case(search,"each");
    cout<<setw(10)<<"Book ID"<<setw(40)<<"Title"<<setw(20)<<"Auther"<<setw(15)<<"Category"<<endl;
    for (int i = 0; i < idv.size(); i++)
    {
        if (autherv[i]==search){
            cout<<setw(10)<<idv[i]<<setw(40)<<truncate(titlev[i],38)<<setw(20)<<autherv[i]<<setw(15)<<categoryv[i]<<endl;
            found=true;
            break;
        }
        else{
            continue;
        }
        
    }
    cout<<endl;
    if (!found)
    {
        cout<<"This auther does not exist"<<endl;
    }
    cout<<"press Esc to return to main menu \nor any button to search for another auther..."<<endl;
        if(getch()==27){
            if (mode==1){
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
    cout<<"Enter category:\n\t";
    getline(cin,search);
    search=set_case(search,"first");
    cout<<setw(10)<<"Book ID"<<setw(40)<<"Title"<<setw(20)<<"Auther"<<setw(15)<<"Category"<<endl;
    for (int i = 0; i < idv.size(); i++)
    {
        if (categoryv[i]==search){
            cout<<setw(10)<<idv[i]<<setw(40)<<truncate(titlev[i],38)<<setw(20)<<autherv[i]<<setw(15)<<categoryv[i]<<endl;
            found=true;
            break;
        }
        else{
            continue;
        }
        
    }
    cout<<endl;
    if (!found)
    {
        cout<<"This category does not exist press, 'Esc' to return to menu \nOr any buttton to choose another category \n"<<endl;
        int a=getch();
        if(a=27){
            if (mode==1){
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
    else{
        cout<<"Search in this category";
        cout<<"\t"<<setw(30)<<"1-Search by ID"<<"2-Search by title \n";
        cout<<"\t"<<setw(30)<<"3-Search by auther"<<"Esc-Return to main menu \n";
        cout<<"\t"<<setw(30)<<"Or any buttton to choose another category \n";
        char op;
        op=getch();
        switch(op){
            case '1':{
                get_data(search);
                sbyid();
                break;
            }
            case '2':{
                get_data(search);
                sbytitle();
                break;
            }
            case '3':{
                get_data(search);
                sbyauther();
                break;
            }
            case 27:{
                if (mode==1){
                    main();
                }
                else{
                    admin();
                }
                break;
            }
            default:{
                sbycategory();
            }

        }
    }
}

void books :: add_book(){
    system("cls");
    ofstream book ("book data.vsc", ios::app);
        cout<<"Enter book ID: \n\t";
        getline(cin,id);
        if (checkID(id)){
            cout<<"This ID already exist, please enter another Id \n press any key to comtinue";
            getch();
            add_book();
        }
        
        cout<<"Enter book title: \n\t";
        getline(cin,title);
        title=set_case(title,"first");
        cout<<"Enter book auther: \n\t";
        getline(cin,auther);
        auther=set_case(auther,"each");
        cout<<"Enter book category: \n\t";
        getline(cin,category);
        category=set_case(category,"first");
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
    cout<<endl;
    get_data();
    cout<<"Enter ID of book to be removed: \n\t";
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
    cout<<endl;
    get_data();
    cout<<"Enter ID of book to be modified: \n\t";
    cin>>search;
    for (int i = 0; i < idv.size(); i++)
    {
        if (idv[i]==search)
        {
            getline(cin,search);
            cout<<endl;
            cout<<"Enter book ID: \n\t";
            getline(cin,idv[i]);
            cout<<"Enter book title: \n\t";
            getline(cin,title);
            title[0]=toupper(title[0]);
            titlev[i]=title;
            cout<<"Enter book auther: \n\t";
            getline(cin,autherv[i]);
            cout<<"Enter book category: \n\t";
            getline(cin,categoryv[i]);
        }
        
    }
    
    ofstream book2("book data.vsc");
    for(int i = 0; i<idv.size() ; i++)
    {
        book2<<idv[i]<<"\t"<<titlev[i]<<"\t"<<autherv[i]<<"\t"<<categoryv[i]<<endl;
    }
    book2.close();

    sort();
    
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

void books :: get_data(string categorys){
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
        if (category==categorys){
            idv.push_back(id);
            titlev.push_back(title);
            autherv.push_back(auther);
            categoryv.push_back(category);
        }
    }
    book.close();
    idv.pop_back();
    titlev.pop_back();
    autherv.pop_back();
    categoryv.pop_back();
}

bool books :: checkID(string id){
    get_data();
    for (int i = 0; i < idv.size(); i++)
    {
        if (search==idv[i])
        {
            return true;
        }
        
    }
    
    
}

string books :: set_case(string str,string case_type){
   if (case_type == "first")
   {
      str[0]=toupper(str[0]);
      for (int i = 1; i < str.length(); i++){
         str[i]=tolower(str[i]);
      }
      return str;
   }
   else if(case_type == "each"){
      for (int i = 0; i < str.length(); i++)
      {
         if (i==0 || str[i-1]==' ' || str[i-1]=='.'){
            str[i]=toupper(str[i]);
         }
         else{
            str[i]=tolower(str[i]);
         }
      }
      return str;
   }
   else if(case_type == "lower"){
      for (int i = 0; i < str.length(); i++)
      {
         str[i]=tolower(str[i]);
      }
      return str;
   }
   
   return str;
}