CC     = gcc
WINDRES= windres
RM     = rm -f
OBJS   = main.o \
         AppResource.res

LIBS   =
CFLAGS =

.PHONY: ChatBotRpg.exe clean clean-after

all: ChatBotRpg.exe

clean:
	$(RM) $(OBJS) ChatBotRpg.exe

clean-after:
	$(RM) $(OBJS)

ChatBotRpg.exe: $(OBJS)
	$(CC) -Wall -s -o $@ $(OBJS) $(LIBS)

main.o: main.c
	$(CC) -Wall -s -c $< -o $@ $(CFLAGS)

AppResource.res: AppResource.rc
	$(WINDRES) -i AppResource.rc -J rc -o AppResource.res -O coff

