CC = g++
FLAGS = -Wall

all: 
	@printf "Usage: \n    make [problem.elf]\n"

%:
	$(CC) $(FLAGS) $*.cpp -o $*.elf && \
		./$*.elf < indata/$*/in.txt

.PHONY: clean
clean:
	rm -f *.elf

