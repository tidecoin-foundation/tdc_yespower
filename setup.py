from setuptools import setup, Extension

tdc_yespower_module = Extension('tdc_yespower',
                            sources = ['yespower-module.c',
                                       'yespower.c',
                                       'yespower-opt.c',
                                       'sha256.c'
                                       ],
                            extra_compile_args=['-O2', '-funroll-loops', '-fomit-frame-pointer'],
                            include_dirs=['.'])

setup (name = 'tdc_yespower',
       version = '1.0.0',
       author_email = 'tidecoins@protonmail.com',
       author = 'yarsawyer',
       url = 'https://github.com/yarsawyer/tdc_yespower',
       description = 'Bindings for yespower-1.0 proof of work used by tidecoin',
       ext_modules = [tdc_yespower_module])
