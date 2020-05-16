#pragma once
#include "volume.h"
#include "camera.hpp"
#include <iostream>
//https://github.com/yuki-koyama/tinycolormap
#include "tinycolormap.hpp"

class Classifier{
    public:
    virtual opticsData transfer(volumeData v_data,float dt,Camera* cam ,std::vector<Light *> lights,float grad_max_norm=1)=0;
};

class myClassifier:public Classifier{
    public:
    opticsData transfer(volumeData v_data,float dt,Camera* cam,std::vector<Light *> lights,float grad_max_norm=1){
        opticsData optics;
		//Write your own classifier, make use of input args(may not all)
		// should set transparency and color of optics
        return optics;
    }
};