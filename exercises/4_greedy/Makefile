# Source Code

Q4 = q4
Q4_CODE = $(Q4).cpp
Q5 = q5
Q5_CODE = $(Q5).c
Q7 = q7
Q7_CODE = $(Q7).cpp
Q13 = q13
Q13_CODE = $(Q13).c
Q15 = q15
Q15_CODE = $(Q15).cpp

# Compilation Settings
FLAGS_C = -O2 -lm -Wall
FLAGS_CPP = -std=c++14 $(FLAGS_C)
COMPILE_Q4 = g++ $(FLAGS_CPP) $(Q4_CODE) -o $(Q4)
COMPILE_Q5 = gcc $(FLAGS_C) $(Q5_CODE) -o $(Q5)
COMPILE_Q7 = g++ $(FLAGS_CPP) $(Q7_CODE) -o $(Q7)
COMPILE_Q13 = gcc $(FLAGS_C) $(Q13_CODE) -o $(Q13)
COMPILE_Q15 = g++ $(FLAGS_CPP) $(Q15_CODE) -o $(Q15)

.PHONY: all q4 q5 q7 q13 clean

all:
	@make q4 --always-make --no-print-directory
	@make q7 --always-make --no-print-directory
	@make q15 --always-make --no-print-directory

q4: q4.cpp
	$(COMPILE_Q4)

q5: q5.c
	$(COMPILE_Q5)

q7: q7.cpp
	$(COMPILE_Q7)

q13: q13.c
		$(COMPILE_Q13)

q15: q15.cpp
	$(COMPILE_Q15)

clean:
	@echo "\nCLEANING CONTENT"
	@rm -f $(Q4) $(Q5) $(Q7) $(Q13) $(Q15)
