#MakeFile de myPing
#Notas: $@ es el nombre del target que se está generando y $< es el primer pre-requisito .$^ sonb todos los requisitos.

CC 			= gcc
INC_DIR 	= include
SRC_DIR 	= src
OBJ_DIR 	= obj
BIN_DIR 	= bin
PRJ_DIR 	= .

#Nombre del ejecutable
EXE = myPingClient

#Ficheros de codigo
SRC = $(wildcard $(SRC_DIR)/*.c)

#Lista de objetos
#OBJ := $(pathsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o $(SRC))
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

#DEPS    := $(wildcard $(INC_DIR)/*.h)


CFLAGS		:= -g -Wall -Wextra -I$(PRJ_DIR) 
#CFLAGS		:= -g -Wall -Wextra -I$(DEPS) 
CPPFLAGS 	:=
LDFLAGS 	:= -Llib
LDLIBS 		:=  -lm

.PHONY: all clean info

all: $(EXE)

#main:  main.c
#		gcc -Wall -g -I$INCLUDE_DIR -o ./bin/myPing ./src/myPing.c

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $(BIN_DIR)/$@
	

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@


$(BIN_DIR) $(OBJ_DIR):
	mkdir -p  $@

clean: 
	@rm -rv $(BIN_DIR) $(OBJ_DIR)

info: 
	$(info Source is ${SRC})
	$(info Object is $(OBJ))
	$(info BIN dir is $(BIN_DIR))
	$(info EXE is $(EXE))
