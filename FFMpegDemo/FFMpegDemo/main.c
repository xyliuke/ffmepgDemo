//
//  main.c
//  FFMpegDemo
//
//  Created by 刘科 on 2021/12/21.
//

#include <stdio.h>
#include <libavcodec/avcodec.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    const char *config = avcodec_configuration();
    printf("%s\n", config);
    return 0;
}
