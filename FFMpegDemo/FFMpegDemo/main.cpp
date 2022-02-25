//
//  main.c
//  FFMpegDemo
//
//  Created by 刘科 on 2021/12/21.
//

#include <stdio.h>
#include "yuv_util.hpp"
#include "pcm2mp3.hpp"
#include <string>
extern "C" {
#include <libavcodec/avcodec.h>
}

void print_config();
void test_yuv();
void test_pcm2mp3();

int main(int argc, const char * argv[]) {
    // insert code here...

//    print_config();
//    test_yuv();
    test_pcm2mp3();
    return 0;
}

void print_config() {
    const char *config = avcodec_configuration();
    printf("%s\n", config);
}

void test_yuv() {
    std::string path = "/Users/liuke/workspace/project/github/ffmepgDemo/01.yuv";
    yuv_util *yuv = new yuv_util(path, 3500, 2000);
    std::string y_path = "/Users/liuke/workspace/project/github/ffmepgDemo/001.y";
    yuv->get_y(y_path);
    std::string u_path = "/Users/liuke/workspace/project/github/ffmepgDemo/001.u";
    yuv->get_u(u_path);
    std::string v_path = "/Users/liuke/workspace/project/github/ffmepgDemo/001.v";
    yuv->get_v(v_path);
}

void test_pcm2mp3() {
    pcm2mp3 p("/Users/liuke/1.pcm", "/Users/liuke/dump.mp3", 16000, 2, 512000);
    p.encode();
}
