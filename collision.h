byte collision[32][30] = {};

void write_collision(byte x, byte y, byte val)
{
  collision[x][y] = val;
}

byte read_collision(byte x, byte y)
{
  return collision[x][y];
}
