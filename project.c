#include <stdio.h>
#include <strings.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
// global Variables
char g1[100]="Streak Math";
char g2[100]="Battle Ship";
char g3[100]="Mine Sweeper";
char d1[100]="Easy";
char d2[100]="Normal";
char d3[100]="Hard";
int point=0,i,j,k;
int rows=0;
int *r= &rows;
int diff,table_size;
int stage=1,bomb,bomb_left,box_count,turn=1,PowerUp=0,First_InputC,First_InputR;
int gameover=0,stageover=0,stageclear=0,stagecleared=0,input_error=0,touch_bomb=0,game_skipped=0;
clock_t turn_start,turn_end;
double turn_time_used;
char info_str[300];
int Score=0;
float modifier=1.0,time_modifier=1.0,life=10.0;

struct box{
    int status; //1=closed 0=opened
    int checked; //1=checked 0=unchecked, mainly used by blank_open()
    char value; //'9'=bomb ' '=blank box
}box[100][100];

void table_set(int);
int GetIntInput(void);
int check_outbound(int,int);
void score_display(void);
void end_screen(void);
float time_bonus(double);
struct Menu{
char name[100];
char input;
}menu;
struct Menu *me = &menu;

struct bs{
    int ocean[10][10], num[5],check, x[100], y[100], guess[10][10],score,Guess;
     char sele;
}ship;
struct bs *b =&ship;

struct math{

int point;

}num;
struct math *m =&num;


