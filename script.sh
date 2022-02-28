#!/bin/bash
echo "Вы запустили скрипт с именем script.sh"
echo "Разработчик: Водянкин Кирилл"
echo "Программа для отключения/подключения репозиториев"

echo "Список репозиториев"
yum repolist all
echo "Список включенных репозиториев"
yum repolist
while :
do
echo "Введите имя отключенного репозитория, который будет включен или включенного, который будет отключен"
read -r repo
if !(checkrepo $repolist); then
	echo "Такого репозитория нет в списке подключенных, отключить?"
	echo -n "y/n: "
	read answer
	if [ "$answer" != "${answer#[Yy]}" ] ;then
	    yum-config-manager --disable $repo
	else
	    yum-config-manager --enable $repo
	fi
	echo "Закончили?"
	echo -n "y/n: "
	read answer
	if [ "$answer" != "${answer#[Nn]}" ] ;then
	        echo "Выход!"
	    exit
	else
	    echo "Закончили!!"
	fi
else
	echo "Закончили?"
	echo -n "y/n: "
	read answer
	if [ "$answer" != "${answer#[Nn]}" ] ;then
		echo "Выход!!"
		exit
	else
		echo "Закончили!"
fi
fi
done
