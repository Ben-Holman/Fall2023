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
#include <unistd.h>
#include <sys/un.h> /* UNIX domain header */
void cleanup(int soc, char *file)
{ close(soc);
unlink(file);
}
int main(){ 
int soc; // socket number
char buf[] = "Hello there, this is the message to be sent to the reciever terminal"; // message content to be sent
const char *NAME = "./receiver_soc"; //name of the socket path
struct sockaddr_un peer; //socket address variable
int n;
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
if ( n < 0 ){ 
    fprintf(stderr, "sendto failed\n");
    exit(1);
  }
  printf("Sender: %d characters sent!\n", n); /* print the message
sent */
  close(soc); /* close the socket */
  }

//REC CODE
  
int soc_rec; // socket number
char buf_rec[128]; // buffer
const char *NAME_REC = "./receiver_soc"; // name of the socket path
struct sockaddr_un self; //declare a socket address variable
struct sockaddr_un peer_send; // declare another socket address
int n_rec, len; //used for the length of the message
// create a socket - to understand the code read the page of the Linux
//Programmer's Manual at http://man7.org/linux/man-pages/man7/unix.7.html
//bind the socket to a socket name
self.sun_family = AF_UNIX; // The AF_UNIX (also called the AF_LOCAL) is a
//socket family used to communicate between processes on the same machine
strcpy(self.sun_path, NAME_REC); //copy the NAME to the socket pathname of self
/* The socket() function create an unbound socket in a communications
domain, and return a file descriptor that can be used in later function calls that
operate on sockets.
The socket() function takes the following arguments:
domain - Specifies the communications domain in which a socket is to be
created.
type - Specifies the type of socket to be created.
SOCK_STREAM
Provides sequenced, reliable, bidirectional, connection-mode byte
streams, and may provide a transmission mechanism for out-of-band data.
SOCK_DGRAM
Provides datagrams, which are connectionless-mode, unreliable
messages of fixed maximum length.
SOCK_SEQPACKET
Provides sequenced, reliable, bidirectional, connection-mode
transmission paths for records. A record can be sent using one or more output
operations and received using one or more input operations, but a single operation
never transfers part of more than one record. Record boundaries are visible to the
receiver via the MSG_EOR flag.
protocol - Specifies a particular protocol to be used with the socket.
Specifying a protocol of 0 causes socket() to use an unspecified default protocol
appropriate for the requested socket type.
RETURN VALUE
Upon successful completion, socket() shall return a non-negative integer, the
socket file descriptor. Otherwise, a value of -1 shall be returned and errno set to
indicate the error.
*/
soc_rec = socket(AF_UNIX, SOCK_DGRAM, 0); /* SOCK_DGRAM is used for
datagram oriented sockets */
//functions such as bind, connect, and sendto take a sockaddr_un argument as
//input
//bind(..) binds a UNIX socket to a pathname - the casting of the address of
//self is done to eliminate a warning
/* The bind() function assigns a local socket address to a socket identified
by descriptor socket that has no local socket address assigned. Sockets created
with the socket() function are initially unnamed; they are identified only by their
address family.
The bind() function takes the following arguments:
socket - Specifies the file descriptor of the socket to be bound.
address - Points to a sockaddr structure containing the address to be
bound to the socket. The length and format of the address depend on the address
family of the socket.
address_len - Specifies the length of the sockaddr structure pointed to
by the address argument.
The socket specified by socket may require the process to have
appropriate privileges to use the bind() function.
RETURN VALUE
Upon successful completion, bind() shall return 0; otherwise, -1 shall
be returned and errno set to indicate the error.
*/
n_rec = bind(soc_rec, (const struct sockaddr *) &self, sizeof(self)); /* (C)
*/
//check if the binding failed
if ( n_rec < 0 )
{ fprintf(stderr, "bind failed\n");
exit(1);
}
/*recvfrom receive a message from a socket. The recvfrom() function
takes the following arguments:
socket - Specifies the socket file descriptor.
buffer - Points to the buffer where the message should be stored.
length - Specifies the length in bytes of the buffer pointed to by the
buffer argument.
flags - Specifies the type of message reception - 0 in our case
address - A null pointer, or points to a sockaddr structure in which
the sending address is to be stored. The length and format of the address depend on
the address family of the socket.
address_len - Specifies the length of the sockaddr structure pointed to
by the address argument.
RETURN VALUE
IT returns the length of the message that is written in the
buffer.
*/
n_rec = recvfrom(soc_rec, buf_rec, sizeof(buf_rec), 0, (struct sockaddr *)&peer_send, &len);
/* receive the datagram sent from your peer - the casting of address of peer is
done to eliminate a warning */
//check if the receiving failed
if ( n_rec < 0 )
{ fprintf(stderr, "recvfrom failed\n");
//close the socket and disconnect it
cleanup(soc_rec, self.sun_path);
exit(1);
}
buf_rec[n_rec] = '\0'; /* attach the \0 at the end of
the stream of characters since buf is a C-string */
printf("Datagram received = %s\n", buf_rec); /* print buf which now
contains the datagram*/
  
  return(0);
}
