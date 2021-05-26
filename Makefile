# variables declaration
CC=g++
BOARD_FOLDER_PATH =./Board
PLAYER_FOLDER_PATH =./Player
OUTPUT_EXECUTABLE = game

$(OUTPUT_EXECUTABLE): main.o board.o player.o
	$(CC) main.o board.o player.o -o game

main.o: main.cpp 
	$(CC) -c main.cpp 

board.o: $(BOARD_FOLDER_PATH)/board.cpp 
	$(CC) -c $(BOARD_FOLDER_PATH)/board.cpp 

player.o: $(PLAYER_FOLDER_PATH)/player.cpp 
	$(CC) -c $(PLAYER_FOLDER_PATH)/player.cpp 

clean:
	rm *.o $(OUTPUT_EXECUTABLE)