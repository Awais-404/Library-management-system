#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class books{
    string id,title,auther;
    public:
    display_books();
    sbytitle();
    sbyauther();
    sbycategory();
    admin();
}obj;

main(){
    cout<<"Choose an action: \n
    1-Show all books \n
    2-Search by title \n
    3-Search by auther \n
    4-Choose category \n
    5-ADMIN control \n
    6-Exit program \n";
    switch(op){
        case 1{
            display_books();
        }
        case 2{
            sbytitle();
        }
        case 3{
            sbyauther();
        }
        case 4{
            sbycategory();
        }
        case 5{
            admin();
        }
        case 6{
            return 0;
        }
    }

return 0;
}