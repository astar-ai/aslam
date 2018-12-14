#include <unistd.h>
#include <iostream>
#include <thread>
#include <netdb.h>
#include <strings.h>

using namespace std;

int main(int argc, char** argv) {
  while (1) {
    int sockfd, new_sockfd;
    socklen_t cli_len;
    sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
      cout << "ERROR opening socket" << endl;

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8001);

    if (bind(sockfd, (sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
      cout << "ERROR on binding" << endl;

    listen(sockfd, 5);

    cli_len = sizeof(cli_addr);
    new_sockfd = accept(sockfd, (sockaddr *) &cli_addr, &cli_len);
    if (new_sockfd < 0)
      cout << "ERROR on accept" << endl;

    cout << "Connected" << endl;

    struct SlamData {
      int   status;
      float inl;
      float x, y, z;
      float qx, qy, qz, qw;
    };

    SlamData data;

    while (1) {
      int n = read(new_sockfd, &data, sizeof(SlamData));

      if (n < 0)
        cout << "ERROR reading from socket" << endl;

      if (n == 0)
        continue;

      cout << data.status << " " << data.inl << " "
           << data.x  << " " << data.y  << " " << data.z  << " "
           << data.qx << " " << data.qy << " " << data.qz << " " << data.qw
           << endl;

      usleep(100);
    }

    close(new_sockfd);
    close(sockfd);
  }

  cout << "Why is here? " << endl;

  return 0;
}

