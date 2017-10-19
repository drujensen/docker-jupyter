FROM gcr.io/tensorflow/tensorflow:latest-gpu

MAINTAINER Dru Jensen <drujensen@gmail.com>

USER root

ENV GRANT_SUDO=yes

RUN apt-get -y update

#RUN pip install bcolz

#RUN conda install -c conda-forge theano pygpu keras tensorflow
