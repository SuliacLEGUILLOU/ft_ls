DIR=/Users/msorin/Desktop/gh_ft_ls/test/test_prot
for f in $DIR/*
do
	ls -R $f
	echo $?
done
ls blabla
echo $?
