OBJS	= workout.o exercise.o
SOURCE	= workout.cpp exercise.cpp
HEADER	= exercise.h
OUT	= workout.exe
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

workout.o: workout.cpp
	$(CC) $(FLAGS) workout.cpp 

exercise.o: exercise.cpp
	$(CC) $(FLAGS) exercise.cpp 


clean:
	rm -f $(OBJS) $(OUT)