#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "ui.h"
#include "error.h"

// Set Commands

void setName(struct Player *p, char newName[256])
{
    strncpy(p->name, newName, sizeof(p->name));
    p->name[sizeof(p->name) - 1] = '\0';
}

void setType(struct Player *p, int newType)
{
    p->type = newType;
}

void setLevel(struct Player *p, int newLevel)
{
    p->level = newLevel;
}

void setCoin(struct Player *p, int newCoin)
{
    p->coin = newCoin;
}

void setAttack(struct Player *p, int newAttack)
{
    p->attack = newAttack;
}

void setDefense(struct Player *p, int newDefense)
{
    p->defense = newDefense;
}

void setHP(struct Player *p, int newHP)
{
    p->hp = newHP;
}

// Get Commands

char *getName(struct Player *p)
{
    return p->name;
}

int *getType(struct Player *p)
{
    return p->type;
}

char *getTypeName(struct Player *p)
{
    if (p->type == 1)
    {
        return "Chevalier";
    }
    else if (p->type ==  2)
    {
        return "Sorcier";
    }
    else if (p->type == 3)
    {
        return "Archere";
    }
    else if (p->type == 4)
    {
        return "Lyriste";
    }
    else
    {
        system("cls");
        printf("\033[31mERROR\033[0m: getTypeName() give a invalid result.\n");
        system("pause");
        exit(1);
    }
}

int *getLevel(struct Player *p)
{
    return p->level;
}

int *getCoin(struct Player *p)
{
    return p->coin;
}

int *getAttack(struct Player *p)
{
    return p->attack;
}

int *getDefense(struct Player *p)
{
    return p->defense;
}

int *getHP(struct Player *p)
{
    return p->hp;
}

// Add Command

void addLevel(struct Player *p, int addLevel)
{
    p->level += addLevel;
}

void addCoin(struct Player *p, int addCoin)
{
    p->coin += addCoin;
}

void addAttack(struct Player *p, int addAttack)
{
    p->attack += addAttack;
}

void addDefense(struct Player *p, int addDefense)
{
    p->defense += addDefense;
}

void addHP(struct Player *p, int addHP)
{
    p->hp += addHP;
}

// Misc Command

void initPlayer(struct Player *p)
{
    p->attack = 0;
    p->level = 0;
    p->coin = 0;
    p->defense = 0;
    p->type = 0;

    memset(p->items, 0, sizeof(p->items));
}
