#include <stdio.h>
#include <stdlib.h>

char matrix[5][5];  //two-dimensional matrix 5 by 5
char check(void);
void init_matrix(void);
void get_player_move(void);//the player's move
void get_computer_move(void);//move \ PC
void disp_matrix(void);// Matrix on the display



int main(void) //home
{
  char done; 

  printf("Game X:0\n");
  printf("You will play against the computer.\n");

  done =  ' ';
  init_matrix();

  do {
    disp_matrix();
    get_player_move();
    done = check(); /* see if the winner */
    if(done!= ' ') break; /* winner!*/
    get_computer_move();
    done = check(); /*or winner*/
  } while(done== ' ');
disp_matrix(); /* show end positions */

  if(done=='X') printf("You won!\n");
  else printf("I won!!!!\n");
  

  return 0;
}

/* Matrix initialization. */
void init_matrix(void)
{
  int i, j;

  for(i=0; i<5; i++)
    for(j=0; j<5; j++) matrix[i][j] =  ' ';
}

/* the player's move. */
void get_player_move(void)
{
  int x, y;
  char x1,y1;

while(1)
{
  printf("Enter X,Y coordinates for your move: ");//enter coordinates
  
  do{
  	x1=getch();
  }while(x1<'1' || x1>'5'); // left key filter minimum number 1 maximum 5 by x
  printf("%c ",x1);
  do{
  	y1=getch();
  }while(y1<'1' || y1>'5');
  printf("%c\n",y1);
  x=x1-'0'-1; y=y1-'0'-1; // filter left keys minimum number 1 maximum 5 by y

  if(matrix[x][y]!= ' '){
    printf("Invalid move, try again.\n"); // invalid move
    
  }
  else break;
}
  matrix[x][y] = 'X';
}

/* movement from the computer. */
void get_computer_move(void)
{
  int i, j; // random filling of cells
  while(1){
  	i=rand()%5;
  	j=rand()%5;
  	if(matrix[i][j]==' '){
  		matrix[i][j] = 'O';
  		break;
	}
  }    
}

/* matrix on the screen. */
void disp_matrix(void)
{
  int t;

  for(t=0; t<5; t++) {
    printf(" %c | %c | %c | %c | %c ",matrix[t][0], matrix[t][1], matrix [t][2], matrix[t][3], matrix[t][4]);
    if(t!=4) printf("\n---|---|---|---|---\n");
  }
  printf("\n");
}

/* See if there is a winner. */
char check(void)
{
  int i;

  for(i=0; i<5; i++)  /* lines */
    if(matrix[i][0]==matrix[i][1] &&
       matrix[i][0]==matrix[i][2] &&
       matrix[i][0]==matrix[i][3] &&
       matrix[i][0]==matrix[i][4]) return matrix[i][0];

  for(i=0; i<5; i++)  /* column */
    if(matrix[0][i]==matrix[1][i] &&
       matrix[0][i]==matrix[2][i] &&
       matrix[0][i]==matrix[3][i] &&
       matrix[0][i]==matrix[4][i]) return matrix[0][i];

  /* diagonal */
  if(matrix[0][0]==matrix[1][1] &&
     matrix[1][1]==matrix[2][2] &&
     matrix[2][2]==matrix[3][3] &&
     matrix[3][3]==matrix[4][4])
       return matrix[0][0];

  if(matrix[0][4]==matrix[1][3] &&
     matrix[1][3]==matrix[2][2] &&
     matrix[2][2]==matrix[3][1] &&
     matrix[3][1]==matrix[4][0])
       return matrix[0][4];
       
       

  return ' ';
}
