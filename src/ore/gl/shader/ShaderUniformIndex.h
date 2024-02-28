#pragma once

namespace ore {
    namespace gl {
        struct ShaderInputIndex {
            static const unsigned int vertices = 0;
            static const unsigned int normals = 1;
            static const unsigned int texCoords = 2;
            static const unsigned int normalMapTangent = 4;
            static const unsigned int normalMapBitangent = 5;
        };

        struct ShaderUniformIndex {
            // Texture bindings
            static const unsigned int diffuseTextureID = 0;
            static const unsigned int normalMapTextureID = 1;
            static const unsigned int shadowDepthMapTextureID0 = 5;
            static const unsigned int shadowDepthMapTextureID1 = 6;
            static const unsigned int shadowDepthMapTextureID2 = 7;
            static const unsigned int shadowDepthMapTextureID3 = 8;

            // Uniforms

            static const unsigned int diffuseTextureEnabled = 1;
            static const unsigned int lightingEnabled = 2;
            static const unsigned int shadowsEnabled = 3;
            static const unsigned int normalMappingEnabled = 4;

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

            static const unsigned int modelViewProjectionMatrix = 30;
            static const unsigned int modelViewMatrix = 31;
            static const unsigned int normalMatrix = 32;
            static const unsigned int shadowMapMVP = 33;

            // Arrays require one uniform per index. Thus, the next ID must be past the max number of lights
            static const unsigned int lightPositionArrayCount = 49;
            static const unsigned int lightPositionArrayID = 50; // + 16
            static const unsigned int lightAttenuationArray = 66; // + 16

            static const unsigned int shadowLightCount = 90;
            static const unsigned int shadowLightPositionArray = 91; // + 4
            static const unsigned int shadowLightAttenuationArray = 95; // + 4
        };
    }
}