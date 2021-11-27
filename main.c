#include <locale.h>
#include "datatypes.h"
#include "iodata.h"
#include "utility.h"
#include "handler.h"

int main() {
    setlocale(LC_CTYPE, "");

    struct Text text = txtscan();
    if (text.length == 0)
        return 0;

    filtertxt(&text);

    txtprint(text);

    txtfree(text);

    return 0;
}
