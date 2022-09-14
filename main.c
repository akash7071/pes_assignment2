#include <stdio.h>

#include <stdlib.h>
//#include "llfifo.c"
#include "llfifo.h"
//#include "test_llfifo.c"
#include "test_llfifo.h"
#include "cbfifo.h"
#include "test_llfifo.h"
//#include "test_llfifo.c"
//#include "cbfifo.c"

int main(void)
{
    test_llfifo();
    test_cbfifo();

    return 0;
}