objects := main.o board.o coord.o boardelement.o ship.o element.o
flags := -Wall -std=c++11
obj_flags = -c $(flags)
SeaBattle: $(objects)
	g++ $(flags) $(objects) -o SeaBattle
main.o: main.cpp
	g++ $(obj_flags) main.cpp
board.o: board.cpp grid.h hitinfo.h
	g++ $(obj_flags) board.cpp
coord.o: coord.cpp
	g++ $(obj_flags) coord.cpp
boardelement.o: boardelement.cpp
	g++ $(obj_flags) boardelement.cpp hitinfo.h
ship.o: ship.cpp
	g++ $(obj_flags) ship.cpp
element.o: element.cpp hitinfo.h
	g++ $(obj_flags) element.cpp
clear:
	rm -f *.o *~
