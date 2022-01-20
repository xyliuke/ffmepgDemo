//
//  yuv_util.cpp
//  FFMpegDemo
//
//  Created by liuke on 2022/1/20.
//

#include <fstream>
#include "yuv_util.hpp"

class yuv_util::yuv_util_impl {
public:
    yuv_util_impl(std::string &yuv_path) {
        ifstream = std::ifstream(yuv_path, std::ios::binary | std::ios::in);
    }
    void get_y(std::string &y_file) {
        if (ifstream.is_open()) {
            std::streampos size = ifstream.tellg();
            ifstream.seekg(0, std::ios::beg);
            char buf[(int)size];
            ifstream.read(buf, size);
            ifstream.close();
        }
    }
    void get_u(std::string &u_file) {

    }
    void get_v(std::string &v_file) {

    }

private:
    std::ifstream ifstream;
};

yuv_util::yuv_util(std::string &yuv_path): impl(new yuv_util_impl(yuv_path)) {

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