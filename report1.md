#### 1. Инициализация переменных GITHUB_USERNAME(имя пользователя на Github и GIST_TOKEN(гист токен)
`$ export GITHUB_USERNAME=<имя_пользователя>`
`$ export GIST_TOKEN=<сохраненный_токен>`
###### Установка текстового редактора по умолчанию
`$ alias edit=<nano|vi|vim|subl>`

#### 2. Создание(если не существует) директории {GITHUB_USERNAME}/workspace
`$ mkdir -p ${GITHUB_USERNAME}/workspace`
###### Изменение текущей директории на {GITHUB_USERNAME}/workspace
`$ cd ${GITHUB_USERNAME}/workspace`
###### Вывод полного пути до текущей директории
`$ pwd`
###### Изменение текущей директории на {GITHUB_USERNAME}
`$ cd ..`
###### Вывод полного пути до текущей директории
`$ pwd`

#### 3. Создание(если не существует) директорий workspace/tasks/, workspace/projects/, workspace/reports/
`$ mkdir -p workspace/tasks/`
`$ mkdir -p workspace/projects/`
`$ mkdir -p workspace/reports/`
###### Изменение текущей директории на workspace
`$ cd workspace`

# 4. Для Debian:
###### Скачивание архива с node.js для линукс с 64-битной архитектурой
`$ wget https://nodejs.org/dist/v6.11.5/node-v6.11.5-linux-x64.tar.xz`
###### Извлечение этого архива
`$ tar -xf node-v6.11.5-linux-x64.tar.xz`
###### Удаление архива
`$ rm -rf node-v6.11.5-linux-x64.tar.xz`
###### Изменение имени разархивированной директории на node
`$ mv node-v6.11.5-linux-x64 node`

#### 5. Вывод всех директорий и файлов в директории node/bin
`$ ls node/bin`
###### Вывод значения переменной PATH
`$ echo ${PATH}`
###### Добавление в PATH новой директории node/bin
`$ export PATH=${PATH}:`pwd`/node/bin`
###### Вывод значения переменной PATH
`$ echo ${PATH}`
###### Создание директории scripts
`$ mkdir scripts`
###### Создание файла activate в директории scripts и запись в него скрипта export PATH=\${PATH}: pwd /node/bin
######(<<EOF EOF нужны для передачи многострочного текста в cat)
`$ cat > scripts/activate<<EOF
export PATH=\${PATH}: pwd /node/bin
EOF`
###### Запуск файла scripts/activate
`$ source scripts/activate`

#### 6. Установка Ruby пакета gist
`$ gem install gist`

#### 7. Создание маски для контроля доступа к файлу
###### Вывод гист токена и запись этого токена в файл
`$ (umask 0077 && echo ${GIST_TOKEN} > ~/.gist)`
