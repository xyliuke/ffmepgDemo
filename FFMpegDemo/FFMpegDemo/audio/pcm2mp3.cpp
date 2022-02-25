//
//  pcm2mp3.cpp
//  FFMpegDemo
//
//  Created by liuke on 2022/2/24.
//

#include "pcm2mp3.hpp"
#include <string>
#include <fstream>
extern "C" {
#include <lame/lame.h>
}


class pcm2mp3::pcm2mp3_impl {
public:
    pcm2mp3_impl(std::string pcm_file, std::string mp3_file, int sample_rate, int channels, int bit_rate) {
        //初始化lame库
        lame = lame_init();
        lame_set_in_samplerate(lame, sample_rate);
        lame_set_out_samplerate(lame, sample_rate);
        lame_set_num_channels(lame, channels);
        lame_set_brate(lame, bit_rate / 1000);
        lame_init_params(lame);
        
        this->pcm_file = pcm_file;
        this->mp3_file = mp3_file;
        this->sample_rate = sample_rate;
    }
    //pcm文件转码成mp3文件
    bool encode() {
        std::ifstream ifs = std::ifstream(pcm_file, std::ios::in | std::ios::binary);//输入的pcm文件流
        std::ofstream ofs = std::ofstream(mp3_file, std::ios::out | std::ios::binary | std::ios::trunc);//输出的mp3文件流
        if (ifs.is_open() && ofs.is_open()) {
            const int buffer_size = 1024 * 256;
            char *buffer = new char[buffer_size];
            unsigned char *out_buffer = new unsigned char[buffer_size];
            //循环读取文件内容到内存
            while(ifs.read(buffer, buffer_size)) {
                //读取字节个数
                std::streamsize read = ifs.gcount();
                //分别将数据读取到左右声道
                char *left_buffer = new char[read / 2];
                char *right_buffer = new char[read / 2];
                for (int i = 0; i < read; ++ i) {
                    if (i % 2 == 0) {
                        left_buffer[i / 2] = buffer[i];
                    } else {
                        right_buffer[i / 2] = buffer[i];
                    }
                }
                //将左右声道的数据编码到out_buffer中
                int write_size = lame_encode_buffer(lame, (short int*)left_buffer, (short int*)right_buffer, (int)(read / 2), out_buffer, buffer_size);
                //写入文件
                ofs.write((char *)out_buffer, write_size);
                delete [] left_buffer;
                delete [] right_buffer;
            }
            delete [] buffer;
            delete [] out_buffer;
            return true;
        }
        ifs.close();
        ofs.close();
        return false;
    }
    
    bool decode() {
        return true;
    }
    
    ~pcm2mp3_impl() {
        lame_close(lame);
    }
    
private:
    lame_global_flags *lame;
    std::string pcm_file;
    std::string mp3_file;
    int sample_rate;
};


pcm2mp3::pcm2mp3(std::string pcm_file, std::string mp3_file, int sample_rate, int channels, int bit_rate):
                    impl(new pcm2mp3_impl(pcm_file, mp3_file, sample_rate, channels, bit_rate)) {
    
}

bool pcm2mp3::encode() {
    return impl->encode();
}

bool pcm2mp3::decode() {
    return impl->decode();
}

pcm2mp3::~pcm2mp3() {
    
}
