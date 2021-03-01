#include "CountFile.h"

int lines, characters, words;;

void checkfile()
{
	int f_d,n_bytes;
	char ch[16384];

    f_d=open("Document1.txt",O_RDONLY);
	  if(f_d<0)
	  {
	  	perror("open");
		  exit(1);
  	}
    words = 0,lines = 0;
      while(n_bytes=read(f_d,ch,sizeof(ch)))
      {
          for(int i=0;i<n_bytes;i++)
           {
            if (ch[i] == '\n')
               lines++;
            
            if (ch[i] == ' ' || ch[i] == '\t' || ch[i] == '\n')
               words++;
           }
        characters=n_bytes;
    }
      close(f_d);
}

      int get_lines()
      {
       return lines;
      }

int get_characters()
{
  return characters;
}
      int get_words()
      {
      return words;
      }