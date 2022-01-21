//
//  yuv_util.hpp
//  FFMpegDemo
//
//  Created by liuke on 2022/1/20.
//

#ifndef yuv_util_hpp
#define yuv_util_hpp

#include <stdio.h>
#include <memory>

class yuv_util {
public:
    yuv_util(std::string &yuv_path, int width, int height);
    void get_y(std::string &y_file);
    void get_u(std::string &u_file);
    void get_v(std::string &v_file);
private:
    class yuv_util_impl;
    std::shared_ptr<yuv_util_impl> impl;
};

#endif /* yuv_util_hpp */
