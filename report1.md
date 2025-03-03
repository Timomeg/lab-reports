# Инициализация переменных GITHUB_USERNAME(имя пользователя на Github и GIST_TOKEN(гист токен)
$ export GITHUB_USERNAME=<имя_пользователя>
$ export GIST_TOKEN=<сохраненный_токен>
# установка текстового редактора по умолчанию
$ alias edit=<nano|vi|vim|subl>

# Создание(если не существует) директории {GITHUB_USERNAME}/workspace
$ mkdir -p ${GITHUB_USERNAME}/workspace
# изменение текущей директории на {GITHUB_USERNAME}/workspace
$ cd ${GITHUB_USERNAME}/workspace
# вывод полного пути до текущей директории
$ pwd
# изменение текущей директории на {GITHUB_USERNAME}
$ cd ..
# вывод полного пути до текущей директории
$ pwd

# создание(если не существует) директорий workspace/tasks/, workspace/projects/, workspace/reports/
$ mkdir -p workspace/tasks/
$ mkdir -p workspace/projects/
$ mkdir -p workspace/reports/
# изменение текущей директории на workspace
$ cd workspace

# для Debian:
# скачивание архива с node.js для линукс с 64-битной архитектурой
$ wget https://nodejs.org/dist/v6.11.5/node-v6.11.5-linux-x64.tar.xz
# извлечение этого архива
$ tar -xf node-v6.11.5-linux-x64.tar.xz
# удаление архива
$ rm -rf node-v6.11.5-linux-x64.tar.xz
# изменение имени разархивированной директории на node
$ mv node-v6.11.5-linux-x64 node

# вывод всех директорий и файлов в директории node/bin
$ ls node/bin
# вывод значения переменной PATH
$ echo ${PATH}
# добавление в PATH новой директории node/bin
$ export PATH=${PATH}:`pwd`/node/bin
# вывод значения переменной PATH
$ echo ${PATH}
# создание директории scripts
$ mkdir scripts
# создание файла activate в директории scripts и запись в него скрипта export PATH=\${PATH}:`pwd`/node/bin
(<<EOF EOF нужны для передачи многострочного текста в cat)
$ cat > scripts/activate<<EOF
export PATH=\${PATH}:`pwd`/node/bin
EOF
# запуск файла scripts/activate
$ source scripts/activate

# установка Ruby пакета gist
$ gem install gist

# создание маски для контроля доступа к файлу
# вывод гист токена и запись этого токена в файл
$ (umask 0077 && echo ${GIST_TOKEN} > ~/.gist)
