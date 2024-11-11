# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I./lib/Task
SRC = main.c lib/Task/Task.c
OBJ = $(patsubst %.c,build/%.o,$(notdir $(SRC)))
TARGET = build/task_app

# Reglas
all: $(TARGET)

# Regla para crear el ejecutable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Regla para compilar archivos fuente a objetos
build/%.o: %.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

build/%.o: lib/Task/%.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar archivos generados
clean:
	rm -rf build/

# Regla para ejecutar el programa
run: $(TARGET)
	./$(TARGET)

