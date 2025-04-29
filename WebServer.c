#include <stdio.h>
#include <arpa/inet.h>
int main(int argc, char const *argv[])
{
  int serv_sock;
  struct sockaddr_in serv_addr;

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
  
  // 서버 주소 설정
  memset(&serv_addr, 0, sizeof(serv_addr));   // serv_addr구조체의 모든 값을 0으로 초기화
  serv_addr.sin_family = AF_INET; // IPv4
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);  // 모든 IP에서 오는 연결 수락
  serv_addr.sin_port = htons(atoi(argv[1]));  // 포트번호
  return 0;
}
