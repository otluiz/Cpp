CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

SRC = fibonacciGPT.cpp
OBJ = $(SRC:.cpp=.o)
EXECUTABLE = fibo

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)
