path=$(pwd);
g++ amplitude.cpp;
for f in *.pcm;do
./a.out $f $path;
done
