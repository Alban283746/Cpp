# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = main2
SRCS = main2.cpp ex2.cpp

# Règles
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)
