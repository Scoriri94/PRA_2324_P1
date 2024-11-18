bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp ListArray.h

bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.h

bin/testListLinked: testListLinked.cpp ListLinked.h list.h
	mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp ListLinked.h

bin/testPoint2D: testPoint2D.cpp Point2D.o
	g++ -c testPoint2D.cpp
	mkdir -p bin
	g++ -o bin/testPoint2D testPoint2D.o Point2D.o

bin/testCircle: testCircle.cpp Circle.o Shape.o Point2D.o
	g++ -c testCircle.cpp
	mkdir -p bin
	g++ -o bin/testCircle testCircle.o Circle.o Shape.o Point2D.o

bin/Shape.o: Shape.h Shape.cpp
	g++ -c Shape.cpp

bin/Circle.o: Circle.h Circle.cpp
	g++ -c Circle.cpp

Point2D.o: Point2D.h Point2D.cpp
	g++ -c Point2D.cpp



clean:
	rm -r *.o *.gch bin


