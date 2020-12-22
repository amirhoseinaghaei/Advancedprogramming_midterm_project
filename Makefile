CXX = g++
CXXFLAGS = -std=c++2a -Wall -I h -I /usr/local/include/gtest/ -c -O3
LXXFLAGS = -std=c++2a -Ih -pthread
OBJECTS = main.o bfs.o  
GTEST = /usr/local/lib/libgtest.a
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) -o $(TARGET) $(OBJECTS) $(GTEST)
bfs.o: ./cpp/bfs.cpp  ./h/bfs.h  ./h/project.h
	$(CXX) $(CXXFLAGS) ./cpp/bfs.cpp -o bfs.o
# dfs.o: ./cpp/dfs.cpp ./h/dfs.h ./h/bfs.h ./h/project.h
# 	$(CXX) $(CXXFLAGS) ./cpp/dfs.cpp -o dfs.o
main.o: ./cpp/main.cpp ./h/project.h ./h/bfs.h 
	$(CXX) $(CXXFLAGS) ./cpp/main.cpp -o main.o

clean:
	rm -fv $(TARGET) $(OBJECTS)
