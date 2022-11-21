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
void display1();
void display2();
void display3();
void pause();
//void command
void attack();
void heal();
void skill();
void retreat();
//Void enemy act (auto)
void enemyA();
void enemyT();
void RapidFire();

//prototipe Function
int getOption(char Action);
int serangan(int ATK);
int critical(int ATK);
int skill (int ATK);
int torpedoes(int Torps);
   
//Program Utama
int main(){
    system("cls");
    //Round 1
    enemy = DD;
    std::cout<<"Welcome To Boat Game!\n============================="<<std::endl;
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
            display1();
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
                    pause();
                    goto balik1;
                }else{
                    skill();
                    pl.Cooldown = CooldownPL;
                }
            
            //Apabila playerR memilih 'R'
            }else if(Action == 'R' || Action == 'r'){
                retreat();
                if (go == false){return 0;}
            } else {
                std::cout<<"Invalid Input!"<<std::endl;
                pause();
                goto balik1;
            }

        display1();
        pl.Cooldown--;
        role--;
        //Menjalankan Enemy
        }else{
            std::cout<<"Enemy Turn!"<<std::endl<<std::endl;
            //Menentukan act enemy
            int EnemyAct = (rand()%5)+1;
            if(enemy.Cooldown <= 0){
                //Enemy skill
                enemyT();
                
            //Enemy Normal Attack
            }else if (EnemyAct > 2){
                enemyA();
                
            //Enemy using buff 
            }else {
                enemy.ATK += 30;
                enemy.Torps += 45;
                std::cout<<enemy.name<<" Uses Range Finder!\nIncreasing Her Fire Power!"<<std::endl<<std::endl;
                
            }

        display1();
        enemy.Cooldown--;
        role++;
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
            display2();
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
                    pause();
                    goto balik2;
                }else{
                    skill();
                    pl.Cooldown = CooldownPL;
                }
            
            //Apabila playerR memilih 'R'
            }else if(Action == 'R' || Action == 'r'){
                retreat();
                if (go == false){return 0;}
            } else {
                std::cout<<"Invalid Input!"<<std::endl;
                pause();
                goto balik2;
            }

        display2();
        pl.Cooldown--;
        role--;
        //Menjalankan Enemy
        }else{
            std::cout<<"Enemy Turn!"<<std::endl<<std::endl;
            //Menentukan act enemy
            int EnemyAct = (rand()%5)+1;
            if(enemy.Cooldown <= 0){
                //Enemy skill
                enemyT();
                
            //Enemy Normal Attack
            }else if (EnemyAct > 2){
                enemyA();
                
            //Enemy using buff 
            }else {
                enemy.ATK += 50;
                std::cout<<enemy.name<<" Enhance Her AP Shell!"<<std::endl;
                std::cout<<"Increasing Its Fire Power and Penetration Capability!"<<std::endl<<std::endl;
            }
    
        display2();
        enemy.Cooldown--;
        role++;
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
            display3();
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
                    pause();
                    goto balik3;
                }else{
                    skill();
                    pl.Cooldown = CooldownPL;
                }
            
            //Apabila playerR memilih 'R'
            }else if(Action == 'R' || Action == 'r'){
                retreat();
                if (go == false){return 0;}
            } else {
                std::cout<<"Invalid Input!"<<std::endl;
                pause();
                goto balik3;
            }

        display3();
        pl.Cooldown--;
        role--;
        //Menjalankan Enemy
        }else{
            std::cout<<"Enemy Turn!"<<std::endl<<std::endl;
            //Menentukan act enemy
            int EnemyAct = (rand()%5)+1;
            if(enemy.Cooldown <= 0){
                //Enemy skill
                RapidFire();
                
            //Enemy Normal Attack
            }else if (EnemyAct > 2){
                enemyA();
                
            //Enemy using buff 
            }else {
                enemy.ATK += 50;
                std::cout<<enemy.name<<" Enhance Her Radar!"<<std::endl;
                std::cout<<"Greatly Increasing Her Fire Power Capability!"<<std::endl<<std::endl;
            }
    
        display3();
        enemy.Cooldown--;
        role++;
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




