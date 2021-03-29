#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>
#include <signal.h>

int testline(int grid[][9])
{

  for (int x = 0; x < 9; x++)
  {
    int one = 0;
    int two = 0;
    int three = 0;
    int four = 0;
    int five = 0;
    int six = 0;
    int seven = 0;
    int eight = 0;
    int nine = 0;
    int go[9];

    for (int count = 0; count < 9; count++)
    {
      int go = grid[x][count];

      if (go == 1)
      {
        one++;
        if (one > 1)
        {
          return 0;
        }
      }
      else if (go == 2)
      {
        two++;
        if (two > 1)
        {
          return 0;
        }
      }
      if (go == 3)
      {
        three++;
        if (three > 1)
        {
          return 0;
        }
      }
      if (go == 4)
      {
        four++;
        if (four > 1)
        {
          return 0;
        }
      }
      if (go == 5)
      {
        five++;
        if (five > 1)
        {
          return 0;
        }
      }
      if (go == 6)
      {
        six++;
        if (six > 1)
        {
          return 0;
        }
      }
      if (go == 7)
      {
        seven++;
        if (seven > 1)
        {
          return 0;
        }
      }
      if (go == 8)
      {
        eight++;
        if (eight > 1)
        {
          return 0;
        }
      }
      if (go == 9)
      {
        nine++;
        if (nine > 1)
        {
          return 0;
        }
      }
        
      }
  }

  return 1;
}

int testlineUpDown(int grid[][9])
{

  for (int x = 0; x < 9; x++)
  {
    int one = 0;
    int two = 0;
    int three = 0;
    int four = 0;
    int five = 0;
    int six = 0;
    int seven = 0;
    int eight = 0;
    int nine = 0;
    for (int count = 0; count < 9; count++)
    {
      int go = grid[count][x];

      if (go == 1)
      {
        one++;
        if (one > 1)
        {
          return 0;
        }
      }
      else if (go == 2)
      {
        two++;
        if (two > 1)
        {
          return 0;
        }
      }
      if (go == 3)
      {
        three++;
        if (three > 1)
        {
          return 0;
        }
      }
      if (go == 4)
      {
        four++;
        if (four > 1)
        {
          return 0;
        }
      }
      if (go == 5)
      {
        five++;
        if (five > 1)
        {
          return 0;
        }
      }
      if (go == 6)
      {
        six++;
        if (six > 1)
        {
          return 0;
        }
      }
      if (go == 7)
      {
        seven++;
        if (seven > 1)
        {
          return 0;
        }
      }
      if (go == 8)
      {
        eight++;
        if (eight > 1)
        {
          return 0;
        }
      }
      if (go == 9)
      {
        nine++;
        if (nine > 1)
        {
          return 0;
        }
      }
    }
  }

  return 1;
}

int testsquare(int grid[][9])
{

  for (int x = 0; x < 9; x = (x + 3))
  {
    for (int y = 0; y < 9; y = (y + 3))
    {
      int newi = (x / 3);
      // printf("%d-i-",newi);
      int newc = (y / 3);
      // printf("%d-c-\n",newc);
      int one = 0;
      int two = 0;
      int three = 0;
      int four = 0;
      int five = 0;
      int six = 0;
      int seven = 0;
      int eight = 0;
      int nine = 0;

      for (int ni = (newi * 3); ni < ((newi * 3) + 3); ni++)
      {
        //printf("here One %d\n",ni);
        for (int nc = (newc * 3); nc < ((newc * 3) + 3); nc++)

        {

          int go = grid[ni][nc];

          if (go == 1)
          {
            one++;
            if (one > 1)
            {
              return 0;
            }
          }
          else if (go == 2)
          {
            two++;
            if (two > 1)
            {
              return 0;
            }
          }
          if (go == 3)
          {
            three++;
            if (three > 1)
            {
              return 0;
            }
          }
          if (go == 4)
          {
            four++;
            if (four > 1)
            {
              return 0;
            }
          }
          if (go == 5)
          {
            five++;
            if (five > 1)
            {
              return 0;
            }
          }
          if (go == 6)
          {
            six++;
            if (six > 1)
            {
              return 0;
            }
          }
          if (go == 7)
          {
            seven++;
            if (seven > 1)
            {
              return 0;
            }
          }
          if (go == 8)
          {
            eight++;
            if (eight > 1)
            {
              return 0;
            }
          }
          if (go == 9)
          {
            nine++;
            if (nine > 1)
            {
              return 0;
            }
          }
        }
      }
    }
  }
  return 1;
}

