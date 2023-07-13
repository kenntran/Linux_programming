.PHONY: obj clean share 

PRJ_NAME := hello
SHARED_LIB_NAME := libhello.so
STATIC_LIB_NAME := libhello.a

CUR_DIR := .
INC_DIR := $(CUR_DIR)/inc
SRC_DIR := $(CUR_DIR)/src
OBJ_DIR := $(CUR_DIR)/obj
LIB_DIR := $(CUR_DIR)/lib
BIN_DIR := $(CUR_DIR)/bin

SHARED_DIR := $(LIB_DIR)/shared
STATIC_DIR := $(LIB_DIR)/static

CC := gcc
CFLAG := -c -fPIC -o

 
obj:
	$(CC) $(CFLAG) $(OBJ_DIR)/main.o $(CUR_DIR)/main.c -I $(INC_DIR)
	$(CC) $(CFLAG) $(OBJ_DIR)/hello_minh.o $(SRC_DIR)/hello_minh.c -I $(INC_DIR)
	$(CC) $(CFLAG) $(OBJ_DIR)/hello_main.o $(SRC_DIR)/hello_world.c -I $(INC_DIR)

all: obj shared
	$(CC) $(OBJ_DIR)/main.o -L$(SHARED_DIR) -lhello -o $(BIN_DIR)/$(PRJ_NAME)

all_static: obj static
	$(CC) $(OBJ_DIR)/main.o -L$(STATIC_DIR) -lhello -o $(BIN_DIR)/$(PRJ_NAME)

install:
	install $(SHARED_DIR)/$(SHARED_LIB_NAME) /usr/bin

shared:
	$(CC) -shared $(OBJ_DIR)/* -o $(SHARED_DIR)/$(SHARED_LIB_NAME)

static:
	ar rcs $(STATIC_DIR)/$(STATIC_LIB_NAME) $(OBJ_DIR)/*

clean:
	rm -rf $(OBJ_DIR)/*
	rm -rf $(SHARED_DIR)/*
	rm -rf $(STATIC_DIR)/*
	rm -rf $(BIN_DIR)/*
