TOP_DIR = .
INC_DIR = $(TOP_DIR)/inc
SRC_DIR = $(TOP_DIR)/src
BUILD_DIR = $(TOP_DIR)/build
CC=gcc
FLAGS = -g -std=c99 -Wall -I$(INC_DIR)
OBJS = $(BUILD_DIR)/sort.o

default: all

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(FLAGS) -c -o $@ $<

all: $(OBJS)
	$(CC) $(FLAGS) $(SRC_DIR)/main.c -o test $(OBJS)

test: all
	./test

clean:
	-rm -f $(BUILD_DIR)/*.o test
