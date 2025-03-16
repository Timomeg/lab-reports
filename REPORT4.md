##### Инициализация переменных GITHUB_USERNAME и GITHUB_TOKEN(имя пользователя и токен на Github)
```
$ export GITHUB_USERNAME=<имя_пользователя>
$ export GITHUB_TOKEN=<полученный_токен>
```
##### Использование рабочей директории, размещение директории на стеке и запуска файла scripts/activate
```
$ cd ${GITHUB_USERNAME}/workspace
$ pushd .
$ source scripts/activate
```
##### Установка виртуальной машины Ruby, запуск . scripts/activate, загрузка Ruby версии 2.4.2 и установка её по умолчанию, загрузка Travis CI
```
$ \curl -sSL https://get.rvm.io | bash -s -- --ignore-dotfiles
$ echo "source $HOME/.rvm/scripts/rvm" >> scripts/activate
$ . scripts/activate
$ rvm autolibs disable
$ rvm install ruby-2.4.2
$ rvm use 2.4.2 --default
$ gem install travis
```
##### Клонирование репозитория третьей лабораторной работы в директорию projects/lab04 и её использование, удаление связи с прошлым удалённым репозиторием и добавление нового

```
$ git clone https://github.com/${GITHUB_USERNAME}/lab03 projects/lab04
$ cd projects/lab04
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab04
```
##### Добавление в файл .travis.yml языка программирования
```
$ cat > .travis.yml <<EOF
language: cpp
EOF
```
##### Добавление в файл .travis.yml команд для сборки проекта с помощью cmake
```
$ cat >> .travis.yml <<EOF

script:
- cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install
- cmake --build _build
- cmake --build _build --target install
EOF
```
##### Добавление в файл .travis.yml
```
$ cat >> .travis.yml <<EOF

addons:
  apt:
    sources:
      - george-edison55-precise-backports
    packages:
      - cmake
      - cmake-data
EOF
```
##### Вход в аккаунт travis ci с помощью токена
```
$ travis login --github-token ${GITHUB_TOKEN}
```
##### Проверка на корректность файла .travis.yml
```
$ travis lint
```
###### Вывод: Hooray, .travis.yml looks valid :)
##### Коммит файлов .travis.yml и README.md
```
$ git add .travis.yml
$ git add README.md
$ git commit -m"added CI"
$ git push origin master
```
##### Проверка на корректность файла .travis.yml
```
$ travis lint
```
###### Вывод для travis lint: Hooray, .travis.yml looks valid :)
##### Вывод данных привязанного аккаунта
```
$ travis accounts
```
###### Вывод: Timomeg (Timofey Rotin): educational account, 19 repositories
##### Синхронизация аккаунта Travis CI с GitHub
```
$ travis sync
```
###### Вывод: synchronizing: .......... done
##### Вывод списка репозиториев, связанных с аккаунтом Travis CI
```
$ travis repos
```
##### Подключение Travis CI для текущего репозитория 
```
$ travis enable
```
###### Вывод: Timomeg/lab-reports: enabled :)
##### Вывод статусов текущих билдов
```
$ travis whatsup
```
###### Вывод: Timomeg/lab-reports passed: #3
##### Вывод списка веток и статуса их билдов
```
$ travis branches
```

##### Вывод истории билдов
```
$ travis history
```
###### Вывод: master:  #3    passed     Add Gtest dependencies
##### Вывод детальной информации о билде
```
$ travis show
```
###### Вывод: 
```
Build #3:  Add Gtest dependencies
State:         passed
Type:          push
Branch:        master
Commit:        cce18b2
Compare URL:   https://github.com/Timomeg/lab-reports/compare/7d877d947b12...cce18b288702
Duration:      58 sec
Started:       2025-03-15 15:26:26
Finished:      2025-03-15 15:27:58

#3.1 passed:     30 sec         os: linux, compiler: gcc
#3.2 passed:     28 sec         os: linux, compiler: clang
```
#### Отчёт: скачиваем репозиторий с лабораторной работой, создаём в нём отчёт и загружаем через gist
```
$ popd
$ export LAB_NUMBER=04
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gist REPORT.md
```
