#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/


void countForALL(const char GAME[], int cur_index, int &ABC, int &n, int counter){
    if (counter==2){
        ABC+=10;
    }
    else if(counter==1){
        if (GAME[cur_index-1]=='-'){
            ABC+=10;
        }
        else{
            ABC+=(10-(GAME[cur_index-1]-'0'));
        }
    }
    cur_index++;

    while(GAME[cur_index]==' '){
        cur_index++;
    }

    while(counter>0){
        if (GAME[cur_index]=='X'){
            ABC+=10;
        }
        else if(GAME[cur_index]=='-'){
        }
        else{
            ABC+=GAME[cur_index]-'0';
        }
        counter-=1;
        if (counter==1){
            cur_index++;
            if (GAME[cur_index]==' '){
                cur_index++;
            }
            if (GAME[cur_index]=='X'){
                ABC+=10;
            }
            else if(GAME[cur_index]=='-'){
            }
            else if(GAME[cur_index]=='/'){
                if (GAME[cur_index-1]=='-'){
                    ABC+=10;
                }
                else{
                    ABC+=(10-(GAME[cur_index-1]-'0'));
                }
            }
            else{
                ABC+=GAME[cur_index]-'0';
            }
            counter-=1;
        }        
        break;
    }
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
                    countForALL(GAME, i, ABC[n], n,2);
                    if (n == 9)
                        break;
                }
                else if (GAME[i] == '/')
                {
                    countForALL(GAME, i, ABC[n], n,1);
                    if (n == 9)
                        break;
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

// 8/8 數字過大原因還找不到  今天就是慢慢一直修改，但還沒找到最後的問題