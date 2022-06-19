/*
This vector library exists primarily for the backend. You *can* use it, but it's not the point.
That being said, it's a pretty solid vector system. It uses (void*)s, so it's extendable enough.
*/

#ifndef UI_VECTOR
#define UI_VECTOR

#include <stddef.h>
#include <stdbool.h>

#define UI_VECTOR_INIT_CAPACITY 8
#define UI_VECTOR_GROWTH_MULT   2

typedef struct {
    void**  data;
    size_t  max;
    size_t  count;
} UiVector;

void  ui_vector_init   (UiVector* vector);
void  ui_vector_resize (UiVector* vector, size_t new_size               );
void  ui_vector_push   (UiVector* vector, void*  element                );
void  ui_vector_set    (UiVector* vector, size_t index,   void* element );
void* ui_vector_get    (UiVector* vector, size_t index                  );
void  ui_vector_pop    (UiVector* vector, size_t index                  );
void  ui_vector_free   (UiVector* vector                                );

#endif
