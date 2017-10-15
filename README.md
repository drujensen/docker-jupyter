## Spin up Amazon EC2 Instance with Docker Machine
```
docker-machine create --driver=amazonec2 --amazonec2-region us-west-2 --amazonec2-instance-type t2.micro jupyter
```

## Build Docker Image
```
docker-compose build server
```

## Run Jupyter
```
docker-compose up -d
```

## Access Jupyter
Look in the logs for the url:
```
docker-compose logs -f
```

when you find the url, open it in a browser.
