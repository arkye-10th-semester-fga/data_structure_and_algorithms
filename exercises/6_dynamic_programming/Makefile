# Source Code

Q1 = q1c
Q1_CODE = $(Q1).cpp
Q2 = q2b
Q2_CODE = $(Q2).cpp
Q6 = q6
Q6_CODE = $(Q6).cpp
Q7 = q7
Q7_CODE = $(Q7).cpp
Q9 = q9
Q9_CODE = $(Q9).cpp

# Compilation Settings
FLAGS_C = -O2 -lm -Wall
FLAGS_CPP = -std=c++14 $(FLAGS_C)
COMPILE_Q1 = g++ $(FLAGS_CPP) $(Q1_CODE) -o $(Q1)
COMPILE_Q2 = g++ $(FLAGS_CPP) $(Q2_CODE) -o $(Q2)
COMPILE_Q6 = g++ $(FLAGS_CPP) $(Q6_CODE) -o $(Q6)
COMPILE_Q7 = g++ $(FLAGS_CPP) $(Q7_CODE) -o $(Q7)
COMPILE_Q9 = g++ $(FLAGS_CPP) $(Q9_CODE) -o $(Q9)

.PHONY: all $(Q1) $(Q2) $(Q6) $(Q7) $(Q9) clean

all:
	@make q1c --always-make --no-print-directory
	@make q2 --always-make --no-print-directory
	@make q6 --always-make --no-print-directory
	@make q7 --always-make --no-print-directory
	@make q9 --always-make --no-print-directory

$(Q1): $(Q1_CODE)
	$(COMPILE_Q1)

$(Q2): $(Q2_CODE)
	$(COMPILE_Q2)

$(Q6): $(Q6_CODE)
	$(COMPILE_Q6)

$(Q7): $(Q7_CODE)
	$(COMPILE_Q7)

$(Q9): $(Q9_CODE)
	$(COMPILE_Q9)

clean:
	@echo "\nCLEANING CONTENT"
	@rm -f $(Q1) $(Q2) $(Q6) $(Q7) $(Q9)
