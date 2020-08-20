git init
git remote add origin https://github.com/yanxiaoyong-ch/study.git
touch a.txt
git add a.txt
git commit -m "axxxx"

git pull origin master
git push -u origin master

git tag -d v4.9.1
git clean -d -fx;git checkout -B 4.9.1 v4.9.1
