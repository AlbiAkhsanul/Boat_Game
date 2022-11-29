#include <cstdlib>
//Function

//Get Ship Option
short getShipOption(){
    
}
//Get Option
short getOption(){
    char Option;
    std::cin>>Option;
    std::cout<<"_____________________________________________"<<std::endl<<std::endl;
    return Option;
}
//Serangan biasa
short serangan(short ATK){
    return (rand()%35) + ATK - 20;
}
//Critikal
short critical(short ATK){
    return ATK * 2;
}
//Skill
short BismarckSkill(short ATK){
    return (ATK * 3.5) - (rand()%25);
}
short VanguardSkill(short ATK){
    return (ATK * 4.2) - (rand()%25);
}
short RichelieuSkill(short ATK){
    return (ATK * 1.8) - (rand()%25);
}
//Torps
short torpedoes(short Torps){
    return Torps * 2 - ((rand()%40) - 25);
}