override CFLAGS	+=	-W -Wall -Wextra
CPPFLAGS	=	-I ./include
LDFLAGS		=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CC		=	gcc

BINARY		=	motus

SRCMAIN		=	src/main.c

SRC		=	src/game_handling/board_display.c		\
			src/game_handling/board_shapes_creation.c	\
			src/game_handling/events_handling.c		\
			src/game_handling/game_loops.c			\
			src/game_handling/levels_init.c			\
			src/game_handling/line_validation.c		\
			src/structures_handling/board_handling.c	\
			src/structures_handling/resource_handling.c	\
			src/structures_handling/sound_list_handling.c	\
			src/utilities/binary_toolbox.c			\
			src/utilities/get_next_line.c			\
			src/utilities/line_parsing.c			\
			src/utilities/string_toolbox.c			\
			src/utilities/text_toolbox.c

OBJMAIN		=	$(SRCMAIN:.c=.o)

OBJ		=	$(SRC:.c=.o)

$(BINARY):	$(OBJ) $(OBJMAIN)
	$(CC) -o $(BINARY) $(OBJ) $(OBJMAIN) $(LDFLAGS)

all:		$(BINARY)

clean:
	@echo Removing $(BINARY) temporary files
	@rm -f $(OBJ) $(OBJMAIN) $(OBJ:.o=.gcno) $(OBJ:.o=.gcda)

fclean:		clean
	@echo Removing $(BINARY) binary
	@rm -f $(BINARY)

re:		fclean all

.PHONY:		all clean fclean re