int sudokuTest(int grid[][9], int test, int i, int c)
{

  grid[i][c] = test;

  if (testline(grid) && testsquare(grid) && testlineUpDown(grid))
  {
    grid[i][c] = 0;
    return 1;
  }

  grid[i][c] = 0;
  return 0;
}
int fillgrid(int grid[][9], int i, int c, int gridplayer[][9])
{

  int rdom = (rand() % 10);

  if (sudokuTest(grid, rdom, i, c))
  {
    if (grid[i][c] != 0)
    {
      return 1;
    }

    else
    {
      grid[i][c] = rdom;
      gridplayer[i][c] = rdom;
      return 0;
    }
  }
  return 0;
}

void gridseed(int grid[][9], int gridplayer[][9])
{
  int long count = 0;
  for (int i = 0; i < 9; i++)
  {
    for (int c = 0; c < 9; c++)
    {

      // printf("%d",test);
      fillgrid(grid, i, c, gridplayer);
    }

    count++;
    //printf(" %d\n", i);
  }
}

void drawgrid(int grid[][9])
{
  printf("\033[?25l\033[2J");
  printf("\033[H");

  printf("\n");
  printf("\033[38;5;207m");
  printf(" ---------x----------");

  for (int i = 0; i < 9; i++)
  {
    if (i == 0)
    {
      printf("\n");
    }
    printf("\033[38;5;207m");
    if (i == 4)
    {
      printf("y");
      printf(" %d ", i);
    }
    else
    {
      printf("| %d ", i);
    }
    for (int c = 0; c < 9; c++)
    {
      if (i == 0 && c == 0)
      {
        printf("0 1 2 3 4 5 6 7 8\n| 0 ");
      }
      if (c >= 3 && c < 6)
      {
        printf("\033[38;5;16m");
        if (i >= 3 && i < 6)
        {
          printf("\033[38;5;40m");
        }

        printf("%d ", grid[i][c]);
      }
      else
      {
        printf("\033[38;5;40m");
        if (i >= 3 && i < 6)
        {
          printf("\033[38;5;16m");
        }

        printf("%d ", grid[i][c]);
      }
    }
    printf("\n");
    printf("\033[?25h\033[m");
  }

  printf("\n-----------\n");
  // printf("\033[A");
}

int unassigned(int grid[][9], int *row, int *column)
{

  int x, y;

  for (x = 0; x < 9; x++)
  {
    for (y = 0; y < 9; y++)
    {
      if (grid[x][y] == 0)
      {
        *row = x;
        *column = y;

        return 1;
      }
    }
  }
  return 0;
  ;
}

int solve(int grid[][9])
{

  int row;
  int column;

  if (!unassigned(grid, &row, &column))
  {
    printf("finished");
    return 1;
  }

  //printf("STARTrow %d, col %d\n", row, column);
  int i;
  for (i = 1; i < 10; i++)
  {
    if (sudokuTest(grid, i, row, column))
    {
      // printf("passed-%d\n", i);
      grid[row][column] = i;

      if (solve(grid))
      {
        // printf("made it");
        return 1;
      }
      //printf("reset, %d\n", i);
      grid[row][column] = 0;
    }
    //printf("give me i %d\n",i);
  }

  // printf("ENDfailed 0---\n");
  return 0;
}

int createrandom(int grid[][9], int gridplayer[][9])
{
  int comp = 0;
  do
  {

    gridseed(grid, gridplayer);

    comp = solve(grid);
    if (comp == 0)
    {
      memset(gridplayer, 0, sizeof(gridplayer[0][0]) * 9 * 9);
      memset(grid, 0, sizeof(grid[0][0]) * 9 * 9);
    }

  } while (comp == 0);
}

