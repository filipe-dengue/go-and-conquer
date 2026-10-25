
AQUIVOS_O :=build/main.o build/menu_config.o build/menu_principal.o
FLAGS :=-Lraylib/raylib-linux/lib -Wl,-Bstatic -lraylib -Wl,-Bdynamic -lm -lpthread -ldl -lrt -lX11
INCLUDES :=-Iincludes -Iraylib/raylib-linux/include -Iraylib/raygui/src

go_and_conquer.elf: build/ $(AQUIVOS_O)
	gcc -o go_and_conquer.elf $(AQUIVOS_O) $(INCLUDES) $(FLAGS)

build/main.o: src/main.c
	gcc -c src/main.c $(INCLUDES) $(FLAGS) -o build/main.o

build/menu_config.o: src/telas/menu_config.c includes/telas.h
	gcc -c src/telas/menu_config.c $(INCLUDES) $(FLAGS) -o build/menu_config.o

build/menu_principal.o: src/telas/menu_principal.c includes/telas.h
	gcc -c src/telas/menu_principal.c $(INCLUDES) $(FLAGS) -o build/menu_principal.o

build/:
	mkdir build/

clear:
	rm go_and_conquer.elf; rm -r build