void start();
void main_menu();
void sure(char);
void game(char);
void  game1();
void game2();
void art(int,int);
void game3();
void gotoxy(int,int);
void game_over()
{


    gotoxy(75,17);printf("GAME OVER!");
    gotoxy(75,19);printf("Student Union Center Keepsakes!");
    gotoxy(75,21);printf("Please press any key to go to leaderboard....");



}
void pi(int p,int *r)
{
    void pi1(int *r)
{
  gotoxy(70,20+*r);printf("  ########");*r+=1;
  gotoxy(70,20+*r);printf("  ########");*r+=1;
  gotoxy(70,20+*r);printf(" #########");*r+=1;
  gotoxy(70,20+*r);printf(" ####    #");*r+=1;
  gotoxy(70,20+*r);printf("###      #");*r+=1;
  gotoxy(70,20+*r);printf("#        #");*r+=1;
  gotoxy(70,20+*r);printf("#        #");*r+=1;
  gotoxy(70,20+*r);printf("         #");*r+=1;
  gotoxy(70,20+*r);printf("         #");*r+=1;
  gotoxy(70,20+*r);printf("         #");*r+=1;
  gotoxy(70,20+*r);printf("        ##");*r+=1;
  gotoxy(70,20+*r);printf("        ##");*r+=1;
  gotoxy(70,20+*r);printf("        ##");*r+=1;
  gotoxy(70,20+*r);printf("        ##");*r+=1;
  gotoxy(70,20+*r);printf("       ###");*r+=1;
  gotoxy(70,20+*r);printf("      ####");*r+=1;
  gotoxy(70,20+*r);printf("      ####");*r+=1;
  gotoxy(70,20+*r);printf("     #####");*r+=1;
  gotoxy(70,20+*r);printf("    ######");*r+=1;
  gotoxy(70,20+*r);printf("   #######");*r+=1;
  gotoxy(70,20+*r);printf("   #######");*r+=1;
  gotoxy(70,20+*r);printf("   ###### ");*r+=1;
  *r=0;
}
void pi2(int x,int *r)
{
  gotoxy(70+x,20+*r);printf("########");*r+=1;
  gotoxy(70+x,20+*r);printf("########");*r+=1;
  gotoxy(70+x,20+*r);printf("########");*r+=1;
  gotoxy(70+x,20+*r);printf("####");*r+=1;
  gotoxy(70+x,20+*r);printf("####");*r+=1;
  gotoxy(70+x,20+*r);printf("####");*r+=1;
  gotoxy(70+x,20+*r);printf("####");*r+=1;
  gotoxy(70+x,20+*r);printf("###");*r+=1;
  gotoxy(70+x,20+*r);printf("###");*r+=1;
  gotoxy(70+x,20+*r);printf("###");*r+=1;
  gotoxy(70+x,20+*r);printf("###");*r+=1;
  gotoxy(70+x,20+*r);printf("###");*r+=1;
  gotoxy(70+x,20+*r);printf("##");*r+=1;
  gotoxy(70+x,20+*r);printf("##");*r+=1;
  gotoxy(70+x,20+*r);printf("##");*r+=1;
  gotoxy(70+x,20+*r);printf("##");*r+=1;
  gotoxy(70+x,20+*r);printf("#");*r+=1;
  gotoxy(70+x,20+*r);printf("##");*r+=1;
  gotoxy(70+x,20+*r);printf("#");*r+=1;
  *r=0;
}
void pi3(int x ,int *r)
{
  gotoxy(70+x,20+*r);printf("########");*r+=1;
  gotoxy(70+x,20+*r);printf("########");*r+=1;
  gotoxy(70+x,20+*r);printf("########");*r+=1;
  gotoxy(70+x,20+*r);printf("     ###");*r+=1;
  gotoxy(70+x,20+*r);printf("    ####");*r+=1;
  gotoxy(70+x,20+*r);printf("    ####");*r+=1;
  gotoxy(70+x,20+*r);printf("    ####");*r+=1;
  gotoxy(70+x,20+*r);printf("    ####");*r+=1;
  gotoxy(70+x,20+*r);printf("    ####");*r+=1;
  gotoxy(70+x,20+*r);printf("    ####");*r+=1;
  gotoxy(70+x,20+*r);printf("   #####");*r+=1;
  gotoxy(70+x,20+*r);printf("   #####");*r+=1;
  gotoxy(70+x,20+*r);printf("   #####");*r+=1;
  gotoxy(70+x,20+*r);printf("   #####");*r+=1;
  gotoxy(70+x,20+*r);printf("   #####");*r+=1;
  gotoxy(70+x,20+*r);printf("   #####");*r+=1;
  gotoxy(70+x,20+*r);printf("   #####");*r+=1;
  gotoxy(70+x,20+*r);printf("   #####");*r+=1;
  gotoxy(70+x,20+*r);printf("    ####");*r+=1;
  gotoxy(70+x,20+*r);printf("    ####");*r+=1;
  gotoxy(70+x,20+*r);printf("     ###");*r+=1;
  gotoxy(70+x,20+*r);printf("      ##");*r+=1;
  *r=0;
}
void pi4(int x,int *r)
{
  gotoxy(70+x,20+*r);printf("########     ");*r+=1;
  gotoxy(70+x,20+*r);printf("##########   ");*r+=1;
  gotoxy(70+x,20+*r);printf("##########   ");*r+=1;
  gotoxy(70+x,20+*r);printf("#");*r+=1;
  gotoxy(70+x,20+*r);printf("#");*r+=1;
  gotoxy(70+x,20+*r);printf("#");*r+=12;
  gotoxy(70+x,20+*r);printf("         ##");*r+=1;
  gotoxy(70+x,20+*r);printf("#       ##");*r+=1;
  gotoxy(70+x,20+*r);printf("##########");*r+=1;
  gotoxy(70+x,20+*r);printf("#########    ");*r+=1;
  gotoxy(70+x,20+*r);printf("########    ");*r+=1;
  gotoxy(70+x,20+*r);printf("#######      ");*r+=1;
}
    switch(p/2)
    {
     case(1):
     pi1(r);
   break;
   case(2):
     pi1(r);
     pi2(10,r);
   break;
   case(3):
     pi1(r);
     pi2(10,r);
     pi3(18,r);
   break;
   case(4):
   case(5):
    pi1(r);
    pi2(10,r);
    pi3(18,r);
    pi4(26,r);
   break;
    }
}
 void ship0(int x) // build ship
{
       gotoxy(41+x,3);
       printf("__/____");
       gotoxy(41+x,4);
       printf("|______\\_____ ");
       gotoxy(41+x,5);
       printf("/_____\\_____\\___________ ");
       gotoxy(41+x,6);
       printf("|          > > >        \\");
       gotoxy(41+x,7);
       printf("-------------------------");

}
void Ship(int p) // ship art
    {
     gotoxy(141,1);printf("Health");
    for(int i=1; i<=100; i++)
    {
        gotoxy(40+i,8);printf("~");
    }
    for(int i=1; i<=6; i++)
    {
        gotoxy(141,i+1);printf("|");
    }
    switch(b->sele)
    {
    case(49):
        {
    switch((p*4)/50)
    {
      case(4):// full
       ship0(75);
       ship0(50);
       ship0(25);
       ship0(0);
       break;
     case(3):// 3/4 left
       ship0(50);
       ship0(25);
       ship0(0);
      break;
     case(2): //half left
       ship0(25);
       ship0(0);
      break;
      case(1):// almost dead
       ship0(0);
      break;
    }
        }
        break;
    case(50):
        {
    switch((p*4)/30)
    {
      case(4):// full
       ship0(75);
       ship0(50);
       ship0(25);
       ship0(0);
       break;
     case(3):// 3/4 left
       ship0(50);
       ship0(25);
       ship0(0);
      break;
     case(2): //half left
       ship0(25);
       ship0(0);
      break;
      case(1):// almost dead
       ship0(0);
      break;
    }
        }
    break;
    case(51):
        {
         switch((p*4)/15)
         {
        case(4):// full
       ship0(75);
       ship0(50);
       ship0(25);
       ship0(0);
       break;
     case(3):// 3/4 left
       ship0(50);
       ship0(25);
       ship0(0);
      break;
     case(2): //half left
       ship0(25);
       ship0(0);
      break;
      case(1):// almost dead
       ship0(0);
      break;
    }
    break;
        }
        }

}
int score(int x,char input) //score
{
    int scor;
     switch(input)
        {
        case (49)://Streak math's score
           scor = (250*x);
            break;
        case(50)://Battle ship's score
           switch(b->sele)
           {
            case (49)://easy
           scor = 80*x;
            break;
          case(50):// normal
           scor =(400/3)*x;
            break;
           case(51):// hard
           scor =(800/3)*x;
            break;
           }
            break;
            case(51)://Mine sweeper
          scor = point;
            break;
        }
      return scor;
}
void scoreboard(int p,char x[]) //scoreboard
{

    system("cls");
    gotoxy(60,8);printf("THE END");
    gotoxy(60,9);printf("---------------------------------------------------------\n");
    gotoxy(60,10);printf("Game:%s                   \n",x);
    if(x==g2)// selected Battle ship
    {
      switch(b->sele)
    {
       case(49):
       gotoxy(100,10); printf("Difficulty: %s\n",d1);//easy
        break;
        case(50):
       gotoxy(100,10);printf("Difficulty: %s\n",d2);//normal
        break;
        case(51):
       gotoxy(100,10); printf("Difficulty: %s\n",d3);//hard
        break;
    }
    }
    gotoxy(60,11);printf("Name:%s                            \n",me->name);;//your name
    gotoxy(60,12);printf("Score:%d                           \n",score(p,me->input));// score
    gotoxy(60,13);printf("---------------------------------------------------------\n");

}
void gotoxy(int x,int y) // set position
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void delay(int ms) //like sleep()
{
    clock_t time_delay = ms+clock();
    while(time_delay>clock());
}
void start() //start
{
    int i;




        //exit

   //start
    gotoxy(75,15);
    printf("\t _          _ _         _ \n");
    gotoxy(75,16);
    printf("\t| |        | | |       | |\n");
    gotoxy(75,17);
    printf("\t| |__   ___| | | ___   | |\n");
    gotoxy(75,18);
    printf("\t| '_ \\ / _ \\ | |/ _ \\  | |\n");
    gotoxy(75,19);
    printf("\t| | | |  __/ | | (_)   |_|\n");
    gotoxy(75,20);
    printf("\t|_| |_|\\___|_|_|\\___/  (_)\n");
    gotoxy(75,21);
    printf("\n");
    gotoxy(75,22);
    printf("USERNAME?:");
    fflush(stdin);
    gets(me->name);


    system("cls");
     // loading
    gotoxy(75,15);
    printf("\t\t LOADING ");

    for(i = 1 ; i<=3 ; i++)
    {
       Sleep(500);
       printf(".");
    }


    system("cls");

    main_menu();
}
void main_menu()
{
    // Welcome
    gotoxy(75,15);printf("Hi! %s\n",me->name);
    Sleep(100);
    gotoxy(75,16);printf("__          __  _   \n");
    Sleep(100);
    gotoxy(75,17);printf("\\ \\        / / | |\n");
    Sleep(100);
    gotoxy(75,18);printf(" \\ \\  /\\  / /__| | ___ ___  _ __ ___   ___  \n");
    Sleep(100);
    gotoxy(75,19);printf("  \\ \\/  \\/ / _ \\ |/ __/ _ \\| \'_ ` _ \\ / _ \\\n");
    Sleep(100);
    gotoxy(75,20);printf("   \\  /\\  /  __/ | (_| (_) | | | | | |  __/\n");
    Sleep(100);
    gotoxy(75,21);printf("    \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|\n");
    Sleep(100);
    gotoxy(110,22);printf("  _______ ____  \n");
    Sleep(100);
    gotoxy(110,23);printf(" |__   __/ __ \\ \n");
    Sleep(100);
   gotoxy(110,24); printf("    | | | |  | |\n");
    Sleep(100);
   gotoxy(110,25); printf("    | | | |  | |\n");
    Sleep(100);
   gotoxy(110,26); printf("    | | | |__| |\n");
    Sleep(100);
    gotoxy(110,27);printf("    |_|  \\____/ \n");
    Sleep(100);
    printf("\n");
    Sleep(100);
    printf("\n");
    Sleep(100);


    // select games
    gotoxy(100,35);
    printf(" (ESC:Exit) ");
    gotoxy(75,35);
    printf("Select The Games:\n");
    gotoxy(70,37);printf("1. %s",g1);
    gotoxy(70,39);printf("2. %s",g2);
    gotoxy(70,41);printf("3. %s",g3);


   // go to games
    do
    {
        fflush(stdin);
        me->input = getch();
        if(me->input<=51&& me->input>=49)
        {
            break;
        }

    if(me->input == 27) //exit
    {
        exit(0);

    }


    }while(me->input<65 ||me->input>68 );
       switch(me->input)
        {
        case (49):
            system("cls");
            game1();
            break;
        case (50):
            system("cls");
            game2();
            break;
        case (51):
            system("cls");
            game3();
            break;
        }
}

