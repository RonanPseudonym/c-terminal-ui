#include <stdlib.h>
#include <stdio.h>

#include "vector.h"
#include "error.h"

void ui_vector_init(UiVector* vector) {
    vector->max   = UI_VECTOR_INIT_CAPACITY;
    vector->count = 0;
    vector->data  = malloc(sizeof(void*) * vector->max);
}

void ui_vector_resize(UiVector* vector, size_t new_size) {
    if (vector) {
        void** data = realloc(vector->data, sizeof(void*) * vector->max);
        if (data) {
            vector->data = data;
            vector->max  = new_size;
            return;
        }
    } else {
        ui_error("ui_vector_resize", "UiVector is null");
    }

    ui_error("ui_vector_resize", "Unable to reallocate needed memory to UiVector (are you out of RAM?)\n");
}

void ui_vector_push(UiVector* vector, void* element) {
    if (vector) {
        if (vector->count == vector->max) {
            ui_vector_resize(vector, vector->max * UI_VECTOR_GROWTH_MULT);
        }
        vector->data[vector->count++] = element;
    } else {
        ui_error("ui_vector_push", "UiVector is null");
    }
}

void ui_vector_set(UiVector* vector, size_t index, void* value) {
    if (vector) {
        if (index < vector->count && index >= 0) {
            vector->data[index] = value;
        } else {
            ui_error("ui_vector_set", "Index out of bounds");
        }
    } else {
        ui_error("ui_vector_set", "UiVector is null");
    }
}

void* ui_vector_get(UiVector* vector, size_t index) {
    if (vector) {
        if (index < vector->count && index >= 0) {
            return vector->data[index];
        } else {
            ui_error("ui_vector_get", "Index out of bounds");
        }
    } else {
        ui_error("ui_vector_get", "UiVector is null");
    }
}

void ui_vector_delete(UiVector* vector, size_t index) {
    if (vector) {
        if (index < vector->count && index >= 0) {
            vector->data[index] = NULL;
            vector->count--;

            for (size_t i = index; i < vector->count; ++i) {
                vector->data[i] = vector->data[i + 1];
                vector->data[i + 1] = NULL;
            }

            if (    vector->count > 0 &&
                    vector->count == vector->max / (UI_VECTOR_GROWTH_MULT * 2)) {
                ui_vector_resize(vector, vector->max / UI_VECTOR_GROWTH_MULT);
            }

        } else {
            ui_error("ui_vector_delete", "Index out of bounds");
        }
    } else {
        ui_error("ui_vector_delete", "UiVector is null");
    }
}

void ui_vector_free(UiVector* vector) {
    if (vector) {
        for (size_t i = 0; i < vector->count; ++i) {
            free(vector->data[i]);
        }

        free(vector->data);
        free(vector);
    } else {
        ui_error("ui_vector_free", "UiVector is (already!) null");
    }
}
