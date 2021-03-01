#include "CountFile.h"

int main()
{
  printf("Checking for file content\n");

  checkfile();

  printf("Lines : %d\n", get_lines());

  printf("Words : %d\n", get_words());

  printf("Characters : %d\n", get_characters());
}