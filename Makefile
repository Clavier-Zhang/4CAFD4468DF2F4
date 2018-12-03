CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = biquadris
OBJECTS = main.o game.o abstractLevel.o levelZero.o levelOne.o levelTwo.o levelThree.o levelFour.o blockI.o blockJ.o blockL.o blockO.o blockS.o blockT.o blockX.o blockZ.o abstractBlock.o abstractDecorator.o blindDecorator.o heavyDecorator.o abstractPlayer.o player.o point.o window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -L/usr/X11R6/lib -lX11 -lncurses

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
