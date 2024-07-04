TARGET_EXEC = main
CC = g++
OBJ = $(TARGET_EXEC).o Vector.o vec_container.o list_container.o Container.o Shape.o Circle.o Smiley.o my_complex.o

$(TARGET_EXEC): $(OBJ)
	$(CC) -o $(TARGET_EXEC) $(OBJ)
clean:
	rm *.o
	rm $(TARGET_EXEC)
