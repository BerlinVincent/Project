#include "inclusions.hpp"

enum DamageType {
    PIERCING,
    BLUDEONING,
    SLASHING,
    COLD,
    FIRE,
    LIGHTNING,
    THUNDER,
    POISON,
    ACID,
    NECROTIC,
    RADIANT,
    FORCE,
    PSYCHIC
};

class Attack {
    string name;
    int attack_bonus;
    int damage;
    DamageType type;
};