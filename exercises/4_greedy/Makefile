# Source Code

Q4 = q4
Q4_CODE = $(Q4).cpp
Q7 = q7
Q7_CODE = $(Q7).cpp
Q15 = q15
Q15_CODE = $(Q15).cpp

# Compilation Settings
FLAGS = -std=c++14 -O2 -lm -Wall
COMPILE_Q4 = g++ $(FLAGS) $(Q4_CODE) -o $(Q4)
COMPILE_Q7 = g++ $(FLAGS) $(Q7_CODE) -o $(Q7)
COMPILE_Q15 = g++ $(FLAGS) $(Q15_CODE) -o $(Q15)

.PHONY: all q4 q7 clean

all:
	@make q4 --always-make --no-print-directory
	@make q7 --always-make --no-print-directory
	@make q15 --always-make --no-print-directory

q4: q4.cpp
	$(COMPILE_Q4)

q7: q7.cpp
	$(COMPILE_Q7)

q15: q15.cpp
	$(COMPILE_Q15)

clean:
	@echo "\nCLEANING CONTENT"
	@rm -f $(Q4) $(Q7) $(Q15)
