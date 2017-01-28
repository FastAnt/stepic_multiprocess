#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message {
    long mtype;
    char mtext[80];
};

int main() {
  const std::string file_name{"/home/box/message.txt"};
  std::ofstream ofs{file_name};
  key_t key = ftok("/tmp/msg.temp", 1);
  int msgid = msgget(key, IPC_CREAT | 0666);
  message *msg = new message;
  int msg_len = msgrcv(msgid, msg, 80, 1, 0);

  ofs << msg->mtext;
  delete msg;

  return 0;
}
