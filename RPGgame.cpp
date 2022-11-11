#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

//Variabel Global

struct entities {
    string name;
    int HP;
    int ATK;
    int DEF;
    int torps;
};
entities pl{
    "KMS Bismarck",
    6000,
    550,
    200,
    0,
};
entities DD{
    "IJN Fubuki",
    2300,
    250,
    50,
    600,
};
entities CL{
    "HMS Edinburgh",
    4100,
    350,
    100,
    450,
};
entities CA{
    "USS Des Moines",
    5000,
    430,
    150,
    0,
};
entities enemy;
bool go = true;
//Prototipe Void
//void display
void order();
void display1();
void display2();
void display3();
//void command
void attack();
void heal();
void skill();
void retreat();
void enemyA();
void enemyT();
//prototipe Function
int serangan(int ATK);
int critical(int ATK);
int skill (int ATK);
int torpedoes(int torps);
   
//Program Utama
int main(){
    //Round 1
    enemy = DD;
    cout<<"Welcome To Boat Game!\n============================="<<endl;
    cout<<"A Wild "<<enemy.name<<" Appeared !"<<endl<<endl;

    display1();
    //Menjalankan Giliran 1
    int role = (rand()%10)+3;
    do{
        //Menjalankan giliran player
        if(role % 2 == 0){
            order();
            balik1:
            //Memasukan Action
            char Action;
            cin>>Action;
            cout<<"_____________________________________________"<<endl<<endl;
            //Tindakan Action

            //Apabila player memilih 'A'
            if(Action == 'A' || Action == 'a'){
                attack();
                
            
            //Apabila player memilih 'H'
            }else if(Action == 'H' || Action == 'h'){
                heal();
                
            
            //Apabila player memilih 'S'
            }else if(Action == 'S' || Action == 's'){
                skill();
                
            
            //Apabila playerR memilih 'R'
            }else if(Action == 'R' || Action == 'r'){
                retreat();
                if (go == false){return 0;}
            } else {
                cout<<"Invalid Input!";
                goto balik1;
            }

        display1();
        role--;
        //Menjalankan Enemy
        }else{
            cout<<"Enemy Turn!"<<endl<<endl;
            //Menentukan act enemy
            int EnemyAct = (rand()%4)+1;
            //Enemy Normal Attack
            if (EnemyAct >= 3){
                enemyA();
                
            //Enemy skill
            }else if(EnemyAct <= 2){
                int Hit = (rand()%5)+1;
                cout<<enemy.name<<" Launches Torpedoes!"<<endl;
                cout<<". . . .\n. . . ."<<endl<<endl;
                if (Hit > 3){
                    cout<<pl.name<<" Evaded "<<enemy.name<<"'s Torps!"<<endl<<endl;
                }else {
                    int TorpsCrit = (rand()%5)+1;
                    if (TorpsCrit >= 3){
                        cout<<"BOOM! Direct Hit!"<<endl<<endl;
                        pl.HP -= 1.5 * torpedoes(enemy.ATK) - pl.DEF;

                    }else{
                        cout<<pl.name<<" Got Hit!"<<endl<<endl;
                        pl.HP -= torpedoes(enemy.ATK) - pl.DEF;
                    }
                }
                
            //Enemy using buff 
            }else {
                enemy.ATK += 30;
                enemy.torps += 45;
                cout<<enemy.name<<" Uses Range Finder!\nIncreasing Her Fire Power!"<<endl<<endl;
                
            }
        display1();
        role++;
        } 
    }while (pl.HP > 0 && enemy.HP > 0);
    if (pl.HP <= 0){
        cout<<"Defeat !";
        return 0;
    }
    cout<<"Enemy Destroyer "<<enemy.name<<" Sunk!"<<endl<<endl;

    //Round 2
    cout<<"A New Opponent Has Appeared!"<<endl;
    enemy = CL;
    cout<<"It is "<<enemy.name<<" !"<<endl<<endl;
    display2();

    //Menjalankan Giliran 2
    do{
        //Menjalankan giliran player
        if(role % 2 == 0){
            order();
            balik2:
            //Memasukan Action
            char Action;
            cin>>Action;
            cout<<"_____________________________________________"<<endl<<endl;
            //Tindakan Action

            //Apabila player memilih 'A'
            if(Action == 'A'|| Action == 'a'){
                attack();
            //Apabila player memilih 'H'
            }else if(Action == 'H'|| Action == 'h'){
                heal();
            //Apabila player memilih 'S'
            }else if(Action == 'S'|| Action == 's'){
                skill();
            //Apabila player memilih 'R'
            }else if(Action == 'R'|| Action == 'r'){
                retreat();
                if (go == false){return 0;}
            }else {
                cout<<"Invalid Input!";
                goto balik2;
            }

        display2();
        role--;
        //Menjalankan Enemy
        }else{
            cout<<"Enemy Turn!"<<endl<<endl;
            //Menentukan act enemy
            int EnemyAct = (rand()%4)+1;
            //Enemy Normal Attack
            if (EnemyAct <= 2){
               enemyA();

            //Enemy skill
            }else if(EnemyAct == 4){
                enemyT();
            //Enemy using buff 
            }else {
                enemy.ATK += 50;
                cout<<enemy.name<<" Enhance Her AP Shell!"<<endl;
                cout<<"Increasing Its Fire Power and Penetration Capability!"<<endl<<endl;
            }
        display2();
        role++;
        } 
    }while (pl.HP > 0 && enemy.HP > 0);
    if (pl.HP <= 0){
        cout<<"Defeat !";
        return 0;
    }
    cout<<"Enemy "<<enemy.name<<" Sent To Davy Johnt Locker !"<<endl<<endl;

    //Round 3
    cout<<"Enemy Heavy Cruiser Sighted Over The Horizon!"<<endl;
    enemy = CA;
    cout<<"It is "<<enemy.name<<" !"<<endl<<endl;
    display3();

    //Menjalankan Giliran 3
    do{
        //Menjalankan giliran player
        if(role % 2 == 0){
            order();
            balik3:
            //Memasukan Action
            char Action;
            cin>>Action;
            cout<<"_____________________________________________"<<endl<<endl;
            //Tindakan Action

            //Apabila player memilih 'A'
            if(Action == 'A'|| Action == 'a'){
                attack();
                
            
            //Apabila player memilih 'H'
            }else if(Action == 'H'|| Action == 'h'){
                heal();
                

            //Apabila player memilih 'S'
            }else if(Action == 'S'|| Action == 's'){
                skill();
                

            //Apabila player memilih 'R'
            }else if (Action == 'R'|| Action == 'r'){
                retreat();
                if (go == false){return 0;}
                goto balik3;
            }else {
                cout<<"Invalid Input!";
            }
        display3();
        role--;
        //Menjalankan Enemy
        }else{
            cout<<"Enemy Turn!"<<endl<<endl;
            //Menentukan act enemy
            int EnemyAct = (rand()%4)+1;
            //Enemy Normal Attack
            if (EnemyAct <= 2){
               enemyA();

            //Enemy skill
            }else if(EnemyAct == 4){
                cout<<enemy.name<<" Uses Rapid Fire!"<<endl;
                cout<<enemy.name<<" Shot Multiple Barrages!"<<endl<<endl;
                int CRate = (rand()%3)+1;
                if (CRate >= 2){
                    pl.HP -= serangan(enemy.ATK) - pl.DEF;
                    display3();
                    pl.HP -= serangan(enemy.ATK) - pl.DEF;
                    display3();
                    pl.HP -= serangan(enemy.ATK) - pl.DEF;

                }else {
                    cout<<pl.name<<" Dodged The Barrages!"<<endl<<endl;

                }
            //Enemy using buff 
            }else {
                enemy.ATK += 50;
                cout<<enemy.name<<" Enhance Her Radar!"<<endl;
                cout<<"Greatly Increasing Her Fire Power Capability!"<<endl<<endl;
            }
        display3();
        role++;
        } 
    }while (pl.HP > 0 && enemy.HP > 0);
    if (enemy.HP <= 0){
        cout<<enemy.name<<" Sleep With The Fishes Tonight!"<<endl;
    }
    //Menentukan Output
    if(pl.HP > 0){
        cout<<"Victory!"<<endl;
    }else {
        cout<<"Defeat!"<<endl;
    }
    return 0;
}

