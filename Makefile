CXX = g++
CXX_FLAGS = -I. -std=c++17 -Wfatal-errors -Wall -Wextra -Wpedantic -Wconversion -Wshadow

TMPFILE=tmpimg
GEOM?=
VARS?=

ifdef GEOM
VARS += -V geometry:"$(GEOM)"
endif

PRJ = main
SRC = $(PRJ).cpp
BIN = a.out

.PHONY : all clean test score1 score2 score3 score4

solution: sol2pdf imgpdf clean

imgpdf:
	pdftoppm $(PRJ)-t.pdf $(TMPFILE) -png
	convert $(TMPFILE)*.png $(PRJ).pdf

sol2pdf:
	enscript --color=1 -C -Ecpp -fCourier9 -o - $(PRJ).sol.* | ps2pdf - $(PRJ)-t.pdf

all: $(BIN)

test.o: test.cpp
	$(CXX) $(CXX_FLAGS) test.cpp -c

$(BIN): test.o $(PRJ).o
	g++ $(CXX_FLAGS) test.o $(SRC)

clean:
	@rm $(PRJ)-t.pdf $(TMPFILE)*.png || true
	rm $(BIN) *.o | true

test: $(BIN)
	./$(BIN)

score1: $(BIN)
	./$(BIN) -c Parasite-Fields

score2: $(BIN)
	./$(BIN) -c Parasite-Methods

score3: $(BIN)
	./$(BIN) -c Animal-Fields

score4: $(BIN)
	./$(BIN) -c Animal-Methods