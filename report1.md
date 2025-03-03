# инициализация переменных GITHUB_USERNAME(имя пользователя на Github и GIST_TOKEN(гист токен),
# установка текстового редактора по умолчанию
$ export GITHUB_USERNAME=<имя_пользователя>
$ export GIST_TOKEN=<сохраненный_токен>
$ alias edit=<nano|vi|vim|subl>

# создание(если не существует) директории {GITHUB_USERNAME}/workspace,
# изменение текущей директории на {GITHUB_USERNAME}/workspace,
# вывод полного пути до текущей директории,
# изменение текущей директории на {GITHUB_USERNAME},
# вывод полного пути до текущей директории,
$ mkdir -p ${GITHUB_USERNAME}/workspace
$ cd ${GITHUB_USERNAME}/workspace
$ pwd
$ cd ..
$ pwd

# создание(если не существует) директорий workspace/tasks/, workspace/projects/, workspace/reports/
# изменение текущей директории на workspace
$ mkdir -p workspace/tasks/
$ mkdir -p workspace/projects/
$ mkdir -p workspace/reports/
$ cd workspace

# для Debian:
# скачивание архива с node.js для линукс с 64-битной архитектурой процессора,
# извлечение этого архива,
# удаление архива,
# изменение имени разархивированной директории на node
$ wget https://nodejs.org/dist/v6.11.5/node-v6.11.5-linux-x64.tar.xz
$ tar -xf node-v6.11.5-linux-x64.tar.xz
$ rm -rf node-v6.11.5-linux-x64.tar.xz
$ mv node-v6.11.5-linux-x64 node

# вывод всех директорий и файлов в директории node/bin,
# вывод значения переменной PATH,
# добавление в PATH новой директории node/bin,
# вывод значения переменной PATH,
# создание директории scripts,
# создание файла activate в директории scripts и запись в него скрипта export PATH=\${PATH}:`pwd`/node/bin
(<<EOF EOF нужны для передачи многострочного текста в cat),
запуск файла scripts/activate
$ ls node/bin
$ echo ${PATH}
$ export PATH=${PATH}:`pwd`/node/bin
$ echo ${PATH}
$ mkdir scripts
$ cat > scripts/activate<<EOF
export PATH=\${PATH}:`pwd`/node/bin
EOF
$ source scripts/activate

# установка Ruby пакета gist
$ gem install gist

# создание маски для контроля доступа к файлу,
# вывод гист токена и запись этого токена в файл
$ (umask 0077 && echo ${GIST_TOKEN} > ~/.gist)