//Void

//oder
void order(){
    cout<<"Pick Your Order!"<<endl;
    cout<<"(A) Attack"<<endl;
    cout<<"(H) Repair"<<endl;
    //Situasi dimana player mendapatkan skill 
    int awake = (rand()%10)+1;
    if(awake % 5 == 0){cout<<"(S) Focused Fire!"<<endl;}
    cout<<"(R) Retreat"<<endl;
    cout<<"Action : ";
}
//attack
void attack(){
    cout<<pl.name<<" Opens Fire!"<<endl;
    //Menentukan kondisi 'serangan'
    int CRate = (rand()%4)+1;
    if(CRate <= 2){
        cout<<"Hit!"<<endl<<endl;
        enemy.HP -= serangan(pl.ATK) - enemy.DEF;
        
    }else if(CRate == 3){
        cout<<"Critical Hits!"<<endl<<endl;
        enemy.HP -= critical(pl.ATK) - enemy.DEF;
        
    }else{
        cout<<pl.name<<"'s Salvos Missed!"<<endl<<endl;
        
    }
}
//heal
void heal(){
    pl.HP += 800 + ((rand()%35)-10);
    if (pl.HP > 6000){pl.HP = 6000;}
    cout<<pl.name<<" Repaired Her Wound!"<<endl<<endl;
    
}
//skill
void skill(){
    cout<<pl.name<<" Uses Focused Fire! "<<endl;
    cout<<"Beep--\nBeep--\nTarget Acquired! Fire!!"<<endl<<endl;
    int CRate = (rand()%3)+1;
    if (CRate >= 2){
        cout<<enemy.name<<" Critically Damaged!!"<<endl<<endl;
        enemy.HP -= skill(pl.ATK) - enemy.DEF;
        

    }else {
        cout<<enemy.name<<" Manages To Dodge!"<<endl<<endl;
        

    }
}
//retreat
void retreat(){
    cout<<pl.name<<" Sets A Smoke Screen!"<<endl;
    int retreat = (rand()%5)+1;
    if (retreat <=3){
        cout<<pl.name<<" Retreated Succesfully!";
        go = false;
    }else {
        cout<<enemy.name<<" Uses Radar!\n"<<pl.name<<" Failed To Escape!"<<endl;
        cout<<"_____________________________________________"<<endl<<endl;

    }
}
//Enemy normal attack
void enemyA(){
    cout<<enemy.name<<" Opens Fire!"<<endl;
    int CRate = (rand()%4)+1;
    if(CRate >= 3){
        cout<<"Hit!"<<endl<<endl;
        pl.HP -= serangan(enemy.ATK) - pl.DEF;
    }else if(CRate == 2){
        cout<<"Critical Hits!"<<endl<<endl;
        pl.HP -= critical(enemy.ATK) - pl.DEF;
    }else{
        cout<<enemy.name<<"'s Salvos Missed!"<<endl<<endl;
    }
}
//Enemy Torps
void enemyT(){
    int Hit = (rand()%5)+1;
    cout<<enemy.name<<" Launches Torpedoes!"<<endl;
    cout<<". . . .\n. . . ."<<endl<<endl;
    if (Hit == 3){
        cout<<pl.name<<" Evaded "<<enemy.name<<"'s Torps!"<<endl<<endl;
        
    }else {
        int TorpsCrit = (rand()%5)+1;
        if (TorpsCrit >= 3){
            cout<<"BOOM! Direct Hit!"<<endl<<endl;
            pl.HP -= 1.5 * torpedoes(enemy.torps) - pl.DEF;
            

        }else{
            cout<<pl.name<<" Got Hit!"<<endl<<endl;
            pl.HP -= torpedoes(enemy.torps) - pl.DEF;
            
        }
    }
}
//display HP
void display1(){
    cout<<"KMS Bismarck     : ["<<pl.HP<<"]"<<endl;
    cout<<"IJN Fubuki       : ["<<enemy.HP<<"]"<<endl;
    cout<<"_____________________________________________"<<endl<<endl;
}
void display2(){
    cout<<"KMS Bismarck     : ["<<pl.HP<<"]"<<endl;
    cout<<"HMS Edinburgh    : ["<<enemy.HP<<"]"<<endl;
    cout<<"_____________________________________________"<<endl<<endl;
}
void display3(){
    cout<<"KMS Bismarck     : ["<<pl.HP<<"]"<<endl;
    cout<<"USS Des Monines  : ["<<enemy.HP<<"]"<<endl;
    cout<<"_____________________________________________"<<endl<<endl;
}
//Function

//Serangan biasa
int serangan(int ATK){
    return (rand()%35) + ATK - 20;
}
//Critikal
int critical(int ATK){
    return ATK * 2;
}
//Skill
int skill(int ATK){
    return (ATK * 4) - (rand()%25);
}
//Torps
int torpedoes(int torps){
    return torps * 2 - ((rand()%40) - 25);
}


