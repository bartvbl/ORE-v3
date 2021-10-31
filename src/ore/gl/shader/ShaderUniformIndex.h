#pragma once

namespace ore {
    namespace gl {
        struct ShaderUniformIndex {
            static const unsigned int diffuseTextureID = 3;
            static const unsigned int texturesEnabled = 5;

            static const unsigned int cameraPosition = 12;

            static const unsigned int lightPosition = 14;
            static const unsigned int lightColourAmbient = 15;
            static const unsigned int lightColourDiffuse = 16;
            static const unsigned int lightColourSpecular = 17;
            static const unsigned int lightSpecularStrength = 18;

            static const unsigned int lightAttenuationConstant = 24;
            static const unsigned int lightAttenuationLinear = 25;
            static const unsigned int lightAttenuationQuadratic = 26;

            static const unsigned int materialColourAmbient = 19;
            static const unsigned int materialColourDiffuse = 20;
            static const unsigned int materialColourSpecular = 21;
            static const unsigned int materialColourEmission = 22;
            static const unsigned int materialShininess = 23;
        };
    }
}