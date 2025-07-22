# =============================================================================
# Makefile for the TinyDB Project
# =============================================================================

# --- Compiler and Flags ---
CC = gcc
CFLAGS = -Iinclude -Wall -g -std=c99

# --- Project Structure ---
# NEW: Directory for the final binary
# UPDATED: Target executable now includes the bin directory path
# OBJDIR: Directory for intermediate object files
BINDIR = bin
TARGET = $(BINDIR)/tinydb
SRCDIR = src
OBJDIR = obj
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))

# --- Build Rules ---

.PHONY: all
all: $(TARGET)

# Rule to link the final executable.
# UPDATED: Now creates the bin directory before linking.
$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR) # Create the bin directory if it doesn't exist
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile source files (.c) into object files (.o).
# No changes needed here.
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# --- Utility Rules ---

.PHONY: clean
# UPDATED: The clean rule now removes the entire bin and obj directories.
clean:
	@echo "--- Cleaning project files ---"
	-rm -rf $(BINDIR) $(OBJDIR)

.PHONY: run
# UPDATED: The run rule now executes the binary from the bin directory.
run: all
	@echo "--- Running TinyDB ---"
	./$(TARGET)