###########################
#This script interacts    #
#with user to get the     #
#input and act accordingly#
###########################

#change path to script folder
current_path="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd $current_path;

#play recording to prompt for input
aplay buffer/responses/yes_sir.wav >/dev/null 2>&1

#get the audio input and send it for classification
cd recording
./getAudio.sh >/dev/null 2>&1
cd ..
cp recording/*.pcm test/train/
rm -rf recording/*.pcm;

#put the word classifiedin the file asd
./tester.sh 2>&1 |tail -1 >>asd;
command=$(head -n 1 asd);
rm -rf asd;

echo $command
case $command in
"louder")
	aplay buffer/responses/increasing_volume.wav >/dev/null 2>&1
	amixer -c 1 sset Master 10%+ >/dev/null 2>&1
;;
"sshh")
    aplay buffer/responses/decreasing_volume.wav >/dev/null 2>&1
    amixer -c 1 sset Master 10%- >/dev/null 2>&1
;;
*)
	aplay buffer/responses/right_away_sir.wav >/dev/null 2>&1
;;
esac
