#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "error.h"

int Error(const char *ErrorText, int ErrorCode)
{
    char buffer[2000];
    strcpy(buffer, ErrorText);
    system("cls");
    printf("\033[31mERROR\033[0m: %s\n", buffer);
    system("pause");
    exit(ErrorCode);
    return 0;
}
