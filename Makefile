CC = g++
FLAGS = -Wall
EXEC = WaterMap

all:
	$(CC) src/main.cpp -o $(EXEC) $(FLAGS)

clean:
	rm $(EXEC)
