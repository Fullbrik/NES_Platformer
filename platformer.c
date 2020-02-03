
#include <stdlib.h>
#include <string.h>

#include <stdlib.h>
#include <string.h>

// include NESLIB header
#include "neslib.h"

// include CC65 NES Header (PPU)
#include <nes.h>

// link the pattern table into CHR ROM
//#link "chr_generic.s"

// BCD arithmetic support
#include "bcd.h"
//#link "bcd.c"

// VRAM update buffer
#include "vrambuf.h"
//#link "vrambuf.c"

byte i, j;


#include "tostr.h"
#include "screen.h"
#include "collision.h"
#include "game.h"


/*{pal:"nes",layout:"nes"}*/
const char PALETTE[32] = { 
  0x0F,			// screen color

  0x11,0x30,0x27,0x00,	// background palette 0
  0x1C,0x20,0x2C,0x00,	// background palette 1
  0x00,0x10,0x20,0x00,	// background palette 2
  0x06,0x16,0x26,0x00,   // background palette 3

  0x16,0x35,0x24,0x00,	// sprite palette 0
  0x00,0x37,0x25,0x00,	// sprite palette 1
  0x0D,0x2D,0x3A,0x00,	// sprite palette 2
  0x0D,0x27,0x2A	// sprite palette 3
};

// setup PPU and tables
void setup_graphics() {
  // clear sprites
  oam_clear();
  
  
  // set palette colors
  pal_all(PALETTE);
  
  //vram_adr(NTADR_A(0, 16));
  //vram_write("_Hello_World123456789101112abcd", 1);
  
  vram_adr(NTADR_A(16, 24));
  vram_put('c');
  vram_put('d');
  
  vram_adr(NTADR_A(14, 20));
  vram_put('c');
  vram_put('c');
  vram_put('c');
  vram_put('d');
  vram_put('d');
  vram_put('d');
  
  vram_adr(NTADR_A(16, 14));
  vram_put('c');
  vram_put('d');
  
  write_collision(16, 24, 'c');
  write_collision(17, 24, 'd');
  
  write_collision(16, 20, 'c');
  write_collision(17, 20, 'd');
  
  write_collision(16, 14, 'c');
  write_collision(17, 14, 'd');
}

void main(void)
{
  setup_graphics();
  
  start();
  
  // enable rendering
  ppu_on_all();
  // infinite loop
  while(1) {
    ppu_wait_nmi();
    oam_off = 0;
    render();
    if(oam_off != 0) oam_hide_rest(oam_off);
    
    update();
  }
}
