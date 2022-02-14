#include"threadpool.hpp"
#include"Task.hpp"
#include<time.h>
#include<stdlib.h>
int main()
{
  ThreadPool<Task> * q=new ThreadPool<Task>();//创建线程池
  q->ThreadPoolInit();
  srand((long int)time(NULL));
  while(1)
  {
    char arr[]="+-*/%";
    int x=rand()%100+1;
    int y=rand()%100+1;
    char op=arr[rand()%5];
    Task t(x,y,op);//创建任务
    q->Push(t);//将任务推送给队列中
  }
  return 0;
}
