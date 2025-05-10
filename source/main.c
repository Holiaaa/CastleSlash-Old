#include <stdio.h>
#include <stdlib.h>

#include "player.h"
#include "ui.h"
#include "error.h"
#include "events.h"
#include "items.h"

//------------------------------------------------------------------------------------
// main.c
// Main file of our game.
//------------------------------------------------------------------------------------

int main(void)
{
    initUI();

    // Créer le Player.
    Player joueur;
    initPlayer(&joueur); // Evite les probleme de variable aleatoire.

    // Intro.
    printf("Entrer un nom : ");
    scanf("%s", joueur.name);

    printf("Choisisez une classe.\n");
    printf("\t[ \033[93mChevalier\033[0m ] (\033[33m1\033[0m) [\033[31mATK\033[0m: 20] [\033[34mDEF\033[0m: 15] [\033[92mHP\033[0m: 150]\n\t\tLe Chevalier est un courageux aventurier qui se sert de son epee pour vaincre son ennemie.\n\n");
    printf("\t[ \033[93m Sorcier\033[0m  ] (\033[33m2\033[0m) [\033[31mATK\033[0m: 15] [\033[34mDEF\033[0m: 20] [\033[92mHP\033[0m: 200]\n\t\tLe Sorcier utilise ses livres pour lancer des sorts a ses ennemies ou a lui meme.\n\n");
    printf("\t[ \033[93m Archere\033[0m  ] (\033[33m3\033[0m) [\033[31mATK\033[0m: 15] [\033[34mDEF\033[0m: 20] [\033[92mHP\033[0m: 180]\n\t\tL'Archere utilise ses fleche pour combattre son ennemi, elle peut egalement personnaliser les fleches\n\t\tavec des materiaux pour les rendres plus forte.\n\n");
    printf("\t[ \033[93m Lyriste\033[0m  ] (\033[33m4\033[0m) [\033[31mATK\033[0m: 20] [\033[34mDEF\033[0m: 15] [\033[92mHP\033[0m: 150]\n\t\tLe Lyriste peut attaquer ses ennemies a l'aide de ses chants et de sa lyre divine.\n\n");
    printf("Tapez un nombre (1-4) : ");
    scanf("%d", &joueur.type); // Recupère le Type de classe du joueur.

    Items epee_1;
    epee_1.id = 1;
    itemSetName(&epee_1, "Epee en pierre");
    itemSetDescription(&epee_1, "Epee du camp d'entrainement.");
    epee_1.attackPlus = 0;
    epee_1.defensePlus = 0;
    epee_1.sellPrice = 10;

    Items livre_1;
    livre_1.id = 2;
    itemSetName(&livre_1, "Grimoire de l'Apprenti");
    itemSetDescription(&livre_1, "Livre magique destiné au apprenti.");
    livre_1.attackPlus = 0;
    livre_1.defensePlus = 0;
    livre_1.sellPrice = 10;

    Items arc_1;
    arc_1.id = 3;
    itemSetName(&arc_1, "Arc en Bois");
    itemSetDescription(&arc_1, "Arc des apprentis archers.");
    arc_1.attackPlus = 0;
    arc_1.defensePlus = 0;
    arc_1.sellPrice = 10;

    Items lyre_1;
    lyre_1.id = 4;
    itemSetName(&lyre_1, "Lyre en Bois");
    itemSetDescription(&lyre_1, "Lyre destine au apprentis.");
    lyre_1.attackPlus = 0;
    lyre_1.defensePlus = 0;
    lyre_1.sellPrice = 10;


    switch (joueur.type) {
        case CHEVALIER_T:
            giveItems(&joueur, &epee_1);
            break;
        case SORCIER_T:
            giveItems(&joueur, &livre_1);
            break;
        case ARCHERE_T:
            giveItems(&joueur, &arc_1);
            break;
        case LYRISTE_T:
            giveItems(&joueur, &lyre_1);
            break;
        default:
            Error("Numero de class Invalide.", 1);
    }

    initUI();

    while (GAME_RUNNING)
    {
        DrawMainFrame(118, 25);
        WriteText(3, 2, "Nom    : \033[34m%s \033[0m", getName(&joueur));
        WriteText(3, 3, "Niveau : \033[32m%d\033[0m / \033[32m100 \033[0m", getLevel(&joueur));
        WriteText(3, 4, "Argent : \033[33m%d $ \033[0m", getCoin(&joueur));
        addLevel(&joueur, 1);
        addCoin(&joueur, 100);

        int input;
        input = getInput();

        switch (input)
        {
        case KEY_LEFT:
            Clear();
            printf("%d %d %d %d %d %d %d %d %d %d\n", joueur.items[0], joueur.items[1], joueur.items[3], joueur.items[4], joueur.items[5], joueur.items[6], joueur.items[7], joueur.items[8], joueur.items[9]);
            Pause();
            break;
        case KEY_RIGHT:
            Error("DROITE", 1);
            break;
        case KEY_UP:
            Error("HAUT", 1);
            break;
        case KEY_DOWN:
            Error("BAS", 1);
            break; 
        case KEY_Q:
            DrawFrame(40, 5, 70, 17);
            WriteText(42, 6, "Inventaire");
            moveCursor(40, 7);
            DrawLine(204, 1);
            DrawLine(205, 68);
            DrawLine(185, 1);

            ListItems(&joueur, 42, 9);

            moveCursor(1, 26);
            Pause();
            break;
        default:
            break;
        }

        Clear();
    }
    
    Pause();
    return 0;
}
