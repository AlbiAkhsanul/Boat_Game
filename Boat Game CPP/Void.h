//Void

//oder
void order(){
    std::cout<<"Pick Your Order!"<<std::endl;
    std::cout<<"(A) Attack"<<std::endl;
    std::cout<<"(H) Repair"<<std::endl;
    //Situasi dimana player mendapatkan skill 
    if(pl.Cooldown <= 0){std::cout<<"(S) Focused Fire!"<<std::endl;}
    std::cout<<"(R) Retreat"<<std::endl;
    std::cout<<"Action : ";
}
//display HP
void display1(){
    std::cout<<"KMS Bismarck     : ["<<pl.HP<<"]"<<std::endl;
    std::cout<<"IJN Fubuki       : ["<<enemy.HP<<"]"<<std::endl;
    std::cout<<"_____________________________________________"<<std::endl<<std::endl;
}
void display2(){
    std::cout<<"KMS Bismarck     : ["<<pl.HP<<"]"<<std::endl;
    std::cout<<"HMS Edinburgh    : ["<<enemy.HP<<"]"<<std::endl;
    std::cout<<"_____________________________________________"<<std::endl<<std::endl;
}
void display3(){
    std::cout<<"KMS Bismarck     : ["<<pl.HP<<"]"<<std::endl;
    std::cout<<"USS Des Monines  : ["<<enemy.HP<<"]"<<std::endl;
    std::cout<<"_____________________________________________"<<std::endl<<std::endl;
}
//Pause
void pause(){
    system("pause");
    system("cls");
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
    pl.HP += 800 + ((rand()%35)-10);
    if (pl.HP > 6000){pl.HP = 6000;}
    std::cout<<pl.name<<" Repaired Her Wound!"<<std::endl<<std::endl;
    
}
//skill
void skill(){
    std::cout<<pl.name<<" Uses Focused Fire! "<<std::endl;
    std::cout<<"Beep--\nBeep--\nTarget Acquired! Fire!!"<<std::endl<<std::endl;
    int HitRate = (rand()%10)+1;
    if (HitRate <= enemy.EvadeRate){
        std::cout<<enemy.name<<" Manages To Dodge!"<<std::endl<<std::endl;
        
    }else {
        std::cout<<enemy.name<<" Critically Damaged!!"<<std::endl<<std::endl;
        enemy.HP -= skill(pl.ATK) - enemy.DEF;
        
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
//Enemy normal attack
void enemyA(){
    std::cout<<enemy.name<<" Opens Fire!"<<std::endl;
    int HitRate = (rand()%10)+1;
    if(HitRate <= 3){
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
void enemyT(){
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
            display3();
            pl.HP -= serangan(enemy.ATK)*1.2 - pl.DEF;
            display3();
            pl.HP -= serangan(enemy.ATK)*1.4 - pl.DEF;
            enemy.Cooldown =  CooldownEY;
        }
    }
}
