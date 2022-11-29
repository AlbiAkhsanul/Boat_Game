#include <string>
//Entities
struct entities {
    std::string Name;
    int HP;
    int ATK;
    int DEF;
    int Torps;
    int Cooldown;
    int EvadeRate;
    int CritRate;
    std::string Skill;
    int SkillDuration;
};
entities BB1{
    "KMS Bismarck",
    6500,
    540,
    250,
    0,
    5,
    3,
    5,
    "Iron And Blood",
    2,
};
entities BB2{
    "HMS Vanguard",
    6000,
    600,
    220,
    0,
    5,
    3,
    7,
    "Divine Marksman",
    0,
};
entities BB3{
    "FN Richelieu",
    5500,
    570,
    210,
    0,
    5,
    5,
    6,
    "Iris Flagbearer",
    2,
};
entities DD{
    "IJN Shimakaze",
    2100,
    250,
    50,
    600,
    4,
    7,
    5,
    "Torpedoes",
    0,
};
entities CL{
    "HMS Edinburgh",
    4100,
    420,
    110,
    450,
    5,
    5,
    5,
    "Torpedoes",
    0,
};
entities CA{
    "USS Des Moines",
    5000,
    480,
    150,
    0,
    4,
    5,
    6,
    "Rapid Fire",
    0,
};
//Buffer
entities Enemy;
entities Player;
//Buffer stat sebelum buff
entities PlayerStatAwal;
entities EnemyStatawal;

