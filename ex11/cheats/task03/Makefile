CXX = g++
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
CXXFLAGS = --std=c++11 -g3 -O0
RM = rm -f
TARGET = algo

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) $(TARGET) $(OBJ)
