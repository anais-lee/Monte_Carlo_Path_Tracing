#pragma once
#include <scene/materials/bxdfs/bxdf.h>

class LambertBxDF : public BxDF
{
public:
//Constructors/Destructors
    LambertBxDF(const glm::vec3 &color) : BxDF(BxDFType(BSDF_REFLECTION | BSDF_DIFFUSE)), diffuse_color(color)
    {}
//Functions
    virtual glm::vec3 EvaluateScatteredEnergy(const glm::vec3 &wo, const glm::vec3 &wi) const;
//    virtual glm::vec3 EvaluateHemisphereScatteredEnergy(const glm::vec3 &wo, int num_samples, const glm::vec2 *samples) const;
    virtual glm::vec3 SampleAndEvaluateScatteredEnergy( const glm::vec3 &wo, glm::vec3 &wi_ret, float rand1, float rand2, float &pdf_ret, BxDFType flags) const;
    virtual float PDF(const glm::vec3 &wo, const glm::vec3 &wi) const;

    //Member variables
    glm::vec3 diffuse_color;
};
