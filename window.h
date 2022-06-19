#ifndef UI_WINDOW
#define UI_WINDOW

#include "utils/vector.h"

typedef struct {
    void*    window;
    UiVector children;
} UiWindow;

#endif
