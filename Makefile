CC = g++
FLAGS = -Wall

all: 
	@printf "Usage: \n    make [problem]\n"

%:
	$(CC) $(FLAGS) $*.cpp -o $*.elf
	@[ -f $*.elf ] && \
		[ -f "indata/$*/in.txt" ] && \
		./$*.elf < indata/$*/in.txt || \
		true

.PHONY: clean
clean:
	rm -f *.elf

