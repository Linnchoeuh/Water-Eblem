/**
 ** @file create_spellbook.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "fe.h"

t_weapon create_spellbook(int type)
{
    t_weapon spellbook;

    if (type == 0)
    {
        spellbook.attack = 4;
        spellbook.max_durability = 20;
        spellbook.name = term_strdup("Fire spellbook");
    }
    else if (type == 1)
    {
        spellbook.attack = 7;
        spellbook.max_durability = 20;
        spellbook.name = term_strdup("Elfire spellbook");
    }
    else if (type == 2)
    {
        spellbook.attack = 3;
        spellbook.max_durability = 30;
        spellbook.name = term_strdup("wind spellbook");
    }
    else if (type == 3)
    {
        spellbook.attack = 6;
        spellbook.max_durability = 40;
        spellbook.name = term_strdup("Elwind spellbook");
    }
    spellbook.durability = spellbook.max_durability;
    spellbook.range = 2;
    return (spellbook);
}

