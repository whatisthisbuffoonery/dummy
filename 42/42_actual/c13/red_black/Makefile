CC := clang
CC_FLAGS := -Wall -Wextra -Werror -g
PCH_FLAGS := -x c-header
SRCDIR := src
OBJDIR := obj
PCHDIR := pch
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))
TARGET := a.out
PCH := $(PCHDIR)/rb.h.gch

all: $(TARGET)

$(TARGET): $(PCH) $(OBJECTS)
	$(CC) -include rb.h $(OBJECTS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR) $(PCH)
	$(CC) -I $(PCHDIR) -include $(PCHDIR)/rb.h $(CC_FLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(PCH): $(PCHDIR)/rb.h
	$(CC) $(PCH_FLAGS) -o $(PCH) -c $(PCHDIR)/rb.h
