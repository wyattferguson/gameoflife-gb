PROJECTNAME = gameoflife

CC = lcc

CFLAGS = -Wa-l -Wl-m -DUSE_SFR_FOR_REG -debug -c

LDFLAGS = -Wa-l -Wl-m -debug -Z -Wm-yoA -Wm-yn"$(PROJECTNAME)"

BUILD_DIR = build

# Auto-discover all .c files under src/ (recursive)
SRC = $(shell find src -name '*.c')

# Map src/%.c -> build/%.o
OBJ = $(patsubst src/%.c, $(BUILD_DIR)/%.o, $(SRC))

all: $(BUILD_DIR)/$(PROJECTNAME).gb

# Pattern rule: compile any src/%.c to build/%.o, creating subdirs as needed
$(BUILD_DIR)/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $<

# Link all .o files into .gb rom
$(BUILD_DIR)/$(PROJECTNAME).gb: $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(OBJ)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) *.gb *.ihx *.map *.noi *.cdb *.adb

# Show what files were found
sources:
	@echo "Source files:"
	@echo $(SRC)
