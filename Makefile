CC = g++
FLAGS = -Wall

all: 
	@printf "Usage: \n    make [problem]\n"

%:
	$(CC) $(FLAGS) $*.cpp -o $*.elf
	@[ -d indata/$* ] && \
		find indata/$* -name 'in*.txt' | \
		while read f; do \
			echo "Testing $$f"; \
			[ -f "$$f" ] && \
				./$*.elf < "$$f" || \
				true; \
		done || \
		true

.PHONY: clean
clean:
	rm -f *.elf