void game1() // Streak Math
{
    m->point=0;
    void rule()
{
    printf("dada");
}
    int check()
{
    int num = 0, ch;
    do {
        ch = getchar();

        if (ch >= 48 && ch <= 57) {

            num = num * 10 + (ch - 48);
        }

        if (ch == '\n')
            break;
    } while (1);

    return (num);
}

    int Game1(int point)
{
    int i=1;
    float time1,time2,a,b,answer;
    time1 = clock();
    do
    {
        art(point,1);
        delay(300);
        int t;
        srand(time(NULL));
        switch(rand()%5)
        {
        case 0:
        {
            gotoxy(75,15);
            printf(" %d. %.0f+%.0f :",i,a=rand()%100,b=rand()%100);
            answer = check();
            if(answer==0)
            {
                gotoxy(75,16);printf("Error! please try again!");
                i=i-1;
                break;
            }
            if(answer==a+b)
            {
                point=point+1;
                gotoxy(75,16);printf("+1 point\n");
            }
            break;
        }

        case 1:
        {
            gotoxy(75,15);
            printf(" %d. %.0f-%.0f : ",i,a=rand()%100,b=rand()%100);
            answer = check();
            if(answer==0)
            {
                gotoxy(75,16);printf("Error! please try again!");
                i=i-1;
                break;
            }
                if(answer==a-b)
                {
                    point=point+1;
                    gotoxy(75,16);printf("+1 point\n");
                }
                break;

        }

        case 2:
        {
            gotoxy(75,15);
            printf(" %d. %.0f*%.0f : ",i,a=rand()%100,b=rand()%10);
            answer = check();
             if(answer==0)
            {
                gotoxy(75,16);printf("Error! please try again!");
                i=i-1;
                break;
            }
                if(answer==a*b)
                {
                    point=point+1;
                    gotoxy(75,16);printf("+1 point\n");
                }
                break;
            }


        case 3:
        {
            gotoxy(75,15);
            printf(" %d. %.0f/%.0f : ",i,a=rand()%100,b=rand()%9+1);
            answer = check();
             if(answer==0)
            {
                gotoxy(75,16);printf("Error! please try again!");
                i=i-1;
                break;
            }

                if(answer==a/b)
                {
                    point=point+1;
                    gotoxy(75,16);printf("+1 point\n");
                }
                break;

        }

        case 4:
        {
            gotoxy(75,15);
            printf(" %d. %.0f %% %.0f : ",i,a=(rand()%99)+1,b=(rand()%10)+1);
            answer = check();
             if(answer==0)
            {
                gotoxy(75,16);printf("Error! please try again!");
                i=i-1;
                break;
            }

                if(answer==(int)a%(int)b)
                {
                    point=point+1;
                    gotoxy(75,16);printf("+1 point\n");
                }
                break;
            }

        }
    i=i+1;
    delay(100);
    system("cls");
    }while(i!=11);
    time2 = clock();
   gotoxy(75,15); printf("Totaltime = %.2f\n",((time2-time1)/1000));
    return point*100/((int)((time2-time1)/1000));
}

    char nchoice;
    char cchoice;
    do{
    gotoxy(75,15);printf("Streak Math");
    gotoxy(75,17);printf("1.START");
    gotoxy(75,19);printf("2.Rule");
    fflush(stdin);
    nchoice=getch();
    switch(nchoice){
    case 49:
    system("cls");
    {point=Game1(m->point);gotoxy(75,16);printf("Total point = %d\n",point);break;}
    case 50:
     system("cls");
    rule();
    break;
    }do{
    gotoxy(75,17);
   printf("Restart(y/n)? : ");
    scanf(" %c",&cchoice);
    tolower(cchoice);
    if(cchoice==110||cchoice==121)
    {
        break;
    }else{
     gotoxy(75,18); printf("Try Again!");
    }
    }while(cchoice!=110||cchoice!=121);

    }while(cchoice!=110);


    scoreboard(point,g1);

}


