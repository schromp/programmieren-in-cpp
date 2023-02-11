CXX = g++
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
CXXFLAGS = --std=c++11
RM = rm -f
TARGET = database

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) $(TARGET) $(OBJ)
