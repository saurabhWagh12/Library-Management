#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Library{
    private:
    int bookcode;
    string bookname,authorname;
    int price;

    public:
    void menu();//done
    void administrator();//done
    void list();//done
    void add();//done
    void modify();//done
    void removal();//done
    void customer();//done
    void calculateRent();//done
};

int main(){
  Library l;
  l.menu();
  return 0;  
}

void Library::menu(){
  my:  
    cout<<"\n\n__________Welcome__________\n\n\n\n";
    cout<<"__________Menu page__________\n\n";
    // int choice;
    int choice;
    

    cout<<"press (1) if you are {Administrator}"<<endl;
    cout<<"press (2) if you are {Customer}"<<endl;
    cout<<"press (3) to {Exit}"<<endl<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;

    switch (choice)
    {
    case 2:{ //customer
         customer();
      break;
    }  

    case 1:{ //Administrator
        administrator();
        break;
    }
    case 3: //exit
    cout<<"\t\t\t\tThank you!!!\n\n\n";
    exit(0);
       
    default: system("cls"); 
        cout<<endl<<endl<<"Sorry Invalid Input, Please make a correct choice!!!"<<endl<<endl;
        goto my;
    }
}

void Library::administrator(){
    system("cls");
    int n;
    string email,password;

    cout<<"\n\n\n_____Welcome to Administrator Menu_____\n\n\n";
     cout<<"\n\n\n\t\tEnter e-mail id : ";
     cin>>email;
     cout<<"\n\n\n\t\tEnter password : ";
     cin>>password;
     if(email=="saurabhisbest123@gmail.com" && password=="SaurabhBoss!!!"){
        adminpart:
        system("cls");
        cout<<"\n\n\t\t\t_____Welcome Saurabh_____\n\n";
        cout<<"Press (1) to add a book : "<<endl;
        cout<<"Press (2) to remove a book : "<<endl;
        cout<<"Press (3) to modify a book : "<<endl;
        cout<<"Press (4) to see list of books : "<<endl;
        cout<<"Press (5) to Exit : \n\n";
        cout<<"Enter your choice here : ";
        cin>>n;

        switch (n){
        
        case 1:
            add();
            break;

        case 3:
            modify();
            break;    
        
        case 2:
            removal();
            break;

        case 4:
             list();
             break;      

        case 5:
            menu();    
            break;

        default:system("cls");
            cout<<"Sorry Invalid Input, Please make a correct choice !!!"<<endl;
            goto adminpart;
        }

     }
}

void Library::add(){
back:
    system("cls");
    fstream data;
    int bcode,cost,tocken=0;
    string bname,aname;
cout<<"\n\n\t\t\t\tEnter details of Book to add it:\n\n\n\n";
    cout<<"Enter Book Code : ";
    cin>>bookcode;
    cout<<"Enter Book Name : ";
    cin>>bookname;
    cout<<"Enter Author Name : ";
    cin>>authorname;
    cout<<"Enter price of book : ";
    cin>>price;

    data.open("library1.txt",ios::app|ios::out);
    if(!data){
        data<<bookcode<<" "<<bookname<<" "<<authorname<<" "<<price<<endl;
        data.close();
    }else{
        data>>bcode>>bname>>aname>>cost;
        while(!data.eof()){
            if(bcode==bookcode){
                tocken++;
            }
            data>>bcode>>bname>>aname>>cost;
        }
        data.close();

        if(tocken==1){
            goto back;
        }else{
            data.open("library1.txt",ios::app|ios::out);
            data<<bookcode<<" "<<bookname<<" "<<authorname<<" "<<price<<endl;
            data.close();
        }
    system("cls");
    cout<<"Record Inserted";

    int c;
again:
    cout<<"\n\n\nWant to add another book Press (1) "<<endl;
    cout<<"To Exit press (2) : "<<endl;
    cout<<"\n\nEnter your choice here : ";
    cin>>c;
    switch (c)
    {
    case 1:
        add();
        break;

    case 2:
        menu();
        break;    
    
    default: system("cls");
     cout<<"Invalid Input, Enter correct choice!!!";
        goto again;
    }

    
    }
}

