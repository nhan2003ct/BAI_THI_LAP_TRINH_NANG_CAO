// BAI TACH HO VA TEN RA
//------------------------------------------------------------------------------//
#include <string.h>
#include <stdio.h>
void tachhoten(char hoten[80])// bai 6
{
   char *token;
   token = strtok(hoten, " ");
   int c=0;
   char mang[5][15];
   while( token != NULL )
   {
      strcpy(mang[c],token);
      c++;
      token = strtok(NULL, " ");
   }
   printf("%s \n",mang[0]);
   for(int i=1;i<c-1;i++){
    printf("%s ",mang[i]);
   }
   printf("%s",mang[c-1]);
}
void tachhoten2(char hoten[80])// bai 7
{
    char *token;
   token = strtok(hoten, " ");
   int c=0;
   char mang[5][15];
   while( token != NULL )
   {
      strcpy(mang[c],token);
      c++;
      token = strtok(NULL, " ");
   }
   printf("%s\n",mang[c-1]);
   printf("%s ",mang[0]);
   for(int i=1;i<c-1;i++){
    printf("%s\n",mang[i]);
   }
  // printf("%s",mang[c-1]);
}
int main()
{
   FILE *f;

   char s[1000];
   int n=0;
   f=fopen("fileten.txt","r");
   while(fgets(s,sizeof(s),f)!=NULL)
    {
        tachhoten2(s);
    }
   return(0);
}