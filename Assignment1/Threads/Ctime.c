
#include "time.h"

void *task_body_time(void* pv)
{
  int i=0;
  time_t t;
  struct tm* current_time;
  
  t = time(NULL);
  
  current_time = localtime(&t);
  printf("%02d : %02d : %02d \n",current_time->tm_hour, current_time->tm_min, current_time->tm_sec);

}
void getTime()
{
  int i, n=10;
  pthread_t ptrarr[n];

  for(i=0; i<n; ++i)
  {
    
    pthread_create(&ptrarr[i], NULL, task_body_time, (void *)(__intptr_t)i);
    
    sleep(3);
  }
  for(i=0; i<n; i++)
  {
    pthread_join(ptrarr[i], NULL);
  }
}
