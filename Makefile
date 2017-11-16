##
## Makefile for  in /home/munoz_d/Epitech/rendu/rendu_ProgElem/need4stek
## 
## Made by David Munoz
## Login   <munoz_d@epitech.net>
## 
## Started on  Thu May 19 15:49:31 2016 David Munoz
## Last update Thu May 26 15:44:30 2016 David Munoz
##

TARGET   = ia

CC       = gcc

SRC      = checkpoint.c		\
	   my_str_to_wordtab.c	\
	   lidar.c		\
	   cerr_err.c		\
	   wheels.c		\
	   car_mvnt.c		\
	   main.c

CFLAGS   = -W -Wall -Werror -ansi -pedantic -Iinclude

SRCDIR   = src
OBJDIR   = obj
DIRLIB	 = lib/

SOURCES  := $(addprefix src/, $(SRC))

OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

rm       = rm -rf
mkdir    = mkdir -p

$(TARGET): $(OBJECTS)
	@cd $(DIRLIB) && $(MAKE)
	@$(CC) $(CFLAGS) -o $@ $(OBJECTS) -lm -L./lib -lmy
	@mv $(TARGET) VREP
	@echo "\033[0;35m"$(TARGET)"\033[1;32m compiled !\033[0m"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(mkdir) $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all     : $(TARGET)

clean   :
	@$(rm) $(OBJDIR)
	cd $(DIRLIB) && $(MAKE) clean
	@echo "\033[1;31mBinary files deleted\033[0m"

fclean  : clean
	@$(rm) $(TARGET)
	cd $(DIRLIB) && $(MAKE) fclean
	@echo "\033[1;31mBinary and executable files are deleted\033[0m"

re      : lib fclean all

.PHONY: all clean fclean re lib