void Library::removal(){
    system("cls");
    int bcode,tocken=0;
    fstream data,data1;

    cout<<"\n\n\n\t\t\t_____Removing Book_____\n\n\n\n";
    cout<<"Enter book code : ";
    cin>>bcode;
    data.open("library1.txt",ios::in);
    if(!data){
        system("cls");
        cout<<"File doesn't Exist!!!"<<endl<<endl;
    }else{
        data1.open("library2.txt",ios::app|ios::out);
        data>>bookcode>>bookname>>authorname>>price;
        while (!data.eof()){
            if(bcode==bookcode){
                system("cls");
                cout<<"\n\n\nBook Removed Sussessfully!!!\n\n\n";
            }else{
                data1<<" "<<bookcode<<" "<<bookname<<" "<<authorname<<" "<<price<<endl;
            }
        
        data>>bookcode>>bookname>>authorname>>price;
        }
        data.close(); data1.close();
        remove("library1.txt");
        rename("library2.txt","library1.txt");  

        if(tocken==0){
            system("cls");
            cout<<"\n\n\nRecord not found!!!\n\n\n";
        }
    }
    // administrator();
}

void Library::list(){
    // system("cls");
    fstream data;
    data.open("library1.txt",ios::in);
    cout<<"\n\n\n";
    cout<<"book code \t\t book name \t\t book price\n\n";
    data>>bookcode>>bookname>>authorname>>price;

    while(!data.eof()){
        cout<<" "<<bookcode<<"\t\t\t"<<bookname<<"\t\t\t"<<price<<endl;
        data>>bookcode>>bookname>>authorname>>price;
    }

    data.close();
    // menu();
}

void Library::modify(){
    system("cls");
    fstream data1,data;
    int bcode,b2code,cost,tocken=0;
    string bname,aname;
    cout<<"\n\n\n\t\t\t_____Modifying Book Record_____\n\n\n";
    cout<<"Enter Book Code : ";
    cin>>bcode;

    data.open("library1.txt",ios::in);
    if(!data){
        system("cls");
        cout<<"\n\n\nFile Doesn't Exist\n\n\n";
    }else{
        data1.open("library2.txt",ios::app|ios::out);
        
        data>>bookcode>>bookname>>authorname>>price;
        while(!data.eof()){
            if(bcode==bookcode){
                cout<<"Enter new Book code : ";
                cin>>b2code;
                cout<<"Enter name of book : ";
                cin>>bname;
                cout<<"Enter author name : ";
                cin>>aname;
                cout<<"Enter price of book : ";
                cin>>cost;

                data1<<b2code<<" "<<bname<<" "<<aname<<" "<<cost<<endl;
                cout<<"\n\n\nRecoed Edited\n\n";
                tocken++;
            }else{
                data1<<bookcode<<" "<<bookname<<" "<<authorname<<" "<<price<<endl;
            }

            data>>bookcode>>bookname>>authorname>>price;
        }

        data.close();
        data1.close();

        remove("library1.txt");
        rename("library2.txt","library1.txt");

        if(tocken==0){
            cout<<"\n\n\n Record not found\n\n\n";
        }
    }
    menu();
}

void Library::customer(){
    system("cls");
back:
    cout<<"\n\n\n__________Welcome to Our Library__________\n\n\n";
    cout<<"This is list of books we have in our library : \n\n";

    list();
    int n;
    cout<<"\n\n\nPress (1) to rent a book : ";
    cout<<"\nPress (2) to exit : "<<endl;
    cout<<"\n\nEnter your choice here : ";
    cin>>n;

    switch (n)
    {
    case 1:
        calculateRent();
        break;

    case 2:
        menu(); 
            
    default: system("cls");
    cout<<"Sorry Invalid Input, Please enter correct choice!!!";
    goto back;   
    }
}

void Library::calculateRent(){
    system("cls");
    cout<<"\t\t\t\n\n\nFinal Receipt\n\n\n\n";
    int bcode,b2code,cost,days=0;
    float deposit=0,total=0;
    string bname,aname;
    fstream data,data1,data2;
    list();
    data.open("library1.txt",ios::in);
    data1.open("library2.txt",ios::app|ios::out);
    cout<<"\n\n\nEnter Book code you want to rent : ";
    cin>>bcode;
    cout<<"Enter for How many number of days you want book : ";
    cin>>days;

    data>>bookcode>>bookname>>authorname>>price;
    while(!data.eof()){
           if(bcode==bookcode){
                data2.open("library3.txt",ios::out);
                deposit = price*(0.8);
                total = deposit + (days*5);
                data2<<bookcode<<" "<<bookname<<" "<<authorname<<" "<<price<<endl;
           }else{
             data1<<bookcode<<" "<<bookname<<" "<<authorname<<" "<<price<<endl;
           }

    data>>bookcode>>bookname>>authorname>>price;
    }
    data.close();
    data1.close();
    data2.close();
    remove("library1.txt");
    rename("library2.txt","library1.txt");

cout<<"\n\n\n\t\t\tYour total is : "<<total;
cout<<"\nIn this deposit amount is : "<<deposit<<" (which you will get refund after returning the book)";
cout<<"\n\n\n\t\t\t\tThank you\n\n\n";
menu();
}
