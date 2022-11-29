#include <iostream>

//Data Entities
#include "Boats.h"

//Data Variable Global
#include "Variable.h"

//Function
#include "Function.h"

//Void
#include "Void.h"

//Prototipe Void
//void lain
void BBDesc1();
void BBDesc2();
void BBDesc3();
void order();
void display();
void pause();
void BuffSkillDuration();
//void command
void attack();
void heal();
void skill();
void retreat();
void PlayerAct();
//Void Enemy act (auto)
void EnemyA();
void EnemyT();
void RapidFire();
void EnemySkill();
void EnemyBuff();
//prototipe Function
short getOption(char Action);
short serangan(short ATK);
short critical(short ATK);
short BismarckSkill (short ATK);
short VanguardSkill (short ATK);
short RichelieuSkill (short ATK);
short torpedoes(short Torps);
   
//Program Utama
int main(){
    StartMain:
    //Main Menu
    system("cls");
    std::cout<<"\t   Welcome To Boat Game!"<<std::endl;
    std::cout<<"============================================="<<std::endl;
    std::cout<<"Choose Your Battleship!\n\t\t\t\twow such ship"<<std::endl<<std::endl;
    std::cout<<"(A) KMS Bismarck\n(B) HMS Vanguard\n(C) FN Richelieu"<<std::endl;
    std::cout<<"_____________________________________________"<<std::endl;
    start:
    std::cout<<"Choose : ";

    char ShipOption = getOption();
    
    //Menentukan BB
    if(ShipOption == 'A' || ShipOption == 'a'){
        BBDesc1();
        PilihanBoat = 'A';

    }else if(ShipOption == 'B' || ShipOption == 'b'){
        BBDesc2();
        PilihanBoat = 'B';

    }else if(ShipOption == 'C' || ShipOption == 'c'){
        BBDesc3();
        PilihanBoat = 'C';

    }else{
        std::cout<<"Invalid Input !"<<std::endl;
        goto start;
    }
    StartValidasiKapal:
    std::cout<<"_____________________________________________"<<std::endl<<std::endl;
    std::cout<<"To Battle ? [Y/N]: ";
    char Option = getOption();
    if(Option == 'Y' || Option == 'y'){
        //Menentukan Kapal
        if(PilihanBoat == 'A'){
            Player = BB1;
        }else if(PilihanBoat == 'B'){
            Player = BB2;
        }else if(PilihanBoat == 'C'){
            Player = BB3;
        }

    }else if(Option == 'N' || Option == 'n'){
        goto StartMain;

    }else{
        std::cout<<"Invalid Input !"<<std::endl;
        goto StartValidasiKapal;
    }
    system("cls");
    //Round 1
    Enemy = DD;
    std::cout<<"A Wild "<<Enemy.Name<<" Appeared !"<<std::endl<<std::endl;

    //Menjalankan Giliran 1
    short role = 2;
    //Membuat Buffer Cooldown
    CooldownPL = Player.Cooldown;
    CooldownEY = Enemy.Cooldown;

    do{
        //Menjalankan giliran player
        if(role % 2 == 0){
            balik1:
            Balik = false;
            display();
            order();
            //Memasukan Action
            char Action = getOption();
            //Tindakan Action

            //Apabila player memilih 'A'
            if(Action == 'A' || Action == 'a'){
                attack();
                
            //Apabila player memilih 'H'
            }else if(Action == 'H' || Action == 'h'){
                heal();
                
            //Apabila player memilih 'S'
            }else if(Action == 'S' || Action == 's'){
                //Apabila player memilih 'S' (Saat Cooldown)
                if(Player.Cooldown > 0){
                    std::cout<<"Warning : [Skill Is Still On Cooldown!] "<<std::endl;
                    Balik = true;
                    pause();
                }else{
                    skill();
                    DurationPL = Player.SkillDuration;
                    Player.Cooldown = CooldownPL;
                }
            
            //Apabila playerR memilih 'R'
            }else if(Action == 'R' || Action == 'r'){
                retreat();
                if (go == false){return 0;}
            } else {
                std::cout<<"Invalid Input!"<<std::endl;
                Balik = true;
                pause();
            }
            //Check Balik
            if(Balik == true ){goto balik1;}
            //Menjalankan SKill Berdurasi
            BuffSkillDuration();

            display();
            Player.Cooldown--;
            role--;
        //Menjalankan Enemy
        }else{
            std::cout<<"Enemy Turn!"<<std::endl<<std::endl;
            //Menentukan act enemy
            short EnemyAct = (rand()%5)+1;
            if(Enemy.Cooldown <= 0){
                //Enemy skill
                EnemySkill();
                
            //Enemy Normal Attack
            }else if (EnemyAct > 2){
                EnemyA();
                
            //Enemy using buff 
            }else {
                EnemyBuff();
                
            }
            display();
            Enemy.Cooldown--;
            role++;
            DurationPL--;
            //Gate
            pause();
        } 
    }while (Player.HP > 0 && Enemy.HP > 0);
    if (Player.HP <= 0){
        std::cout<<"Defeat !";
        return 0;
    }
    std::cout<<"Enemy Destroyer "<<Enemy.Name<<" Sunk!"<<std::endl<<std::endl;
    pause();
    //Mengreset CooldownEY
    Enemy.Cooldown =  CooldownEY;

    //Round 2
    std::cout<<"A New Opponent Has Appeared!"<<std::endl;
    Enemy = CL;
    std::cout<<"It is "<<Enemy.Name<<" !"<<std::endl<<std::endl;

    //Membuat Buffer Cooldown
    CooldownEY =  Enemy.Cooldown;
   
    //Menjalankan Giliran 2
    do{
        //Menjalankan giliran player
        if(role % 2 == 0){
            balik2:
            Balik = false;
            display();
            order();
            //Memasukan Action
            char Action = getOption();
            //Tindakan Action

            //Apabila player memilih 'A'
            if(Action == 'A' || Action == 'a'){
                attack();
                
            //Apabila player memilih 'H'
            }else if(Action == 'H' || Action == 'h'){
                heal();
                
            //Apabila player memilih 'S'
            }else if(Action == 'S' || Action == 's'){
                //Apabila player memilih 'S' (Saat Cooldown)
                if(Player.Cooldown > 0){
                    std::cout<<"Skill Is Still On Cooldown! "<<std::endl;
                    Balik = true;
                    pause();
                }else{
                    skill();
                    DurationPL = Player.SkillDuration;
                    Player.Cooldown = CooldownPL;
                }
            
            //Apabila playerR memilih 'R'
            }else if(Action == 'R' || Action == 'r'){
                retreat();
                if (go == false){return 0;}
            } else {
                std::cout<<"Invalid Input!"<<std::endl;
                Balik = true;
                pause();
            }
            //Check Balik
            if(Balik == true ){goto balik2;}
            //Menjalankan SKill Berdurasi
            BuffSkillDuration();

            display();
            Player.Cooldown--;
            role--;
        //Menjalankan Enemy
        }else{
            std::cout<<"Enemy Turn!"<<std::endl<<std::endl;
            //Menentukan act Enemy
            short EnemyAct = (rand()%5)+1;
            if(Enemy.Cooldown <= 0){
                //Enemy skill
                EnemySkill();
                
            //Enemy Normal Attack
            }else if (EnemyAct > 2){
                EnemyA();
                
            //Enemy using buff 
            }else {
                EnemyBuff();

            }
    
        display();
        Enemy.Cooldown--;
        role++;
        DurationPL--;
        //Gate
        pause();
        } 
    }while (Player.HP > 0 && Enemy.HP > 0);
    if (Player.HP <= 0){
        std::cout<<"Defeat !";
        return 0;
    }
    std::cout<<"Enemy "<<Enemy.Name<<" Sent To Davy Johnt Locker !"<<std::endl<<std::endl;
    pause();

    //Round 3
    std::cout<<"Enemy Heavy Cruiser Sighted Over The Horizon!"<<std::endl;
    Enemy = CA;
    std::cout<<"It is "<<Enemy.Name<<" !"<<std::endl<<std::endl;

    //Membuat Buffer Cooldown
    CooldownEY =  Enemy.Cooldown;

    //Menjalankan Giliran 3
    do{
        //Menjalankan giliran player
        if(role % 2 == 0){
            balik3:
            Balik = false;
            display();
            order();
            //Memasukan Action
            char Action = getOption();
            //Tindakan Action

            //Apabila player memilih 'A'
            if(Action == 'A' || Action == 'a'){
                attack();
                
            //Apabila player memilih 'H'
            }else if(Action == 'H' || Action == 'h'){
                heal();
                
            //Apabila player memilih 'S'
            }else if(Action == 'S' || Action == 's'){
                //Apabila player memilih 'S' (Saat Cooldown)
                if(Player.Cooldown > 0){
                    std::cout<<"Skill Is Still On Cooldown! "<<std::endl;
                    Balik = true;
                    pause();
                }else{
                    skill();
                    DurationPL = Player.SkillDuration;
                    Player.Cooldown = CooldownPL;
                }
            
            //Apabila playerR memilih 'R'
            }else if(Action == 'R' || Action == 'r'){
                retreat();
                if (go == false){return 0;}
            } else {
                std::cout<<"Invalid Input!"<<std::endl;
                Balik = true;
                pause();
            }
            //Check Balik
            if(Balik == true ){goto balik3;}
            //Menjalankan SKill Berdurasi
            BuffSkillDuration();

            display();
            Player.Cooldown--;
            role--;
        //Menjalankan Enemy
        }else{
            std::cout<<"Enemy Turn!"<<std::endl<<std::endl;
            //Menentukan act Enemy
            short EnemyAct = (rand()%5)+1;
            if(Enemy.Cooldown <= 0){
                //Enemy skill
                EnemySkill();
                
            //Enemy Normal Attack
            }else if (EnemyAct > 2){
                EnemyA();
                
            //Enemy using buff 
            }else {
                EnemyBuff();

            }
    
        display();
        Enemy.Cooldown--;
        role++;
        DurationPL--;
        //Gate
        pause();
        } 
    }while (Player.HP > 0 && Enemy.HP > 0);
    if (Enemy.HP <= 0){
        std::cout<<Enemy.Name<<" Sleep With The Fishes Tonight!"<<std::endl;
    }
    //Menentukan Output
    if(Player.HP > 0){
        std::cout<<"Victory!"<<std::endl;
    }else {
        std::cout<<"Defeat!"<<std::endl;
    }
    return 0;
}




