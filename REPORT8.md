##### Инициализация переменной GITHUB_USERNAME
```
$ export GITHUB_USERNAME=<имя_пользователя>
```
##### Использование рабочей директории, размещение директории на стеке и запуска файла scripts/activate
```
$ cd ${GITHUB_USERNAME}/workspace
$ pushd .
$ source scripts/activate
```
##### Клонирование репозитория седьмой лабораторной работы в директорию projects/lab08 и её использование, удаление связи с прошлым удалённым репозиторием и добавление нового
```
$ git clone https://github.com/${GITHUB_USERNAME}/lab07 lab08
$ cd lab08
$ git submodule update --init
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab08
```
##### Добавление данных об операционной системе в Dockerfile
```
$ cat > Dockerfile <<EOF
FROM ubuntu:18.04
EOF
```
##### Обновление пакетов и добавление необходимых пакетов(gcc, g++, cmake)
```
$ cat >> Dockerfile <<EOF

RUN apt update
RUN apt install -yy gcc g++ cmake
EOF
```
##### Копирование директории print, добавление рабочей директории
```
$ cat >> Dockerfile <<EOF

COPY . print/
WORKDIR print
EOF
```
##### Добавление команд для сборки проекта
```
$ cat >> Dockerfile <<EOF

RUN cmake -H. -B_build -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=_install
RUN cmake --build _build
RUN cmake --build _build --target install
EOF
```
##### Добавление пути до файла для логов
```
$ cat >> Dockerfile <<EOF

ENV LOG_PATH /home/logs/log.txt
EOF
```
##### Добавление тома для хранения данных
```
$ cat >> Dockerfile <<EOF

VOLUME /home/logs
EOF
```
##### Изменение рабочей директории
```
$ cat >> Dockerfile <<EOF

WORKDIR _install/bin
EOF
```
##### Установка исполняемого файла по умолчанию
```
$ cat >> Dockerfile <<EOF

ENTRYPOINT ./demo
EOF
```
##### Сборка logger
```
$ docker build -t logger .
```
##### Вывод образов
```
$ docker images
```
###### Вывод:
```
REPOSITORY    TAG       IMAGE ID       CREATED          SIZE
logger        latest    94845db3aa62   54 seconds ago   611MB
hello-world   latest    74cc54e27dc4   2 months ago     10.1kB
```
##### Создание директории logs и выполнение программы из Dockerfile для text1, text2, text3
```
$ mkdir logs
$ docker run -it -v "$(pwd)/logs/:/home/logs/" logger
text1
text2
text3
<C-D>
```
##### Вывод данных об образе
```
$ docker inspect logger
```
##### Вывод содержимого log.txt
```
$ cat logs/log.txt
```
##### Добавление информации о лабораторной работе в README.md
```
$ gsed -i 's/lab07/lab08/g' README.md
```
##### Добавление тестов для Docker в .travis.yml с помощью vim
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
##### Коммит Dockerfile и .travis.yml
```
$ git add Dockerfile
$ git add .travis.yml
$ git commit -m"adding Dockerfile"
$ git push origin master
```
##### Вход в аккаунт travis ci и его подключение к репозиторию
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
