CXX = g++
CXXFLAGS = -std=c++2a -Wall -I h -I /usr/local/include/gtest/ -c -O3
LXXFLAGS = -std=c++2a -Ih -pthread
OBJECTS =  bfs.o main.o 
GTEST = /usr/local/lib/libgtest.a
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) -o $(TARGET) $(OBJECTS) $(GTEST)
bfs.o: ./cpp/bfs.cpp 
	$(CXX) $(CXXFLAGS) ./cpp/bfs.cpp -o bfs.o
main.o: ./cpp/main.cpp
	$(CXX) $(CXXFLAGS) ./cpp/main.cpp -o main.o

clean:
	rm -fv $(TARGET) $(OBJECTS)
