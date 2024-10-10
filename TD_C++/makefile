# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = main
SRCS = main.cpp ex.cpp

# Règles
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)
