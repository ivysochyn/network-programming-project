#include "callback.hpp"
#include <stdio.h>
#include <sys/socket.h>

std::vector<user_info> users;

int Callback::connectionCallback(uint16_t fd)
{
    user_info tempuser;
    if (recv(fd, tempuser.username, USERNAME_LEN, 0) <= 0)
        return -1;
    tempuser.fd = fd;
    tempuser.score = 0;
    users.push_back(tempuser);
    return 0;
}
