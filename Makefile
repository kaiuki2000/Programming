DB_FLAGS	= -Wall -g -ggdb 
#DB_FLAGS	= -O3

GTK_CMP		= `pkg-config --cflags --libs gtk+-3.0`
GTK_LIB		= `pkg-config --libs gtk+-3.0`

INCLUDE		= 

LIBS		=  $(GTK_LIB) -lm

LOPTS		=

CFLAGS		= $(DB_FLAGS) $(GTK_CMP)
LFLAGS		= $(DB_FLAGS)

CC		= gcc
CP		= cp
RM		= rm
LS		= ls

OBJS		= 

EXEC		= 

PROGS		= Gtk3_01_01 Gtk3_01_02 Gtk3_02_01 Gtk3_02_02 Gtk3_02_03 Gtk3_02_04

all: comp link

comp: 
	for fname in $(PROGS); do $(CC) $(CFLAGS) -c $$fname.c ; done

link: 
	for fname in $(PROGS); do $(CC) $(LFLAGS) -o $$fname $$fname.o $(LIBS) ; done

clean:
	$(RM) -f *~ *.o $(PROGS) $(DELFILES)
