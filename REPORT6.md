##### Инициализация переменных GITHUB_USERNAME, GITHUB_EMAIL, установка текстового редактора по умолчанию и изменение команды gsed на sed
```
$ export GITHUB_USERNAME=<имя_пользователя>
$ export GITHUB_EMAIL=<адрес_почтового_ящика>
$ alias edit=<nano|vi|vim|subl>
$ alias gsed=sed # for *-nix system
```
##### Использование рабочей директории, размещение директории на стеке и запуска файла scripts/activate
```
$ cd ${GITHUB_USERNAME}/workspace
$ pushd .
$ source scripts/activate
```
##### Клонирование репозитория пятой лабораторной работы в директорию projects/lab06 и её использование, удаление связи с прошлым удалённым репозиторием и добавление нового
```
$ git clone https://github.com/${GITHUB_USERNAME}/lab05 projects/lab06
$ cd projects/lab06
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab05
```
##### Установка переменных в CMake
```
$ gsed -i '/project(print)/a\
set(PRINT_VERSION_STRING "v\${PRINT_VERSION}")
' CMakeLists.txt
$ gsed -i '/project(print)/a\
set(PRINT_VERSION\
  \${PRINT_VERSION_MAJOR}.\${PRINT_VERSION_MINOR}.\${PRINT_VERSION_PATCH}.\${PRINT_VERSION_TWEAK})
' CMakeLists.txt
$ gsed -i '/project(print)/a\
set(PRINT_VERSION_TWEAK 0)
' CMakeLists.txt
$ gsed -i '/project(print)/a\
set(PRINT_VERSION_PATCH 0)
' CMakeLists.txt
$ gsed -i '/project(print)/a\
set(PRINT_VERSION_MINOR 1)
' CMakeLists.txt
$ gsed -i '/project(print)/a\
set(PRINT_VERSION_MAJOR 0)
' CMakeLists.txt
$ git diff
```
##### Создание файлов описания и изменений проекта, запись в файл с изменениями времени релиза
```
$ touch DESCRIPTION && edit DESCRIPTION
$ touch ChangeLog.md
$ export DATE="`LANG=en_US date +'%a %b %d %Y'`"
$ cat > ChangeLog.md <<EOF
* ${DATE} ${GITHUB_USERNAME} <${GITHUB_EMAIL}> 0.1.0.0
- Initial RPM release
EOF
```
##### Включение в CPackConfig.cmake необходимых библиотек
```
$ cat > CPackConfig.cmake <<EOF
include(InstallRequiredSystemLibraries)
EOF
```
##### Инициализация переменных версий CPack в CPackConfig.cmake
```
$ cat >> CPackConfig.cmake <<EOF
set(CPACK_PACKAGE_CONTACT ${GITHUB_EMAIL})
set(CPACK_PACKAGE_VERSION_MAJOR \${PRINT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR \${PRINT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH \${PRINT_VERSION_PATCH})
set(CPACK_PACKAGE_VERSION_TWEAK \${PRINT_VERSION_TWEAK})
set(CPACK_PACKAGE_VERSION \${PRINT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_FILE \${CMAKE_CURRENT_SOURCE_DIR}/DESCRIPTION)
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "static C++ library for printing")
EOF
```
##### Добавление в CPackConfig.cmake файлов LICENSE и README.md
```
$ cat >> CPackConfig.cmake <<EOF

set(CPACK_RESOURCE_FILE_LICENSE \${CMAKE_CURRENT_SOURCE_DIR}/LICENSE)
set(CPACK_RESOURCE_FILE_README \${CMAKE_CURRENT_SOURCE_DIR}/README.md)
EOF
```
##### Добавление информации о пакете(название, лицензия, файл с изменениями, название группы пакета)
```
$ cat >> CPackConfig.cmake <<EOF

set(CPACK_RPM_PACKAGE_NAME "print-devel")
set(CPACK_RPM_PACKAGE_LICENSE "MIT")
set(CPACK_RPM_PACKAGE_GROUP "print")
set(CPACK_RPM_CHANGELOG_FILE \${CMAKE_CURRENT_SOURCE_DIR}/ChangeLog.md)
set(CPACK_RPM_PACKAGE_RELEASE 1)
EOF
```
##### Добавление пакета Debian и запись минимальной версии CMake
```
$ cat >> CPackConfig.cmake <<EOF

set(CPACK_DEBIAN_PACKAGE_NAME "libprint-dev")
set(CPACK_DEBIAN_PACKAGE_PREDEPENDS "cmake >= 3.0")
set(CPACK_DEBIAN_PACKAGE_RELEASE 1)
EOF
```
##### Подключение CPack в файл конфигурации
```
$ cat >> CPackConfig.cmake <<EOF

include(CPack)
EOF
```
##### Подключение файла конфигурации к проекту
```
$ cat >> CMakeLists.txt <<EOF

include(CPackConfig.cmake)
EOF
```
##### Добавление информации о лабораторной работе в README.md
```
$ gsed -i 's/lab05/lab06/g' README.md
```
##### Коммит файлов с тегом версии проекта
```
$ git add .
$ git commit -m"added cpack config"
$ git tag v0.1.0.0
$ git push origin master --tags
```
##### Вход в аккаунт travis ci и его подключение к репозиторию
```
$ travis login --auto
$ travis enable
```
##### Сборка проекта с помощью CMake, 
```
$ cmake -H. -B_build
$ cmake --build _build
$ cd _build
$ cpack -G "TGZ"
$ cd ..
```
##### Создание папки artifacts и добавление в неё сжатого билда
```
$ mkdir artifacts
$ mv _build/*.tar.gz artifacts
$ tree artifacts
```
###### Вывод:
```
artifacts
└── print-0.1.0.0-Linux.tar.gz
1 directory, 1 file
```
#### Отчёт: скачиваем репозиторий с лабораторной работой, создаём в нём отчёт и загружаем через gist
```
 $ popd
 $ export LAB_NUMBER=06
 $ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
 $ mkdir reports/lab${LAB_NUMBER}
 $ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
 $ cd reports/lab${LAB_NUMBER}
 $ edit REPORT.md
 $ gist REPORT.md
```
