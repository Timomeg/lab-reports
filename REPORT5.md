##### Инициализация переменных GITHUB_USERNAME и изменение команды gsed на sed
```
$ export GITHUB_USERNAME=<имя_пользователя>
$ alias gsed=sed # for *-nix system
```
##### Использование рабочей директории, размещение директории на стеке и запуска файла scripts/activate
```
$ cd ${GITHUB_USERNAME}/workspace
$ pushd .
$ source scripts/activate
```
##### Клонирование репозитория четвёртого лабораторной работы в директорию projects/lab04 и её использование, удаление связи с прошлым удалённым репозиторием и добавление нового
```
$ git clone https://github.com/${GITHUB_USERNAME}/lab04 projects/lab05
$ cd projects/lab05
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab05
```
##### Создание директории third-party и добавление в неё библиотеки GTest, коммит изменений в Git репозиторий
```
$ mkdir third-party
$ git submodule add https://github.com/google/googletest third-party/gtest
$ cd third-party/gtest && git checkout release-1.8.1 && cd ../..
$ git add third-party/gtest
$ git commit -m"added gtest framework"
```
##### Добавление зависимостей для тестов в CMakeLists.txt
```
$ gsed -i '/option(BUILD_EXAMPLES "Build examples" OFF)/a\
option(BUILD_TESTS "Build tests" OFF)
' CMakeLists.txt
$ cat >> CMakeLists.txt <<EOF

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(third-party/gtest)
  file(GLOB \${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
  add_executable(check \${\${PROJECT_NAME}_TEST_SOURCES})
  target_link_libraries(check \${PROJECT_NAME} gtest_main)
  add_test(NAME check COMMAND check)
endif()
EOF
```
##### Создание директории tests и добавление в неё файла test1.cpp с тестами
```
$ mkdir tests
$ cat > tests/test1.cpp <<EOF
#include <print.hpp>

#include <gtest/gtest.h>

TEST(Print, InFileStream)
{
  std::string filepath = "file.txt";
  std::string text = "hello";
  std::ofstream out{filepath};

  print(text, out);
  out.close();

  std::string result;
  std::ifstream in{filepath};
  in >> result;

  EXPECT_EQ(result, text);
}
EOF
```
##### Подключение тестов в CMake, сборка и тестирование проекта с помощью CMake и Googletest
```
$ cmake -H. -B_build -DBUILD_TESTS=ON
$ cmake --build _build
$ cmake --build _build --target test
```
##### Запуск файла _build/check, подробный вывод хода тестирования
```
$ _build/check
```
###### Вывод:
```
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from Print
[ RUN      ] Print.InFileStream
[       OK ] Print.InFileStream (0 ms)
[----------] 1 test from Print (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (0 ms total)
[  PASSED  ] 1 test.

```
```
$ cmake --build _build --target test -- ARGS=--verbose
```
##### Добавление текста в README.md и CMake команд в файл .travis.yml
```
$ gsed -i 's/lab04/lab05/g' README.md
$ gsed -i 's/\(DCMAKE_INSTALL_PREFIX=_install\)/\1 -DBUILD_TESTS=ON/' .travis.yml
$ gsed -i '/cmake --build _build --target install/a\
- cmake --build _build --target test -- ARGS=--verbose
' .travis.yml
```
##### Проверка на корректность файла .travis.yml
```
$ travis lint
```
###### Вывод для travis lint: Hooray, .travis.yml looks valid :)
##### Коммит тестов и файла .travis.yml в Git репозиторий
```
$ git add .travis.yml
$ git add tests
$ git add -p
$ git commit -m"added tests"
$ git push origin master
```
##### Вход в аккаунт travis ci и его подключение к репозиторию
```
$ travis login --auto
$ travis enable
```
##### Создаём директорию artifacts, делаем скриншот и сохраняем в artifacts
```
$ mkdir artifacts
$ sleep 20s && gnome-screenshot --file artifacts/screenshot.png
# for macOS: $ screencapture -T 20 artifacts/screenshot.png
# open https://github.com/${GITHUB_USERNAME}/lab05
```
#### Отчёт: скачиваем репозиторий с лабораторной работой, создаём в нём отчёт и загружаем через gist
```
 $ popd
 $ export LAB_NUMBER=05
 $ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
 $ mkdir reports/lab${LAB_NUMBER}
 $ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
 $ cd reports/lab${LAB_NUMBER}
 $ edit REPORT.md
 $ gist REPORT.md
```
