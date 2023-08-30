// Jadea Parchment this program will compute a suffix with at most M characters (M ≥ 20) for each file.
#include<stdio.h>
#include<string.h>
#define MAXIMUMNUM 1000

int main(int argc , char *argv[])
 { 
    int M;
    printf("Enter the value of M: \n"); //accept input
    scanf("%d", &M);
     FILE *Filename;
     int l;
     for (l = 1;l < argc;l++) 
{
       Filename = fopen(argv[l], "r"); //read the file 
  if (Filename == NULL) 
{
       printf("Error opening file\n"); //print error message
       return 1;
   }

    char s[MAXIMUMNUM+1];
    char s1[MAXIMUMNUM+1] = "" ;

    while (fgets (s, MAXIMUMNUM, Filename) != NULL)
{
     if (((strlen(s)-1) + strlen(s1)) > M)
{
         *(s1) = '\0';
    }
    *s1 = *strcat(s1,s); // concatunate the 2 strings
    int n;
    for (n = 0;n <strlen(s1);n++)
{
        if (*(s1+n) == '\n') 
{
            *(s1+n) = '\0';
} 
    } 
    } 
printf("%s: %s \n", argv[l],s1);//print the suffix
  *(s1) = '\0';
fclose(Filename); //close the file
    } 

  return 0;
} 
