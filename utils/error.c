#include <stdio.h>
#include <stdlib.h>

#include "error.h"
#include "ansi.h"

void ui_error(const char* location, const char* text) {
    printf("%s[ERROR]%s %s%s%s :: %s\n",
            UI_ANSI_BOLD
            UI_ANSI_RED,
            UI_ANSI_RESET,
            UI_ANSI_BOLD,
            location,
            UI_ANSI_RESET,
            text);

    exit(255);
}
