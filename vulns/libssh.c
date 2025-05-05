
#include <stdio.h>
#include <string.h>

// Simulated SSH message types
#define SSH2_MSG_USERAUTH_SUCCESS 52
#define SSH2_MSG_USERAUTH_REQUEST 50

typedef struct {
    int authenticated;
} ssh_session;

typedef struct {
    int type;
} ssh_message;

int process_authentication(ssh_session *session, ssh_message msg) {
    if (msg.type == SSH2_MSG_USERAUTH_SUCCESS) {
        // VULNERABILITY: Accepting a server-only message from the client
        session->authenticated = 1;
        return 0;
    }
    return 1;
}

int main() {
    ssh_session session = {0};
    ssh_message msg = {SSH2_MSG_USERAUTH_SUCCESS}; // Attacker-supplied message

    process_authentication(&session, msg);

    if (session.authenticated) {
        printf("Access Granted (Bypassed Auth)\n");
    } else {
        printf("Access Denied\n");
    }
    return 0;
}
