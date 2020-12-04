#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 255

#define MSG_1 "Could not read file!\n"
#define MSG_2 "File received\n"
#define MSG_3 "creating file\n"
#define MSG_4 "program finished\n"
#define MSG_5 "only one argument given, please provide two\n"
#define MSG_6 "no arguments given\n"

void word_link(char string[]);

int main(int argc, char* argv[])
{
    char current_line[SIZE];
    FILE *myFile;
    FILE *myFileOUT;

    //argv[1] = "duomenys.txt";
    //argv[2] = "rezultatai.txt";

    if(argc == 2){
       printf(MSG_5);
    }else if(argc >= 3 ){
        myFile = fopen (argv[1], "r");
        fopen(argv[2], "w");
        myFileOUT = fopen (argv[2], "a");
        if(myFile != NULL){
            printf(MSG_2);
            if(myFileOUT != NULL){
                printf(MSG_3);
                while(!feof(myFile)){
                    fgets(current_line, SIZE, myFile);
                    word_link(current_line);
                    fputs(current_line, myFileOUT);
                }
            } else{
                printf("Could not create file!\n");
                perror("");
            }
            fclose(myFile);
            fclose(myFileOUT);
            printf(MSG_4);
        } else{
            printf(MSG_1);
            perror("");
        }
    }else{
        printf(MSG_6);
    }


    return 0;
}

void word_link(char string[])
{
    int size_length = strlen(string);
    for(int i = 0; i < size_length; ++i)
        if((string[i] == '-') && (string[i + 1] != ' ' && string[i + 1] != '\0' && string[i + 1] != '\n'))
            for(int j = i; j < size_length; j++)
                string[j] = string[j + 1];
}
