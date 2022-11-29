//Void

//Desc Kapal
//Bismarck
void BBDesc1(){
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

}
//Vanguard
void BBDesc2(){
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

}
//Richelieu
void BBDesc3(){
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

}
//oder
void order(){
    std::cout<<"Pick Your Order!"<<std::endl;
    std::cout<<"(A) Attack"<<std::endl;
    std::cout<<"(H) Repair"<<std::endl;
    //Situasi dimana player mendapatkan skill 
    if(Player.Cooldown <= 0){std::cout<<"(S) "<<Player.Skill<<std::endl;}
    std::cout<<"(R) Retreat"<<std::endl;
    std::cout<<"Action : ";
}
//display HP
void display(){
    std::cout<<Player.Name<<"\t : ["<<Player.HP<<"]"<<std::endl;
    std::cout<<Enemy.Name<<"\t : ["<<Enemy.HP<<"]"<<std::endl;
    std::cout<<"_____________________________________________"<<std::endl<<std::endl;
}
//Pause
void pause(){
    system("pause");
    system("cls");
}
//Skill Duration
void BuffSkillDuration(){
    if(DurationPL > 0){
        if(Player.Name == "KMS Bismarck"){
            Player.DEF = Player.DEF*3;
        }else if(Player.Name == "FN Richelieu"){
            Player.EvadeRate += 2;
        }
    }else{
        if(Player.Name == "KMS Bismarck"){
            Player.DEF = 250;
        }else if(Player.Name == "FN Richelieu"){
            Player.EvadeRate = 5;
        }
    }
}
//attack
void attack(){
    std::cout<<Player.Name<<" Opens Fire!"<<std::endl;
    //Menentukan kondisi 'serangan'
    unsigned short HitRate = (rand()%10)+1;
    if(HitRate <= Enemy.EvadeRate){
        std::cout<<Player.Name<<"'s Salvos Missed!"<<std::endl<<std::endl;
        
    }else{
        short CRate = (rand()%10)+1;
        if(CRate <= Player.CritRate){
            std::cout<<"Critical Hits!"<<std::endl<<std::endl;
            Enemy.HP -= critical(Player.ATK) - Enemy.DEF;
        }else{
            std::cout<<"Hit!"<<std::endl<<std::endl;
            Enemy.HP -= serangan(Player.ATK) - Enemy.DEF;
        }
    }
}
//heal
void heal(){
    if(Player.Name == "KMS Bismarck"){
        Player.HP += 900 + ((rand()%35)-10);
        if (Player.HP > 6500){Player.HP = 6500;}

    }else if(Player.Name == "HMS Vanguard"){
        Player.HP += 800 + ((rand()%35)-10);
        if (Player.HP > 6000){Player.HP = 6000;}

    }else if(Player.Name == "FN Richelieu"){
        Player.HP += 750 + ((rand()%35)-10);
        if (Player.HP > 5500){Player.HP = 5500;}

    }
    
    std::cout<<Player.Name<<" Repaired Her Wound!"<<std::endl<<std::endl;
}
//skill
void skill(){
    unsigned short HitRate = (rand()%10)+1;
    if(Player.Skill == "Iron And Blood"){
        std::cout<<Player.Name<<" Uses 'Iron And Blood'! "<<std::endl;
        std::cout<<"Increasing Its Deffense For A Period Of Time"<<std::endl;
        std::cout<<"Beep--\nBeep--\nTarget Acquired! Feuer!!"<<std::endl<<std::endl;
        if (HitRate <= Enemy.EvadeRate){
            std::cout<<Enemy.Name<<" Manages To Dodge!"<<std::endl<<std::endl;
            
        }else {
            std::cout<<Enemy.Name<<" Critically Damaged!!"<<std::endl<<std::endl;
            Enemy.HP -= BismarckSkill(Player.ATK) - Enemy.DEF;
            
        }

    }else if(Player.Skill == "Divine Marksman"){
        std::cout<<Player.Name<<" Uses 'Divine Marksman'! "<<std::endl;
        std::cout<<"Belli Dura Despicio!!"<<std::endl<<std::endl;
        //Vanguard has superb accuracy so it has higher chance to hit
        if (HitRate <= Enemy.EvadeRate - 2){
            std::cout<<Enemy.Name<<" Manages To Dodge!"<<std::endl<<std::endl;
            
        }else {
            std::cout<<Enemy.Name<<" Suffered Critical Damage!!"<<std::endl<<std::endl;
            Enemy.HP -= VanguardSkill(Player.ATK) - Enemy.DEF;
            
        }

    }else if(Player.Skill == "Iris Flagbearer"){
        std::cout<<Player.Name<<" Uses 'Iris Flagbearer'! "<<std::endl;
        std::cout<<"Increasing Its Evade Rate For A Period Of Time"<<std::endl;
        std::cout<<"Fire!!"<<std::endl<<std::endl;
        if (HitRate <= Enemy.EvadeRate){
            std::cout<<Enemy.Name<<" Manages To Dodge!"<<std::endl<<std::endl;
            
        }else {
            std::cout<<"First Barage!"<<std::endl;
            std::cout<<"_____________________________________________"<<std::endl<<std::endl;
            Enemy.HP -= RichelieuSkill(Player.ATK) - Enemy.DEF;
            display();
            std::cout<<"Second Barage!"<<std::endl;
            Enemy.HP -= RichelieuSkill(Player.ATK) - Enemy.DEF;
            std::cout<<"_____________________________________________"<<std::endl<<std::endl;

        }

    }
}
//retreat
void retreat(){
    std::cout<<Player.Name<<" Sets A Smoke Screen!"<<std::endl;
    short retreat = (rand()%10)+1;
    if (retreat <= Player.EvadeRate){
        std::cout<<Player.Name<<" Retreated Succesfully!";
        go = false;

    }else {
        std::cout<<Enemy.Name<<" Uses Radar!\n"<<Player.Name<<" Failed To Escape!"<<std::endl;
        std::cout<<"_____________________________________________"<<std::endl<<std::endl;

    }
}
//Enemy Attack
void EnemyA(){
    std::cout<<Enemy.Name<<" Opens Fire!"<<std::endl;
    unsigned short HitRate = (rand()%10)+1;
    if(HitRate <= Player.EvadeRate){
        std::cout<<Enemy.Name<<"'s Salvos Missed!"<<std::endl<<std::endl;
        
    }else{
        short CRate = (rand()%10)+1;
        if(CRate <= Enemy.CritRate){
            std::cout<<"Critical Hits!"<<std::endl<<std::endl;
            Player.HP -= critical(Enemy.ATK) - Player.DEF;

        }else{
            std::cout<<"Hit!"<<std::endl<<std::endl;
            Player.HP -= serangan(Enemy.ATK) - Player.DEF;

        }

    } 
}
//Enemy Torps
void EnemyT(){
    unsigned short EnemySkillAct = (rand()%2)+1;
    if( EnemySkillAct = 1){
        short TorpsHit = (rand()%10)+1;
        std::cout<<Enemy.Name<<" Launches Torpedoes!"<<std::endl;
        std::cout<<". . . .\n. . . ."<<std::endl<<std::endl;
        if (TorpsHit <= Player.EvadeRate){
            std::cout<<Player.Name<<" Evaded "<<Enemy.Name<<"'s Torps!"<<std::endl<<std::endl;
            Enemy.Cooldown =  CooldownEY - 2;
        }else {
            short TorpsCrit = (rand()%5)+1;
                if (TorpsCrit >= 3){
                    std::cout<<"BOOM! Direct Hit!"<<std::endl<<std::endl;
                    Player.HP -= 1.5 * torpedoes(Enemy.ATK) - Player.DEF;

                }else{
                    std::cout<<Player.Name<<" Got Hit!"<<std::endl<<std::endl;
                    Player.HP -= torpedoes(Enemy.ATK) - Player.DEF;
                }
            Enemy.Cooldown =  CooldownEY;
        }
    }
}
//Enemy Rapid Fire
void RapidFire(){
    unsigned short EnemySkillAct = (rand()%2)+1;
    if( EnemySkillAct = 1){
        short RFHit = (rand()%10)+1;
        std::cout<<Enemy.Name<<" Uses Rapid Fire!"<<std::endl;
        std::cout<<Enemy.Name<<" Shot Multiple Barrages!"<<std::endl<<std::endl;
        if (RFHit <= Player.EvadeRate){
            std::cout<<Player.Name<<" Dodged The Barrages!"<<std::endl<<std::endl;
            Enemy.Cooldown =  CooldownEY - 2;
        }else {
            Player.HP -= serangan(Enemy.ATK)*1.1 - Player.DEF;
            display();
            Player.HP -= serangan(Enemy.ATK)*1.2 - Player.DEF;
            display();
            Player.HP -= serangan(Enemy.ATK)*1.4 - Player.DEF;
            Enemy.Cooldown =  CooldownEY;
        }
    }
}
//Enemy Skill
void EnemySkill(){
    if(Enemy.Skill == "Torpedoes"){
        EnemyT();

    }else{
        RapidFire();

    }
}
//Enemy Buff
void EnemyBuff(){
    if(Enemy.Name == "IJN Shimakaze"){
        Enemy.ATK += 30;
        Enemy.Torps += 45;
        std::cout<<Enemy.Name<<" Uses Range Finder!\nIncreasing Her Fire Power!"<<std::endl<<std::endl;

    }else if(Enemy.Name == "HMS Edinburgh"){
        Enemy.ATK += 40;
        std::cout<<Enemy.Name<<" Enhance Her AP Shell!"<<std::endl;
        std::cout<<"Increasing Its Fire Power and Penetration Capability!"<<std::endl<<std::endl;

    }else if(Enemy.Name == "USS Des Moines"){
        Enemy.ATK += 40;
        std::cout<<Enemy.Name<<" Enhance Her Radar!"<<std::endl;
        std::cout<<"Greatly Increasing Her Fire Power Capability!"<<std::endl<<std::endl;

    }
}