# Source Code

Q4 = q4
Q4_CODE = $(Q4).cpp

# Compilation Settings
FLAGS = -std=c++14 -O2 -lm -Wall
COMPILE_Q4 = g++ $(FLAGS) $(Q4_CODE) -o $(Q4)

.PHONY: all q4 test clean

all:
	@make q4 --always-make --no-print-directory

q4:
	$(COMPILE_Q4)

clean:
	@echo "\nCLEANING CONTENT"
	@rm -f $(Q4)
