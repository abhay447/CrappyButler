current_path="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd $current_path;
path=$(pwd);
train_path=$path"/test/train";
result_path=$path"/test/result";
fft_path=$result_path"/fft/";

cd $train_path
for f in *.sh;do
chmod a+x $f;
done

#./getAudio.sh
./getAmplitudes.sh
./segmenter.sh

rm -rf *.txt
rm -rf *.pcm

cd $result_path

for segment in *.txt;do
	rm -rf *.rst;
	rm -rf *.xyz
	temp_path=$(pwd)
	
	g++ fft.cpp -lfftw3;
	./a.out $segment $temp_path
	rm -rf $segment
	
	cd $fft_path
	temp_path=$(pwd)
	g++ bellfft.cpp;
	./a.out *.fft $temp_path;
	rm -rf *.fft
	
	cd ..
	g++ result.cpp -std=c++0x
	./a.out
	
	cd fft
	rm -rf *.xyz	
	
	cd $path
	g++ roughCom.cpp;
	./a.out;
	cd test/result;
	rm -rf *.txt;
	rm -rf *.rst;
	rm -rf *.xyz;
	
	cd $result_path
done