void difficulty(int grid[][9], int gridplayer[][9])
{

  for (int x = 0; x < 9; x++)
  {
    for (int y = 0; y < 9; y++)
    {
      int rdom = (rand() % 10);
      if (rdom == grid[x][x])
      {
        gridplayer[x][y] = grid[x][y];
        printf("hitter");
      }
    }
  }
}

int compare(int grid[][9], int gridplayer[][9])
{
  for (int x = 0; x < 9; x++)
  {
    for (int y = 0; y < 9; y++)
    {
      if (grid[x][y] != gridplayer[x][y])
      {
        return 0;
      }
    }
  }
  return 1;
}

void usernumber(int grid[][9], int gridplayer[][9])
{
  drawgrid(gridplayer);

  do
  {
    char x[2];
    char y[2];
    char value[2];

    printf("\nx: ");
    scanf("%s", x);

    printf("y: ");
    scanf("%s", y);

    printf("value: ");
    scanf("%s", value);

    int inx = atoi(x);
    int iny = atoi(y);
    int invalue = atoi(value);

    gridplayer[iny][inx] = invalue;
    printf("%s-%s-%s\n", x, y, value);
    printf("%d-%d-%d", inx, iny, invalue);

    drawgrid(gridplayer);
    //drawgrid(grid);
  } while (compare(grid, gridplayer) == 0);

  printf("finished congratulations");
}
void addnums(int gridplayer[][9]) {
  int quit = 0;
  do {
  char x[2];
    char y[2];
    char value[2];

    printf("\nx: ");
    scanf("%s", x);

    printf("y: ");
    scanf("%s", y);

    printf("value: ");
    scanf("%s", value);

    int inx = atoi(x);
    int iny = atoi(y);
    int invalue = atoi(value);

    gridplayer[iny][inx] = invalue;
    printf("%s-%s-%s\n", x, y, value);
    printf("%d-%d-%d", inx, iny, invalue);

    drawgrid(gridplayer);
    char quits[2];
    
    printf("enter 1 to finish adding numbers or enter 0  to keep going: ");
    scanf("%s", quits);
    quit = atoi(quits);
    
  } while (quit != 1);
}
  

int setupmenu()
{
  char gridsetc[3];
  int gridset;
  printf("Sudoku Grid set up\n\n");
  printf("1) HARD (least numbers prefilled)\n");
  printf("2) MEDIUM \n");
  printf("3) EASY (most numbers prefilled)");
  printf("\n : ");
  scanf("%s", gridsetc);
  printf("GENERATING GRID");

  gridset = atoi(gridsetc);

  return gridset;
}

int startmenu()
{
  char startsetc[3];
  int startset;
  do
  {

    printf("Sudoku Grid start up\n\n");
    printf("1) Create a solved grid\n");
    printf("2) Solve my partially filled grid \n");
    printf("3) play sudoku\n");
    printf("4) exit");
    printf("\n : ");
    scanf("%s", startsetc);

    startset = atoi(startsetc);

    if (startset == 1)
    {
      int newgrid[9][9] = {0};
      int blank[9][9] = {0};
      printf("GENERATING GRID");
      createrandom(newgrid, blank);

      drawgrid(newgrid);
    }
    else if (startset == 2)
    {
       int newgrid[9][9] = {0};
      
      drawgrid(newgrid);
      addnums(newgrid);
      solve(newgrid);
      drawgrid(newgrid);
      
    }
    else if (startset == 3)
    {
      int newgrid[9][9] = {0};
      int gridplayer[9][9] = {0};

      int gridset = setupmenu();

      createrandom(newgrid, gridplayer);

      for (int v = 0; v < (gridset * 2); v++)
      {
        difficulty(newgrid, gridplayer);
      }

      //drawgrid(newgrid);
      //printf("\033[?25h\033[m");   //
      usernumber(newgrid, gridplayer);
    }

  } while (startset != 4);
}

int main()
{

  srand(time(NULL));

  startmenu();

  printf("\n");
  return;
}
