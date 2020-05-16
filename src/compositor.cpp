#include "compositor.h"

Compositor::Compositor(){};
Compositor::~Compositor(){};
void Compositor::compositeFrontToBack(Eigen::Vector3f& color_dst,Eigen::Vector3f& alpha_dst,Eigen::Vector3f color_src,Eigen::Vector3f alpha_src){
//Here your front to back code

};
void Compositor::compositeBackToFront(Eigen::Vector3f& color_dst,Eigen::Vector3f color_src,Eigen::Vector3f alpha_src){
    //Here your back to front code
};

