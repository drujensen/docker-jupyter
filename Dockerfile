FROM jupyter/tensorflow-notebook

USER $NB_UID
ENV GRANT_SUDO=yes

RUN pip install "torch==1.4" "torchvision==0.5.0"
RUN pip install --quiet fastai

CMD jupyter notebook --allow-root
