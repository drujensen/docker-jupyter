# Jupyter using Docker

## Start Server
```bash
dc up -d
```

## Find Jupyter URL
```bash
dc logs
```

Look for URL and open in browser


# Jupyter using Docker with GPU

## Setup
Install docker for your environment:
https://www.docker.com/community-edition#/download

Install AWS CLI and configure credentials:
[Install Link](http://docs.aws.amazon.com/cli/latest/userguide/installing.html)
[Configure Link](http://docs.aws.amazon.com/cli/latest/userguide/cli-chap-getting-started.html)

## Alias docker commands in your .bashrc
```bash
alias dm="docker-machine"
alias dc="docker-compose"
```

## Docker Machine commands

### Create
```bash
dm create --driver=amazonec2 --amazonec2-region us-west-2 --amazonec2-instance-type p2.xlarge jupyter
```

Or follow these instructions to install docker on your own instance:

https://docs.docker.com/engine/install/ubuntu/

### List
```bash
dm ls
```

### Start
```bash
dm start jupyter
```

### Stop
```bash
dm stop jupyter
```

### Remove
```bash
dm rm jupyter
```

### SSH
```bash
dm ssh jupyter
```

### SCP
```bash
dm scp [machine:][path] machine:][path]
```

## NVidia Driver

### Install CUDA on host server
SSH into the host
```bash
dm ssh jupyter
```

On the host server:
```bash
distribution=$(. /etc/os-release;echo $ID$VERSION_ID)
curl -s -L https://nvidia.github.io/nvidia-docker/gpgkey | sudo apt-key add -
curl -s -L https://nvidia.github.io/nvidia-docker/$distribution/nvidia-docker.list | sudo tee /etc/apt/sources.list.d/nvidia-docker.list

sudo apt-get update && sudo apt-get install -y nvidia-container-toolkit
sudo systemctl restart docker
```

Verify Cuda is properly setup and GPU is working
```bash
sudo docker run --gpus all nvidia/cuda:10.0-base nvidia-smi
```

Run Jupyter using docker:
```
sudo docker run --rm -d --gpus all --name jupyter -p 8888:8888 -v /home/ubuntu/notebooks:/home/jovyan/work drujensen/jupyter:latest
```

Watch logs and grab URL to open
```
sudo docker logs jupyter
```
