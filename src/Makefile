main_obj := main.o game.o board.o coord.o boardelement.o ship.o element.o hit.o map.o mapelement.o player.o computer.o view.o boardelemview.o mapelemview.o
flags := -Wall -std=c++11
obj_flags = -c $(flags)
SeaBattle: $(main_obj)
	g++ $(flags) $(main_obj) -o SeaBattle
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
map.o: map.cpp grid.h
	g++ $(obj_flags) map.cpp
mapelement.o: mapelement.cpp
	g++ $(obj_flags) mapelement.cpp
game.o: game.cpp
	g++ $(obj_flags) game.cpp
player.o: player.cpp
	g++ $(obj_flags) player.cpp
computer.o: computer.cpp
	g++ $(obj_flags) computer.cpp
view.o: view.cpp
	g++ $(obj_flags) view.cpp
boardelemview.o: boardelemview.cpp
	g++ $(obj_flags) boardelemview.cpp
mapelemview.o: mapelemview.cpp
	g++ $(obj_flags) mapelemview.cpp
clear:
	rm -f *.o *~ SeaBattle
