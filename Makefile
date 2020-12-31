CXX = g++
CXXFLAGS = -std=c++2a -Wall -I h -I /usr/local/include/gtest/ -c -O3
LXXFLAGS = -std=c++2a -Ih -pthread
OBJECTS = main.o project.o Node.o  
GTEST = /usr/local/lib/libgtest.a
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) -o $(TARGET) $(OBJECTS) $(GTEST)
project.o: ./cpp/project.cpp ./h/project.h 
	$(CXX) $(CXXFLAGS) ./cpp/project.cpp -o project.o
Node.o: ./cpp/Node.cpp  ./h/Node.h  ./h/project.h
	$(CXX) $(CXXFLAGS) ./cpp/Node.cpp -o Node.o
main.o: ./cpp/main.cpp ./h/project.h ./h/Node.h 
	$(CXX) $(CXXFLAGS) ./cpp/main.cpp -o main.o

clean:
	rm -fv $(TARGET) $(OBJECTS)
