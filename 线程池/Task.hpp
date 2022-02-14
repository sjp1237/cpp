#pragma  once
#include<iostream>
#include<stdio.h>
using namespace std;
class Task
{
  private:
    int x;
    int y;
    char op;
  public:
    Task(int _x,int _y,char _op)
      :x(_x)
      ,y(_y)
      ,op(_op)
    {

    }
    Task()
    {

    };
    void Run()
    {
      int ret=0;
      switch(op){
        case '+':
          ret=x+y;
          break;
        case '-':
          ret=x-y;
          break;
        case '*':
          ret=x*y;
          break;
          case '/':
          ret=x/y;
          break;
          case '%':
          ret=x%y;
          break;
      }
      printf("%d %c %d = %d\n",x,op,y,ret);
    } 
};
