#include "define.h"

char *MyOwnQStringToChar(QString str){
    char    *ch1 = new char(100);
    unsigned int     i;
    std::string ch = str.toStdString();

    for(i = 0; i <= ch.length(); i++){
        ch1[i] = ch[i];
    }
    ch1[i] = '\0';
    return ch1;
    free(ch1);
}

