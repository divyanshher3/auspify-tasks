#include <iostream>
#include<vector>
#include<string>
using namespace std;

 
//creating a structer named student as datatype
struct student {
    int id;
    string name;
    int age;
    string course;
};
//add function to add the student
void addstd(vector<student>& students){
    student s;

    cout<<"enter the Id of the srtudent "<<endl;
    cin>> s.id;
    //checking if id already exist 
    for(const student& st : students){
        if(st.id == s.id){
            cout<<"id already exits\n "<<endl;
            return ; 
        }
    }

    cout<<"enter the name of the student "<<endl;
    getline(cin >> ws, s.name);

    cout<<"enter the age "<<endl;
    cin>>s.age;

    cout<<"enter the course of the student "<<endl;
    getline(cin >> ws, s.course);

    //adding in vector
    students.push_back(s);
    cout << "Student added successfully!\n";
}


void display(const vector<student>& students){
if(students.empty()){
    cout<<"no Student exits "<<endl;
    return;
}

for(const student& s : students){
    cout<<"\nStudent id ->"<<s.id<<endl;
    cout<<"\nStudent name ->"<<s.name<<endl;
    cout<<"\nStudent age ->"<<s.age<<endl;
    cout<<"\nStudent course ->"<<s.course<<endl;
    cout<<"----------------------------------------"<<endl;
}
}
void searchstd( vector<student>& students){
int id;
cout<<"enter student id to search "<<endl;
cin>>id;
for(const student& st : students){
    if(st.id ==id){
        cout<<"Student id ->"<<st.id<<endl;
        cout<<"Student name ->"<<st.name<<endl;
        cout<<"Student age ->"<<st.age<<endl;
        cout<<"Student course ->"<<st.course<<endl;
        return;
    }

   }
    cout<<"student not found "<<endl;
        
}
void updatestd(vector<student>& students){
int id;
cout<<"enter the id of the student to update its record "<<endl;
cin>>id;
for(student& st : students){
    if(st.id==id){
    cout<<"Update the name :"<<endl;
    getline(cin>>ws, st.name);
     
    cout<<"Enter new age "<<endl;
    cin>>st.age;
    
    cout<<"Enter the course "<<endl;
    getline(cin >> ws, st.course);

    cout<<"update successfully !"<<endl;
    return;
    }
}

cout<<"Id does not exists "<<endl;
}

void deleteid(vector<student>&   students){
int id ;
cout<<"Enter the id of the stuednt to delete "<<endl;
cin>>id;


    for(auto stud = students.begin() ; stud != students.end() ; stud++ ){
        if(stud->id == id){
            students.erase(stud);
            cout<<"Student record deleted successfully !"<<endl;
            return ;
        }
    }
    cout<<"Student not found !"<<endl;
}
 
int main() {
    vector<student> std;
    int n;
    
    while(true){
    cout<<"===== Student Management System ====="<<endl;
        cout<<"1. Add Student"<<endl
               <<"2. Display All Students"<<endl
               <<"3. Search Student"<<endl
               <<"4. Update Student"<<endl
               <<"5. Delete Student"<<endl
               <<"6. Exit "<<endl;
    cout<<"enter your coice "<<endl;
    cin>>n;
    switch (n)
    {
    case 1:{
        addstd(std);
        break;
    }
    case 2:{
        display(std);
      break;
    }
    case 3:{
        searchstd(std);
        break;
    }
    case 4:{
        updatestd(std);
        break;
    }
    case 5:{
        deleteid(std);
        break;
    }
    case 6:{
        return 0 ;
        
    }
    default:
        cout<<"Invalid choice. Please enter a number from 1 to 6."<<endl;
        break;
    }

}
}