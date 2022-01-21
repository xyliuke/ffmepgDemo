//
//  yuv_util.cpp
//  FFMpegDemo
//
//  Created by liuke on 2022/1/20.
//

#include <fstream>
#include <iostream>
#include "yuv_util.hpp"

class yuv_util::yuv_util_impl {
public:
    yuv_util_impl(std::string &yuv_path, int width, int height) {
        this->yuv_file = yuv_path;
        this->width = width;
        this->height = height;
    }
    void get_y(std::string &y_file) {
        const char *buf = get_yuv_content();
        write(y_file, buf, 0, width * height);
        delete[](buf);
    }
    void get_u(std::string &u_file) {
        const char *buf = get_yuv_content();
        write(u_file, buf, width * height, width * height / 4);
        delete[](buf);
    }
    void get_v(std::string &v_file) {
        const char *buf = get_yuv_content();
        write(v_file, buf, int(width * height * 1.25), width * height / 4);
        delete[](buf);
    }

private:
    std::string yuv_file;
    int width;
    int height;

    char* get_yuv_content() {
        std::ifstream ifstream = std::ifstream(this->yuv_file, std::ios::binary | std::ios::in | std::ios::ate);
        if (ifstream.is_open()) {
            std::streampos size = ifstream.tellg();
            ifstream.seekg(0, std::ios::beg);
            char *buf = new char[size]();
            ifstream.read(buf, size);
            ifstream.close();
            return buf;
        }
        return nullptr;
    }

    bool write(std::string &file, const char* buf, int begin, int len) {
        std::ofstream y_ofsteam = std::ofstream(file, std::ios::out | std::ios::app | std::ios::binary);
        if (y_ofsteam.is_open()) {
            y_ofsteam.write(buf + begin, len);
            y_ofsteam.close();
            return true;
        }
        return false;
    }
};

yuv_util::yuv_util(std::string &yuv_path, int width, int height): impl(new yuv_util_impl(yuv_path, width, height)) {

}

void yuv_util::get_y(std::string &y_file) {
    impl->get_y(y_file);
}

void yuv_util::get_u(std::string &u_file) {
    impl->get_u(u_file);
}

void yuv_util::get_v(std::string &v_file) {
    impl->get_v(v_file);
}