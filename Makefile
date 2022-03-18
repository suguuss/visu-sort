CC		:= g++
FLAGS	:= -Wall -Wextra -g -fsanitize=leak -fsanitize=undefined -fsanitize=address
LIB		:= 

SRC		:= src
BUILD	:= build

.PHONY: all run clean pre-build

all: $(BUILD)/main

# Main prog
$(BUILD)/main: $(BUILD)/main.o
	$(CC) $^ -o $@ $(FLAGS) $(LIB)

$(BUILD)/main.o: $(SRC)/main.cpp pre-build
	$(CC) -c $< -o $@ $(FLAGS) $(LIB)

run: $(BUILD)/main
	./$<

clean:
	rm -f $(BUILD)/*

pre-build:
	mkdir -p $(BUILD)
