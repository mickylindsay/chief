#ifndef TERM_H
#define TERM_H

#include <stdlib.h>
#include <termios.h>

#include "row.h"

typedef struct term{
  int w;
  int h;
  struct termios orig_termios;
  int cx;
  int cy;
  char *message;
  int m_len;
  row_t *rows;
  int num_rows;
  char *filepath;
  int filepath_len;
}term_t;

enum keys{
  BACKSPACE = 127,
  ENTER_KEY = '\r',
  ARROW_UP = 256,
  ARROW_LEFT,
  ARROW_DOWN,
  ARROW_RIGHT,
  HOME_KEY,
  END_KEY,
  DELETE_KEY
};

extern term_t chief;

void reset_terminal();
void initialize_terminal();
void initialize_editor(int argc, char **argv);
void free_terminal();

void terminal_loop();
int editor_input(int c);
int read_input();

int get_terminal_size(int *width, int *height);
void clear_terminal();
void render_terminal();
void set_message(const char *m, ...);

void append_row(const char *m);
void insert_row(int index, const char *m);
void delete_row(int index);
void insert_character(char c, int index, int row_num);
void delete_character(int index);

void open_file(const char *path);
void save_file(const char *path);

#endif
