#ifndef UI_H
#define UI_H

#include <stdio.h>
#include <stdlib.h>

#define GAME_RUNNING 1

void Clear();
void Pause();
void initUI();
void WriteText(int x, int y, const char *format, ...);
void DrawLine(char type, int nombreDeFois); // Voir Dans ui.c les format (Mettre le code ASCII)
void DrawFrame(int x, int y, int largeur, int hauteur);
void DrawMainFrame(int largeur, int hauteur);

#endif
