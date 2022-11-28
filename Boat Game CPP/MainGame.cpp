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
void order();
void display();
void pause();
void SkillDuration();
//void command
void attack();
void heal();
void skill();
void retreat();
void PlayerAct();
//Void enemy act (auto)
void EnemyA();
void EnemyT();
void RapidFire();
void EnemySkill();
void ShimaBuff();
void EdinBuff();
void MoinBuff();
void EnemyBuff();
//prototipe Function
int getOption(char Action);
int serangan(int ATK);
int critical(int ATK);
int BismarckSkill (int ATK);
int VanguardSkill (int ATK);
int RichelieuSkill (int ATK);
int torpedoes(int Torps);
   
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
        std::cout<<"The KMS Bismarck was once the most feared ship"<<std::endl;
        std::cout<<"in the world. Its heavly armored but due to some"<<std::endl; 
        std::cout<<"design flaw making its fire power somehow limited."<<std::endl;
        std::cout<<"Her skill 'Iron And Blood' shot a powerful barrage"<<std::endl;
        std::cout<<"while also increasing her deffense for a period of time."<<std::endl;
        std::cout<<"_____________________________________________"<<std::endl<<std::endl;
        std::cout<<"General Stat : "<<std::endl<<std::endl;
        std::cout<<"Fire Power      : *****"<<std::endl;
        std::cout<<"Survivabilty    : **********"<<std::endl;
        std::cout<<"Manuverabilty   : ****"<<std::endl;
        PilihanBoat = 'A';

    }else if(ShipOption == 'B' || ShipOption == 'b'){
        std::cout<<"The HMS Vanguard was the last battleship from"<<std::endl;
        std::cout<<"the Royal Navy. It has superb fire power "<<std::endl;
        std::cout<<"and amazing fire control system. Her skill"<<std::endl; 
        std::cout<<"'Divine Marksman' shot a powerful barrage with"<<std::endl;
        std::cout<<"high accuracy which has higher chance to hit."<<std::endl<<std::endl;
        std::cout<<"_____________________________________________"<<std::endl<<std::endl;
        std::cout<<"General Stat : "<<std::endl<<std::endl;
        std::cout<<"Fire Power      : **********"<<std::endl;
        std::cout<<"Survivabilty    : ******"<<std::endl;
        std::cout<<"Manuverabilty   : ****"<<std::endl;
        PilihanBoat = 'B';

    }else if(ShipOption == 'C' || ShipOption == 'c'){
        std::cout<<"The FN Richelieu was one of the most known"<<std::endl;
        std::cout<<"battleship due to its superb mobilty."<<std::endl;
        std::cout<<"Her turret layout makes it possible for her"<<std::endl; 
        std::cout<<"to shoot without showing broadside."<<std::endl;
        std::cout<<"Her skill 'Iris Flagbearer' shot a multiple"<<std::endl; 
        std::cout<<"barrages with decent damage while also"<<std::endl;
        std::cout<<"increasing her evade rate for a period of time.."<<std::endl;
        std::cout<<"_____________________________________________"<<std::endl<<std::endl;
        std::cout<<"General Stat : "<<std::endl<<std::endl;
        std::cout<<"Fire Power      : ******"<<std::endl;
        std::cout<<"Survivabilty    : *****"<<std::endl;
        std::cout<<"Manuverabilty   : **********"<<std::endl;
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
            pl = BB1;
        }else if(PilihanBoat == 'B'){
            pl = BB2;
        }else if(PilihanBoat == 'C'){
            pl = BB3;
        }

    }else if(Option == 'N' || Option == 'n'){
        goto StartMain;

    }else{
        std::cout<<"Invalid Input !"<<std::endl;
        goto StartValidasiKapal;
    }
    system("cls");
    //Round 1
    enemy = DD;
    std::cout<<"A Wild "<<enemy.name<<" Appeared !"<<std::endl<<std::endl;

    //Menjalankan Giliran 1
    int role = 2;
    //Membuat Buffer Cooldown
    CooldownPL = pl.Cooldown;
    CooldownEY = enemy.Cooldown;

    do{
        //Menjalankan giliran player
        if(role % 2 == 0){
            balik1:
            std::cout<<pl.DEF<<std::endl;
            balik = false;
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
                if(pl.Cooldown > 0){
                    std::cout<<"Warning : [Skill Is Still On Cooldown!] "<<std::endl;
                    balik = true;
                    pause();
                }else{
                    skill();
                    DurationPL = pl.SkillDuration;
                    pl.Cooldown = CooldownPL;
                }
            
            //Apabila playerR memilih 'R'
            }else if(Action == 'R' || Action == 'r'){
                retreat();
                if (go == false){return 0;}
            } else {
                std::cout<<"Invalid Input!"<<std::endl;
                balik = true;
                pause();
            }
            //Check Balik
            if(balik == true ){goto balik1;}
             //Menjalankan SKill Berdurasi
            SkillDuration();

            display();
            pl.Cooldown--;
            role--;
        //Menjalankan Enemy
        }else{
            std::cout<<"Enemy Turn!"<<std::endl<<std::endl;
            //Menentukan act enemy
            int EnemyAct = (rand()%5)+1;
            if(enemy.Cooldown <= 0){
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
            enemy.Cooldown--;
            role++;
            DurationPL--;
            //Gate
            pause();
        } 
    }while (pl.HP > 0 && enemy.HP > 0);
    if (pl.HP <= 0){
        std::cout<<"Defeat !";
        return 0;
    }
    std::cout<<"Enemy Destroyer "<<enemy.name<<" Sunk!"<<std::endl<<std::endl;
    pause();
    //Mengreset CooldownEY
    enemy.Cooldown =  CooldownEY;

    //Round 2
    std::cout<<"A New Opponent Has Appeared!"<<std::endl;
    enemy = CL;
    std::cout<<"It is "<<enemy.name<<" !"<<std::endl<<std::endl;

    //Membuat Buffer Cooldown
    CooldownEY =  enemy.Cooldown;
   
    //Menjalankan Giliran 2
    do{
        //Menjalankan giliran player
        if(role % 2 == 0){
            balik2:
            balik = false;
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
                if(pl.Cooldown > 0){
                    std::cout<<"Skill Is Still On Cooldown! "<<std::endl;
                    balik = true;
                    pause();
                }else{
                    skill();
                    DurationPL = pl.SkillDuration;
                    pl.Cooldown = CooldownPL;
                }
            
            //Apabila playerR memilih 'R'
            }else if(Action == 'R' || Action == 'r'){
                retreat();
                if (go == false){return 0;}
            } else {
                std::cout<<"Invalid Input!"<<std::endl;
                balik = true;
                pause();
            }
            //Check Balik
            if(balik == true ){goto balik2;}
             //Menjalankan SKill Berdurasi
            SkillDuration();

            display();
            pl.Cooldown--;
            role--;
        //Menjalankan Enemy
        }else{
            std::cout<<"Enemy Turn!"<<std::endl<<std::endl;
            //Menentukan act enemy
            int EnemyAct = (rand()%5)+1;
            if(enemy.Cooldown <= 0){
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
        enemy.Cooldown--;
        role++;
        DurationPL--;
        //Gate
        pause();
        } 
    }while (pl.HP > 0 && enemy.HP > 0);
    if (pl.HP <= 0){
        std::cout<<"Defeat !";
        return 0;
    }
    std::cout<<"Enemy "<<enemy.name<<" Sent To Davy Johnt Locker !"<<std::endl<<std::endl;
    pause();

    //Round 3
    std::cout<<"Enemy Heavy Cruiser Sighted Over The Horizon!"<<std::endl;
    enemy = CA;
    std::cout<<"It is "<<enemy.name<<" !"<<std::endl<<std::endl;

    //Membuat Buffer Cooldown
    CooldownEY =  enemy.Cooldown;

    //Menjalankan Giliran 3
    do{
        //Menjalankan giliran player
        if(role % 2 == 0){
            balik3:
            balik = false;
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
                if(pl.Cooldown > 0){
                    std::cout<<"Skill Is Still On Cooldown! "<<std::endl;
                    balik = true;
                    pause();
                }else{
                    skill();
                    DurationPL = pl.SkillDuration;
                    pl.Cooldown = CooldownPL;
                }
            
            //Apabila playerR memilih 'R'
            }else if(Action == 'R' || Action == 'r'){
                retreat();
                if (go == false){return 0;}
            } else {
                std::cout<<"Invalid Input!"<<std::endl;
                balik = true;
                pause();
            }
            //Check Balik
            if(balik == true ){goto balik3;}
             //Menjalankan SKill Berdurasi
            SkillDuration();

            display();
            pl.Cooldown--;
            role--;
        //Menjalankan Enemy
        }else{
            std::cout<<"Enemy Turn!"<<std::endl<<std::endl;
            //Menentukan act enemy
            int EnemyAct = (rand()%5)+1;
            if(enemy.Cooldown <= 0){
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
        enemy.Cooldown--;
        role++;
        DurationPL--;
        //Gate
        pause();
        } 
    }while (pl.HP > 0 && enemy.HP > 0);
    if (enemy.HP <= 0){
        std::cout<<enemy.name<<" Sleep With The Fishes Tonight!"<<std::endl;
    }
    //Menentukan Output
    if(pl.HP > 0){
        std::cout<<"Victory!"<<std::endl;
    }else {
        std::cout<<"Defeat!"<<std::endl;
    }
    return 0;
}




