project('ore', 'c', 'cpp',
        version : '0.1',
        default_options : ['warning_level=2',
                           'cpp_std=c++20',
                           'c_std=c17'])

if host_machine.system() == 'linux'
    compiler_flags = ['-Wconversion', '-fdiagnostics-color=always', '-Werror=return-type',  '-Wall', '-Wextra', '-Wpedantic',
                      '-DspinImageWidthPixels=64', '-DGLFW_INCLUDE_NONE']
else
    compiler_flags = ['-Wconversion', '-fdiagnostics-color=always', '-Werror=return-type', '-fcolor-diagnostics', '-fansi-escape-codes']
endif

omp = dependency('openmp')
glfw3 = dependency('glfw')
freetype = dependency('freetype2')

fmt = dependency('fmt')
glm = dependency('glm')
json = dependency('nlohmann_json')
#miniaudio = dependency('miniaudio')

cmake = import('cmake')

miniaudio_project = cmake.subproject('miniaudio')
miniaudio = miniaudio_project.dependency('miniaudio')

jolt_project = cmake.subproject('joltphysics')
jolt = jolt_project.dependency('Jolt')

include_dirs = include_directories('lib/stb_image', 'lib/fast_obj', 'lib/nuklear', 'src')


src = [
    'lib/fast_obj/fast_obj.c'
]

ore = library(
    'presentation',
    src,
    dependencies : [freetype, omp, glfw3, fmt, glm, json, jolt, miniaudio],
    include_directories: [include_dirs],
    cpp_args : compiler_flags
)