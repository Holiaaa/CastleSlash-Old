#include <stdio.h>
#include <stdlib.h>

#include "items.h"
#include "player.h"
#include "ui.h"
#include "error.h"
#include "events.h"

void itemSetName(struct Items *i, const char *ItemName)
{
    strncpy(i->name, ItemName, sizeof(i->name));
    i->name[sizeof(i->name) - 1] = '\0';
}

void itemSetDescription(struct Items *i, const char *ItemDescription)
{
    strncpy(i->description, ItemDescription, sizeof(i->description));
    i->description[sizeof(i->description) - 1] = '\0';
}

void giveItems(struct Player *p, struct Items *i)
{
    int index = 0;
    while (index < MAX_ITEMS && p->items[index] != 0) {
        index++;
    }

    p->items[index] = i->id;
    p->numberOfItem += 1;
}

void removeItems(struct Player *p, struct Items *i)
{
    int index = 0;
    while (index < MAX_ITEMS && p->items[index] == i->id)
    {
        index++;
    }

    p->items[index] = 0;
    p->numberOfItem -= 1;
}

void showItem(struct Items *i, int x, int y)
{
    moveCursor(x, y);
    printf("\033[93m%s\033[0m [\033[31mATK+ \033[0m: %d] [\033[34mDEF+\033[0m: %d] (\033[33m%d $\033[0m)", i->name, i->attackPlus, i->defensePlus, i->sellPrice);
    moveCursor(x, y+1);
    printf("\t%s", i->description);
}

void ListItems(struct Player *p, int x, int y)
{
    int index = 0;
    while (index < MAX_ITEMS && p->items[index] != 0) {
        showItem(&p->items[index], x, y);
        y++;
        index++;
    }
}
