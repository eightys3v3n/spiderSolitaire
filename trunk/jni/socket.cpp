#ifdef VERBOSE
#include <iostream>
#endif // VERBOSE

#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include <stdio.h>
#include <string.h> // bzero()
#include <netdb.h> // gethostbyname(), bcopy((char *)server->h_addr...
#include <fcntl.h>

#ifdef ANDROID
#include <SFML/System.hpp>
#include "android.hpp"
#endif // ANDROID

struct Socket
{
  int fd = 0;

  int open(std::string address, unsigned int port);
  int send(std::string m);
  std::string read();
  void close();
};

int Socket::open(std::string address, unsigned int port)
{
  struct sockaddr_in addr;
  struct hostent *server;

  fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd < 0)
  {
    #ifdef VERBOSE
    std::cerr << "failed to create a socket" << std::endl;
    #endif // VERBOSE

    #ifdef ANDROID
    switch(fd)
    {
      case EACCES: // no permission to use sockets 'android.permission.INTERNET'
        vibrate(sf::milliseconds(500));
        break;
      default:
        vibrate(sf::milliseconds(3000));
        break;
    }
    #endif // ANDROID

    return 1;
  }

  server = gethostbyname(address.c_str());
  if (server == 0)
  {
    #ifdef VERBOSE
    std::cerr << "host not found '" + address + "'" << std::endl;
    #endif // VERBOSE
    return 2;
  }

  bzero((char*)&addr, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  bcopy((char *)server->h_addr, (char *)&addr.sin_addr.s_addr, server->h_length);

  if (connect(fd, (struct sockaddr*)&addr, sizeof(addr)) < 0)
  {
    #ifdef VERBOSE
    std::cerr << "coundn't connect to '" + address + ":" << port << "'" << std::endl;
    #endif // VERBOSE
    return 3;
  }

  fcntl(fd, F_SETFL, O_NONBLOCK);

  return 0;
}

int Socket::send(std::string m)
{
  int r = 0;

  r = ::write(fd, m.c_str(), m.length());
  if (r < 0)
    return r;

  return 0;
}

std::string Socket::read()
{
  char buf[4097];
  std::string r = "";
  int e = 0;

  // keeps reading until the bytes read do not create a string of length 4096; ie there was nothing left to read.
  while (true)
  {
    bzero(buf, 4097);
    e = ::read(fd, &buf, 4096);

    r += std::string(buf);

    if (e)
    {
      #ifdef VERBOSE
      std::cerr << "read returned:" << e << std::endl;
      #endif // VERBOSE
      return r;
    }

    if (std::string(buf).length() < 4096)
      break;
  }

  return r;
}

void Socket::close()
{
  ::close(fd);
}