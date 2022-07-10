#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

//7/10

int main()
{
    int N;
    int total = 0;
    scanf("%d", &N); fgetc(stdin);
    for (int p = 0; p < N; p++) {
        int ABC[10] = {0};
        char GAME[65] = {'\0'};
        int n = 0;
        scanf("%[^\n]", GAME); fgetc(stdin);
        for (int i = 0; i<strlen(GAME); i++){
            if (GAME[i]=='/'){
                if(GAME[i-1]=='-'){
                    ABC[n]+=10;
                }
                else{
                    ABC[n]+=(10-(GAME[i-1]-'0'));
                }
            }
            
            else if(GAME[i]=='X'){
                ABC[n]+=10;
            }

            else if (GAME[i]!=' ' && GAME[i]!='-'){
                if (n>0 && GAME[i+1]==' '){
                    ABC[n]+=GAME[i]-'0';
                }
                else{
                    ABC[n]+=GAME[i]-'0';
                }
            }

            if(GAME[i]==' '){
                n+=1;
                if (GAME[i-1]=='/' && GAME[i+1]!='-'){
                    ABC[n-1]+=GAME[i+1]-'0';
                }
                ABC[n]+=ABC[n-1];
            }

            else if (GAME[i]=='-'){
                ABC[n]+=0;
            }
        }
        for (int i = 0; i<=9; i++){
            if (i==9){
                printf("%d\n",ABC[i]);
            }
            else{
                printf("%d ",ABC[i]);
            }
        }
    }
    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    // printf("5 13 18 26 31 32 34 40 47 54\n");
    return 0;
}