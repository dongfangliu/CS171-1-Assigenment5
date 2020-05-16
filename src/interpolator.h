#pragma once
#include "volumeData.h"
#include "Eigen/Dense"
//ref https://en.wikipedia.org/wiki/Trilinear_interpolation
class Interpolator
{
public:
    virtual volumeData interpolate(Eigen::Vector3f &p, const voxel &voxel) = 0;
};
class NearestNeighbourInterpolator : public Interpolator
{
    inline volumeData interpolate(Eigen::Vector3f &p, const voxel &voxel)
    {
        //Here your NNInterpolator code
    };
};
class TrilinearInterpolator : public Interpolator
{

    inline volumeData interpolate(Eigen::Vector3f &p, const voxel &voxel)
    {
        
        //Here your TrilinearInterpolator code
    };

};