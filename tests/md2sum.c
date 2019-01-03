#include <stdio.h>
#include "../md2.h"

int
main(void)
{
    int i;
    struct md2 md2[1];
    static char buf[1024 * 1024];
    static char hexdigest[MD2_BLOCK_SIZE * 2 + 1];
    static unsigned char digest[MD2_BLOCK_SIZE];

    md2_init(md2);
    for (;;) {
        size_t len = fread(buf, 1, sizeof(buf), stdin);
        md2_append(md2, buf, len);
        if (len < sizeof(buf))
            break;
    }

    md2_finish(md2, digest);
    for (i = 0; i < MD2_BLOCK_SIZE; i++) {
        static const char hex[16] = "0123456789abcdef";
        hexdigest[i * 2 + 0] = hex[digest[i] >> 4];
        hexdigest[i * 2 + 1] = hex[digest[i] & 0xf];
    }
    hexdigest[MD2_BLOCK_SIZE * 2] = '\n';
    fwrite(hexdigest, sizeof(hexdigest), 1, stdout);
    return fflush(stdout) == 0;
}
