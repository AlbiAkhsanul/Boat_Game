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
    "KMS Tirpitz      ",
    6000,
    550,
    200,
    400,
};
entities DD{
    "IJN Fubuki       ",
    2300,
    250,
    50,
    600,
};
entities CL{
    "HMS Edinburgh    ",
    4100,
    350,
    100,
    450,
};
entities CA{
    "USS Des Moines   ",
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
void display();
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
int mai(){
    //Round 1
    enemy = DD;
    cout<<"Welcome To Boat Game!\n===================="<<endl;
    cout<<"A Wild "<<enemy.name<<" Appeared !"<<endl<<endl;

    display();
    //Menjalankan Giliran 1
    int role1 = (rand()%10)+1;
    do{
        //Menjalankan giliran player
        if(role1 % 2 == 0){
            order();

            //Memasukan Action
            char Action;
            cin>>Action;
            cout<<"_____________________________________________"<<endl<<endl;
            //Tindakan Action

            //Apabila player memilih 'A'
            if(Action == 'A'){
                attack();
            }
            //Apabila player memilih 'H'
            else if(Action == 'H'){
                heal();
            }
            //Apabila player memilih 'S'
            else if(Action == 'S'){
                skill();
            }
            //Apabila player memilih 'R'
            else{
                retreat();
            }
            role1--;

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
                int Hit = (rand()%5)+1;
                cout<<enemy.name<<" Launches Torpedoes!"<<endl;
                cout<<". . . .\n. . . ."<<endl<<endl;
                if (Hit >= 3){
                    cout<<pl.name<<" Evaded "<<enemy.name<<"'s Torps!"<<endl<<endl;
                    display();
                }else {
                    int TorpsCrit = (rand()%5)+1;
                    if (TorpsCrit >= 3){
                        cout<<"BOOM! Direct Hit!"<<endl<<endl;
                        pl.HP -= 1.5 * torpedoes(enemy.ATK) - pl.DEF;
                        display();

                    }else{
                        cout<<pl.name<<" Got Hit!"<<endl<<endl;
                        pl.HP -= torpedoes(enemy.ATK) - pl.DEF;
                        display();
                    }
                }
            //Enemy using buff 
            }else {
                enemy.ATK += 30;
                enemy.torps += 45;
                cout<<enemy.name<<" Uses Range Finder!\nIncreasing Her Fire Power!"<<endl<<endl;
                display();
            }
        } 
        if (go == 1){return 0;}
        role1++;
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
    display();

    //Menjalankan Giliran 2
    int role2 = (rand()%10)+1;
    do{
        //Menjalankan giliran player
        if(role2 % 2 == 0){
            order();

            //Memasukan Action
            char Action;
            cin>>Action;
            cout<<"_____________________________________________"<<endl<<endl;
            //Tindakan Action

            //Apabila player memilih 'A'
            if(Action == 'A'){
                attack();
            }
            //Apabila player memilih 'H'
            else if(Action == 'H'){
                heal();
            }
            //Apabila player memilih 'S'
            else if(Action == 'S'){
                skill();
            }
            //Apabila player memilih 'R'
            else{
                retreat();
            }
            role2--;

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
                display();
            }
            if (go == false){return 0;}
            role2++;
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
    display();

    //Menjalankan Giliran 3
    int role3 = (rand()%10)+1;
    do{
        //Menjalankan giliran player
        if(role3 % 2 == 0){
            order();

            //Memasukan Action
            char Action;
            cin>>Action;
            cout<<"_____________________________________________"<<endl<<endl;
            //Tindakan Action

            //Apabila player memilih 'A'
            if(Action == 'A'){
                attack();
            }
            //Apabila player memilih 'H'
            else if(Action == 'H'){
                heal();
            }
            //Apabila player memilih 'S'
            else if(Action == 'S'){
                skill();
            }
            //Apabila player memilih 'R'
            else{
                retreat();
            }
            role3--;

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
                    display();
                    pl.HP -= serangan(enemy.ATK) - pl.DEF;
                    display();
                    pl.HP -= serangan(enemy.ATK) - pl.DEF;
                    display();

                }else {
                    cout<<pl.name<<" Dodged The Barrages!"<<endl<<endl;
                    display();

                }
            //Enemy using buff 
            }else {
                enemy.ATK += 50;
                cout<<enemy.name<<" Enhance Her Radar!"<<endl;
                cout<<"Greatly Increasing Her Fire Power Capability"<<endl<<endl;
                display();
            }
        } 
        if (go == false){return 0;}
        role3++;
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
        display();
    }else if(CRate == 3){
        cout<<"Critical Hits!"<<endl<<endl;
        enemy.HP -= critical(pl.ATK) - enemy.DEF;
        display();
    }else{
        cout<<"Prinz Eugen's Salvos Missed!"<<endl<<endl;
        display();
    }
}
//heal
void heal(){
    pl.HP += 600 + ((rand()%35)-10);
    if (pl.HP > 6000){pl.HP = 6000;}
    cout<<"Prinz Eugen Repaired Her Wound!"<<endl<<endl;
    display();
}
//skill
void skill(){
    cout<<pl.name<<" Uses Focused Fire! "<<endl;
    cout<<"Beep--\nBeep--\nTarget Acquired! Fire!!"<<endl<<endl;
    int CRate = (rand()%3)+1;
    if (CRate >= 2){
        cout<<enemy.name<<" Critically Damaged!!"<<endl<<endl;
        enemy.HP -= skill(pl.ATK) - enemy.DEF;
        display();

    }else {
        cout<<enemy.name<<" Manages To Dodge!"<<endl<<endl;
        display();

    }
}
//retreat
void retreat(){
    cout<<pl.name<<" Sets A Smoke Screen!"<<endl;
    int retreat = (rand()%5)+1;
    if (retreat <=3){
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
        display();
    }else if(CRate == 2){
        cout<<"Critical Hits!"<<endl<<endl;
        pl.HP -= critical(enemy.ATK) - pl.DEF;
        display();
    }else{
        cout<<enemy.name<<"'s Salvos Missed!"<<endl<<endl;
        display();
    }
}
//Enemy Torps
void enemyT(){
    int Hit = (rand()%5)+1;
    cout<<enemy.name<<" Launches Torpedoes!"<<endl;
    cout<<". . . .\n. . . ."<<endl<<endl;
    if (Hit == 3){
        cout<<pl.name<<" Evaded "<<enemy.name<<"'s Torps!"<<endl<<endl;
        display();
    }else {
        int TorpsCrit = (rand()%5)+1;
        if (TorpsCrit >= 3){
            cout<<"BOOM! Direct Hit!"<<endl<<endl;
            pl.HP -= 1.5 * torpedoes(enemy.torps) - pl.DEF;
            display();

        }else{
            cout<<pl.name<<" Got Hit!"<<endl<<endl;
            pl.HP -= torpedoes(enemy.torps) - pl.DEF;
            display();
        }
    }
}
//display HP
void display(){
    cout<<pl.name<<": ["<<pl.HP<<"]"<<endl;
    cout<<enemy.name<<": ["<<enemy.HP<<"]"<<endl;
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


