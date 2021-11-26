#include "utility.h"
#include "datatypes.h"
#include <malloc.h>
#include <wchar.h>

#define BUFSIZE 10

wchar_t buf[BUFSIZE];
int bufp = 0;

wchar_t getch() {
    return bufp > 0 ? buf[--bufp] : (wchar_t) getwchar();
}

int ungetch(wchar_t c) {
    if (bufp >= BUFSIZE)
        return 0;
    buf[bufp++] = (wchar_t) c;
    return 1;
}

void freeText(void *ptr) {
    struct Text *text = (struct Text *) ptr;
    for (int i = 0; i < text->length; i++)
        freeSentence(text->sentences[i]);
    free(text->sentences);
    free(text);
}

void freeSentence(void *ptr) {
    struct Sentence *sentence = (struct Sentence *) ptr;
    free(sentence->value);
    free(sentence);
}
