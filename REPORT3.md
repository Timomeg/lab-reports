#### 1. Инициализация переменных GITHUB_USERNAME(имя пользователя на Github)
`$ export GITHUB_USERNAME=<имя_пользователя>`
##### Использование рабочей директории, размещение директории на стеке и запуска файла scripts/activate
```
$ cd ${GITHUB_USERNAME}/workspace
$ pushd .
$ source scripts/activate
```
#### 2. Клонирование репозитория второй лабораторной работы в директорию projects/lab03 и её использование
```
$ git clone https://github.com/${GITHUB_USERNAME}/lab02.git projects/lab03
$ cd projects/lab03
```
##### Удаление связи с прошлым удалённым репозиторием и добавление нового
```
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab03.git
```
#### 3. Компиляция файла sources/print.cpp, вывод названия скомпилированного файла

```
$ g++ -std=c++11 -I./include -c sources/print.cpp
$ ls print.o
```
###### Вывод: print.o
##### Вывод всех слов print, создание статической библиотеки print.a из файла print.o, вывод типа файла print.a
```
$ nm print.o | grep print
$ ar rvs print.a print.o
$ file print.a
```
###### Вывод: 000000000000009e t _GLOBAL__sub_I__Z5printRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERSo
0000000000000000 T _Z5printRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERSo
0000000000000026 T _Z5printRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERSt14basic_ofstreamIcS2_E
print.a: current ar archive
##### Компиляция файла sources/print.cpp, вывод названия скомпилированного файла
```
$ g++ -std=c++11 -I./include -c examples/example1.cpp
$ ls example1.o
```
###### Вывод: example1.o
##### Компиляция файла sources/print.cpp, запуск файла, и при удачной работе печать новой строки
```
$ g++ example1.o print.a -o example1
$ ./example1 && echo
```
###### Вывод: hello
#### 4. Компиляция файла examples/example2.cpp
```
$ g++ -std=c++11 -I./include -c examples/example2.cpp
$ nm example2.o
$ g++ example2.o print.a -o example2
```
###### Вывод:    U __cxa_atexit
                 U __dso_handle
0000000000000000 V DW.ref.__gxx_personality_v0
                 U _GLOBAL_OFFSET_TABLE_
0000000000000133 t _GLOBAL__sub_I_main
                 U __gxx_personality_v0
0000000000000000 T main
                 U _Unwind_Resume
00000000000000e1 t _Z41__static_initialization_and_destruction_0ii
                 U _Z5printRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERSt14basic_ofstreamIcS2_E
                 U _ZNSaIcEC1Ev
                 U _ZNSaIcED1Ev
                 U _ZNSt14basic_ofstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode
                 U _ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev
                 U _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_
                 U _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
                 U _ZNSt8ios_base4InitC1Ev
                 U _ZNSt8ios_base4InitD1Ev
0000000000000000 r _ZStL19piecewise_construct
0000000000000000 b _ZStL8__ioinit

##### Запуск файла example2, вывод содержимого файла log.txt, и при удачной работе печать новой строки 
```
$ ./example2
$ cat log.txt && echo
```
###### Вывод: Hello
#### 5. Удаление файлов example1.o, example2.o, print.o, print.a, example1, example2, log.txt
```
$ rm -rf example1.o example2.o print.o
$ rm -rf print.a
$ rm -rf example1 example2
$ rm -rf log.txt
```
#### 6. Добавление в файл CMakeLists.txt необходимой версии и имени проекта
```
$ cat > CMakeLists.txt <<EOF
cmake_minimum_required(VERSION 3.4)
project(print)
EOF
```
##### Добавление в файл CMakeLists.txt стандарта C++ и использование этого стандарта как обязательного
```
$ cat >> CMakeLists.txt <<EOF
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
EOF
```
##### Добавление в файл CMakeLists.txt статической библиотеки
```
$ cat >> CMakeLists.txt <<EOF
add_library(print STATIC \${CMAKE_CURRENT_SOURCE_DIR}/sources/print.cpp)
EOF
```
##### Добавление в файл CMakeLists.txt директории include
```
$ cat >> CMakeLists.txt <<EOF
include_directories(\${CMAKE_CURRENT_SOURCE_DIR}/include)
EOF
```
##### Сборка проекта с помощью CMake
```
$ cmake -H. -B_build
$ cmake --build _build
```
##### Добавление в файл CMakeLists.txt исполняемых файлов
```
$ cat >> CMakeLists.txt <<EOF
add_executable(example1 \${CMAKE_CURRENT_SOURCE_DIR}/examples/example1.cpp)
add_executable(example2 \${CMAKE_CURRENT_SOURCE_DIR}/examples/example2.cpp)
EOF
```
##### Добавление в файл CMakeLists.txt связей между библиотекой print и исполняемыми файлами
```
$ cat >> CMakeLists.txt <<EOF
target_link_libraries(example1 print)
target_link_libraries(example2 print)
EOF
```
##### Сборка проекта с добавлением новых связей
```
$ cmake --build _build
$ cmake --build _build --target print
$ cmake --build _build --target example1
$ cmake --build _build --target example2
```
#### 7. Вывод информации о файле _build/libprint.a, запуск файла _build/example1 и вывод hello
```
$ ls -la _build/libprint.a
$ _build/example1 && echo hello
```
###### Вывод: -rw-r--r-- 1 timomeg timomeg 2982 мар 10 10:57 _build/libprint.a
hellohello
##### Запуск файла _build/example2, вывод содержимого log.txt и вывод hello, удаление log.txt
```
$ _build/example2
$ cat log.txt && echo hello
$ rm -rf log.txt
```
###### Вывод: hellohello
#### 8. Клонирование репозитория lab03 в директорию tmp, перенос файла tmp/CMakeLists.txt в рабочую директорию, удаление tmp
```
$ git clone https://github.com/tp-labs/lab03 tmp
$ mv -f tmp/CMakeLists.txt .
$ rm -rf tmp
```
#### 9. Вывод содержимого CMakeLists.txt, сборка проекта, вывод графа, изображающего директории и файлы в проекте
```
$ cat CMakeLists.txt
$ cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install
$ cmake --build _build --target install
$ tree _install
```
###### Вывод: 
├── cmake
│   ├── print-config.cmake
│   └── print-config-noconfig.cmake
├── include
│   └── print.hpp
└── lib
    └── libprint.a

4 directories, 4 files
#### 10. Коммит файла CMakeLists.txt в удалённый репозиторий
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
