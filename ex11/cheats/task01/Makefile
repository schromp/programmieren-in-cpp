CXX = g++
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
CXXFLAGS = --std=c++11
RM = rm -f
TARGET = containers

all: $(TARGET)

FIX_A: $(OBJ)
	$(CXX) $(CXXFLAGS) -DFIX_A -o $(TARGET) $^

FIX_B: $(OBJ)
	$(CXX) $(CXXFLAGS) -DFIX_B -o $(TARGET) $^

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) $(TARGET) $(OBJ)
