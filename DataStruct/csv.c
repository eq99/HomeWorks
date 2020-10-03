#include<stdio.h>
/*#include<stdlib.h>*/
#include<string.h>

int
main(){

  FILE *fp;
  char line[1024];/*every line of file*/
  char *result;/*every record of line */

  if((fp=fopen("test.csv", "at+")) != NULL){
    for( ; fgets(line, sizeof(line), fp) != NULL; ){
      printf("%s",line);

      result=strtok(line, ",");

      for( ; result != NULL; ){
        printf("%s\n", result);
        result=strtok(NULL, ",");
      }
    }
  }

  fclose(fp);
}
