//  C programs to simulate UNIX commands like cp, ls, grep

// ************** Simulation of ls command ************
#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char*argv[])
{
    DIR * dp;
    struct dirent * link;
    dp = opendir(argv[1]);
    while((link = readdir(dp))!=0)
    {
        printf("%s\n", link->d_name);
    }
    closedir(dp);
}

// ************** Simulation of cp command ************
#include<stdio.h>
#include<stdlib.h>
#include<fenv.h>

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    fp1 = fopen(argv[1], "r");
    if(fp1 == NULL)
    {
        print("Error opening file\n");
        exit(1);
    }
    fp2 = fopen(argv[2],"a");
    char ch;
    while((ch=fgetc(fp1))!=EOF)
    {
        fputc(ch, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}

// ************** Simulation of grep command ************
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    if(argc!=3)
    {
        printf("Usage: ./grep <string><file>\n");
        return 1;
    }
    FILE *fp;
    fp=fopen(argcv[2], "r");
    if(fp==NULL)
    {
        printf("Error opening file \n");
        exit(1);
    }
    char line[1024];
    while(fgets(line, sizeof(line), fp)!=NULL)
    {
        if(strstr(line, argv[1])!=NULL)
        {
            printf("%s", line);
        }
    }
    fclose(fp);
    return 0;
}