void game2()//game2
{
    void dif()
{
      gotoxy(75,30);printf("Select Difficulty");
      gotoxy(75,32);printf("1. %s",d1);
      gotoxy(75,34);printf("2. %s",d2);
      gotoxy(75,36);printf("3, %s",d3);
      fflush(stdin);
    do { b->sele=getch();
    if(b->sele>51||b->sele<49)
    {
        gotoxy(75,46);printf("Try Again!");
    }
      switch(b->sele)
        {
        case (49):
            b->Guess=50;
            b->score=50;
            break;
        case (50):
            b->Guess=30;
            b->score=30;
            break;
        case (51):
            b->Guess=15;
            b->score=15;
            break;
        }
    }while(b->sele>51||b->sele<49);
}
     dif();
    void ship()
{
    srand(time(NULL));
    b->num[i]=rand()%100+1;
}
void water()
{
    gotoxy(75,15);printf("   1  2  3  4  5  6  7  8  9  10");
    for(i=0; i<10; i++)
    {
       gotoxy(75,16+(2*i+1)); printf("%2d ", i+1);
        for(j=0; j<10; j++)
        {
            if(b->ocean[i][j]==b->guess[i][j]&&b->guess[i][j]==1) printf("%c  ", 'X');
            else if(b->ocean[i][j]==b->guess[i][j]&&b->guess[i][j]==0) printf("-  ");
            else printf("~  ");

        }
    }
}
int battleground()
{
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            b->guess[i][j]=2;
        }
    }
    do{
        for(i-0;i<5;i++) ship();
        b->check=0;
        for(i=0; i<4; i++)
        {
            for(j=1; j<5; j++)
            {
                if(i==j) continue;
                else if(b->num[i]==b->num[j])
                {
                    ship();
                    (b->check)++;
                }
            }
        }
    }while((b->check)!=0);
    for(i=0; i<5; i++)
    {
        for(j=0; j<10; j++)
        {
            for(k=0; k<10; k++)
            {
                if(j==ceil((float)(b->num[i])/10)-1&&(k==(b->num[i])%10-1||k==(b->num[i])%10+9)) b->ocean[j][k]=1;
            }
        }
    }
    do{
        j=0;
        system("cls");
        gotoxy(1,100);printf("%d %d %d %d %d\n", b->num[0], b->num[1], b->num[2], b->num[3], b->num[4]);
        art(b->score,2);
        water();
        gotoxy(143,9);printf("Guess:%d",b->Guess);
        do{
            fflush(stdin);
        gotoxy(75,40);printf("Line : ");
        scanf("%d", &b->x[j]);
        if(b->x[j]>10||b->x[j]<1)
        {
            gotoxy(75,50);printf(" Invaild! Try Again!");
            continue;
        }
        }while(b->x[j]>10||b->x[j]<1);
       do{
            fflush(stdin);
        gotoxy(75,41);printf("Column : ");
        scanf("%d", &b->y[j]);
        if(b->y[j]>10||b->y[j]<1)
        {
            gotoxy(75,50);printf("Invaild! Try Again!");
            continue;
        }
        }while(b->y[j]>10||b->y[j]<1);
        for(i=0;i<5;i++)
        {
            if(((b->x[j]-1)*10+b->y[j])==b->num[i])
            {
                (b->guess[b->x[j]-1][b->y[j]-1])=1;
                (b->num[i])=0;
                break;
            }
            else (b->guess[(b->x[j])-1][(b->y[j])-1])=0;
        }
        (b->Guess)=(b->Guess)-1;
        for(i=0;i<10;i++)
        {
            for(j=0;j<10; j++)
            {
              if(b->ocean[i][j]==b->guess[i][j]&&b->guess[i][j]==0)
              {
                  (b->score)=(b->score)-1;
                 break;
              }
            }

        }
       j++;

    }while(((b->num[0])!=0||(b->num[1])!=0||(b->num[2])!=0||(b->num[3])!=0||(b->num[4])!=0)&&b->Guess>0);
    if(b->Guess<=0)
         {
             system("cls");
             game_over();
             getch();
         }
    return b->score;
}
    scoreboard(battleground(),g2);
}
void game3()
{

int GetIntInput(void){
    /*Receive input as string first and terminate it if there's any text other than 0-9.
      Convert digits text to int and return it back.
    */
    fflush(stdin);
    int num=0,i=0;
    char ch[200];
    gets(ch);
    do{
        if((int)ch[i]>=48&&(int)ch[i]<=57){
            num=(num*10)+((int)ch[i]-48);
        }
        else if(ch[i]=='\n') break;
        else{
            input_error=1;
            strcpy(info_str,"!- Invalid input, please try again. -!");
            break;
        }
        i++;
    }while(ch[i]!='\0');
    if(input_error!=1) return (num);
    else return -1;
}

int check_outbound(int a, int b){
    //checking if the box that's being checked is out of bounds or not.
    if(a<0||a>table_size-1||b<0||b>table_size-1) return 1;
    else return 0;
}

void end_screen(void){
    //print Score when the game ends
    if(game_skipped!=1) Score=Score+(life*1000.0);
    system ("cls");
    gotoxy(60,9); printf("%s",info_str);
   gotoxy(60,10); printf("Stage Cleared : [%d/10]",stagecleared);
   gotoxy(60,11); printf(">Total Score : %.0f <",point);
   gotoxy(60,12); printf("Press any key to go to leaderboard");
    getch();
    scoreboard(point,g3);
}

float time_bonus(double t){
    //change bonus modifier based on time used in each turn
    float bonus;
    if(turn!=1)
        if(t<1) bonus=3.0;
        else if(t>=600) bonus=0.0;
        else{
            bonus=(float)log10(600.0/t);
        }
    else bonus=1.0;
    return bonus;
 }
  void random_bomb(struct box *b,struct box *temp,struct box *check){
    //generating bomb in random cell that isn't opened
    int x,y,bom;
    srand(time(0));
    check=temp+((First_InputR*100)+First_InputC);
    bom=bomb_left;
    while(bom>0){
        x=(rand()%table_size);
        y=(rand()%table_size);
        b=temp+((y*100)+x);
        if(b->value!='9'&&b!=check&&b->status==1){
            b->value='9';
            bom=bom-1;
        }
    }
}

void check_adj_bomb(struct box *b,struct box *temp,struct box *mid){
    //checking the amount of boxes that contained bomb around it, excluding itself.
    //also process only if the box that is checked isn't bomb itself.
    int i,j,m,n,bomb_count;
    for(i=0;i<table_size;i++){
        for(j=0;j<table_size;j++){
            mid=temp+i*100+j;
            if(mid->value!='9'){
                bomb_count=0;
                for(m=i-1;m<=i+1;m++){
                    for(n=j-1;n<=j+1;n++){
                        if(check_outbound(m,n)==0){
                            b=temp+m*100+n;
                            if(b!=mid&&b->value=='9') bomb_count++;
                        }
                    }
                }
                b=mid;
                if(bomb_count!=0) b->value='0'+bomb_count;
            }
        }
    }
}

void blank_open(struct box *b, struct box *temp, struct box *mid,int x,int y){
    //change checked state for itself(middle box) and the boxes around it to 1, also open them.
    //if any box around itself(middle box) is a blank box send recursive function with the new box address.
    int i,j,m,n,bomb_count,row,col;
    col=x;
    row=y;
    mid=temp+row*100+col;
    mid->checked=1;
    printf("[[check,%d,%d]]\n",col,row);
    for(m=row-1;m<=row+1;m++){
        for(n=col-1;n<=col+1;n++){
            if(check_outbound(m,n)==0){
                b=temp+m*100+n;
                if(b!=mid){
                    b->status=0;
                    if(b->checked!=1){
                        b->checked=1;
                        box_count++;
                        if(b->value==' ') blank_open(b,temp,b,n,m);
                    }
                }
            }
        }
    }
}

void print_table(struct box *b, struct box *temp){
    //print the table
    int i,j,m,line;
    for(i=0;i<table_size;i++){
        if(i==0){
            printf("  ");
            for(m=0;m<table_size;m++) printf("%2d ",m+1);
            printf("\n");
        }
        for(line=1;line<=3;line++){
            if(line==1||line==3) printf("  ");
            else printf("%c ",'a'+i);
            for(j=0;j<table_size;j++){
                b=temp+((i*100)+j);
                if(line==1||line==3) printf("---");
                else{
                    printf("|");
                    if(b->status==1) printf("#");
                    else{
                        if(b->value=='9') printf("@");
                        else printf("%c",b->value);
                    }
                    printf("|");
                }
            }
            printf("\n");
        }
    }
 art(life,3);
}

void input_check(struct box *b, struct box *temp){
    //function for checking and giving input
    //also display majority of info or error msg above the input area
    int num,inputC,i,j,m=0,power_select;
    char buff[50],inputR,ans,buff2[2];
    printf("%s\n",info_str);
    strcpy(info_str,"");
    if(input_error==1){
        input_error=0;
    }
    else printf("\n");

    printf("Selection (1 = Box Select / 2 = Power-Up(%d) / 3 = Skip Stage / 4 = Quit Game)\n",PowerUp);
    printf("> ");
    num=GetIntInput();
    switch(num){
        case 1:{
            printf("Select Row : ");
            fflush(stdin);
            gets(buff);
            while(buff[m]!='\0'){
                //error if the input's length is not exact 1 letter long.
                if(m>0&&buff[m]!='\0'){
                    strcpy(info_str,"!- Invalid input, please try again. -!");
                    input_error=1;
                    break;
                }
                m++;
            }
            if(input_error!=1){
                inputR=buff[0];
                //checking if inputted letter is in fact a letter or not.
                if((inputR>=97&&inputR<=97+(table_size-1))||(inputR>=65&&inputR<=65+(table_size-1))){
                    printf("Select Column : ");
                    inputC=GetIntInput();
                    //checking if inputted column is out of bounds or not.
                    if(inputC>=1&&inputC<=table_size){
                        if(inputR>=97&&inputR<=97+(table_size-1)){
                            b=temp+((((int)inputR-97)*100)+inputC-1);
                            if(b->status==0){
                                //checking if the box is already opened or not.
                                input_error=1;
                                strcpy(info_str,"The box you selected is already opened.");
                            }
                            else{
                                b->status=0;
                                if(turn==1){
                                    First_InputR=(int)inputR-97;
                                    First_InputC=inputC-1;
                                }
                                strcpy(info_str,"You have selected box -> [");
                                strcpy(buff2,"");
                                buff2[0]=inputR;
                                strcat(info_str,buff2);
                                if(inputC<=9){
                                    char buff3[2];
                                    strcpy(buff3,"");
                                    buff3[0]=(char)(inputC+48);
                                    strcat(info_str,buff3);
                                }
                                else{
                                    char buff3[3];
                                    strcpy(buff3,"");
                                    buff3[0]=(char)((inputC/10)+48);
                                    buff3[1]=(char)((inputC%10)+48);
                                    strcat(info_str,buff3);
                                }
                                strcat(info_str,"]");
                                if(b->value=='9'){
                                    touch_bomb=1;
                                    strcat(info_str,", it has a bomb!");
                                    bomb_left--;
                                }
                                if(b->value==' '&&turn!=1){
                                    blank_open(b,temp,b,inputC-1,(int)inputR-97);
                                }
                                else box_count++;
                            }
                        }
                        else if(inputR>=65&&inputR<=65+(table_size-1)){
                            inputR=inputR+32;
                            b=temp+((((int)inputR-97)*100)+inputC-1);
                            if(b->status==0){
                                //checking if the box is already opened or not.
                                input_error=1;
                                strcpy(info_str,"The box you selected is already opened.");
                            }
                            else{
                                b->status=0;
                                if(turn==1){
                                    First_InputR=(int)inputR-97;
                                    First_InputC=inputC-1;
                                }
                                strcpy(info_str,"You have selected box -> [");
                                strcpy(buff2,"");
                                buff2[0]=inputR;
                                strcat(info_str,buff2);
                                if(inputC<=9){
                                    char buff3[2];
                                    strcpy(buff3,"");
                                    buff3[0]=(char)(inputC+48);
                                    strcat(info_str,buff3);
                                }
                                else{
                                    char buff3[3];
                                    strcpy(buff3,"");
                                    buff3[0]=(char)((inputC/10)+48);
                                    buff3[1]=(char)((inputC%10)+48);
                                    strcat(info_str,buff3);
                                }
                                strcat(info_str,"]");
                                if(b->value=='9'){
                                    touch_bomb=1;
                                    strcat(info_str,", it has a bomb!");
                                    bomb_left--;
                                }
                                if(b->value==' '&&turn!=1){
                                    blank_open(b,temp,b,inputC-1,(int)inputR-97);
                                }
                                else box_count++;
                            }
                        }
                    }
                    else{
                        strcpy(info_str,"!- Invalid input/Input is out of bounds, please try again. -!");
                        input_error=1;
                    }
                }
                else{
                    strcpy(info_str,"!- Invalid input/Input is out of bounds, please try again. -!");
                    input_error=1;
                }
            }
            break;
        }
        case 2:{
            if(PowerUp>=0){
                printf("Select your Power-Up\n");
                printf("1: \"Frenzied state\" - Increase the over-all modifier for this stage. Makes you gain more score but also dealt more dmg when you hit a bomb. Can be Stacked.\n");
                printf("2: \"Tornado\" - Random all the tiles that hasn't been opened. This could make your stage easier... or not.\n");
                printf("3: \"Nature's bargain\" - Heals 5.0 life points at the cost of -10000 score. Life cannot exceed 10.0 points!\n");
                printf("Power-Ups left : %d\n",PowerUp);
                printf("> ");
                power_select=GetIntInput();
                switch(power_select){
                    case 1:{
                        modifier=modifier*2.0;
                        strcpy(info_str,"\"Frenzied state\" is used! Modifier increased until the next stage!");
                        PowerUp--;
                        break;
                    }
                    case 2:{
                        random_bomb(temp,temp,temp);
                        check_adj_bomb(temp,temp,temp);
                        strcpy(info_str,"\"Tornado\" is used! All unopened boxes is now randomized!");
                        PowerUp--;
                        break;
                    }
                    case 3:{
                        life=life+5.0;
                        if(life>10.0) life=10.0;
                        Score=Score-10000.0;
                        strcpy(info_str,"\"Nature's bargain\" is used! Your life points is replenished at the costs of 10000 score points!");
                        PowerUp--;
                        break;
                    }
                    default:{
                        input_error=1;
                        strcpy(info_str,"!- Invalid input, please try again. -!");
                        break;
                    }
                }
            }
            else{
                input_error=1;
                strcpy(info_str,"You already used all of your Power-Ups on this stage!");
            }
            break;
        }
        case 3:{
            printf("Are you sure? (y/n) : ");
            scanf(" %c",&ans);
            if(ans=='y'){
                stageover=1;
                strcpy(info_str,"You skipped the stage. Proceeded to the next stage...");
                break;
            }
            else break;
        }
        case 4:{
            printf("Are you sure? (y/n) : ");
            scanf(" %c",&ans);
            if(ans=='y'){
                gameover=1;
                game_skipped=1;
                strcpy(info_str,"You ended the game. Game Over!");
                break;
            }
            else break;
        }
        case 991:{
            //cheat code to open all boxes. may skipped the stage in the process.
            for(i=0;i<table_size;i++){
                for(j=0;j<table_size;j++){
                    box[i][j].status=0;
                    box[i][j].checked=0;
                }
            }
            break;
        }
        case 992:{
            //cheat code to close all boxes. may skipped the stage in the process.
            for(i=0;i<table_size;i++){
                for(j=0;j<table_size;j++){
                    box[i][j].status=1;
                    box[i][j].checked=0;
                }
            }
            break;
        }
        default:{
            input_error=1;
            strcpy(info_str,"!- Invalid input, please try again. -!");
            break;
        }
    }
}

void score_display(void){
    //displaying score and other infos
    printf("||Score : %.0f\tLife : %.1f\tStage : [%d/10]\tCurrent Difficulty : %d||\n",score,life,stage,diff);
}

void display(struct box *b){
    //function for refreshing screen and what it's displaying
    system ("cls");
    print_table(b,b);
    score_display();
    input_check(b,b);
}

void check_bomb_left(struct box *b, struct box *temp){
    //check if the remaining closed box that has a bomb is equal to the amount of bomb that's yet to open.
    //if it does, stageover and stageclear is set to 1.
    int i,j,closed_box_count=0;
    for(i=0;i<table_size;i++){
        for(j=0;j<table_size;j++){
            b=temp+i*100+j;
            if(b->status==1) closed_box_count++;
        }
    }
    if(closed_box_count==bomb_left){
        strcpy(info_str,"All bomb found! Congratulations, you cleared the stage! Proceeded to the next stage...");
        stageclear=1;
        stagecleared++;
        stageover=1;
    }
}
void table_set(int d){
    //set table size based on difficulty
    if(d>=0 && d<=4) table_size=9;
    else if(d>=5 && d<=8) table_size=11;
    else if(d>=9 && d<=12) table_size=13;
    else if(d>=13 && d<=16) table_size=15;
    else if(d>=17 && d<=20) table_size=17;
}
    int i,j;
    char input[10];
    do{
        //choosing starting difficulty, repeat until the answer is valid.
        system ("cls");
        if(input_error=1){
            printf("%s",info_str);
            input_error=0;
        }
        gotoxy(75,15);printf("Select starting difficulty [0-20]");
        gotoxy(75,16);printf("> ");
        diff=GetIntInput();
        if(diff<0 || diff>20) strcpy(info_str,"!- Invalid input/Input is out of bounds, please try again. -!");
    }while(diff<0 || diff>20 || input_error==1);
    gameover=0;
    while(gameover!=1){
        //repeat until game is over.
        table_set(diff);
        system ("cls");
        bomb=(table_size*table_size*(10+(diff/2))/100)+(stage-1);
        bomb_left=bomb;
        //assigning every box's value with blank and then close it.
        for(i=0;i<table_size;i++){
            for(j=0;j<table_size;j++){
                box[i][j].status=1;
                box[i][j].value=' ';
                box[i][j].checked=0;
            }
        }
        modifier=1.0;
        stageover=0;
        stageclear=0;
        PowerUp=1+(diff/8);
        turn=1;
        while(stageover!=1&&gameover!=1){
            //repeat until stage or game is over.
            turn_start=clock();
            box_count=0;
            touch_bomb=0;
            do{
                display(&box[0][0]);
            }while(input_error==1);
            if(turn==1){
                //not random until first input is succeed.
                random_bomb(&box[0][0],&box[0][0],&box[0][0]);
                check_adj_bomb(&box[0][0],&box[0][0],&box[0][0]);
            }
            turn_end=clock();
            turn_time_used=(turn_end-turn_start)/CLOCKS_PER_SEC;
            time_modifier=time_bonus(turn_time_used);
            Score=(int)(Score+(((float)box_count*10.0)*modifier*(((float)diff+100.0)/100.0)*time_modifier));
            point = Score;
            if(turn!=1) check_bomb_left(&box[0][0],&box[0][0]);
            if(touch_bomb==1) life=life-(1.0*((((float)diff*2.5)+100.0)/100.0)*modifier);
            if(life<=0.0){
                gameover=1;
                strcpy(info_str,"Your life has been fully depleted! Game Over!");
            }
            if(stageclear==1) Score=(int)Score+10000.0;
            turn++;
        }
        stage++;
        stageover=0;
        if(diff<20) diff++;
        if(stage>10) gameover=1;
    }
    end_screen();

}

