# Compiler to use
CXX = g++

# Compiler flags (for debugging and optimization)
CXXFLAGS = -Wall -std=c++17 -I.

# Source files
SRC = main.cpp card.cpp energy_card.cpp player.cpp pokemon_card.cpp trainer_card.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Executable file name
EXE = main

# Default target to build the executable
all: $(EXE)

# Rule to build the executable
$(EXE): $(OBJ)
	$(CXX) $(OBJ) -o $(EXE)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean up the project (remove object files and the executable)
clean:
	rm -f $(OBJ) $(EXE)
