#include <stdio.h>
#include <arpa/inet.h>
int main(int argc, char const *argv[])
{
  int serv_sock;

  if (argc != 2)  //서버 실행시킬 때 서버프로그램명, 포트번호 2개만 받도록 설정(아니라면 exit)
  {
     exit(1);
  }
  
  // 소켓 생성
  serv_sock = socket(PF_INET,SOCK_STREAM, 0); //PF_INET = IPv4, SOCK_STREAM = TCP 방식을 의미함, 실패하면 -1 리턴
  if (serv_sock == -1) {
    perror("socket() error");
    exit(1);
  }
  
  return 0;
}
