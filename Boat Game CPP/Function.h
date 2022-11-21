#include <cstdlib>
//Function

//Get Option
int getOption(){
    char Action;
    std::cin>>Action;
    std::cout<<"_____________________________________________"<<std::endl<<std::endl;
    return Action;
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
int skill(int ATK){
    return (ATK * 4) - (rand()%25);
}
//Torps
int torpedoes(int Torps){
    return Torps * 2 - ((rand()%40) - 25);
}