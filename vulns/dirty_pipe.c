
#include <stdio.h>
#include <string.h>

#define PIPE_BUF_FLAG_CAN_MERGE 0x01

typedef struct {
    int flags;
    char page_cache[16];
} pipe_buffer;

void write_to_pipe(pipe_buffer *buf, const char *input) {
    if (buf->flags & PIPE_BUF_FLAG_CAN_MERGE) {
        // VULNERABILITY: writing into page cache of read-only file
        memcpy(buf->page_cache, input, strlen(input)); // Potential overflow
    }
}

int main() {
    pipe_buffer buf = {PIPE_BUF_FLAG_CAN_MERGE, {0}};
    char attacker_input[32] = "Injected malicious content";

    write_to_pipe(&buf, attacker_input);
    printf("Pipe data: %s\n", buf.page_cache);
    return 0;
}
