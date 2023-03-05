#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct point 
{
    char nameofrest[20];
    int xcor, ycor;
};
int converter(char * str);

void main()
{
    struct point p1;
    struct point p2;
    char c;
    char rx[10];
    char ry[10];
    int j=0,next=0,counter =0;
    FILE *fpt;
    printf("Please enter your address in X and Y co-ordinates\n");
    scanf("%d %d", &p1.xcor, &p1.ycor);
    printf("x = %d, y = %d\n", p1.xcor, p1.ycor);
    int restno =3;//will be asigned based on rest picked
    fpt = fopen("address.txt", "r");	// open file
    c = fgetc(fpt);
    while (c != EOF)		//printing until we encounter end of file
    {
       // printf("%c", c);
        if(counter == restno-1)
        {
            if(c==' ')
            {
                rx[j]='\0';
                next=1;
                j=0;
                goto labelend;
            }
            if(c=='\n') 
            {
                ry[j]='\0';
                break;
            }
            if(next==0)
            {
                rx[j]=c;
            }
            else if(next ==1)
            {
                
                ry[j]=c;
                
            }
            j++;
        }
        labelend:
        if(c=='\n') counter++;
        c = fgetc(fpt);

    }
  
    fclose(fpt);
    int cx = converter(rx);
    int cy = converter(ry);
    float time = (sqrt((cx-p1.xcor)*(cx-p1.xcor) + (cy-p1.ycor)*(cy-p1.ycor)))+5;
    printf("the estimated time of arrival of your food is %d mins",(int)time );
    }
int converter(char * str)
{
    int num = 0;
  
    // converting string to number
    for (int i = 0; str[i] != '\0'; i++) {
        num = num * 10 + (str[i] - 48);
    }
  
    // at this point num contains the converted number
    return num;
}