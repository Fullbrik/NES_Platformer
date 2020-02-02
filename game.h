byte current_level;


const byte FLOOR = 100;
const byte GRAVITY = 1;

byte pad;

byte playerx = 0;
byte playery = 100;

sbyte player_vel_y = 0;


const byte JUMP_HEIGHT = 4;
const byte MAX_JUMP_FRAMES = 4;
byte jumpframes;



void start(void)
{
  playery = FLOOR;
}

void render(void)
{
  oam_spr(SCREEN_HALF_X, ~playery, 'c', 0x00, oam_off);
  
  
}

void update(void)
{
  pad = pad_poll(0);
  
  
  
  playery += player_vel_y >> 1;
  
  if(playery > FLOOR)
  {
    player_vel_y -= GRAVITY;
  }
  else
  {
    player_vel_y = 0;
    playery = FLOOR; 
  }
  
  
  
  
  
  
  
  
  if(pad&PAD_A)
  {
    if(jumpframes < MAX_JUMP_FRAMES)
    {
      ++jumpframes;
    
      player_vel_y += JUMP_HEIGHT;
    }
  }
  else
  {
    if(player_vel_y != 0)
      jumpframes = MAX_JUMP_FRAMES;
    else
      jumpframes = 0;
  }
}
