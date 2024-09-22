CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -I.
GUIFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
VALGRIND_FLAGS = -v --leak-check=full --show-leak-kinds=all --error-exitcode=99

# Source files
SOURCES_DEMO = Tree.cpp main.cpp
TEST_S=TestCounter.cpp Test.cpp 

# Object files
OBJECTS_DEMO = $(SOURCES_DEMO:.cpp=.o)
TEST_OBJECTS=$(subst .cpp,.o,$(TEST_S))

.PHONY: all tree test clean valgrind

# Default target to build and run main
all: tree

# Build and run the main program
tree: $(OBJECTS_DEMO)
	$(CXX) $(CXXFLAGS) $^ -o main $(GUIFLAGS)
	./main

# Build test executable
test: $(CODE_OBJECTS) $(SOURCES_TEST)
	$(CXX) $(CXXFLAGS) $^ -o test -lstdc++ -lm

# Run valgrind to check for memory leaks
valgrind: main
	valgrind $(VALGRIND_FLAGS) ./main

TestCounter.o: TestCounter.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@	

# Rule to compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up the build artifacts
clean:
	rm -f *.o main test