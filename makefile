PROJECTNAME = gameoflife

CC = lcc

CFLAGS = -Wa-l -Wl-m -debug -DUSE_SFR_FOR_REG -c

LDFLAGS = -debug -Wa-l -Wl-m -DUSE_SFR_FOR_REG -Z -Wm-yoA -Wm-yn"GameOfLife"

SRC = src/main.c src/board.c src/font.c src/screens.c src/utils.c

OBJ = $(patsubst src/%.c, $(BUILD_DIR)/%.o, $(SRC))

BUILD_DIR = build

$(BUILD_DIR)/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $<

all: $(PROJECTNAME).gb

$(PROJECTNAME).gb: $(OBJ)

	$(CC) $(LDFLAGS) -o $@ $(OBJ)
