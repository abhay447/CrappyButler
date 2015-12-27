current_path="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd $current_path;
cd train
SAMPLES=$(ls)
cd ..

for name in $SAMPLES;do
	path=$(pwd);
	train_path=$path"/train/"$name"/";
	result_path=$path"/result/"$name"/";
	fft_path=$result_path"/fft/";

	rm -rf $result_path

	mkdir $train_path;
	mkdir $result_path;
	mkdir $fft_path;

	train_fun_path=$path"/functions/train/"
	result_fun_path=$path"/functions/result/"
	fft_fun_path=$path"/functions/fft/"

	cd $train_fun_path
	for file in $(ls);do
	cp $file $train_path
	done

	cd $train_path
	for f in *.sh;do
		chmod a+x $f;
	done

	./getAmplitudes.sh
	./segmenter.sh

	for f in in *.txt;do
	rm -rf $f;
	done

	cd $train_fun_path
	for file in $(ls);do
		rm -rf $train_path$file;
	done

	cd $result_fun_path
	for file in $(ls);do
		cp $file $result_path;
	done

	cd $result_path
	for f in *.sh;do
		chmod a+x $f
	done

	./fft.sh

	cd $result_fun_path
	for file in $(ls);do
		rm -rf $result_path$file;
	done

	cd $fft_fun_path
	for file in $(ls);do
		cp $file $fft_path;
	done

	cd $fft_path
	for f in *.sh;do
		chmod a+x $f
	done

	./getFftFeature.sh

	cd $fft_fun_path
	for file in $(ls);do
		rm -rf $fft_path$file;
	done

	cd $result_fun_path
	cp result.cpp $result_path
	cd $result_path
	g++ result.cpp -std=c++0x
	./a.out
	rm -rf result.cpp
	rm -rf *.txt
	cd fft
	rm -rf *.fft
	cd $path
	echo $name "done"
done
g++ tabulate.cpp
./a.out
g++ generateCoefficients.cpp
./a.out


