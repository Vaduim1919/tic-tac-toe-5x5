#include <stdio.h>
#include <stdlib.h>

char matrix[5][5];  //двовим≥рна матриц€ 5 на 5
char check(void);
void init_matrix(void);
void get_player_move(void);//х≥д гравц€
void get_computer_move(void);//х≥д\ ѕ 
void disp_matrix(void);// ћатриц€ на дасплей



int main(void) //головна
{
  char done; 

  printf("Game X:0\n");
  printf("You will play against the computer.\n");

  done =  ' ';
  init_matrix();

  do {
    disp_matrix();
    get_player_move();
    done = check(); /* подивитьс€, чи переможець */
    if(done!= ' ') break; /* переможець!*/
    get_computer_move();
    done = check(); /* чи переможець */
  } while(done== ' ');
disp_matrix(); /* показати к≥нцев≥ позиц≥њ */

  if(done=='X') printf("You won!\n");
  else printf("I won!!!!\n");
  

  return 0;
}

/* ≤н≥ц≥ал≥зац≥€ матриц≥. */
void init_matrix(void)
{
  int i, j;

  for(i=0; i<5; i++)
    for(j=0; j<5; j++) matrix[i][j] =  ' ';
}

/* х≥д гравц€. */
void get_player_move(void)
{
  int x, y;
  char x1,y1;

while(1)
{
  printf("Enter X,Y coordinates for your move: ");// ввести координати
  
  do{
  	x1=getch();
  }while(x1<'1' || x1>'5'); // ф≥льтир л≥вих клав≥ш м≥н≥мальне число 1 максимальне 5 по x
  printf("%c ",x1);
  do{
  	y1=getch();
  }while(y1<'1' || y1>'5');
  printf("%c\n",y1);
  x=x1-'0'-1; y=y1-'0'-1; // ф≥льтир л≥вих клав≥ш м≥н≥мальне число 1 максимальне 5  по y

  if(matrix[x][y]!= ' '){
    printf("Invalid move, try again.\n"); // нед≥йсний х≥д
    
  }
  else break;
}
  matrix[x][y] = 'X';
}

/* рух в≥д компТютера. */
void get_computer_move(void)
{
  int i, j; // рандомне заповненн€ ком≥рок
  while(1){
  	i=rand()%5;
  	j=rand()%5;
  	if(matrix[i][j]==' '){
  		matrix[i][j] = 'O';
  		break;
	}
  }    
}

/* матриц€ на екран. */
void disp_matrix(void)
{
  int t;

  for(t=0; t<5; t++) {
    printf(" %c | %c | %c | %c | %c ",matrix[t][0], matrix[t][1], matrix [t][2], matrix[t][3], matrix[t][4]);
    if(t!=4) printf("\n---|---|---|---|---\n");
  }
  printf("\n");
}

/* ѕодив≥тьс€, чи Ї переможець. */
char check(void)
{
  int i;

  for(i=0; i<5; i++)  /* р€дки */
    if(matrix[i][0]==matrix[i][1] &&
       matrix[i][0]==matrix[i][2] &&
       matrix[i][0]==matrix[i][3] &&
       matrix[i][0]==matrix[i][4]) return matrix[i][0];

  for(i=0; i<5; i++)  /* колона */
    if(matrix[0][i]==matrix[1][i] &&
       matrix[0][i]==matrix[2][i] &&
       matrix[0][i]==matrix[3][i] &&
       matrix[0][i]==matrix[4][i]) return matrix[0][i];

  /* д≥агональ */
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
