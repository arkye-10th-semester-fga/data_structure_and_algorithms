# Source Code
Q4 = q4_sequential
Q4_CODE = $(Q4).cpp

Q5 = q5_circular_binary
Q5_CODE = $(Q5).cpp

Q6 = q6_interpolation
Q6_CODE = $(Q6).cpp

DEPENDENCY_IO = io.cpp
DEPENDENCY_LIST_CREATOR= list_creator.cpp
DEPENDENCIES =  $(DEPENDENCY_IO) $(DEPENDENCY_LIST_CREATOR)

# Compilation Settings
FLAGS = -std=c++14 -O2 -lm -Wall
COMPILE_Q4 = g++ $(FLAGS) $(Q4_CODE) $(DEPENDENCIES) -o $(Q4)
COMPILE_Q5 = g++ $(FLAGS) $(Q5_CODE) $(DEPENDENCIES) -o $(Q5)
COMPILE_Q6 = g++ $(FLAGS) $(Q6_CODE) $(DEPENDENCIES) -o $(Q6)

# Others
BILLION = 1000000000

.PHONY: all q4 q5 q6 test clean

all:
	@make q4 --always-make --no-print-directory
	@make q5 --always-make --no-print-directory
	@make q6 --always-make --no-print-directory

q4:
	$(COMPILE_Q4)

q5:
	$(COMPILE_Q5)

q6:
	$(COMPILE_Q6)

test6:
	@make q6 --always-make --no-print-directory
	@echo "LAST ELEMENT BILLION STRESS TEST"
	./$(Q6) 10 10 $(BILLION)
	@echo "================================"
	./$(Q6) 25 25 $(BILLION)
	@echo "================================"
	./$(Q6) 50 50 $(BILLION)
	@echo "================================"
	./$(Q6) 100 100 $(BILLION)
	@echo "================================"
	./$(Q6) 500 500 $(BILLION)
	@echo "================================"
	./$(Q6) 1000 1000 $(BILLION)
	@echo "================================"
	./$(Q6) 10000 10000 $(BILLION)
	@echo "================================"
	./$(Q6) 100000 100000 $(BILLION)
	@echo "================================"
	./$(Q6) 1000000 1000000 $(BILLION)
	@echo "================================"

test6a:
	@make q6 --always-make --no-print-directory
	@echo "FIRST ELEMENT BILLION STRESS TEST"
	./$(Q6) 10 1 $(BILLION)
	@echo "================================"
	./$(Q6) 25 1 $(BILLION)
	@echo "================================"
	./$(Q6) 50 1 $(BILLION)
	@echo "================================"
	./$(Q6) 100 1 $(BILLION)
	@echo "================================"
	./$(Q6) 500 1 $(BILLION)
	@echo "================================"
	./$(Q6) 1000 1 $(BILLION)
	@echo "================================"
	./$(Q6) 10000 1 $(BILLION)
	@echo "================================"
	./$(Q6) 100000 1 $(BILLION)
	@echo "================================"
	./$(Q6) 1000000 1 $(BILLION)
	@echo "================================"

test6b:
	@make q6 --always-make --no-print-directory
	@echo "ELEMENT 10 BILLION STRESS TEST"
	./$(Q6) 10 10 $(BILLION)
	@echo "================================"
	./$(Q6) 25 10 $(BILLION)
	@echo "================================"
	./$(Q6) 50 10 $(BILLION)
	@echo "================================"
	./$(Q6) 100 10 $(BILLION)
	@echo "================================"
	./$(Q6) 500 10 $(BILLION)
	@echo "================================"
	./$(Q6) 1000 10 $(BILLION)
	@echo "================================"
	./$(Q6) 10000 10 $(BILLION)
	@echo "================================"
	./$(Q6) 100000 10 $(BILLION)
	@echo "================================"
	./$(Q6) 1000000 10 $(BILLION)
	@echo "================================"

clean:
	@echo "\nCLEANING CONTENT"
	@rm -f $(Q4) $(Q5) $(Q6)
