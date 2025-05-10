#ifndef ITEMS_H
#define ITEMS_H

#include "player.h"

typedef struct Items Items;
struct Items {
    int id;
    char name[256];
    char description[512];
    int attackPlus;
    int defensePlus;
    int sellPrice;
};

void itemSetName(struct Items *i, const char *ItemName);
void itemSetDescription(struct Items *i, const char *ItemDescription);
void giveItems(struct Player *p, struct Items *i);
void removeItems(struct Player *p, struct Items *i);
void showItem(struct Items *i, int x, int y);
void ListItems(struct Player *p, int x, int y);
void addItem(const char *name, const char *description, int attackPlus, int defensePlus, int sellPrice);

#endif
