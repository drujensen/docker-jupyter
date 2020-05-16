#################################################################################################################
# A docker environment for FASTAI v1.0
# References:
# https://github.com/Paperspace/fastai-docker/blob/master/fastai-v3/Dockerfile
#################################################################################################################

FROM nvidia/cuda:10.2-base-ubuntu18.04

#################################################################################################################
#           Global
#################################################################################################################

ENV LANG=C.UTF-8 LC_ALL=C.UTF-8

#################################################################################################################
#           SYSTEM
#################################################################################################################

# label that nvidia-docker will detect and then mount the driver files (https://github.com/NVIDIA/nvidia-docker/issues/410)
LABEL com.nvidia.volumes.needed="nvidia_driver"

# compute cuda repo for ubuntu1804
RUN echo "deb https://developer.download.nvidia.com/compute/machine-learning/repos/ubuntu1804/x86_64 /" > /etc/apt/sources.list.d/nvidia-ml.list

RUN apt-get update && apt-get install -y --no-install-recommends \
         build-essential \
         cmake \
         git \
         wget \
         vim \
         ca-certificates \
         libjpeg-dev \
         zip \
         unzip \
         libpng-dev \
         python3 \
         python3-dev \
         python3-pip \
         python3-setuptools

ENV LD_LIBRARY_PATH /usr/local/nvidia/lib:/usr/local/nvidia/lib64

#################################################################################################################
#           TINI
#################################################################################################################

ENV TINI_VERSION v0.16.1
ADD https://github.com/krallin/tini/releases/download/${TINI_VERSION}/tini /usr/bin/tini
RUN chmod +x /usr/bin/tini

#################################################################################################################
#           FASTAI
#################################################################################################################

# update fastai version as required
ARG FASTAI_VERSION=1.0.61
RUN git clone --single-branch --branch $FASTAI_VERSION https://github.com/fastai/fastai.git /usr/local/fastai

# install fastai environment
RUN cd /usr/local/fastai && pip3 install -e .

#################################################################################################################
#           JUPYTER
# Notes
# * multiple GPUs, you can point notebook servers to each device using CUDA_DEVICE_ORDER and CUDA_VISIBLE_DEVICES
#   (see https://github.com/MattKleinsmith/dockerfiles/blob/master/fastai/Dockerfile)
#################################################################################################################

# Add a notebook profile.
# 1. set default working directory
RUN mkdir -p -m 700 /root/.jupyter/ && \
    echo "c.NotebookApp.notebook_dir = '/'" >> /root/.jupyter/jupyter_notebook_config.py

# Open port
EXPOSE 8888

#################################################################################################################
#           System CleanUp
#################################################################################################################
# apt-get autoremove: used to remove packages that were automatically installed to satisfy dependencies for some
# package and that are no more needed.
# apt-get clean: removes the aptitude cache in /var/cache/apt/archives. The only drawback is that the packages
# have to be downloaded again if you reinstall them.

RUN apt-get autoremove -y && apt-get clean && \
    rm -rf /var/lib/apt/lists/*

#################################################################################################################
#           START UP
#################################################################################################################

VOLUME /home
WORKDIR /home

ENTRYPOINT [ "/tini", "--" ]

# notebook password: fastai
CMD /bin/bash -c "source activate fastai && jupyter notebook --ip='0.0.0.0' --allow-root --no-browser --NotebookApp.password='sha1:a60ff295d0b9:506732d050d4f50bfac9b6d6f37ea6b86348f4ed'"
