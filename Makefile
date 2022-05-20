CC = g++
FLAGS = -Wall

all: 
	@printf "Usage: \n    make [problem.elf]\n"

%.elf: %.cpp
	$(CC) $(FLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f *.elf

