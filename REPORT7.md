##### Инициализация переменных GITHUB_USERNAME и изменение команды gsed на sed
```
$ export GITHUB_USERNAME=<имя_пользователя>
$ alias gsed=sed
```
##### Использование рабочей директории, размещение директории на стеке и запуска файла scripts/activate
```
$ cd ${GITHUB_USERNAME}/workspace
$ pushd .
$ source scripts/activate
```
##### Клонирование репозитория пятой лабораторной работы в директорию projects/lab06 и её использование, удаление связи с прошлым удалённым репозиторием и добавление нового
```
$ git clone https://github.com/${GITHUB_USERNAME}/lab06 projects/lab07
$ cd projects/lab07
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab07
```
##### Скачивание файла HunterGate.cmake и его связывание с проектом при помощи CMake  
```
$ mkdir -p cmake
$ wget https://raw.githubusercontent.com/cpp-pm/gate/master/cmake/HunterGate.cmake -O cmake/HunterGate.cmake
$ gsed -i '/cmake_minimum_required(VERSION 3.4)/a\

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.23.251.tar.gz"
    SHA1 "5659b15dc0884d4b03dbd95710e6a1fa0fc3258d"
)
' CMakeLists.txt
```
##### Удаление gtest из 6 лабораторной работы, добавление hunter пакета gtest
```
$ git rm -rf third-party/gtest
$ gsed -i '/set(PRINT_VERSION_STRING "v\${PRINT_VERSION}")/a\

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)
' CMakeLists.txt
$ gsed -i 's/add_subdirectory(third-party/gtest)//' CMakeLists.txt
$ gsed -i 's/gtest_main/GTest::main/' CMakeLists.txt
```
##### Сборка проекта с помощью CMake, вывод изменений .hunter
```
$ cmake -H. -B_builds -DBUILD_TESTS=ON
$ cmake --build _builds
$ cmake --build _builds --target test
$ ls -la $HOME/.hunter
```
###### Вывод:
```
итого 12
drwxr-xr-x  3 timomeg timomeg 4096 мар 27 00:37 .
drwx------ 38 timomeg timomeg 4096 мар 27 00:37 ..
drwxr-xr-x  7 timomeg timomeg 4096 мар 27 00:58 _Base
```
##### Сборка проекта с помощью CMake с добавленным репозиторием hunter
```
$ git clone https://github.com/cpp-pm/hunter $HOME/projects/hunter
$ export HUNTER_ROOT=$HOME/projects/hunter
$ rm -rf _builds
$ cmake -H. -B_builds -DBUILD_TESTS=ON
$ cmake --build _builds
$ cmake --build _builds --target test
```
##### Запись в файл default.cmake версий GTest и их вывод
```
$ cat $HUNTER_ROOT/cmake/configs/default.cmake | grep GTest
```
###### Вывод:
```
hunter_default_version(GTest VERSION 1.7.0-hunter-6)
hunter_default_version(GTest VERSION 1.15.2)
```
```
$ cat $HUNTER_ROOT/cmake/projects/GTest/hunter.cmake
$ mkdir cmake/Hunter
$ cat > cmake/Hunter/config.cmake <<EOF
hunter_config(GTest VERSION 1.7.0-hunter-9)
EOF
# add LOCAL in HunterGate function
```
##### Создание файла main.cpp, добавление в файл кода и добавление файла в CMakeLists.txt
```
$ mkdir demo
$ cat > demo/main.cpp <<EOF
#include <print.hpp>

#include <cstdlib>

int main(int argc, char* argv[])
{
  const char* log_path = std::getenv("LOG_PATH");
  if (log_path == nullptr)
  {
    std::cerr << "undefined environment variable: LOG_PATH" << std::endl;
    return 1;
  }
  std::string text;
  while (std::cin >> text)
  {
    std::ofstream out{log_path, std::ios_base::app};
    print(text, out);
    out << std::endl;
  }
}
EOF

$ gsed -i '/endif()/a\

add_executable(demo ${CMAKE_CURRENT_SOURCE_DIR}/demo/main.cpp)
target_link_libraries(demo print)
install(TARGETS demo RUNTIME DESTINATION bin)
' CMakeLists.txt
```
##### Установка и подключение к проекту средства для сборки проектов polly и сборка с его помощью проекта
```
$ mkdir tools
$ git submodule add https://github.com/ruslo/polly tools/polly
$ tools/polly/bin/polly.py --test
```
###### Вывод:
```
-
Generate: 0:00:03.058405s
Build: 0:00:02.140316s
Test: 0:00:00.032752s
-
Total: 0:00:05.232494s
-
SUCCESS

```
```
$ tools/polly/bin/polly.py --install
$ tools/polly/bin/polly.py --toolchain clang-cxx14
```
#### Отчёт: скачиваем репозиторий с лабораторной работой, создаём в нём отчёт и загружаем через gist
```
$ popd
$ export LAB_NUMBER=07
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gist REPORT.md
```
