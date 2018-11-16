CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = biquadris
OBJECTS = main.o window.o board.o player.o abstractLevel.o abstractBlock.o levelOne.o levelTwo.o levelThree.o levelFour.o blockI.o blockJ.o blockL.o blockO.o blockS.o blockT.o blockZ.o point.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -L/usr/X11R6/lib -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
