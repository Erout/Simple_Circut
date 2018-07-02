FLAGS := -std=c++11
Objs := main.o circuitControl.o doorAnd.o doorNot.o doorOr.o doorAndNot.o doorOrNot.o
Hpps := circuitControl.hpp door.hpp doorAnd.hpp doorNot.hpp doorOr.hpp doorAndNot.hpp doorOrNot.hpp 

circuit: $(Objs)
	g++ $(FLAGS) -o circuit $(Objs)

main.o: main.cpp $(Hpps)
	g++ $(FLAGS) -c main.cpp

circuitControl.o: circuitControl.cpp $(Hpps)
	g++ $(FLAGS) -c circuitControl.cpp

doorAnd.o: doorAnd.cpp door.hpp doorAnd.hpp
	g++ $(FLAGS) -c doorAnd.cpp

doorNot.o: doorNot.cpp door.hpp doorNot.hpp
	g++ $(FLAGS) -c doorNot.cpp

doorOr.o: doorOr.cpp door.hpp doorOr.hpp
	g++ $(FLAGS) -c doorOr.cpp

doorAndNot.o: doorAndNot.cpp door.hpp doorAndNot.hpp
	g++ $(FLAGS) -c doorAndNot.cpp

doorOrNot.o: doorOrNot.cpp door.hpp doorOrNot.hpp
	g++ $(FLAGS) -c doorOrNot.cpp

clean:
	rm circuit $(Objs)