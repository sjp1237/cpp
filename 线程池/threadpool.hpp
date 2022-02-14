#pragma once
#include<iostream>
#include<queue>
#include<pthread.h>
#include<unistd.h>
using namespace std;


#define NUM 4
template<class T>
class ThreadPool
{
  private:
    queue<T> q;//任务队列
    int thread_num;//线程池的线程数量
    pthread_mutex_t lock;//互斥锁
    pthread_cond_t cond;//条件变量
  public:
    ThreadPool(int num=NUM)//构造函数
      :thread_num(num){
        pthread_mutex_init(&lock,NULL);
        pthread_cond_init(&cond,NULL);
    }

    bool Empty()
    {
      return q.size()==0?true:false; 
    }

   static  void* Routine(void* arg)//线程执行流
    {
      pthread_detach(pthread_self());//线程分离
      ThreadPool* self=(ThreadPool*)arg;
      while(1)
      {
        self->LockQueue();
        while(self->Empty())//任务队列是否为空
        {
          self->Wait();
        }
        T data;
        self->Pop(data);//取出任务
        self->UnlockQueue();

        cout<<pthread_self()<<"# "; 
        //处理任务
        data.Run();//处理任务
        sleep(1);
      }
    }
    
    void Wait()
    {
      pthread_cond_wait(&cond,&lock);
    }

    void LockQueue()
    {
      pthread_mutex_lock(&lock);
    }

    void UnlockQueue()
    {
      pthread_mutex_unlock(&lock);
    }

    void ThreadPoolInit()
    {
      pthread_t tid;
      for(int i=0;i<thread_num;i++)
      {
        pthread_create(&tid,NULL,Routine,(void*)this);
      }
    }

    void Push(const T& in)//将任务推进任务队列中
    {
      LockQueue();
      q.push(in);
      UnlockQueue();
      SignalThread();
    }

    void SignalThread()
    {
      pthread_cond_signal(&cond);
    }

    void Pop( T& out)//将任务从队列中删除
    {
      out=q.front();
      q.pop();
    }
    ~ThreadPool()
    {
      pthread_mutex_destroy(&lock);
      pthread_cond_destroy(&cond);
    }
};
