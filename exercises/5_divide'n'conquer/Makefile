# Source Code

Q1 = q1
Q1_CODE = $(Q1).c
Q2 = q2
Q2_CODE = $(Q2).cpp
Q3 = q3
Q3_CODE = $(Q3).cpp
Q4 = q4
Q4_CODE = $(Q4).cpp

# Compilation Settings
FLAGS_C = -O2 -lm -Wall
FLAGS_CPP = -std=c++14 $(FLAGS_C)
COMPILE_Q1 = gcc $(FLAGS_C) $(Q1_CODE) -o $(Q1)
COMPILE_Q2 = g++ $(FLAGS_CPP) $(Q2_CODE) -o $(Q2)
COMPILE_Q3 = g++ $(FLAGS_CPP) $(Q3_CODE) -o $(Q3)
COMPILE_Q4 = g++ $(FLAGS_CPP) $(Q4_CODE) -o $(Q4)

.PHONY: all q1 q2 q3 q4 clean

all:
	@make q1 --always-make --no-print-directory
	@make q2 --always-make --no-print-directory
	@make q3 --always-make --no-print-directory
	@make q4 --always-make --no-print-directory

q1: q1.c
	$(COMPILE_Q1)

q2: q2.cpp
	$(COMPILE_Q2)

q3: q3.cpp
	$(COMPILE_Q3)

q4: q4.cpp
	$(COMPILE_Q4)

clean:
	@echo "\nCLEANING CONTENT"
	@rm -f $(Q1) $(Q2) $(Q3) $(Q4)
