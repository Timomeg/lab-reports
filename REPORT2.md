#### 1. Инициализация переменных GITHUB_USERNAME(имя пользователя на Github и GIST_TOKEN(гист токен)
`$ export GITHUB_USERNAME=<имя_пользователя>`
`$ export GIST_TOKEN=<сохраненный_токен>`
###### Установка текстового редактора по умолчанию, создание рабочей директории и запуска файла scripts/activate
```
$ alias edit=<nano|vi|vim|subl>`
$ cd ${GITHUB_USERNAME}/workspace
$ source scripts/activate
```
#### 2. Создание директории .config, добавление в неё данных о Github профиле установка протокола https по умолчанию
```
$ mkdir ~/.config
$ cat > ~/.config/hub <<EOF
github.com:
- user: ${GITHUB_USERNAME}
  oauth_token: ${GITHUB_TOKEN}
  protocol: https
EOF
$ git config --global hub.protocol https
```
#### 3. Создание директории projects/lab02 и использование её как рабочей

`$ mkdir projects/lab02 && cd projects/lab02`
###### Конфигурация настроек git и вывод этих настроек
```
$ git init
$ git config --global user.name ${GITHUB_USERNAME}
$ git config --global user.email ${GITHUB_EMAIL}
$ git config -e --global
```
###### Добавление текущего содержимого локального репозитория в удалённый репозиторий
`$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab02.git`
###### Выгрузка ветки master в локальный репозиторий
`$ git pull origin master`
###### Создание файла README.md, проверка текущего статуса рабочей директории, добавление область подготовленных файлов, коммит и добавление в удалённый репозиторий файла README.md
```
$ touch README.md
$ git status
$ git add README.md
$ git commit -m"added README.md"
$ git push origin master
```
#### 4. Добавление игнорируемых директорий в .gitignore файл
```
*build*/
*install*/
*.swp
.idea/
```
#### 5. Выгрузка ветки master в локальный репозиторий и вывод коммитов в обратном порядке
```
$ git pull origin master
$ git log
```
#### 6. Создание директории sources, include и examples
```
$ mkdir sources
$ mkdir include
$ mkdir examples
```
###### Добавление в файл sources/print.cpp кода
```
$ cat > sources/print.cpp <<EOF
#include <print.hpp>

void print(const std::string& text, std::ostream& out)
{
  out << text;
}

void print(const std::string& text, std::ofstream& out)
{
  out << text;
}
EOF
```
#### 7. Добавление в файл examples/example2.cpp кода
```
$ cat > examples/example2.cpp <<EOF
#include <print.hpp>

#include <fstream>

int main(int argc, char** argv)
{
  std::ofstream file("log.txt");
  print(std::string("hello"), file);
}
EOF
```
#### 8. Изменение файла README.md
`$ edit README.md`
#### 9. Проверка статуса локального репозитория
`$ git status`
###### Добавление всех директорий из workspace в область подготовленных файлов 
`$ git add .`
###### Коммит директорий с сообщением added sources
`$ git commit -m"added sources"`
###### Добавление директорий из локального репозитория в удалённый репозиторий
`$ git push origin master`
#### Отчёт: скачиваем репозиторий с лабораторной работой, создаём в нём отчёт и загружаем через gist
```
$ export LAB_NUMBER=01
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gist REPORT.md
```
