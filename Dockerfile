FROM jupyter/datascience-notebook

MAINTAINER Dru Jensen <drujensen@gmail.com>

RUN sudo apt-get install -y --no-install-recommends apt-transport-https ca-certificates curl software-properties-common

RUN curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add - 

RUN sudo add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) \
   stable"

RUN sudo apt-get -y update

RUN sudo apt-get -y --no-install-recommends install docker-ce

RUN wget https://github.com/NVIDIA/nvidia-docker/releases/download/v1.0.1/nvidia-docker_1.0.1-1_amd64.deb

RUN sudo dpkg -i nvidia-docker*.deb

RUN pip install bcolz

RUN conda install -c conda-forge theano pygpu keras tensorflow
