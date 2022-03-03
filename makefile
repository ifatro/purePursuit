all: clean Car.o Path.o Rotations.o Servo.o SimulatedTrackingLookAheadPoint.o carTrack.o Coord.o mainPurePursuitAssignment.o
	g++ -o PurePersuit Car.o Coord.o Path.o Rotations.o Servo.o SimulatedTrackingLookAheadPoint.o carTrack.o mainPurePursuitAssignment.o
	chmod 755 PurePersuit
	
mainPurePursuitAssignment.o: mainPurePursuitAssignment.cpp config.h Car.h Coord.h Path.h Rotations.h SimulatedTrackingLookAheadPoint.h
	g++ -c mainPurePursuitAssignment.cpp
	
Car.o: Car.cpp config.h Car.h Servo.h
	g++ -c Car.cpp

Coord.o: Coord.cpp Coord.h
	g++ -c Coord.cpp

Path.o: Path.cpp config.h Path.h
	g++ -c Path.cpp

Rotations.o: Rotations.cpp Coord.h Rotations.h
	g++ -c Rotations.cpp

Servo.o: Servo.cpp config.h Servo.h
	g++ -c Servo.cpp

SimulatedTrackingLookAheadPoint.o: SimulatedTrackingLookAheadPoint.cpp config.h SimulatedTrackingLookAheadPoint.h Coord.h Car.h Path.h Rotations.h
	g++ -c SimulatedTrackingLookAheadPoint.cpp

carTrack.o: carTrack.cpp config.h carTrack.h
	g++ -c carTrack.cpp
	
clean:
	rm -f *.o PurePersuit
