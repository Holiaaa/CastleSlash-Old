#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "items.h"

#define MAX_ITEMS 10

#define CHEVALIER_T 1
#define SORCIER_T 2
#define ARCHERE_T 3
#define LYRISTE_T 4

typedef struct Player Player;

struct Player {
    char name[256];
    int level;
    int coin;
    int attack;
    int defense;
    int hp;
    int type;
    int items[MAX_ITEMS];
    int numberOfItem;
};

// Set Command.

void setName(struct Player *p, char newName[256]); // Set the Player name.
void setType(struct Player *p, int newType); // Set the Player type.
void setLevel(struct Player *p, int newLevel); // Set the Player level.
void setCoin(struct Player *p, int newCoin); // Set the Player coin.
void setAttack(struct Player *p, int newAttack); // Set the Player attack.
void setDefense(struct Player *p, int newDefense); // Set the Player attack.
void setHP(struct Player *p, int newHP);

// Get Command

char *getName(struct Player *p);
int *getType(struct Player *p);
char *getTypeName(struct Player *p);
int *getLevel(struct Player *p);
int *getCoin(struct Player *p);
int *getAttack(struct Player *p);
int *getDefense(struct Player *p);
int *getHP(struct Player *p);

// Add Command.

void addLevel(struct Player *p, int addLevel);
void addCoin(struct Player *p, int addCoin);
void addAttack(struct Player *p, int addAttack);
void addDefense(struct Player *p, int addDefense);
void addHP(struct Player *p, int addHP);

// Sub Command.

// Misc Command.

void initPlayer(struct Player *p);
#endif
