#include <iostream> 
#include<vector>
#include<string>
using namespace std;

struct library{
    int id;
    string Bookname;
    bool BookIssueed = false;
};
void addbook(vector<library>& librarys){
    library l;
    cout<<"Enter the ID "<<endl;
    cin>>l.id;

    for(const library lb : librarys){
        if(lb.id == l.id){
            cout<<"ID already exist !"<<endl;
            return ;
        }
    }

    cout<<"Enter the name of the book "<<endl;
    getline(cin>>ws , l.Bookname);

    librarys.push_back(l);
}
void Displaybook(vector<library>& librarys){
    if(librarys.empty()){
    cout<<"Library is empty !"<<endl;
    }

    for(const library lb : librarys){
            cout<<"Book ID -> "<<lb.id<<endl;
            cout<<"Book name -> "<<lb.Bookname<<endl;
            cout<<" Issued ->" <<lb.BookIssueed<<endl;
            cout<<"-----------------------------------"<<endl;
            
    }
    cout<<"book ID not found"<<endl;
    return;
}
void Searchbook(vector<library>& librarys){
int id;
    cout<<"enter the ID of the book "<<endl;
    cin>>id;
    for(const library lb : librarys){
        if(lb.id == id){
            cout<<"Book ID -> "<<lb.id<<endl;
            cout<<"Book name -> "<<lb.Bookname<<endl;
            return;
        }
    }
    cout<<"book ID not found"<<endl;
}
void Removebook(vector<library>& librarys){
int id;
    cout<<"enter the ID of the book "<<endl;
    cin>>id;

    for(auto lb =librarys.begin() ; lb != librarys.end() ; lb++){
        if(lb->id == id && lb->BookIssueed!=true){
            librarys.erase(lb);
            cout<<"book removed Successfully !"<<endl;
            return;
        }
    }
    cout<<"Id don't match with any book "<<endl;

}
void BookIssue(vector<library>& librarys){
    int id;
    cout<<"enter the ID of the book "<<endl;
    cin>>id;

    for(library& ls : librarys){
        if(ls.id == id){
            if(ls.BookIssueed == true){
                cout<<"Book already issued by someone !"<<endl;
                return;
            }
            else{
            ls.BookIssueed = true;
            return;
            }
        }
    }
    cout<<"ID don't exist "<<endl;
}
void  BookRetrun(vector<library>& librarys){
     int id;
    cout<<"enter the ID of the book "<<endl;
    cin>>id;

    for(library& ls : librarys){
        if(ls.id == id){
            if(ls.BookIssueed == false){
                cout<<"Book already returned !"<<endl;
                return;
            }
            else{
            ls.BookIssueed = false;
            return;
            }
        }
    }
    cout<<"ID don't exist or book has been issued by someone"<<endl;
}


int main() {
    vector<library> lib;
    int n;
    while(true){
        cout<<"===== Library Management System ====="<<endl;
            cout<<"1. Add Book"<<endl
               <<"2. Display All Books"<<endl
               <<"3. Search book"<<endl
               <<"4. Remove book"<<endl
               <<"5. Book Issue"<<endl
               <<"6. Book Retrun"<<endl
               <<"7. Exit "<<endl;
        cin>>n;

        switch (n)
        {
        case 1:{
            addbook(lib);
            break;
        }
        case 2:{
            Displaybook(lib);
            break;
        }
        case 3:{
            Searchbook(lib);
            break;
        }
        case 4:{
            Removebook(lib);
            break;
        }
        case 5:{
            BookIssue(lib);
            break;
        }
        case 6:{
            BookRetrun(lib);
            break;
        }
        case 7:{
            return 0 ;
            break;
        }
        default:{
            break;
        }
        }
    }   
    return 0;
}