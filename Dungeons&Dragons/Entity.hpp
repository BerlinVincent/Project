#include "Attacks_and_Spells.cpp"
#include "Alignment.hpp"

class Entity {
    // Attributes
    // Entity Description
    string name;
    Alignment alignment;    

    // Active Entity Game Attributes
    // Health
    int max_health;
    int current_health;
    int temp_health;
    // AC, Initiative, Speed, Passive Wisdom
    int armor_class;
    int initiative;
    int speed;
    int passive_wisdom;
    // Inspiration, Proficiency Bonus, Hit Dice
    bool inspiration;
    int proficiency_bonus;
    int hit_dice;

    // Entity Game Attributes
    uint strength;
    uint dexterity;
    uint constitution;
    uint intelligence;
    uint wisdom;
    uint charisma;

    // Entity Saving Throws
    int strength_st;
    int dexterity_st;
    int constitution_st;
    int intelligence_st;
    int wisdom_st;
    int charisma_st;

    //Entity Game Skills
    int acrobatics;
    int animal_handling;
    int arcana;
    int athletics;
    int deception;
    int history;
    int insight;
    int intimidation;
    int investigation;
    int medicine;
    int nature;
    int perception;
    int performance;
    int persuasion;
    int religion;
    int sleight_of_hand;
    int stealth;
    int survival;

    // Entity Abilities
    vector<Attack> Attacks_and_Spells;
};