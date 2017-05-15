# Source Code

Q3 = q3_merge
Q3_CODE = $(Q3).cpp

Q4 = q4_radix
Q4_CODE = $(Q4).cpp

Q6 = q6_median
Q6_CODE = $(Q6).cpp

DEPENDENCY_IO = io.cpp
DEPENDENCY_LIST_CREATOR= list_creator.cpp
DEPENDENCIES =  $(DEPENDENCY_IO) $(DEPENDENCY_LIST_CREATOR)

# Compilation Settings
FLAGS = -std=c++14 -O2 -lm -Wall
COMPILE_GNUPLOT = g++ -O3 -c -o gnuplot_i.o gnuplot_i.c
COMPILE_Q3 = g++ -std=c++14 gnuplot_i.o $(Q3_CODE) $(DEPENDENCIES) -o $(Q3)
COMPILE_Q4 = g++ $(FLAGS) $(Q4_CODE) $(DEPENDENCIES) -o $(Q4)
COMPILE_Q6 = g++ $(FLAGS) $(Q6_CODE) -o $(Q6)

.PHONY: all q3 q4 q5 q6 test clean

all:
	@make q3 --always-make --no-print-directory
	@make q4 --always-make --no-print-directory
	@make q5 --always-make --no-print-directory
	@make q6 --always-make --no-print-directory

q3:
	$(COMPILE_GNUPLOT)
	$(COMPILE_Q3)

q4:
	$(COMPILE_Q4)

q5:
	$(COMPILE_Q5)

q6:
	$(COMPILE_Q6)

clean:
	@echo "\nCLEANING CONTENT"
	@rm -f gnuplot_i.o gnuplot_tmpdatafile_* $(Q3) $(Q4) $(Q5) $(Q6)
