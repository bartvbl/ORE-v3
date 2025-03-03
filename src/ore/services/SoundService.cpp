
#include <c++/11/iostream>
#include "SoundService.h"
#include "miniaudio.h"



namespace ore {
    uint32_t read_and_mix_pcm_frames_f32(ma_decoder* pDecoder, float* pOutputF32, ma_uint32 frameCount, ore::SoundService* soundService)
    {
        /*
        The way mixing works is that we just read into a temporary buffer, then take the contents of that buffer and mix it with the
        contents of the output buffer by simply adding the samples together. You could also clip the samples to -1..+1, but I'm not
        doing that in this example.
        */
        ma_result result;
        const int bufferLength = 4096;
        float temp[bufferLength];
        uint32_t tempCapInFrames = bufferLength / ore::SoundService::channelCount;
        uint32_t totalFramesRead = 0;

        while (totalFramesRead < frameCount) {
            uint64_t iSample;
            ma_uint64 framesReadThisIteration;
            uint32_t totalFramesRemaining = frameCount - totalFramesRead;
            uint32_t framesToReadThisIteration = tempCapInFrames;
            if (framesToReadThisIteration > totalFramesRemaining) {
                framesToReadThisIteration = totalFramesRemaining;
            }

            result = ma_decoder_read_pcm_frames(pDecoder, temp, framesToReadThisIteration, &framesReadThisIteration);
            if (result != MA_SUCCESS || framesReadThisIteration == 0) {
                throw std::runtime_error("Playback failed");
            }

            /* Mix the frames together. */
            for (iSample = 0; iSample < framesReadThisIteration*ore::SoundService::channelCount; ++iSample) {
                pOutputF32[totalFramesRead*ore::SoundService::channelCount + iSample] += temp[iSample];
            }

            totalFramesRead += (ma_uint32)framesReadThisIteration;

            if (framesReadThisIteration < (ma_uint32)framesToReadThisIteration) {
                break;  /* Reached EOF. */
            }
        }

        return totalFramesRead;
    }

    void data_callback(ma_device *pDevice, void *pOutput, const void *pInput, ma_uint32 frameCount) {
        float *pOutputF32 = (float *) pOutput;
        ore::SoundService *soundService = reinterpret_cast<ore::SoundService *>(pDevice->pUserData);

        /* This example assumes the device was configured to use ma_format_f32. */
        for (uint32_t iDecoder = 0; iDecoder < soundService->playingSounds.size(); ++iDecoder) {
            ma_uint32 framesRead = read_and_mix_pcm_frames_f32(&soundService->playingSounds.at(iDecoder)->decoder, pOutputF32, frameCount, soundService);
            if (framesRead < frameCount) {
                // Remove playing sounds from list
                soundService->playingSounds.erase(soundService->playingSounds.begin() + iDecoder);
                iDecoder--;
            }
        }
    }
}

void ore::SoundService::init() {
    if (ma_context_init(NULL, 0, NULL, &context) != MA_SUCCESS) {
        throw std::runtime_error("Failed to create audio context!");
    }

    ma_device_info* pPlaybackInfos;
    ma_uint32 playbackCount;
    ma_device_info* pCaptureInfos;
    ma_uint32 captureCount;
    if (ma_context_get_devices(&context, &pPlaybackInfos, &playbackCount, &pCaptureInfos, &captureCount) != MA_SUCCESS) {
        throw std::runtime_error("Failed to list audio devices!");
    }

// Loop over each device info and do something with it. Here we just print the name with their index. You may want
// to give the user the opportunity to choose which device they'd prefer.
    for (ma_uint32 iDevice = 0; iDevice < playbackCount; iDevice += 1) {
        std::cout << "Found device: " << iDevice << " -> " << pPlaybackInfos[iDevice].name << std::endl;
    }


    ma_device_config config = ma_device_config_init(ma_device_type_playback);
    const int playbackDeviceID = 0;
    config.playback.pDeviceID = &pPlaybackInfos[playbackDeviceID].id;
    config.playback.format   = ma_format_f32;   // Set to ma_format_unknown to use the device's native format.
    config.playback.channels = 2;               // Set to 0 to use the device's native channel count.
    config.sampleRate        = 48000;           // Set to 0 to use the device's native sample rate.
    config.dataCallback      = data_callback;   // This function will be called when miniaudio needs more data.
    config.pUserData         = this;

    if (ma_device_init(NULL, &config, &device) != MA_SUCCESS) {
        throw std::runtime_error("Failed to create audio device!");
    }

    ma_device_start(&device);     // The device is sleeping by default so you'll need to start it manually.
}

void ore::SoundService::playSound(ore::resources::SoundResource *sound) {
    if(sound == nullptr) {
        throw std::runtime_error("Invalid sound!");
    }

    playingSounds.push_back(sound);
}

void ore::SoundService::shutdown() {
    ma_device_uninit(&device);
    ma_context_uninit(&context);
}
