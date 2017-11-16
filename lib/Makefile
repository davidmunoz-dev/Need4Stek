##
## Makefile for c in /PSU_2015_tetris/lib/my
## 
## Made by David Munoz
## Login   <munoz_d@epitech.net>
## 
## Started on  Tue Mar  1 18:42:18 2016 David Munoz
## Last update Thu May 26 16:21:31 2016 David Munoz
##

TARGET	= libmy.a

SRC	= get_next_line.c \
	  my_putchar.c \
	  my_strlen.c \
	  my_putstr.c \
	  my_getnbr.c \
	  my_strcmp.c \

CFLAGS   = -W -Wall -Werror -ansi -pedantic -Iinclude

SRCDIR   = my
OBJDIR   = obj

SOURCES  := $(addprefix my/, $(SRC))

OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CCLIB	 = ar rc
RANLIB	 = ranlib
rm       = rm -rf
mkdir    = mkdir -p

$(TARGET): $(OBJECTS)
	@$(CCLIB) $(TARGET) -o $@ $(OBJECTS)
	@$(RANLIB) $(TARGET)
	@cp $(TARGET) $(SRCDIR)
	@cp $(SRCDIR)/my.h ../include
	@echo "\033[0;35m"$(TARGET)"\033[1;32m compiled !\033[0m"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(mkdir) $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all     : $(TARGET)

clean   :
	@$(rm) $(OBJDIR)
	@echo "\033[1;31mBinary files deleted\033[0m"

fclean  : clean
	@$(rm) $(TARGET)
	@$(rm) $(SRCDIR)/$(TARGET)
	@echo "\033[1;31mBinary and executable files are deleted\033[0m"

re      : fclean all

.PHONY: all clean fclean re
