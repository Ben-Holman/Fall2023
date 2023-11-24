// sender.c
// sender process example - datagram socket
// function descriptions are extracted from the Linux manual at
//http://man7.org/linux/man-pages/man7/ and
//http://pubs.opengroup.org/onlinepubs/009695399/functions/
#include <stdio.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h> /* UNIX domain header */
#include <unistd.h>
#include <time.h>
int main(){ 
int soc; // socket number
char buf[] = "Hello there, this is the message to be sent to the reciever terminal";// message content to be sent
char buf2[] = "This is a second message.";
const char *NAME = "./receiver_soc"; //name of the socket path
struct sockaddr_un peer; //socket address variable
int n;
int m; 
peer.sun_family = AF_UNIX;// The AF_UNIX (also called the AF_LOCAL) is a
//socket family used to communicate between processes on the same machine.
strcpy(peer.sun_path, NAME); //copy the NAME to the socket pathname of peer

soc = socket(AF_UNIX, SOCK_DGRAM, 0); /* SOCK_DGRAM is used for
datagram oriented sockets */

if ( access(peer.sun_path, F_OK) > -1 ){

n = sendto(soc, buf, strlen(buf), 0, (struct sockaddr *)&peer,
sizeof(peer)); /* the datagram is sent and the content of the buf is
transmitted */
// check if the transmission succeeded
//n = sleep(10);
m = sendto(soc, buf2, strlen(buf2), 0, (struct sockaddr *)&peer, sizeof(peer));
if ( n < 0 ){ 
    fprintf(stderr, "sendto failed\n");
    exit(1);
  }
  printf("Sender: %d characters sent!\n", n); /* print the message
sent */
if(n < 0){
      fprintf(stderr, "sendto failed\n");
      exit(1);
    }
  printf("Sender: %d characters sent!\n", m);
  close(soc); /* close the socket */
  }
  return(0);
}
