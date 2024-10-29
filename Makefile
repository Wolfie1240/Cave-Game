# Makefile for Wumpus Game

CC = g++
CFLAGS = -std=c++11 -Wall

# List of source files
SRCS = main.cpp game.cpp player.cpp room.cpp event.cpp pit.cpp gold.cpp bats.cpp wumpus.cpp wumpus_game.cpp

# List of header files
HDRS = game.h player.h room.h event.h pit.h gold.h bats.h wumpus.h wumpus_game.h

# List of object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = run_wumpus

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
