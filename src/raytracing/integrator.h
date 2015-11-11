#pragma once
#include <la.h>
#include <raytracing/ray.h>
#include <raytracing/intersection.h>
#include <raytracing/intersectionengine.h>
#include <scene/scene.h>

class Scene;

//The Integrator class recursively evaluates the path a ray takes throughout a scene
//and computes the color a ray becomes as it bounces.
//It samples the materials, probability density functions, and BRDFs of the surfaces the ray hits
//to do this.

class Integrator
{
public:
    Integrator();
    Integrator(Scene *s);
    glm::vec3 TraceRay(Ray r, unsigned int depth);
    void SetDepth(unsigned int depth);

    //Samples taken must be set in the function. It tells the how many ray samples were used to estimate the direct
    glm::vec3 EstimateDirectLighting(const Intersection &isx, unsigned int &samples_taken);
    glm::vec3 EstimateIndirectLighting(const Intersection &isx, unsigned int &samples_taken);

    Scene* scene;
    IntersectionEngine* intersection_engine;

protected:
    unsigned int max_depth;//Default value is 5.
};
