path=$(pwd);
g++ bellfft.cpp;
for f in *.fft;do
./a.out $f $path;
echo $f;
done
