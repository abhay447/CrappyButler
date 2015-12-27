##################################
#This script checks the accuracy #
#of the model used to classify   #
#words.                          #
#Modify the multipliers of alfa, #
#beta and gamma results in       #
#roughComp.cpp for varied results#
##################################
current_path="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd $current_path;
path=$(pwd)
cd train;
WORDS=$(ls);
for word in $WORDS;do
	cd $word;
	word_counter=0;
	correct_counter=0;
	temp_path=$(pwd);
	for pcm in *.pcm;do
		((word_counter++));
		#echo $word:$word_counter;
		cp $pcm $path/test/train
		cd $path
		./tester.sh 2>&1 |tail -1 >>asd
		cd $temp_path;
	done;
	cd $path;
	while read -r line;do
		if [[ "$line" == "$word" ]]; then
			((correct_counter++));
		fi;
	done < asd;
	rm -rf asd;
	bc -l <<< 100*$correct_counter/$word_counter;
	cd train;
done;
	
	
