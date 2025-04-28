#include <stdio.h>

int main(int argc, char const *argv[])
{
  if (argc != 2)  //서버 실행시킬 때 서버프로그램명, 포트번호 2개만 받도록 설정(아니라면 exit)
  {
     exit(1);
  }
  
  return 0;
}
