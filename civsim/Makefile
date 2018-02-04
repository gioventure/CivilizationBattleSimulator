objects = main.o unit.o terrain.o

civsim : $(objects)
	g++ -o civsim $(objects)

$(objects) : unit.h terrain.h

.PHONY : clean
clean:
	-rm civsim $(objects)
