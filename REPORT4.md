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
##### Установка виртуальной машины Ruby, запуск . scripts/activate, загрузка Ruby версии 2.4.2 и установка её по умолчанию, загрузка travis
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
####
```
$ travis lint
$ travis accounts
$ travis sync
$ travis repos
$ travis enable
$ travis whatsup
$ travis branches
$ travis history
$ travis show
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
