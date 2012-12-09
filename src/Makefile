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
	./$(EXE) 12 test  # months experiment_id_prefix

exp1: distclean all
	rm -f exp1b.dat
	for x in $(shell seq 3 3 $$((12*3))); do ./simulator "$$x" exp1; done
	gnuplot exp1.gnuplot
	@echo

exp2: CFLAGS += -DLASER
exp2: distclean all
	rm -f exp2b.dat
	for x in $(shell seq 3 3 $$((12*3))); do ./simulator "$$x" exp2; done
	gnuplot exp2.gnuplot
	@echo

submit: submit_zip
submit_zip: doc clean
	zip -q $(SUB).zip -9 * \
		--exclude $(EXE) \
		--exclude '*.o' \
		--exclude 'test*.dat' \
		--exclude '*.xcf' \
		--exclude 'bose0.jpg' \
		--exclude 'sequence_diagram.odg'

clean:
	rm -f $(OBJ) $(SUB).zip

distclean: clean
	rm -f $(EXE) $(DOCNAME).pdf *.dat

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
