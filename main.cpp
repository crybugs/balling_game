#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

void countForX(const char GAME[], int cur_index, int &ABC)
{
    ABC+=10;
    if(GAME[cur_index+2]=='X'){
        ABC+=10;
        if(GAME[cur_index+4]=='X'){
            ABC+=10;
        }
        else if(GAME[cur_index+4]=='-'){
            ABC+=0;
        }
        else{
            ABC+=GAME[cur_index+4];
        }
    }
    else if(GAME[cur_index+2]=='-'){
        if(GAME[cur_index+3]=='/'){
            ABC+=10;
        }
        else{
            ABC+=GAME[cur_index+3];
        }
    }
    else{
        ABC+=GAME[cur_index+2];
        if(GAME[cur_index+3]=='-'){
            ABC+=0;
        }
        else if(GAME[cur_index+3]=='/'){
            ABC+=(10-(GAME[cur_index+3]));
        }
        else{
            ABC+=GAME[cur_index+3];
        }
    }
}

void countforN9X(const char GAME[], int cur_index, int &ABC)
{
        if (GAME[cur_index+1]=='X'){
            ABC+=10;
        }
        else if(GAME[cur_index+1]=='-'){
            ABC+=0;
        }
        else if(GAME[cur_index+1]=='/'){
            ABC+=(10-(GAME[cur_index]-'0'));
        }
        else if(GAME[cur_index+1]!=' '){
            ABC+=GAME[cur_index+1]-'0';
        }
        if (GAME[cur_index+2]=='X'){
            ABC+=10;
        }
        else if (GAME[cur_index+2]=='-'){
            ABC+=0;
        }
        else if(GAME[cur_index+2]=='/'){
            if (GAME[cur_index+1]=='-'){
                ABC+=10;
            }
            else{
                ABC+=(10-(GAME[cur_index+1]-'0'));
            }
        }
        else if(GAME[cur_index+2]!=' '){
            ABC+=GAME[cur_index+2]-'0';
        }
}

void countforSlash(const char GAME[], int cur_index, int &ABC)
{
    if(GAME[cur_index-1]=='-'){
        cur_index+=1;
        ABC+=0;
    }
    else if(GAME[cur_index-1]!='-'){
        ABC+=(10-(GAME[cur_index-1]-'0'));
    }
    if(GAME[cur_index+2]=='X'){
        ABC+=10;
    }
    else if(GAME[cur_index+2]=='-'){
        ABC+=0;
    }
    else{
        ABC+=GAME[cur_index+2];
    }
}

void countforN9Slash(const char GAME[], int cur_index, int &ABC){
    if (GAME[cur_index+1]=='-'){
        ABC+=0;
    }
    else if(GAME[cur_index+1]=='X'){
        ABC+=10;
    }
    else{
        ABC+=GAME[cur_index+1]-'0';
    }
}

int countforNum(const char GAME[], int cur_index, int &ABC)
{
    ABC+=GAME[cur_index];
}
int main()
{
    int N;
    int total = 0;
    scanf("%d", &N);
    fgetc(stdin);
    for (int p = 0; p < N; p++)
    {
        int ABC[10] = {0};
        char GAME[65] = {'\0'};
        int n = 0;
        int c = 0;
        scanf("%[^\n]", GAME);
        fgetc(stdin);
        for (int i = 0; i < strlen(GAME); i++)
        {
            {
                // fprintf(stderr, "Debug messages...%c %d\n",GAME[i],i);
                if (GAME[i] == 'X')
                {
                    if (n == 9 && c==0){
                        countforN9X(GAME, i, ABC[n]);
                        break;
                    }
                    else if(n == 9){
                        c+=1;
                    }
                    else{
                        countForX(GAME, i, ABC[n]);
                    }
                }
                else if (GAME[i] == '/')
                {
                    if (n == 9){
                        countforN9Slash(GAME, i, ABC[n]);
                        break;
                    }
                    else{
                        countforSlash(GAME, i, ABC[n]);
                    }
                }
                else if (GAME[i] == ' ')
                {
                    n++;
                    ABC[n] += ABC[n - 1];
                }
                else if (GAME[i] == '-')
                {
                }
                else
                {
                    ABC[n] += GAME[i] - '0';
                }
            }
        }
        for (int i = 0; i <= 9; i++)
        {
            if (i == 9)
            {
                printf("%d\n", ABC[i]);
            }
            else
            {
                printf("%d ", ABC[i]);
            }
        }
    }
    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    // printf("5 13 18 26 31 32 34 40 47 54\n");
    return 0;
}