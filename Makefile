# variables declaration
CC=g++
BOARD_FOLDER_PATH =./Board
OUTPUT_EXECUTABLE = game

$(OUTPUT_EXECUTABLE): main.o board.o
	$(CC) main.o board.o -o game

main.o: main.cpp 
	$(CC) -c main.cpp 

board.o: $(BOARD_FOLDER_PATH)/board.cpp 
	$(CC) -c $(BOARD_FOLDER_PATH)/board.cpp 

clean:
	rm *.o $(OUTPUT_EXECUTABLE)