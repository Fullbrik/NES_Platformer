byte current_level;


const byte FLOOR = 10;
const byte GRAVITY = 1;
const sbyte MAX_GRAVITY = -16;

byte pad;

byte playerx = SCREEN_HALF_X; 
byte playery = 100;

sbyte player_vel_y = 0;


const byte JUMP_HEIGHT = 4;
const byte MAX_JUMP_FRAMES = 4;
byte jumpframes;

byte block_below;




void start(void)
{
  playery = 10 * 8;
}

void render(void)
{
  oam_off = oam_spr(playerx, playery - 16, 0xdc, 0x00, oam_off);
  oam_off = oam_spr(playerx + 8, playery - 16, 0xde, 0x00, oam_off);
  oam_off = oam_spr(playerx, playery - 8, 0xdd, 0x00, oam_off);
  oam_off = oam_spr(playerx + 8, playery - 8, 0xdf, 0x00, oam_off);}

void update(void)
{
  pad = pad_poll(0);
  
  
  
  
  if(block_below != 255)
  { 
    playery -= (player_vel_y/2);
      
    if(!pad&PAD_A || jumpframes >= MAX_JUMP_FRAMES)
      block_below = read_collision(playerx/8, playery/8)|read_collision(playerx/8 + 1, playery/8);
    
    if(player_vel_y < MAX_GRAVITY)
      player_vel_y = MAX_GRAVITY;
    
    player_vel_y -= GRAVITY;
  }
  
  if(block_below > 1)
  {
    player_vel_y = 0;
    
    if(block_below == 255) ;//playery = ((playery/8))*8;
    else{block_below = 255;playery = ((playery/8) - 1)*8;}
    
    
  }
  else if(block_below != 255)
  {
    
    
  }
  
  
  
  
  
  
  
  
  if(pad&PAD_A)
  {
    if(jumpframes < MAX_JUMP_FRAMES)
    {
      ++jumpframes;
    
      player_vel_y += JUMP_HEIGHT;
      
      block_below = 0;
    }
  }
  else
  {
    if(player_vel_y != 0)
      jumpframes = MAX_JUMP_FRAMES;
    else
      jumpframes = 0;
  }
  
  if(pad&PAD_RIGHT)
  {
    playerx += 1;
  }
  if(pad&PAD_LEFT)
  {
    playerx -= 1;
  }
}
