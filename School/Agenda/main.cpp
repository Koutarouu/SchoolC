#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct contact{
    int num;
    char name[30];
    char email[30];
};

class schedule{
public:
    void add_contact();
    void show_contacts();
    void modify_contact();
    void search_contact();
};

int main()
{
    schedule a;
    char r='s';
    do{
        int o;

        cout<<"1)Add "<<endl;
        cout<<"2)Show "<<endl;
        cout<<"3)Search "<<endl;
        cout<<"4)Modify "<<endl;
        cin>>o;
        switch(o){
        case 1:
            a.add_contact();
            break;
        case 2:
            a.show_contacts();
            break;
        case 3:
            a.search_contact();
            break;
        case 4:
            a.modify_contact();
            break;
        default:
            break;
        //case 4:
        }
        cout<<"Close 's'"<<endl;
        cin>>r;
        system("cls");
    }while(r!='s');

    return 0;
}

void schedule::add_contact(){

    FILE *a;
    a = fopen("schedule", "ab");
    contact x;
    fflush(stdin);
    cout<<"Name: "<<endl;
    cin.getline(x.name, 30, '\n');
    cout<<"Email: "<<endl;
    cin.getline(x.email, 30, '\n');
    cout<<"Phone number: "<<endl;
    cin>>x.num;

    fwrite(&x, sizeof(contact), 1 , a);
    fclose(a);

}

void schedule::show_contacts(){
    FILE *a;
    a=fopen("schedule", "rb");

    if(a!=NULL){
        contact x;
        while( fread(&x, sizeof(contact), 1, a) != 0 ){
            cout<<x.name<<" "<<x.num<<" "<<x.email<< endl;
        }
    }else{
        cout<<"No hay Registros. "<<endl;
    }
}

void schedule::search_contact(){
    FILE *a;
    char d[30];

    a=fopen("schedule", "rb");
    if(a!=NULL){
        cout<<"Dude? "<<endl;
        cin>>d;
        contact x;
        bool found = false;
        while( fread(&x, sizeof(contact), 1, a) != 0 ){
            if(strcmp(x.name, d)==0){
                cout<<"Element Found. "<<endl;
                cout<<x.name<<" "<<x.num<<" "<<x.email<<endl;
                found=true;
            }
        }
        if(!found) cout<<"Not Found."<<endl;
    }else{
        cout<<"There is no registers. "<<endl;
    }
}

void schedule::modify_contact(){
    FILE *a;
    char d[30];
    a=fopen("schedule", "r+b");
    if(a!=NULL){
        cout<<"Dude? "<<endl;
        cin>>d;
        contact x;
        while( fread(&x, sizeof(contact), 1, a) != 0 ){
            if(strcmp(x.name, d)==0){
                cout<<"Element Found. "<<endl;
                cin>>x.name;
                cin>>x.num;
                cin>>x.email;
                fseek(a, -1*sizeof(contact), SEEK_CUR);
                fwrite(&x, sizeof(contact), 1 , a);
                return;
            }
        }
        cout<<"Not Found."<<endl;
    }else{
        cout<<"There is no registers. "<<endl;
    }
}
