#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void Clear()
{
    system("cls");
}

void Pause()
{
    system("pause");
}

void moveCursor(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void initUI()
{
    Clear();
    moveCursor(0, 0);
}

void WriteText(int x, int y, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    char buffer[1000];
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    printf("\033[%d;%dH%s", y, x, buffer);
}

void DrawLine(char type, int nombreDeFois)
{
    int i = 0;
    for (i = 0; i < nombreDeFois; i++)
    {
        printf("%c", type);
    }
}

void DrawMainFrame(int largeur, int hauteur)
{
    char barre = 205;
    char barre_coin_haut_gauche = 201;
    char barre_coin_haut_droite = 187;
    char barre_coin_bas_gauche = 200;
    char barre_coin_bas_droite = 188;
    char barre_vertical = 186;

    int i;
    for (i = 0; i < hauteur; i++)
    {
        if (i == 0)
        {
            printf("%c", barre_coin_haut_gauche);
            DrawLine(barre, largeur - 2);
            printf("%c\n", barre_coin_haut_droite);
        }
        else if (i == hauteur - 1)
        {
            printf("%c", barre_coin_bas_gauche);
            DrawLine(barre, largeur - 2);
            printf("%c\n", barre_coin_bas_droite);
        }
        else
        {
            printf("%c", barre_vertical);
            printf("%*c\n", largeur - 1, barre_vertical);
        }
    }
}

void DrawFrame(int x, int y, int w, int h)
{

    char barre = 205;
    char barre_coin_haut_gauche = 201;
    char barre_coin_haut_droite = 187;
    char barre_coin_bas_gauche = 200;
    char barre_coin_bas_droite = 188;
    char barre_vertical = 186;

    for (int i = x + 1; i < x + w - 1; ++i) {
        printf("\033[%d;%dH%c", y, i, barre);
        printf("\033[%d;%dH%c", y + h - 1, i, barre);
    }

    for (int i = y + 1; i < y + h - 1; ++i) {
        printf("\033[%d;%dH%c", i, x, barre_vertical);
        printf("\033[%d;%dH%c", i, x + w - 1, barre_vertical);
    }

    printf("\033[%d;%dH%c", y, x, barre_coin_haut_gauche);
    printf("\033[%d;%dH%c", y, x + w - 1, barre_coin_haut_droite);
    printf("\033[%d;%dH%c", y + h - 1, x, barre_coin_bas_gauche);
    printf("\033[%d;%dH%c", y + h - 1, x + w - 1, barre_coin_bas_droite);
}
