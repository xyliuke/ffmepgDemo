//
//  main.c
//  FFMpegDemo
//
//  Created by 刘科 on 2021/12/21.
//

#include <stdio.h>
#include "yuv_util.hpp"
#include <string>
extern "C" {
#include <libavcodec/avcodec.h>
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    const char *config = avcodec_configuration();
    printf("%s\n", config);

    std::string path = "/Users/liuke/workspace/project/github/ffmepgDemo/01.yuv";
    yuv_util *yuv = new yuv_util(path);
    std::string y_path = "/Users/liuke/workspace/project/github/ffmepgDemo/01.y";
    yuv->get_y(y_path);
    return 0;
}
