#include <stdio.h>

#include "test.h"

int
main (int argc, char *argv[]) {
    int rc;

    rc = runtest_host("-n",
        "http://break.com/index/beach-tackle-whip-lash.html");

    return(rc);
}
