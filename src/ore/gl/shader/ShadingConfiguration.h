#pragma once

namespace ore {
    namespace gl {
        struct ShadingConfiguration {
            bool enableTexturing = true;
            bool enableShadows = true;
            bool enableLighting = true;

            bool isShadowDepthPass = false;
        };
    };
};
