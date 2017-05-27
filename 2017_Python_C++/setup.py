from distutils.core import setup, Extension
import numpy.distutils.misc_util
import os

os.environ["CC"] = "g++"
os.environ["CXX"] = "g++"

module1 = Extension('CALC', sources = ['CALCmodule.cpp', 'CALC.cpp'])

setup (name = 'CALC',
       version = '1.0',
       description = 'Package for calculating number pairs',
       ext_modules = [module1],
	   include_dirs=numpy.distutils.misc_util.get_numpy_include_dirs())
