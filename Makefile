# Get the base of the makefile.
MAKE_BASE = $(shell pwd)
PROBLEMS := $(wildcard Problems/Problem*)
MAIN_FILES = $(wildcard *.cpp)
FUNCTION_FILES = $(wildcard Functions/*.cpp)
PROBLEM = 0

define MAKE_CORE
    @echo "Building problem loader...";
    @g++ -Wall -std=c++0x $(MAIN_FILES) $(FUNCTION_FILES) -ldl -o build/project-euler;
endef

define MAKE_LIB
    echo "Building $(notdir $(1))...";
    $(eval PROBLEM_FILES := $(wildcard $(1)/*.cpp))
    g++ -Wall -std=c++0x -O0 -shared $(PROBLEM_FILES) -o build/$(notdir $(1)).so;
endef

define CLEAN_LIB
    echo "Cleaning Problem in \"$(1)\"...";
    $(eval PROBLEM_FILES := $(wildcard $(1)/*.cpp))
    rm  build/$(notdir $(1)).so -f;
endef

all: loader all_problems

loader:	
	$(call MAKE_CORE)

all_problems:
	@$(foreach dir,$(PROBLEMS),$(call MAKE_LIB, $(dir)))

problem%:
	@$(call MAKE_LIB, Problems/$@)
	
clean:
	@echo "Cleaning build directory.";
	@rm build/* -f;