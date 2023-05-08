#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING 1
#define DELIM 2
#define SUBDELIM 3

int main(int argc, char *argv[])
{
   char *str1, *str2, *token, *subtoken;
   char *saveptr1, *saveptr2;

   if (argc != 4) 
   {
       fprintf(stderr, "Usage: %s string delim subdelim\n",argv[0]);
       fprintf(stderr, "Example: %s 'a/bbb///cc;xxx:yyy:' ':;' '/'\n", argv[0]);
       exit(EXIT_FAILURE);
   }
   str1 = argv[STRING];
   for (int j = 1; ; j++) 
   {
       token = strtok_r(str1, argv[DELIM], &saveptr1);
       str1 = NULL;
       if (token == NULL)
           break;
       printf("%p (%d): %s\n", saveptr1, j, token);
       
       for (str2 = token; ; ) 
       {
           subtoken = strtok_r(str2, argv[SUBDELIM], &saveptr2);
           str2 = NULL;
           if (subtoken == NULL)
               break;
           printf("%p --> %s\n",saveptr2, subtoken);
       }
   }
   exit(EXIT_SUCCESS);
}

/* Example:
       $ ./a.out 'a/bbb///cc;xxx:yyy:' ':;' '/'
       1: a/bbb///cc
                --> a
                --> bbb
                --> cc
       2: xxx
                --> xxx
       3: yyy
                --> yyy
*/

