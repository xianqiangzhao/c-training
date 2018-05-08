#define _GNU_SOURCE
#include <pthread.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#define THREAD_COUNT 4
/* LT模式 */
#define EPOLL_LT 0
/* ET模式 */
#define EPOLL_ET 1
#define LISTENQ   20

pthread_barrier_t mybarrier;
int i, maxi, listenfd, connfd, sockfd, epfd, nfds;
struct epoll_event ev, events[20];


//set block
void setnonblocking(int sock)
{
  int opts;
  opts = fcntl(sock, F_GETFL);

  if(opts < 0) {
    perror("fcntl(sock, GETFL)");
    exit(1);
  }

  opts = opts | O_NONBLOCK;

  if(fcntl(sock, F_SETFL, opts) < 0) {
    perror("fcntl(sock, SETFL, opts)");
    exit(1);
  }
}


//pthead
void* threadFn(void *id_ptr) {

  int thread_id = *(int*)id_ptr, nfds;
  int wait_sec = 1 + rand() % 5;
  printf("thread %d: Wait for %d seconds.\n", thread_id, wait_sec);
  //sleep(20);
  printf("thread %d: I'm ready...\n", thread_id);
  
  for(; ;) {
    nfds = epoll_wait(epfd, events, 20, 1000);

  }


  pthread_barrier_wait(&mybarrier);

  printf("thread %d: going!\n", thread_id);
  return NULL;
}


int main() {
  int i;
  pthread_t ids[THREAD_COUNT];
  int short_ids[THREAD_COUNT];


  //epoll create 
  printf("epoll socket begins.\n");
 
  ssize_t n;
  socklen_t clilen;
  epfd = epoll_create(256);

  //socket create
  struct sockaddr_in clientaddr;
  struct sockaddr_in serveraddr;
  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  setnonblocking(listenfd);

  ev.data.fd = listenfd;
  ev.events = EPOLLIN;

  epoll_ctl(epfd, EPOLL_CTL_ADD, listenfd, &ev);

  bzero(&serveraddr, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  char *local_addr = "*.*.*.0";
  inet_aton(local_addr, &(serveraddr.sin_addr));
  serveraddr.sin_port = htons(8080);
  
  bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));

  listen(listenfd, LISTENQ);

  for(; ;) {
      nfds = epoll_wait(epfd, events, 20, 1000);

    }

  // srand(time(NULL));
  // pthread_barrier_init(&mybarrier, NULL, THREAD_COUNT + 1);

  // for (i=0; i < THREAD_COUNT; i++) {
  //   short_ids[i] = i;
  //   pthread_create(&ids[i], NULL, threadFn, &short_ids[i]);
  // }

  // printf("main() is ready.\n");

  // pthread_barrier_wait(&mybarrier);

  printf("main() is going!\n");

  // for (i=0; i < THREAD_COUNT; i++) {
  //   pthread_join(ids[i], NULL);
  // }

 // pthread_barrier_destroy(&mybarrier);

  return 0;
}