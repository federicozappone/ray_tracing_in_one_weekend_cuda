cuda = import('unstable-cuda')

nvcc_flags = [
              '-m64',
              '-ccbin',
              'g++',
              '-gencode',
              'arch=compute_75,code=sm_75',
              ]

executable('main', 'main.cu', cuda_args : nvcc_flags)
