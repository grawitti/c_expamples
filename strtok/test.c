#include <string.h>
#include <stdio.h>

int main() {
    char source[] = "acb::def::./some/happy/final";
    char *_temp = strtok(source, "::");
    while (_temp != NULL)
    {
        printf("%s\n", _temp);
        _temp = strtok(NULL, "::");
    }

    return 0;
}