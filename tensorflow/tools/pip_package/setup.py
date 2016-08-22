# Copyright 2015 Microsoft Inc. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ==============================================================================

from setuptools import setup, Distribution

import os
import fnmatch

def find_files(pattern, root):
  """Return all the files matching pattern below root dir."""
  for path, _, files in os.walk(root):
    for filename in fnmatch.filter(files, pattern):
      yield os.path.join(path, filename)


class BinaryDistribution(Distribution):
  def is_pure(self):
    return False


REQUIRED_PACKAGES = [
    'numpy >= 1.8.2',
    'six >= 1.10.0',
    'protobuf == 3.0.0b2',
	'wheel >= 0.26'
]

matches = ['../' + x for x in find_files('*', 'external')]

setup(
    name='tensorflow',
    version='0.8.1',
    description='TensorFlow helps the tensors flow',
    long_description='',
    url='http://tensorflow.org/',
    author='Google Inc. & Microsoft Inc.',
    author_email='opensource@google.com & shaocs@microsoft.com',
    
	# Contained modules and scripts.
    packages=['tensorflow'],
    entry_points={
        'console_scripts': ['tensorboard = tensorflow.tensorboard.tensorboard:main'],
    },
    install_requires=REQUIRED_PACKAGES,
    tests_require=REQUIRED_PACKAGES + ['scipy >= 0.15.1'],
    
	# Add in any packaged data.
    include_package_data=True,
    package_data={
        'tensorflow': ['python/_pywrap_tensorflow.pyd',
                       'tensorboard/dist/index.html',
                       'tensorboard/dist/tf-tensorboard.html',
                       'tensorboard/lib/css/global.css',] + matches
    },
    zip_safe=False,
    distclass=BinaryDistribution,
    
	# PyPI package information.
    classifiers=[
        'Development Status :: 4 - Beta',
        'Intended Audience :: Developers',
        'Intended Audience :: Education',
        'Intended Audience :: Science/Research',
        'License :: OSI Approved :: Apache Software License',
        'Programming Language :: Python :: 3.5',
        'Topic :: Scientific/Engineering :: Mathematics',
        'Topic :: Software Development :: Libraries :: Python Modules',
        'Topic :: Software Development :: Libraries',
        ],
    license='Apache 2.0',
	platform=['win-amd64'],
    keywords='tensorflow tensor machine learning'
)
