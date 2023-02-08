cuda = import('unstable-cuda')

# nvcc = meson.get_compiler('cuda')
# nvcc_flags = cuda.nvcc_arch_flags(nvcc, 'Turing')

nvcc_flags = [
              '-m64',
              '-ccbin',
              'g++',
              '-gencode',
              'arch=compute_75,code=sm_75',
              ]

includes = include_directories('.')

executable('main', 'main.cu', cuda_args : nvcc_flags)
