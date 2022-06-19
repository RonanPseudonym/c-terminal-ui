C := tests/main.c utils/vector.c utils/error.c
H := utils/vector.h object.h window.h utils/error.h utils/ansi.h

build: $(C) $(H)
	gcc $(C) -o ui_test

run: build
	./ui_test
