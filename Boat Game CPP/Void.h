//Void

//oder
void order(){
    std::cout<<"Pick Your Order!"<<std::endl;
    std::cout<<"(A) Attack"<<std::endl;
    std::cout<<"(H) Repair"<<std::endl;
    //Situasi dimana player mendapatkan skill 
    if(pl.Cooldown <= 0){std::cout<<"(S) "<<pl.Skill<<std::endl;}
    std::cout<<"(R) Retreat"<<std::endl;
    std::cout<<"Action : ";
}
//display HP
void display(){
    std::cout<<pl.name<<"\t : ["<<pl.HP<<"]"<<std::endl;
    std::cout<<enemy.name<<"\t : ["<<enemy.HP<<"]"<<std::endl;
    std::cout<<"_____________________________________________"<<std::endl<<std::endl;
}
//Pause
void pause(){
    system("pause");
    system("cls");
}
//Skill Duration
void SkillDuration(){
    if(DurationPL > 0){
        if(pl.name == "KMS Bismarck"){
            pl.DEF = 300;
        }else if(pl.name == "FN Richelieu"){
            pl.EvadeRate = 7;
        }
    }else{
        if(pl.name == "KMS Bismarck"){
            pl.DEF = 250;
        }else if(pl.name == "FN Richelieu"){
            pl.EvadeRate = 5;
        }
    }
}
//attack
void attack(){
    std::cout<<pl.name<<" Opens Fire!"<<std::endl;
    //Menentukan kondisi 'serangan'
    int HitRate = (rand()%10)+1;
    if(HitRate <= enemy.EvadeRate){
        std::cout<<pl.name<<"'s Salvos Missed!"<<std::endl<<std::endl;
        
    }else{
        int CRate = (rand()%10)+1;
        if(CRate <= pl.CritRate){
            std::cout<<"Critical Hits!"<<std::endl<<std::endl;
            enemy.HP -= critical(pl.ATK) - enemy.DEF;
        }else{
            std::cout<<"Hit!"<<std::endl<<std::endl;
            enemy.HP -= serangan(pl.ATK) - enemy.DEF;
        }
    }
}
//heal
void heal(){
    if(pl.name == "KMS Bismarck"){
        pl.HP += 900 + ((rand()%35)-10);
        if (pl.HP > 6500){pl.HP = 6500;}

    }else if(pl.name == "HMS Vanguard"){
        pl.HP += 800 + ((rand()%35)-10);
        if (pl.HP > 6000){pl.HP = 6000;}

    }else if(pl.name == "FN Richelieu"){
        pl.HP += 750 + ((rand()%35)-10);
        if (pl.HP > 5500){pl.HP = 5500;}

    }
    
    std::cout<<pl.name<<" Repaired Her Wound!"<<std::endl<<std::endl;
}
//skill
void skill(){
    if(pl.Skill == "Iron And Blood"){
        std::cout<<pl.name<<" Uses 'Iron And Blood'! "<<std::endl;
        std::cout<<"Increasing Its Deffense For A Period Of Time"<<std::endl;
        std::cout<<"Beep--\nBeep--\nTarget Acquired! Feuer!!"<<std::endl<<std::endl;
        int HitRate = (rand()%10)+1;
        if (HitRate <= enemy.EvadeRate){
            std::cout<<enemy.name<<" Manages To Dodge!"<<std::endl<<std::endl;
            
        }else {
            std::cout<<enemy.name<<" Critically Damaged!!"<<std::endl<<std::endl;
            enemy.HP -= BismarckSkill(pl.ATK) - enemy.DEF;
            
        }

    }else if(pl.Skill == "Divine Marksman"){
        std::cout<<pl.name<<" Uses 'Divine Marksman'! "<<std::endl;
        std::cout<<"Belli Dura Despicio!!"<<std::endl<<std::endl;
        int HitRate = (rand()%10)+1;
        //Vanguard has superb accuracy so it has higher chance to hit
        if (HitRate <= enemy.EvadeRate - 2){
            std::cout<<enemy.name<<" Manages To Dodge!"<<std::endl<<std::endl;
            
        }else {
            std::cout<<enemy.name<<" Suffered Critical Damage!!"<<std::endl<<std::endl;
            enemy.HP -= VanguardSkill(pl.ATK) - enemy.DEF;
            
        }

    }else if(pl.Skill == "Iris Flagbearer"){
        std::cout<<pl.name<<" Uses 'Iris Flagbearer'! "<<std::endl;
        std::cout<<"Increasing Its Evade Rate For A Period Of Time"<<std::endl;
        std::cout<<"Fire!!"<<std::endl<<std::endl;
        int HitRate = (rand()%10)+1;
        if (HitRate <= enemy.EvadeRate){
            std::cout<<enemy.name<<" Manages To Dodge!"<<std::endl<<std::endl;
            
        }else {
            std::cout<<"First Barage!"<<std::endl;
            std::cout<<"_____________________________________________"<<std::endl<<std::endl;
            enemy.HP -= RichelieuSkill(pl.ATK) - enemy.DEF;
            display();
            std::cout<<"Second Barage!"<<std::endl;
            enemy.HP -= RichelieuSkill(pl.ATK) - enemy.DEF;
            std::cout<<"_____________________________________________"<<std::endl<<std::endl;

        }

    }
}
//retreat
void retreat(){
    std::cout<<pl.name<<" Sets A Smoke Screen!"<<std::endl;
    int retreat = (rand()%10)+1;
    if (retreat <= pl.EvadeRate){
        std::cout<<pl.name<<" Retreated Succesfully!";
        go = false;

    }else {
        std::cout<<enemy.name<<" Uses Radar!\n"<<pl.name<<" Failed To Escape!"<<std::endl;
        std::cout<<"_____________________________________________"<<std::endl<<std::endl;

    }
}
//Enemy Attack
void EnemyA(){
    std::cout<<enemy.name<<" Opens Fire!"<<std::endl;
    int HitRate = (rand()%10)+1;
    if(HitRate <= pl.EvadeRate){
        std::cout<<enemy.name<<"'s Salvos Missed!"<<std::endl<<std::endl;
        
    }else{
        int CRate = (rand()%10)+1;
        if(CRate <= enemy.CritRate){
            std::cout<<"Critical Hits!"<<std::endl<<std::endl;
            pl.HP -= critical(enemy.ATK) - pl.DEF;

        }else{
            std::cout<<"Hit!"<<std::endl<<std::endl;
            pl.HP -= serangan(enemy.ATK) - pl.DEF;

        }

    } 
}
//Enemy Torps
void EnemyT(){
    int EnemySkillAct = (rand()%2)+1;
    if( EnemySkillAct = 1){
        int TorpsHit = (rand()%10)+1;
        std::cout<<enemy.name<<" Launches Torpedoes!"<<std::endl;
        std::cout<<". . . .\n. . . ."<<std::endl<<std::endl;
        if (TorpsHit <= pl.EvadeRate){
            std::cout<<pl.name<<" Evaded "<<enemy.name<<"'s Torps!"<<std::endl<<std::endl;
            enemy.Cooldown =  CooldownEY - 2;
        }else {
            int TorpsCrit = (rand()%5)+1;
                if (TorpsCrit >= 3){
                    std::cout<<"BOOM! Direct Hit!"<<std::endl<<std::endl;
                    pl.HP -= 1.5 * torpedoes(enemy.ATK) - pl.DEF;

                }else{
                    std::cout<<pl.name<<" Got Hit!"<<std::endl<<std::endl;
                    pl.HP -= torpedoes(enemy.ATK) - pl.DEF;
                }
            enemy.Cooldown =  CooldownEY;
        }
    }
}
//Enemy Rapid Fire
void RapidFire(){
    int EnemySkillAct = (rand()%2)+1;
    if( EnemySkillAct = 1){
        int RFHit = (rand()%10)+1;
        std::cout<<enemy.name<<" Uses Rapid Fire!"<<std::endl;
        std::cout<<enemy.name<<" Shot Multiple Barrages!"<<std::endl<<std::endl;
        if (RFHit <= pl.EvadeRate){
            std::cout<<pl.name<<" Dodged The Barrages!"<<std::endl<<std::endl;
            enemy.Cooldown =  CooldownEY - 2;
        }else {
            pl.HP -= serangan(enemy.ATK)*1.1 - pl.DEF;
            display();
            pl.HP -= serangan(enemy.ATK)*1.2 - pl.DEF;
            display();
            pl.HP -= serangan(enemy.ATK)*1.4 - pl.DEF;
            enemy.Cooldown =  CooldownEY;
        }
    }
}
//Enemy Skill
void EnemySkill(){
    if(enemy.Skill == "Torpedoes"){
        EnemyT();

    }else{
        RapidFire();

    }
}
//Shimakaze
void ShimaBuff(){
    enemy.ATK += 30;
    enemy.Torps += 45;
    std::cout<<enemy.name<<" Uses Range Finder!\nIncreasing Her Fire Power!"<<std::endl<<std::endl;

}
//Edinburgh
void EdinBuff(){
    enemy.ATK += 40;
    std::cout<<enemy.name<<" Enhance Her AP Shell!"<<std::endl;
    std::cout<<"Increasing Its Fire Power and Penetration Capability!"<<std::endl<<std::endl;

}
//Des Moines
void MoinBuff(){
    enemy.ATK += 40;
    std::cout<<enemy.name<<" Enhance Her Radar!"<<std::endl;
    std::cout<<"Greatly Increasing Her Fire Power Capability!"<<std::endl<<std::endl;

}
//Enemy Buff
void EnemyBuff(){
    if(enemy.name == "IJN Shimakaze"){
        ShimaBuff();

    }else if(enemy.name == "HMS Edinburgh"){
        EdinBuff();

    }else if(enemy.name == "USS Des Moines"){
        MoinBuff();

    }
}