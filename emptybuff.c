#include "emptybuff.h"
#include <stdio.h>
void emptybuff(){
    
    char buffer;
    while ((buffer = getchar()) != EOF && buffer != '\n');
    return;
}
