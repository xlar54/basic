#include <stdio.h>

#include "io.h"

  void
console_def_char(unsigned char code, char* definition)
{
  char buf[8];
  putchar(0x1b);
  putchar('T');
  snprintf(buf, sizeof(buf), "%02x", code);
  basic_io_print(buf);
  basic_io_print(definition);
}

  void
console_plot(int x, int y, unsigned char code)
{
  putchar(0x1b);
  putchar('Y');
  putchar(' ' + y);
  putchar(' ' + x);
  if(code < 32){
    putchar(0x10); // Data link escape
  }
  putchar(code);
}

  void
console_cursor(int cursor)
{
  putchar(0x1b);
  if(cursor){
    putchar('e');
  } else {
    putchar('f');
  }
}

  void
console_cursor_type(int block)
{
  putchar(0x1b);
  if(block){
    putchar('x');
  } else {
    putchar('y');
  }
  putchar('4');
}

  void
console_line_overflow(int overflow)
{
  putchar(0x1b);
  if(overflow){
    putchar('v');
  } else {
    putchar('w');
  }
}  
  
  void
console_fontbank(int row, int bank)
{
  char banks[] = {'6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@'}; 

  // save cursor
  putchar(0x1b);
  putchar('j');

  // set cursor
  putchar(0x1b);
  putchar('Y');
  putchar(' ' + row);
  putchar(' ' + 0);

  // set bank for actual row
  putchar(0x1b);
  putchar('_');
  if(bank<0) bank = 0;
  if(bank>10) bank = 10;
  putchar(banks[bank]); 

  // restore cursor
  putchar(0x1b);
  putchar('k');
}  

