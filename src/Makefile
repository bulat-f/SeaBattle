objects := main.o board.o coord.o boardelement.o ship.o element.o hit.o map.o mapelement.o
flags := -Wall -std=c++11
obj_flags = -c $(flags)
SeaBattle: $(objects)
	g++ $(flags) $(objects) -o SeaBattle
main.o: main.cpp
	g++ $(obj_flags) main.cpp
board.o: board.cpp grid.h
	g++ $(obj_flags) board.cpp
coord.o: coord.cpp
	g++ $(obj_flags) coord.cpp
boardelement.o: boardelement.cpp hit.o
	g++ $(obj_flags) boardelement.cpp
ship.o: ship.cpp
	g++ $(obj_flags) ship.cpp
element.o: element.cpp hit.o
	g++ $(obj_flags) element.cpp
hit.o: hit.cpp
	g++ $(obj_flags) hit.cpp
map.o: map.cpp
	g++ $(obj_flags) map.cpp
mapelement.o: mapelement.cpp
	g++ $(obj_flags) mapelement.cpp
clear:
	rm -f *.o *~ SeaBattle
