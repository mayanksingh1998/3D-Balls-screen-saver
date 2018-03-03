NUM_THREADS=50
n = 100
COR = 1.0
Compiler = g++ -std=c++11
Obj = OBJ/
Src = SRC/
Exe = EXE/

Design = DOC/

Library = -lGLU -lglut -lGLEW -lGL -lSDL2 -lpthread 
#Header = ball.h physics.h user_interface.h gui.h button.h datastructures.h

all: $(Obj)main.o $(Obj)terrain.o $(Obj)Ball.o $(Obj)physics.o $(Library)

execute: exec
	$(Exe)./$< $(NUM_BALLS) $(NUM_THREADS) $(COR) 

exec:
	$(Compiler) $(Obj)main.o $(Obj)terrain.o $(Obj)Ball.o $(Obj)physics.o -o $@ $(Library) 
	mv $@ $(Exe)


DEBUG:
	$(Compiler) -g $(Obj)main.o $(Obj)terrain.o $(Obj)Ball.o $(Obj)physics.o $(Library) -o $@
	mv $@ $(Exe)


$(Obj)main.o: $(Src)main.cpp $(Src)physics.h $(Src)Vector.h
	$(Compiler) -c $< $(Library)
	mv main.o $(Obj)

$(Obj)Ball.o: $(Src)Ball.cpp $(Src)Ball.h
	$(Compiler) -c $< $(Library)
	mv Ball.o $(Obj)

$(Obj)terrain.o: $(Src)terrain.cpp $(Src)terrain.h 
	$(Compiler) -c $< $(Library)
	mv terrain.o $(Obj)
$(Obj)physics.o: $(Src)physics.cpp $(Src)Ball.h $(Src)terrain.h
				 $(Compiler) -c $< $(Library)
				 mv physics.o $(Obj)

clean:
	rm $(Exe)exec $(Obj)main.o $(Obj)terrain.o $(Obj)Ball.o $(Obj)physics.o 
	rm $(Exe)DEBUG

Changes.pdf: $(Src)Changes.tex
	pdflatex $(Src)Changes.tex
	mv Changes.pdf $(Design)Changes.pdf

Document: Changes.pdf
	rm -rf Changes.log rm -rf Changes.aux rm - rf Changes.toc rm -rf Changes.out
	cd $(Design); xpdf Changes.pdf

