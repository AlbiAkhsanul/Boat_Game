#include <cstdlib>
//Function

//Get Ship Option
int getShipOption(){
    
}
//Get Option
int getOption(){
    char Option;
    std::cin>>Option;
    std::cout<<"_____________________________________________"<<std::endl<<std::endl;
    return Option;
}
//Serangan biasa
int serangan(int ATK){
    return (rand()%35) + ATK - 20;
}
//Critikal
int critical(int ATK){
    return ATK * 2;
}
//Skill
int BismarckSkill(int ATK){
    return (ATK * 3.5) - (rand()%25);
}
int VanguardSkill(int ATK){
    return (ATK * 4.2) - (rand()%25);
}
int RichelieuSkill(int ATK){
    return (ATK * 1.8) - (rand()%25);
}
//Torps
int torpedoes(int Torps){
    return Torps * 2 - ((rand()%40) - 25);
}