/*
Much like GTK's widgets, a UiObject is the base of every object (including window!) in this library.
It's mostly just a wrapper around a void pointer holding the actual object.
Used so that functions can have reasonable in and output types. What's the point in having a type system if you're gonna ignore it? This isn't EFL, folks.
*/

#ifndef UI_OBJECT
#define UI_OBJECT

typedef struct {
    void* unwrapped_object;
} UiObject;

#endif