void art(int p,int x)
{
    switch(x)
    {
         case(1):
         pi(p,r);
         break;
        case(2):
         Ship(p);
        break;
        case(3):
        break;
    }
}
int main()
{
    FILE *fp;
    fp =fopen("leaderboard.txt","a");
     time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    start();
     switch(me->input)
        {
        case (49):
    fprintf(fp,"---------------------------------------------------------\n");
    fprintf(fp,"Date/Time: %d-%02d-%02d %02d:%02d:%02d\n",tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    fprintf(fp,"Game:%s                    \n",g1);
    fprintf(fp,"Name:%s                            \n",me->name);
    fprintf(fp,"Score:%d                           \n",score(point,me->input));
    fprintf(fp,"---------------------------------------------------------\n");
            break;
        case (50):
    fprintf(fp,"---------------------------------------------------------\n");
    fprintf(fp,"Date/Time: %d-%02d-%02d %02d:%02d:%02d\n",tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    switch(b->sele)
    {
       case(49):
       fprintf(fp,"Game:%s             Difficulty: %s   \n",g1,d1);
        break;
        case(50):
       fprintf(fp,"Game:%s             Difficulty: %s   \n",g2,d2);
        break;
        case(51):
       fprintf(fp,"Game:%s             Difficulty: %s   \n",g3,d3);
        break;
    }

    fprintf(fp,"Name:%s                            \n",me->name);
    fprintf(fp,"Score:%d                           \n",score(point,me->input));
    fprintf(fp,"---------------------------------------------------------\n");
            break;
        case (51):
    fprintf(fp,"---------------------------------------------------------\n");
    fprintf(fp,"Date/Time: %d-%02d-%02d %02d:%02d:%02d\n",tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    fprintf(fp,"Game:%s             Difficulty: %d   \n",g3,diff);
    fprintf(fp,"Name:%s                            \n",me->name);
    fprintf(fp,"Score:%d                           \n",score(point,me->input));
    fprintf(fp,"---------------------------------------------------------\n");;
            break;
        }


    fclose(fp);

    return 0;
}
