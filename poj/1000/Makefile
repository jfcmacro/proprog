.phony: all clean Main.class

all: aPlusB aPlusB_c

aPlusB: aPlusB.cpp

aPlusB_c: aPlusB_c.c

Main.class: Main.java
	javac $<

clean:
	rm -f *~ *.*~
	rm -f aPlusB aPlusB_c Main.class
