/*
Because this isn't a traditional ui library, there are no windows proper. Instead, this is used as the child of all objects. In addition, popups (dialog boxes, for example) are instances of UiWindow.
*/

#ifndef UI_WINDOW
#define UI_WINDOW

#include "utils/vector.h"

typedef struct {
    UiVector children; // Yes, this UI library uses a tree system. Shocking, I know.
} UiWindow;

#endif
