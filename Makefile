# make [ | all | debug | doc | submit | clean ]

HDR = main.h
SRC = main.c
OBJ = $(SRC:.c=.o)
EXE = simulator
SUB = 04_xpacne00_xfrenc00
DOCNAME = simulation_study

CC = g++
CFLAGS = -std=c++98 -Wall -Wextra -Werror -pedantic  # c++11

all: $(EXE)

debug: CFLAGS += -DDEBUG -g3
debug: all

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -lsimlib -lm -o $@ $(OBJ)
#	-I/usr/local/include -L/usr/local/lib

.c.o:
	$(CC) $(CFLAGS) -O2 -c $<

run:
	./$(EXE)

submit: submit_zip
submit_zip: doc clean
	zip -q $(SUB).zip -9 * \
		--exclude $(EXE) \
		--exclude '*.o'

clean:
	rm -f $(OBJ) $(SUB).zip

distclean: clean
	rm -f $(EXE) $(DOCNAME).pdf

doc:
	pandoc -S -s --toc -N --section-divs --no-tex-ligatures \
		--variable lang=czech \
		--variable date="$(shell date "+%x")" \
		--variable geometry=margin=2.5cm \
		--variable geometry=a4paper \
		--variable fontsize=11pt \
		--variable documentclass=report \
		--include-in-header=tex_header.include \
		-o $(DOCNAME).pdf $(DOCNAME).markdown
