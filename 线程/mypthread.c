#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t mutex;//创建一把锁
int tickets=10000;
void* grabtickets(void* argv)
{
  int name=(int)argv;
  while(1)
  {
  pthread_mutex_lock(&mutex);//加锁
  if(tickets>0)
  {
    printf("thread[%d],票号: %d\n",name,tickets--);
    usleep(1000);
    pthread_mutex_unlock(&mutex);//解锁
  }
  else{
    pthread_mutex_unlock(&mutex);//解锁
    break;
  }
  }
  return NULL;
}
int main()
{
  pthread_mutex_init(&mutex,NULL);//锁的初始化
  pthread_t ids[10];
  for(int i=0;i<10;i++)
  {
    //创建线程
   pthread_create(&ids[i],NULL,grabtickets,(void*)i);
  }
  for(int i=0;i<10;i++)
  {
    pthread_join(ids[i],NULL);
  }
  pthread_mutex_destroy(&mutex);//将锁销毁
  return 0;
}


















