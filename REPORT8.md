#### 
```
$ export GITHUB_USERNAME=<имя_пользователя>
```
####
```
$ cd ${GITHUB_USERNAME}/workspace
$ pushd .
$ source scripts/activate
```
####
```
$ git clone https://github.com/${GITHUB_USERNAME}/lab07 lab08
$ cd lab08
$ git submodule update --init
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab08
```
####
```
$ cat > Dockerfile <<EOF
FROM ubuntu:18.04
EOF
```
####
```
$ cat >> Dockerfile <<EOF

RUN apt update
RUN apt install -yy gcc g++ cmake
EOF
```
####
```
$ cat >> Dockerfile <<EOF

COPY . print/
WORKDIR print
EOF
```
####
```
$ cat >> Dockerfile <<EOF

RUN cmake -H. -B_build -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=_install
RUN cmake --build _build
RUN cmake --build _build --target install
EOF
```
####
```
$ cat >> Dockerfile <<EOF

ENV LOG_PATH /home/logs/log.txt
EOF
```
####
```
$ cat >> Dockerfile <<EOF

VOLUME /home/logs
EOF
```
####
```
$ cat >> Dockerfile <<EOF

WORKDIR _install/bin
EOF
```
####
```
$ cat >> Dockerfile <<EOF

ENTRYPOINT ./demo
EOF
```
####
```
$ docker build -t logger .
```
####
```
$ docker images
```
####
```
$ mkdir logs
$ docker run -it -v "$(pwd)/logs/:/home/logs/" logger
text1
text2
text3
<C-D>
```
####
```
$ docker inspect logger
```
####
```
$ cat logs/log.txt
```
####
```
$ gsed -i 's/lab07/lab08/g' README.md
```
####
```
$ vim .travis.yml
/lang<CR>o
services:
- docker<ESC>
jVGdo
script:
- docker build -t logger .<ESC>
:wq
```
####
```
$ git add Dockerfile
$ git add .travis.yml
$ git commit -m"adding Dockerfile"
$ git push origin master
```
####
```
$ travis login --auto
$ travis enable
```
#### Отчёт: скачиваем репозиторий с лабораторной работой, создаём в нём отчёт и загружаем через gist
```
$ popd
$ export LAB_NUMBER=08
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gist REPORT.md
```
