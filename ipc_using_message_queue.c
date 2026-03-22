#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer {
    long msg_type;
    char text[100];
};

int main() {
    struct msg_buffer msg;
    int msgid;

    // Create message queue
    msgid = msgget((key_t)1234, 0666 | IPC_CREAT);

    // Input string
    printf("Enter a string: ");
    scanf("%s", msg.text);

    msg.msg_type = 1;

    // Send message
    msgsnd(msgid, &msg, sizeof(msg.text), 0);

    // Receive message
    msgrcv(msgid, &msg, sizeof(msg.text), 1, 0);

    // Palindrome check
    char temp[100];
    strcpy(temp, msg.text);
    strrev(temp);   // Reverse string

    if (strcmp(msg.text, temp) == 0)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}