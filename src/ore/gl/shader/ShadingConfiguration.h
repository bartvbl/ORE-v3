#pragma once

namespace ore {
    namespace gl {
        struct ShadingConfiguration {
            bool enableTexturing = true;
            bool enableShadows = true;
            bool enableLighting = true;
            bool enableNormalMapping = true;

            bool isShadowDepthPass = false;
        };
    };
};
