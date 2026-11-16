CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic
TARGET = biblioteca
SRC = src/main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).exe
	rm -f data/*.dat data/*.txt
