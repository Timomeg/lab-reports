#### 1. Инициализация переменных GITHUB_USERNAME(имя пользователя на Github)
`$ export GITHUB_USERNAME=<имя_пользователя>`
###### Установка текстового редактора по умолчанию, создание рабочей директории и запуска файла scripts/activate
```
$ cd ${GITHUB_USERNAME}/workspace
$ pushd .
$ source scripts/activate
```
#### 2. Создание директории .config, добавление в неё данных о Github профиле установка протокола https по умолчанию
```
$ git clone https://github.com/${GITHUB_USERNAME}/lab02.git projects/lab03
$ cd projects/lab03
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab03.git
```
#### 3. Создание директории projects/lab02 и использование её как рабочей

```
$ g++ -std=c++11 -I./include -c sources/print.cpp
$ ls print.o
$ nm print.o | grep print
$ ar rvs print.a print.o
$ file print.a
$ g++ -std=c++11 -I./include -c examples/example1.cpp
$ ls example1.o
$ g++ example1.o print.a -o example1
$ ./example1 && echo
```
#### 4. Конфигурация настроек git и вывод этих настроек
```
$ g++ -std=c++11 -I./include -c examples/example2.cpp
$ nm example2.o
$ g++ example2.o print.a -o example2
$ ./example2
$ cat log.txt && echo
```
#### 4. Добавление игнорируемых директорий в .gitignore файл
```
$ rm -rf example1.o example2.o print.o
$ rm -rf print.a
$ rm -rf example1 example2
$ rm -rf log.txt
```
#### 5. Выгрузка ветки master в локальный репозиторий и вывод коммитов в обратном порядке
```
$ cat > CMakeLists.txt <<EOF
cmake_minimum_required(VERSION 3.4)
project(print)
EOF
```
######
```
$ cat >> CMakeLists.txt <<EOF
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
EOF
```
######
```
$ cat >> CMakeLists.txt <<EOF
add_library(print STATIC \${CMAKE_CURRENT_SOURCE_DIR}/sources/print.cpp)
EOF
```
######
```
$ cat >> CMakeLists.txt <<EOF
include_directories(\${CMAKE_CURRENT_SOURCE_DIR}/include)
EOF
```
######
```
$ cmake -H. -B_build
$ cmake --build _build
$ cat >> CMakeLists.txt <<EOF
```
######
```
add_executable(example1 \${CMAKE_CURRENT_SOURCE_DIR}/examples/example1.cpp)
add_executable(example2 \${CMAKE_CURRENT_SOURCE_DIR}/examples/example2.cpp)
EOF
$ cat >> CMakeLists.txt <<EOF
```
######
```
target_link_libraries(example1 print)
target_link_libraries(example2 print)
EOF
$ cmake --build _build
$ cmake --build _build --target print
$ cmake --build _build --target example1
$ cmake --build _build --target example2
```
#### 6. Создание директории sources, include и examples
```
$ ls -la _build/libprint.a
$ _build/example1 && echo
hello
$ _build/example2
$ cat log.txt && echo
hello
$ rm -rf log.txt
```
#### 7. Добавление в файл examples/example2.cpp кода
```
$ git clone https://github.com/tp-labs/lab03 tmp
$ mv -f tmp/CMakeLists.txt .
$ rm -rf tmp
```
#### 8. Изменение файла README.md
```
$ cat CMakeLists.txt
$ cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install
$ cmake --build _build --target install
$ tree _install
```
#### 9. Проверка статуса локального репозитория
```
$ git add CMakeLists.txt
$ git commit -m"added CMakeLists.txt"
$ git push origin master
```
#### Отчёт: скачиваем репозиторий с лабораторной работой, создаём в нём отчёт и загружаем через gist
```
$ export LAB_NUMBER=03
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gist REPORT.md
```
