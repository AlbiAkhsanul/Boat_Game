#include <string>
//Entities
struct entities {
    std::string name;
    int HP;
    int ATK;
    int DEF;
    int Torps;
    int Cooldown;
    int EvadeRate;
    int CritRate;
};
entities pl{
    "KMS Bismarck",
    6000,
    550,
    200,
    0,
    5,
    3,
    5,
};
entities DD{
    "IJN Fubuki",
    2100,
    250,
    50,
    600,
    4,
    7,
    5,
};
entities CL{
    "HMS Edinburgh",
    4100,
    400,
    100,
    450,
    5,
    5,
    5,
};
entities CA{
    "USS Des Moines",
    5000,
    480,
    150,
    0,
    4,
    5,
};
//Buffer
entities enemy;

