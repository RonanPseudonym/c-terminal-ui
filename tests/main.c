/*
These are dev tools.
They're not good code.
They're not useful examples.

Please, for the love of god, don't read them.
*/

#include <stdio.h>
#include "../utils/error.h"
#include "../utils/vector.h"

int main() {
    UiVector* vector;
    ui_vector_init(vector);

    ui_vector_push(vector, "Hello");
    ui_vector_push(vector, "World");
    ui_vector_push(vector, ":D");

    printf("%s\n", (char*)ui_vector_get(vector, 4));
}
