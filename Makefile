SRC_DIR := src
OBJ_DIR := obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
INCLUDES := -Iinclude/
LDFLAGS := -lSDL2 -g -lSDL2main -lm -lGLEW -lGL -lpthread -lcjson
CPPFLAGS := -Wall -g -O2

bin/fbla2025-pf: $(OBJ_FILES)
	gcc $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc $(CPPFLAGS) -c -o $@ $<

run:
	./bin/fbla2025-pf
