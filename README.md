# Jupyter using Docker

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
wget -O - -q 'https://gist.githubusercontent.com/allenday/f426e0f146d86bfc3dada06eda55e123/raw/41b6d3bc8ab2dfe1e1d09135851c8f11b8dc8db3/install-cuda.sh' | sudo bash
```

Verify Cuda is properly setup and GPU is working
```bash
sudo nvidia-smi
```

Run nvidia plugin:
```
sudo nvidia-docker-plugin &
```

Run Jupyter using docker:
```
sudo nvidia-docker run --rm -d --name jupyter -p 8888:8888 -p 6006:6006 -v /home/ubuntu/notebooks:/notebooks drujensen/jupyter
```

Watch logs and grab URL to open
```
sudo docker logs jupyter
```

