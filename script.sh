!/bin/bash
echo ""
echo "Автор: Водянкин Кирилл, группа 748"
echo "Программа: script.sh"
echo "Программа для подключения и отключения репозиториев"
echo ""
while :
do
echo "Списк имеющихся репозиториев:"
rep=$(ls /etc/yum.repos.d/)
echo "$rep"
echo ""
read -p "Введите названия репозитория из списка: " repo
dict=$(yum repolist enabled $repo)
stct="$(echo $dict | rev | cut -d" " -f1 | rev)"
if [ -e /etc/yum.repos.d/$repo.repo ]
then
if [ $stct = "0" ]
then
re=$(yum-config-manager --enable $repo)
echo "Репозиторий подключен"
else
re=$(yum-config-manager --disable $repo)
echo "Репозиторий отключен"
fi
else
echo "Репозиторий не найден"
fi
read -p "Начать заново? (д/н): " prodolzaem
if [ $prodolzaem != "д" ]
then
echo "Выход из программы"
break
fi 
done
