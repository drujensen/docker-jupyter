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

## Docker Compose commands

### Use EC2 instance
```bash
eval $(dm env jupyter)
```

### Verify its active
```bash
dm ls
```

### Build
```bash
dc build server
```

### Bring Up
```bash
dc up -d
```

### Logs
```bash
dc logs -f
```

### Start
```bash
dc start
```

### Stop
```bash
dc stop
```

### Shut Down
```bash
dc down
```

## Docker Commands

You can also use any `docker` command if you prefer that over `docker-compose`. 
