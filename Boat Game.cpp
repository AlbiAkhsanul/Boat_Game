#include<iostream>
#include<cstdlib>
using namespace std;

//Variabel Global
int HPPrEugen = 5000;
int HPSuffolk = 3600;
int ATKPrEugen = 450;
int ATKSuffolk = 270;
int Torps = 500;

//Prototipe Void
void display();
//prototipe Function
int serangan(int ATK);
int critical(int ATK);
int skill (int ATK);
int torpedoes(int torps);
   
//Program Utama
int main(){
    cout<<"Welcome To Boat Game!\n===================="<<endl;
    display();

    //Menjalankan Giliran
    int role = (rand()%10)+1;
    do{
        
        //Menjalankan giliran player
        if(role % 2 == 0){
            cout<<"Pick Your Order!"<<endl;
            cout<<"(A) Attack"<<endl;
            cout<<"(H) Repair"<<endl;

            //Situasi dimana player mendapatkan skill khusus
            int awake = (rand()%10)+1;
            if(awake % 5 == 0){cout<<"(S) Focused Fire!"<<endl;}
            cout<<"(R) Retreat"<<endl;
            cout<<"Action : ";

            //Memasukan Action
            char Action;
            cin>>Action;

            cout<<"_____________________________________________"<<endl<<endl;
            //Tindakan Action
            //Apabila player memilih 'A'
            if(Action == 'A'){
                cout<<"Prinz Eugen Opens Fire!"<<endl;
                //Menentukan kondisi 'serangan'
                int CRate = (rand()%4)+1;
                if(CRate <= 2){
                    cout<<"Hit!"<<endl<<endl;
                    HPSuffolk -= serangan(ATKPrEugen);
                    display();
                }else if(CRate == 3){
                    cout<<"Critical Hits!"<<endl<<endl;
                    HPSuffolk -= critical(ATKPrEugen);
                    display();
                }else{
                    cout<<"Prinz Eugen's Salvos Missed!"<<endl<<endl;
                    display();
                }

            }
            //Apabila player memilih 'H'
            else if(Action == 'H'){
                HPPrEugen += 600 + ((rand()%35)-25);
                if (HPPrEugen > 5000){HPPrEugen = 5000;}
                cout<<"Prinz Eugen Repaired Her Wound!"<<endl<<endl;
                display();

            }
            //Apabila player memilih 'S'
            else if(Action == 'S'){
                cout<<"Prinz Eugen Uses Focused Fire! "<<endl;
                cout<<"Beep--\nBeep--\nTarget Acquired! Fire!!"<<endl<<endl;
                int CRate = (rand()%3)+1;
                if (CRate >= 2){
                    cout<<"Suffolk Critically Damaged!!"<<endl<<endl;
                    HPSuffolk -= skill(ATKPrEugen);
                    display();

                }else {
                    cout<<"Suffolk Manages To Dodge!"<<endl<<endl;
                    display();

                }

            }
            //Apabila player memilih 'R'
            else{
                cout<<"Prinz Eugen Sets A Smoke Screen!"<<endl;
                int retreat = (rand()%5)+1;
                if (retreat <=3){
                    cout<<"Prinz Eugen Escaped Succesfully!"<<endl;
                    cout<<"_____________________________________________"<<endl;
                    return 0;
                }else {
                    cout<<"Suffolk Uses Radar!\nPrinz Eugen Failed To Escape!"<<endl;
                    cout<<"_____________________________________________"<<endl<<endl;

                }
            } role--;

        //Menjalankan Enemy
        }else{
            role++;
            cout<<"Enemy Turn!"<<endl<<endl;
            //Menentukan act enemy
            int SuffolkAct = (rand()%4)+1;
            //Enemy Normal Attack
            if (SuffolkAct <= 2){
                 cout<<"Suffolk Opens Fire!"<<endl;
                int CRate = (rand()%4)+1;
                if(CRate >= 3){
                    cout<<"Hit!"<<endl<<endl;
                    HPPrEugen -= serangan(ATKSuffolk);
                    display();
                }else if(CRate == 2){
                    cout<<"Critical Hits!"<<endl<<endl;
                    HPPrEugen -= critical(ATKSuffolk);
                    display();
                }else{
                    cout<<"Suffolk's Salvos Missed!"<<endl<<endl;
                    display();
                }

            //Enemy skill
            }else if(SuffolkAct == 4){
                int Hit = (rand()%5)+1;
                cout<<"Suffolk Launches Torpedoes!"<<endl;
                cout<<". . . .\n. . . ."<<endl<<endl;
                if (Hit <= 3){
                    cout<<"Prinz Eugen Evaded Suffolk's Torps!"<<endl<<endl;
                    display();
                }else {
                    int TorpsCrit = (rand()%5)+1;
                    if (TorpsCrit == 3){
                        cout<<"BOOM! Direct Hit!"<<endl<<endl;
                        HPPrEugen -= 1.5 * torpedoes(Torps);
                        display();

                    }else{
                        cout<<"Prinz Eugen Got Hit!"<<endl<<endl;
                        HPPrEugen -= torpedoes(Torps);
                        display();
                    }
                }
            //Enemy using buff 
            }else {
                ATKSuffolk += 30;
                cout<<"Suffolk's Uses Range Finder!\nIncreasing Her Fire Power!"<<endl<<endl;
                display();
            }
        }
    }while (HPPrEugen > 0 && HPSuffolk > 0);
    
    //Menentukan Output
    if(HPPrEugen > 0){
        cout<<"Victory!"<<endl;
    }else {
        cout<<"Defeat!"<<endl;
    }
    return 0;
}

//Void

//display HP
void display(){
    cout<<"KMS Prinz Eugen : ["<<+HPPrEugen<<"]"<<endl;
    cout<<"HMS Suffolk     : ["<<+HPSuffolk<<"]"<<endl;
    cout<<"_____________________________________________"<<endl<<endl;
}
//Function

//Serangan biasa
int serangan(int ATK){
    return (rand()%35) + ATK - 20;
}
//Critikal
int critical(int ATK){
    return ATK * 1.7;
}
//Skill
int skill(int ATK){
    return (ATK *4) - (rand()%25);
}
//Enemy Skill
int torpedoes(int torps){
    return torps*2 - ((rand()%40) - 25);
}



