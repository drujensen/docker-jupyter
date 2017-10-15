FROM jupyter/datascience-notebook

MAINTAINER Dru Jensen <drujensen@gmail.com>

# install packages to allow apt to use a repository over HTTPS:
RUN sudo apt-get -y install apt-transport-https ca-certificates curl software-properties-common
# add Docker’s official GPG key:
RUN curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add - 
# set up the Docker stable repository.
RUN sudo add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) \
   stable"
# update the apt package index:
RUN sudo apt-get -y update
# finally, install docker
RUN sudo apt-get -y install docker-ce

RUN wget https://github.com/NVIDIA/nvidia-docker/releases/download/v1.0.1/nvidia-docker_1.0.1-1_amd64.deb

RUN sudo dpkg -i nvidia-docker*.deb

RUN pip install bcolz

RUN conda install -c conda-forge theano pygpu keras tensorflow
