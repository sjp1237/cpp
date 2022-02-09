#include<pthread.h>
#include<iostream>
#include<cstdio>
#include<unistd.h>
using namespace std;
pthread_mutex_t lock;
int num1=0;
int num2=0;
void* run1(void* arg)
{
  while(1)
  {
     num1++;
     printf("线程一:%d\n",num1);
     sleep(1);
  }
  return NULL;
}
void* run2(void* arg)
{
  while(1)
  {
     num1--;
     printf("线程二：%d\n",num1);
     sleep(1);
  }
  return NULL;
}





int main()
{
  pthread_mutex_init(&lock,NULL);
  pthread_t tid1,tid2;
  pthread_create(&tid1,NULL,run1,NULL);
  pthread_create(&tid2,NULL,run2,NULL);

  pthread_join(tid1,NULL);
  pthread_join(tid2,NULL);
  return 0;
}
