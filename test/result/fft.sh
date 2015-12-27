path=$(pwd);
g++ fft.cpp -lfftw3;
for f in *.txt;do
./a.out $f $path;
echo $f;
done
