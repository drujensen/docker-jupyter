FROM jupyter/tensorflow-notebook

USER root

ENV GRANT_SUDO=yes

RUN apt-get -y update

RUN pip install bcolz

RUN pip install --quiet keras theano

CMD jupyter notebook --allow-root

USER $NB_UID
