#include <string.h>
#include "include/utils.h"

int remove_whitespace(char* src)
{
    if(src == NULL)
        return 1;

    int n = 0;
    for (int i = 0; i < strlen(src); ++i)
    {
        if(src[i] != ' ')
        {
            src[n++] = src[i];
        }
    }
    src[n] = '\0';
    return 0;
}