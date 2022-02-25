//
//  pcm2mp3.hpp
//  FFMpegDemo
//
//  Created by liuke on 2022/2/24.
//

#ifndef pcm2mp3_hpp
#define pcm2mp3_hpp

#include <stdio.h>
#include <memory>

class pcm2mp3 {
public:
    pcm2mp3(std::string pcm_file, std::string mp3_file, int sample_rate, int channels, int bit_rate);
    bool encode();
    bool decode();
    ~pcm2mp3();
private:
    class pcm2mp3_impl;
    std::shared_ptr<pcm2mp3_impl> impl;
};

#endif /* pcm2mp3_hpp */
